import streamlit as st
import numpy as np
import tensorflow as tf
import matplotlib.pyplot as plt
import cv2
from sklearn.model_selection import train_test_split
import os
from tensorflow.keras.layers import Input, Dense, Dropout, BatchNormalization, Flatten, Concatenate
from tensorflow.keras.models import Model
import json
from tensorflow.keras.models import load_model
from PIL import Image

# Load models based on the selected feature extractor
@st.cache(allow_output_mutation=True)
def load_custom_model(model_name):
    return tf.keras.models.load_model(model_name)

# Define waste categories
class_names = ['battery', 'clothing_waste', 'glass', 'metal', 'organic', 'paper', 'plastic']

def pad_image(img):
    height, width = img.shape[:2]

    height_padding = (96 - height % 96) % 96
    width_padding = (96 - width % 96) % 96

    top_padding = height_padding // 2
    bottom_padding = height_padding - top_padding
    left_padding = width_padding // 2
    right_padding = width_padding - left_padding

    padded_img = cv2.copyMakeBorder(
        img, top_padding, bottom_padding, left_padding, right_padding, cv2.BORDER_CONSTANT, value=[0, 0, 0]
    )

    return padded_img


def resize_image(img):
    return cv2.resize(img, (96,96), interpolation=cv2.INTER_LANCZOS4)

# Default max_keypoints and max_descriptor (ORB)
max_keypoint = 68
max_descriptor = 68

def extract_akaze_features(img, max_keypoints=max_keypoint, max_descriptors=max_descriptor):
    img = img.astype(np.uint8)
    gray_image = cv2.cvtColor(img, cv2.COLOR_RGB2GRAY)
    blur_image = cv2.GaussianBlur(gray_image, (5, 5), 0)
    akaze = cv2.AKAZE_create()
    keypoints, descriptor = akaze.detectAndCompute(blur_image, None)
    
    
    keypoint_positions = []
    keypoint_sizes = []
    keypoint_angles = []

    
    if keypoints:
        for kp in keypoints:
            keypoint_positions.append([kp.pt[0], kp.pt[1]])  # (x, y)
            keypoint_sizes.append(kp.size)
            keypoint_angles.append(kp.angle)

        
        keypoint_positions = np.array(keypoint_positions)
        keypoint_sizes = np.array(keypoint_sizes)
        keypoint_angles = np.array(keypoint_angles)

        
        if keypoint_positions.shape[0] < max_keypoints:
            pad_length = max_keypoints - keypoint_positions.shape[0]
            keypoint_positions = np.pad(keypoint_positions, ((0, pad_length), (0, 0)), mode='constant')
            keypoint_sizes = np.pad(keypoint_sizes, (0, pad_length), mode='constant')
            keypoint_angles = np.pad(keypoint_angles, (0, pad_length), mode='constant')

       
        else:
            keypoint_positions = keypoint_positions[:max_keypoints]
            keypoint_sizes = keypoint_sizes[:max_keypoints]
            keypoint_angles = keypoint_angles[:max_keypoints]

        # Calculate aggregated keypoint stats (mean and std)
        keypoint_stats = np.concatenate([
            np.mean(keypoint_positions, axis=0),  # mean (x, y)
            np.std(keypoint_positions, axis=0),   # std (x, y)
            [np.mean(keypoint_sizes), np.std(keypoint_sizes)],  # mean and std of sizes
            [np.mean(keypoint_angles), np.std(keypoint_angles)]  # mean and std of angles
        ])
    else:
        
        keypoint_stats = np.zeros(8)

    if descriptor is not None:
        
        if descriptor.shape[0] > max_descriptors:
            descriptor = descriptor[:max_descriptors]
        elif descriptor.shape[0] < max_descriptors:
            padding = np.zeros((max_descriptors - descriptor.shape[0], descriptor.shape[1]))
            descriptor = np.vstack([descriptor, padding])
        descriptor = descriptor.flatten()  # Flatten to 1D
        #print(descriptor.shape)
    else:
        
        descriptor = np.zeros(max_descriptors * 61) 

    return keypoint_stats, descriptor

