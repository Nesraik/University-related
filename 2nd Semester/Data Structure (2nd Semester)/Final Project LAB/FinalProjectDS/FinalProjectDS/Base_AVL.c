#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>

//------- Structures, Globals, and Base Functions -------

typedef struct accountCell{
    struct accountCell *next, *prev;
    char username[30];
    char password[30];
}accountCell;

typedef struct treeNode{
    struct treeNode *left, *right, *prev;
    struct accountCell *head;
    char name[30];
    int level, AVL;
}treeNode;

//node -> for tree
//cell -> for linked list

struct Session{
    treeNode *hashRoot[10];
    treeNode *root;
    char name[30];
};

struct Session session; // Global variable related to log in

void session_destroy(){
    int i;
    for(i=0;i<10;i++) session.hashRoot[i] = NULL;
    session.root = NULL;
    strcpy(session.name, "\0");
}

void session_change_root(char str){
    session.root = session.hashRoot[str % 10];
}

treeNode *traverse(char str[], treeNode *node){
    if(node == NULL) return NULL;
    else if(strcmp(str, node->name) < 0) traverse(str, node->left);
    else if(strcmp(str, node->name) > 0) traverse(str, node->right);
    else return node;
    return NULL;
}

void generate_password(char str[30]){
    int i, temp;
    srand(time(NULL));
    for(i = 0; i < 29; i++){
        temp = rand() % 64;
        if(temp < 26) str[i] = temp + 65;
        else if(temp < 52) str[i] = temp + 71;
        else if(temp < 62) str[i] = temp - 4;
        else str[i] = temp - 27;
    }
    str[29] = '\0';
}

int dataCheck(){
    int i, j = 0;
    for(i=0;i<10;i++) if(session.hashRoot[i] != NULL)j++;
    return j;
}

//------- AVL Functions -------

void AVL_L_rotate(treeNode *node){
    treeNode *parent = node->prev;
    node->prev = parent->prev;
    parent->prev = node;
    parent->left = node->right;
    node->right = parent;

    treeNode *temp = node->prev;
    if(temp == NULL) session.root = node;
    else if(temp->left == parent) temp->left = node;
    else temp->right = node;
    temp = parent->left;
    if(temp!=NULL)temp->prev = parent;
    session.hashRoot[node->name[0] % 10] = session.root;
}

    // // -----Troubleshooting Rotation Helper-----
    // printf("\n\nr %s\n", session.root->name);
    // printf("\nn %s\n", node->name);
    // if(node->prev != NULL) printf("n-P %s\n", node->prev->name);
    // if(node->left != NULL) printf("n-L %s\n", node->left->name);
    // if(node->right != NULL) printf("n-R %s\n", node->right->name);
    // printf("\np %s\n", parent->name);
    // if(parent->prev != NULL) printf("p-P %s\n", parent->prev->name);
    // if(parent->left != NULL) printf("p-L %s\n", parent->left->name);
    // if(parent->right != NULL) printf("p-R %s\n", parent->right->name);

void AVL_R_rotate(treeNode *node){
    treeNode *parent = node->prev;
    node->prev = parent->prev;
    parent->prev = node;
    parent->right = node->left;
    node->left = parent;

    treeNode *temp = node->prev;
    if(temp == NULL) session.root = node;
    else if(temp->left == parent) temp->left = node;   
    else temp->right = node;
    temp = parent->right;
    if(temp!=NULL)temp->prev = parent;
    session.hashRoot[node->name[0] % 10] = session.root;
}

void AVL_violation(treeNode *node, int type);

void AVL_check(treeNode *node){
    if(node == NULL) return;
    else if(node->left == NULL && node->right == NULL){
        node->level = 1;
        node->AVL = 0;
    }
    else{
        treeNode *left = node->left, *right = node->right;
        if(left != NULL) AVL_check(left);
        if(right != NULL) AVL_check(right);
        if(left == NULL){
            node->level = right->level+1;
            node->AVL = - right->level;
        } 
        else if(right == NULL){
            node->level = left->level+1;
            node->AVL = left->level;
        } 
        else {
            if(left->level > right->level) node->level = left->level+1;
            else node->level = right->level +1;  
            node->AVL = left->level - right->level;
        }
        if(node->AVL > 1) AVL_violation(node, 0);
        else if(node->AVL < -1) AVL_violation(node, 1);
    }
}

void AVL_violation(treeNode *node, int type){
    treeNode *child;
    if(type == 0){
        child = node->left;
        if(child->AVL > 0){ //LL
            AVL_L_rotate(child);
        }
        else{ //LR
            AVL_R_rotate(child->right);
            AVL_L_rotate(child->prev);
        }
    }
    else{
        child = node->right;
        if(child->AVL > 0){ //RL
            AVL_L_rotate(child->left);
            AVL_R_rotate(child->prev);
        }
        else{ //RR
            AVL_R_rotate(child);
        }
    }
    AVL_check(node);
}