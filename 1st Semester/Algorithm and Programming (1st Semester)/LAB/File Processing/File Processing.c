#include <stdio.h>
#include <stdlib.h>
struct datas{
	int record;
	char toolname[100];
	int quantity;
	float cost;
};
FILE*fptr;
int write(){
	struct datas data;
	system("cls");
	fptr=fopen("hardware.txt","a");
		printf("Record: ");
		scanf("%d",&data.record);
		getchar();
		fprintf(fptr,"%d;",data.record);
		printf("Tool Name: ");
		scanf("%[^\n]",data.toolname);
		getchar();
		fprintf(fptr,"%s;",data.toolname);
		printf("Quantity: ");
		scanf("%d",&data.quantity);
		getchar();
		fprintf(fptr,"%d;",data.quantity);
		printf("Cost: $");
		scanf("%f",&data.cost);
		getchar();
		fprintf(fptr,"%.2f\n",data.cost);
		system("cls");
	fclose(fptr);
	printf("\n-----------Data succesfully created------------------\n");
}
void read(struct datas data[100], int *x)
{
	int limit=*x;
    fptr = fopen("hardware.txt", "r");
    if (fptr == NULL)
    {
        printf("Can't open file or file doesn't exist\n");
        return;
    }
    printf("Record #    Tool Name\t\t Quantity\t     Cost\n");
    printf("=========================================================\n");
    while (fscanf(fptr, "%d;%[^\';'];%d;%f\n", &data[limit].record, &data[limit].toolname, &data[limit].quantity, &data[limit].cost) != EOF)
    {
        printf("%-10d  %-12s\t %8d\t %8.2f\n", data[limit].record, data[limit].toolname, data[limit].quantity, data[limit].cost);
        limit += 1;
    }
    *x=limit;
    printf("\n");
    fclose(fptr);
}
void deletedata(struct datas data[100], int *x)
{
    int delrecord,numdelrecord;
    read(data, x);
    int limit = *x;
    printf("Enter the amount of record do you wish to delete: ");
    scanf("%d",&numdelrecord);
    for(int k=0;k<numdelrecord;k++){
    int found = 0;
    fptr = fopen("hardware.txt", "w");
    printf("Select which record to delete : ");
    scanf("%d", &delrecord);
    for (int i = 0; i < limit; i++)
    {
        if (data[i].record == delrecord)
        {
            found = 1;
            continue;
        }
        else
        {
            if(i == limit - 1){
            	fprintf(fptr, "%d;%s;%d;%f", data[i].record, data[i].toolname, data[i].quantity, data[i].cost);
			}else{
				fprintf(fptr, "%d;%s;%d;%f\n", data[i].record, data[i].toolname, data[i].quantity, data[i].cost);
			}
        }
    }
    if (found == 0)
    {
        printf("Record not found\n");
    }
    else
    {
        printf("Record deleted\n");
    }
    fclose(fptr);
	}
}
void modify(struct datas data[100],int *x){
    int modrecord;
    int indrec= 0;
    int found = 0;
    read(data, x);
    int limit = *x;
    printf("Select which record do you wish to modify : ");
    scanf("%d", &modrecord);
    getchar();
    for (int i = 0; i < limit; i++)
    {
        if (data[i].record == modrecord)
        {
            found = 1;
            indrec = i;
            break;
        }
    }
    if (found == 0)
    {
        printf("Record not found\n");
        indrec = 0;
        system("pause");
        system("cls");
    }
    else
    {
        fptr = fopen("hardware.txt", "w");
        if (fptr == NULL)
        {
            printf("Can't open file or file doesn't exist\n");
            return;
        }
        int menu;
        do
        {
            system("cls");
            printf("-------------------Modify--------------------\n");
            printf("1. Record\n");
            printf("2. Tool name\n");
            printf("3. Quantity\n");
            printf("4. Cost\n");
            printf("5. Exit\n");
            scanf("%d", &menu);
            getchar();
            switch (menu)
            {
            case 1:
                printf("Record : ");
                scanf("%d", &data[indrec].record);
                getchar();
                printf("Data Modified\n");
                system("pause");
                break;
            case 2:
                printf("Tool Name : ");
                scanf("%[^\n]", &data[indrec].toolname);
                getchar();
                printf("Data Modified\n");
                system("pause");
                break;
            case 3:
                printf("Quantity : \n");
                scanf("%d", &data[indrec].quantity);
                getchar();
                printf("Data Modified\n");
                system("pause");
                break;
            case 4:
                printf("Cost : ");
                scanf("%f", &data[indrec].cost);
                getchar();
                printf("Data Modified\n");
                system("pause");
                break;
            case 5:
                for (int i = 0; i < limit; i++)
                {
                    if(i == limit-1){
                    	fprintf(fptr, "%d;%s;%d;%f", data[i].record, data[i].toolname, data[i].quantity, data[i].cost);
					}else{
						fprintf(fptr, "%d;%s;%d;%f\n", data[i].record, data[i].toolname,data[i].quantity, data[i].cost);
					}
                }
                printf("Data Saved\n");
                system("pause");
                system("cls");
                break;
            default:
                printf("Invalid Input\n");
                system("pause");
                system("cls");
                break;
            }
        } while (menu != 5);
        fclose(fptr);
    }
}
int main(){
	int menu,limit;
	struct datas data[100];
	do{
	limit =0;
	printf("----------------Menu--------------------\n");
	printf("1. Create/Add Data\n");
	printf("2. Display Data\n");
	printf("3. Delete Data\n");
	printf("4. Modify Data\n");
	printf("5. Exit\n");
	printf("\nSelect Menu: ");
	scanf("%d",&menu);
	getchar();
	switch(menu){
		case 1:
		system("cls");
		write();
		system("pause");
		system("cls");
		break;
		case 2:
		system("cls");
		read(data,&limit);
		system("pause");
		system("cls");
		break;
		case 3:
		system("cls");
		deletedata(data,&limit);
		system("pause");
		system("cls");
		break;
		case 4:
		system("cls");
		modify(data,&limit);
		system("pause");
		system("cls");
	}
	}while(menu!=5);
	system("cls");
	printf("------------------Program Closed-----------------------\n");
}

