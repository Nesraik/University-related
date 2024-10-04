#include"CRUD_Functions.c"
#include<conio.h>

void viewExtra(treeNode *node){
    char temp = 'a';
    if(node == NULL){
        printf("\n     Error\n\n");
        return;
    }
    while(1){
        int amount = readDataAccount(node);
        printf("0. Back\n1. Add new account\n2. Delete one account from this data\n3. Delete this data\n");
        temp = getch();
        switch(temp){
            case '0':{
                return;
            }
            case '1':{
                accountCell *temp, *newData = (accountCell*) malloc(sizeof(accountCell));
    
                printf("\nInput a new account data\n\n");
                do{
                    printf("Username : "); scanf(" %s", newData->username);
                    fflush(stdin);
                    for(temp = node->head; temp != NULL && newData->username != temp->username; temp = temp->next);
                    if(temp != NULL) printf("\n     Username must be unique\n\n");
                } while(temp != NULL);
                generate_password(newData->password);
                printf("Password (Auto Generated): %s\n\n", newData->password);
                newData->next = NULL;
                newData->prev = NULL;
                createDataAccount(node, newData);
                printf("Data account succesfully created, ");
                system("pause");
                break;
            }
            case '2':{
                int temp = 0, i;
                char temp2;
                printf("\n\n");
                while(temp <= 0 || temp > amount){
                    printf("Select data number [1 - %d]: ", amount);
                    scanf(" %d",&temp);
                }
                accountCell *cell = node->head;
                for(i=0;i<temp-1;i++) cell = cell->next;
                while(1){
                    printf("Are you sure want to delete account \"%s\"?[y/n] ", cell->username); scanf(" %c", &temp2);
                    if(tolower(temp2) == 'n'){
                        printf("\nDelete canceled, ");
                        system("pause");
                        return;
                    }
                    else if(tolower(temp2 == 'y')) break;
                }
                deleteDataAccount(cell, node);
                printf("Data account succesfully deleted, ");
                system("pause");
                break;
            }
            case '3':{
                printf("\nAre you sure you want to delete this data?[y/n]");
                while(1){
                    temp = getch();
                    if(tolower(temp) == 'y') break;
                    else if(tolower(temp) == 'n') return;
                }
                deleteData(node);
                printf("\n\nData succesfully deleted, ");
                system("pause");
                return;
                break;
            }
        }
        system("cls");
    }
}

void add(){
    char temp = 'a';
    while(1){
        printf("-----\n Add\n-----\n");
        printf("0. Back\n1. Add New Data\n2. Add New Account to existing data\n");
        temp = getch();
        switch(temp){
            case '0':{
                return;
            }
            case '1':{
                treeNode *newData = (treeNode*) malloc(sizeof(treeNode)), *node = session.root;
                printf("Site/App : "); scanf(" %[^\n]", newData->name);
                session_change_root(newData->name[0]);
                node = traverse(newData->name, session.root);
                if(node != NULL){
                    printf("\nSame site/app name has been found for ");
                    viewExtra(node);
                    return;
                }
                newData->prev = NULL;
                newData->left = NULL;
                newData->right = NULL;
                accountCell *newAcc = (accountCell*) malloc(sizeof(accountCell));
                newData->head = newAcc;
                printf("Username : "); scanf(" %[^\n]", newAcc->username);
                generate_password(newAcc->password);
                printf("Password (Auto Generated): %s\n\n", newAcc->password);
                newAcc->next = NULL;
                newAcc->prev = NULL;
                createData(newData);
                printf("Data succesfully created, ");
                system("pause");
                return;
                break;
            }
            case '2':{
                char str[30];
                printf("Site/App : "); scanf(" %[^\n]", str);
                session_change_root(str[0]);
                treeNode *node = traverse(str, session.root);
                
                if(node == NULL){
                    printf("\n     ERROR\n");
                    system("pause");
                    return;
                }
                readDataAccount(node);

                accountCell *temp, *newData = (accountCell*) malloc(sizeof(accountCell));;
    
                printf("\nInput a new account data\n\n");
                do{
                    printf("Username : "); scanf(" %s", newData->username);
                    fflush(stdin);
                    for(temp = node->head; temp != NULL && newData->username != temp->username; temp = temp->next);
                    if(temp != NULL) printf("\n     Account name must be unique\n\n");
                } while(temp != NULL);
                generate_password(newData->password);
                printf("Password (Auto Generated): %s\n\n", newData->password);
                newData->next = NULL;
                newData->prev = NULL;
                createDataAccount(node, newData);
                printf("Data account succesfully created, ");
                system("pause");
                return;
                break;
            }
        }
        system("cls");
    }
}

