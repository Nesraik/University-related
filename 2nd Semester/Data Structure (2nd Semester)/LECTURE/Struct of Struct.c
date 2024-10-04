#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//Declaring struct for college detail
struct student_college_detail
{
    int collage_id;
    char collage_name[50];
};


//Declaring struct for student detail
struct student_detail
{
    char id[12];
    char name[100];
    float percentage;
    // structure within structure
    struct student_college_detail clg_data;
};

int main()
{
    struct student_detail stu_data;
    
    //Input
    //Prompt user to input student Id
    printf("Enter Student ID: ");
    fflush(stdin);
    scanf("%s",stu_data.id);
    getchar();
    
    //Prompt user to input student name
    printf("Enter Student Name: ");
    fflush(stdin);
    scanf("%[^\n]",stu_data.name);
    getchar();
    
    //Prompt user to input student percentage
    printf("Enter Percentage: ");
    fflush(stdin);
    scanf("%f",&stu_data.percentage);
    getchar();
    
    
    //Copying "1125" into stu_data.clg_data.college_id
    stu_data.clg_data.collage_id = 1125;
    
    //Copying "binus" into stu_data.clg_data.college_name
    strcpy(stu_data.clg_data.collage_name, "binus");
    
    ///Clearing screen
    system("cls");
    
    //Output
    printf("id is: %s \n", stu_data.id);//Displaying Student Id
    printf("Name is: %s \n", stu_data.name);//Displaying student name
    printf("Percentage is: %.2f \n", stu_data.percentage);//Displaying student percentage
    printf("Collage id is: %d \n", stu_data.clg_data.collage_id);//Displaying college id
    printf("Collage name is: %s \n", stu_data.clg_data.collage_name);//Displaying college name
    getchar();
    return 0;
}