def extract_sift_features(img, max_keypoints=100, max_descriptors=100):
    img = img.astype(np.uint8)
    gray_image = cv2.cvtColor(img, cv2.COLOR_RGB2GRAY)
    blur_image = cv2.GaussianBlur(gray_image, (5, 5), 0)
    sift = cv2.SIFT_create()
    keypoints, descriptor = sift.detectAndCompute(blur_image, None)
    
    # Initialize lists to store keypoint data
    keypoint_positions = []
    keypoint_sizes = []
    keypoint_angles = []

     # If there are keypoints, populate the lists
    if keypoints:
        for kp in keypoints:
            keypoint_positions.append([kp.pt[0], kp.pt[1]])  # (x, y)
            keypoint_sizes.append(kp.size)
            keypoint_angles.append(kp.angle)

        # Convert lists to numpy arrays for calculations
        keypoint_positions = np.array(keypoint_positions)
        keypoint_sizes = np.array(keypoint_sizes)
        keypoint_angles = np.array(keypoint_angles)

        # Ensure padding works even if fewer keypoints than max_keypoints
        if keypoint_positions.shape[0] < max_keypoints:
            pad_length = max_keypoints - keypoint_positions.shape[0]
            keypoint_positions = np.pad(keypoint_positions, ((0, pad_length), (0, 0)), mode='constant')
            keypoint_sizes = np.pad(keypoint_sizes, (0, pad_length), mode='constant')
            keypoint_angles = np.pad(keypoint_angles, (0, pad_length), mode='constant')

        # Truncate if there are more keypoints than max_keypoints
        else:
            keypoint_positions = keypoint_positions[:max_keypoints]
            keypoint_sizes = keypoint_sizes[:max_keypoints]
            keypoint_angles = keypoint_angles[:max_keypoints]

        # Calculate aggregated keypoint stats (mean and std)
        keypoint_stats = np.concatenate([
            np.mean(keypoint_positions, axis=0),  # mean (x, y)
            np.std(keypoint_positions, axis=0),   # std (x, y)
            [np.mean(keypoint_sizes), np.std(keypoint_sizes)],  # mean and std of sizes
            [np.mean(keypoint_angles), np.std(keypoint_angles)]  # mean and std of angles
        ])
    else:
        # If no keypoints, return zero-filled stats
        keypoint_stats = np.zeros(8)

    if descriptor is not None:
        # Truncate or pad descriptors to a fixed length (e.g., max_descriptors x 32)
        if descriptor.shape[0] > max_descriptors:
            descriptor = descriptor[:max_descriptors]
        elif descriptor.shape[0] < max_descriptors:
            padding = np.zeros((max_descriptors - descriptor.shape[0], descriptor.shape[1]))
            descriptor = np.vstack([descriptor, padding])
        descriptor = descriptor.flatten()  # Flatten to 1D
    else:
        # If no descriptors, return a zero-padded vector
        descriptor = np.zeros(max_descriptors * 128) 

    return keypoint_stats, descriptor