void view(){
    char temp = 'a';
    int i = dataCheck();
    if(i == 0){
        printf("\nThere is no data, ");
        system("pause");
        return;
    }
    while(1){
        printf("------\n View\n------\n");
        printf("0. Back\n1. View all data\n2. View specific data\n");
        temp = getch();
        switch(temp){
            case '0':{
                return;
            }
            case '1':{
                int i;
                printf("\n---------------------------------------------------\n");
                for(i=0;i<10;i++) if(session.hashRoot[i] != NULL) readData(session.hashRoot[i]);
                system("pause");
                break;
            }
            case '2':{
                char str[30];
                printf("Site/App : "); scanf(" %[^\n]", str);
                session_change_root(str[0]);
                printf("\n---------------------------------------------------\n");
                viewExtra(traverse(str, session.root));
                system("pause");
                break;
            }
        }
        system("cls");
    }
}

void delete(){
    char temp = 'a';
    int i = dataCheck();
    if(i == 0){
        printf("\nThere is no data, ");
        system("pause");
        return;
    }
    while(1){
        printf("--------\n Delete\n--------\n");
        printf("0. Back\n1. Delete account from a data\n2. Delete an existing data\n");
        temp = getch();
        switch(temp){
            case '0':{
                return;
            }
            case '1':{
                char str[30], temp2;
                printf("Site/App : "); scanf(" %[^\n]", str);
                session_change_root(str[0]);
                treeNode *node = traverse(str, session.root);
                int amount = readDataAccount(node);
                int temp = 0, i;
                printf("\n\n");
                while(temp <= 0 || temp > amount){
                    printf("Select data number [1 - %d]: ", amount);
                    scanf(" %d", &temp);
                }
                accountCell *cell = node->head;
                for(i=0;i<temp-1;i++) cell = cell->next;
                while(1){
                    printf("Are you sure want to delete account \"%s\"?[y/n] ", cell->username); scanf(" %c", &temp2);
                    fflush(stdin);
                    if(tolower(temp2) == 'n'){
                        printf("\nDelete canceled, ");
                        system("pause");
                        return;
                    }
                    else if(tolower(temp2 == 'y')) break;
                }
                deleteDataAccount(cell, node);
                printf("Data account succesfully deleted, ");
                system("pause");
                return;
                break;
            }
            case '2':{
                char str[30], temp;
                printf("Site/App : "); scanf(" %[^\n]", str);
                session_change_root(str[0]);
                treeNode *node = traverse(str, session.root);
                readDataAccount(node);
                printf("\nAre you sure you want to delete this data?[y/n] ");
                while(1){
                    scanf(" %c", &temp);
                    fflush(stdin);
                    if(tolower(temp) == 'y') break;
                    else if(tolower(temp) == 'n') return;
                }
                deleteData(node);
                printf("\n\nData succesfully deleted, ");
                system("pause");
                return;
                break;
            }
        }
        system("cls");
    }
}

// // -----Troubleshooting Password Manager Helper-----
// void menu(){
//     char temp = 'a';
//     while(temp != '0'){
//         printf("----------------------------\n Hello, %s\n----------------------------\n", session.name);
//         printf("0. Log Out\n1. Add New\n2. View\n3. Delete\n"); 
//         temp = getch();
//         switch(temp){
//             case '0':{
//                 session_destroy();
//                 return;                
//             }
//             case '1':{
//                 system("cls");
//                 add();
//                 break;
//             }
//             case '2':{
//                 system("cls");
//                 view();
//                 break;
//             }
//             case '3':{
//                 system("cls");
//                 delete();
//                 break;
//             }
//         }
//         system("cls");
//     }
// }

// int main(){
//     session_destroy();
//     strcpy(session.name, "Passldfad");
//     menu();
// }