def extract_orb_features(img, max_keypoints=max_keypoint, max_descriptors=max_descriptor):
    img = img.astype(np.uint8)
    gray_image = cv2.cvtColor(img, cv2.COLOR_RGB2GRAY)
    blur_image = cv2.GaussianBlur(gray_image, (5, 5), 0)
    orb = cv2.ORB_create()
    keypoints, descriptor = orb.detectAndCompute(blur_image, None)
    
    
    keypoint_positions = []
    keypoint_sizes = []
    keypoint_angles = []

    
    if keypoints:
        for kp in keypoints:
            keypoint_positions.append([kp.pt[0], kp.pt[1]])  # (x, y)
            keypoint_sizes.append(kp.size)
            keypoint_angles.append(kp.angle)

        
        keypoint_positions = np.array(keypoint_positions)
        keypoint_sizes = np.array(keypoint_sizes)
        keypoint_angles = np.array(keypoint_angles)

        
        if keypoint_positions.shape[0] < max_keypoints:
            pad_length = max_keypoints - keypoint_positions.shape[0]
            keypoint_positions = np.pad(keypoint_positions, ((0, pad_length), (0, 0)), mode='constant')
            keypoint_sizes = np.pad(keypoint_sizes, (0, pad_length), mode='constant')
            keypoint_angles = np.pad(keypoint_angles, (0, pad_length), mode='constant')

        
        else:
            keypoint_positions = keypoint_positions[:max_keypoints]
            keypoint_sizes = keypoint_sizes[:max_keypoints]
            keypoint_angles = keypoint_angles[:max_keypoints]

        # Calculate aggregated keypoint stats (mean and std)
        keypoint_stats = np.concatenate([
            np.mean(keypoint_positions, axis=0),  # mean (x, y)
            np.std(keypoint_positions, axis=0),   # std (x, y)
            [np.mean(keypoint_sizes), np.std(keypoint_sizes)],  # mean and std of sizes
            [np.mean(keypoint_angles), np.std(keypoint_angles)]  # mean and std of angles
        ])
    else:
        
        keypoint_stats = np.zeros(8)

    
    if descriptor is not None:
        if descriptor.shape[0] > max_descriptors:
            descriptor = descriptor[:max_descriptors]
        elif descriptor.shape[0] < max_descriptors:
            padding = np.zeros((max_descriptors - descriptor.shape[0], descriptor.shape[1]))
            descriptor = np.vstack([descriptor, padding])
        descriptor = descriptor.flatten()  # Flatten to 1D
    else:
        descriptor = np.zeros(max_descriptors * 32)   # Exact length expected by the model


    return keypoint_stats, descriptor

def overlay_keypoints(image, extractor_method):
    """Overlay the keypoints on the image."""
    img = image.astype(np.uint8)
    gray_image = cv2.cvtColor(img, cv2.COLOR_RGB2GRAY)
    blur_image = cv2.GaussianBlur(gray_image, (5, 5), 0)

    if extractor_method == "ORB":
        orb = cv2.ORB_create(nfeatures = 68)
        keypoints, descriptor = orb.detectAndCompute(blur_image, None)
        # Draw keypoints directly
        image_with_keypoints = cv2.drawKeypoints(image, keypoints, None, color=(0, 255, 0), flags=cv2.DRAW_MATCHES_FLAGS_DRAW_RICH_KEYPOINTS)
        
    elif extractor_method == "AKAZE":
        akaze = cv2.AKAZE_create()
        keypoints, descriptor = akaze.detectAndCompute(blur_image, None)

        # Sort keypoints by response (strength)
        keypoints = sorted(keypoints, key=lambda kp: kp.response, reverse=True)

        # Limit to the top N keypoints
        keypoints = keypoints[:28]
        # Draw keypoints directly
        image_with_keypoints = cv2.drawKeypoints(image, keypoints, None, color=(0, 255, 0), flags=cv2.DRAW_MATCHES_FLAGS_DRAW_RICH_KEYPOINTS)

    elif extractor_method == "SIFT":
        sift = cv2.SIFT_create(nfeatures = 100)
        keypoints, descriptor = sift.detectAndCompute(blur_image, None)
        # Draw keypoints directly
        image_with_keypoints = cv2.drawKeypoints(image, keypoints, None, color=(0, 255, 0), flags=cv2.DRAW_MATCHES_FLAGS_DRAW_RICH_KEYPOINTS)
    
    return image_with_keypoints


def predict_image(image_path, extractor_method, model):
    # Read, resize, pad, and process the image
    image = cv2.imread(image_path)
    image = resize_image(image)
    image = pad_image(image)
    image = cv2.cvtColor(image, cv2.COLOR_BGR2RGB)

    # Extract features dynamically based on extractor method
    if extractor_method == "ORB":
        keypoints, descriptors = extract_orb_features(image, max_descriptors=68, max_keypoints=68)
    elif extractor_method == "AKAZE":
        keypoints, descriptors = extract_akaze_features(image, max_descriptors=28, max_keypoints=28)
    elif extractor_method == "SIFT":
        keypoints, descriptors = extract_sift_features(image, max_descriptors=100, max_keypoints=100)
    else:
        raise ValueError("Invalid extractor method!")
    
    image = image.astype("float32") / 255.0
    

    # Prepare inputs as a list for the model
    image_input = np.expand_dims(image, axis=0)
    descriptor_input = np.expand_dims(descriptors, axis=0)
    keypoint_input = np.expand_dims(keypoints, axis=0)

    # Predict
    with st.spinner("Processing..."):
        predictions = model.predict([image_input, descriptor_input, keypoint_input])[0]

    # Sort predictions for top 3 classes
    top_indices = predictions.argsort()[-3:][::-1]
    top_classes = [(class_names[i], predictions[i]) for i in top_indices]


    return top_classes, predictions

# Streamlit UI
# Streamlit UI for file upload and feature extraction method selection
st.title("Waste Classification with Keypoint Visualization")
st.write("Upload an image and choose the feature extraction method to visualize keypoints.")

# Feature extractor and model selection
extractor_method = st.selectbox(
    "Select a feature extraction method:",
    options=["ORB", "AKAZE", "SIFT"],
    index=0
)

model_mapping = {
    "ORB": "orb_model.h5",
    "AKAZE": "akaze_model.h5",
    "SIFT": "sift_model.h5"
}

model_name = model_mapping.get(extractor_method, "orb_model.h5") # default
model = load_custom_model(model_name)

file_name_mapping = {
    "ORB": "max_feature_length_ORB.json",
    "AKAZE": "max_feature_length_akaze.json",
    "SIFT": "max_feature_length_sift.json"
}
file_name = file_name_mapping.get(extractor_method, "unknown_extractor.json")

with open(file_name, "r") as f:
    max_feature_length = json.load(f)

max_keypoint = max_feature_length['max_keypoint']
max_descriptor = max_feature_length['max_descriptor']


uploaded_file = st.file_uploader("Choose an image...", type=["jpg", "jpeg", "png"])

if uploaded_file is not None:
    
    # Save uploaded image to a temporary location
    with open("temp_uploaded_image.jpg", "wb") as temp_file:
        temp_file.write(uploaded_file.getbuffer())

    # Display the uploaded image
    st.subheader("Uploaded Image:")
    image = Image.open("temp_uploaded_image.jpg")
    st.image(image, caption="Uploaded Image", use_column_width=True)

    # Convert to numpy array for keypoint processing
    image_np = np.array(image)

    # Visualize keypoints on the image
    image_with_keypoints = overlay_keypoints(image_np, extractor_method)

    # Display the image with keypoints in Streamlit
    st.subheader("Keypoints Visualized on the Image:")
    st.image(image_with_keypoints, caption="Image with Keypoints", use_column_width=True)
    st.write(f'Max Keypoint Length of the Model: {max_keypoint}')
    st.write(f'Max Descriptor Length of the Model: {max_descriptor}')

    try:
        predictions, bar_pred = predict_image("temp_uploaded_image.jpg", extractor_method, model)
        st.write(f"### Predictions: ({predictions[0][0].capitalize()})")
        for i, (class_name, confidence) in enumerate(predictions, 1):
            st.write(f"{i}. **{class_name.capitalize()}** with confidence **{confidence:.2%}**")

        fig, ax = plt.subplots()
        ax.barh(class_names, bar_pred, color='skyblue')
        ax.set_xlabel('Confidence')
        ax.set_title('Confidence Scores for Each Class')
        st.pyplot(fig)

    except Exception as e:
        st.error(f"Error during prediction: {e}")
    
    os.remove("temp_uploaded_image.jpg")

with st.expander("About"):
    st.write("""
    This app classifies waste into seven categories using Multi-Modal approach. 
    You can choose different feature extractors (ORB, SIFT, AKAZE) to see their impact on classification accuracy.
    """)