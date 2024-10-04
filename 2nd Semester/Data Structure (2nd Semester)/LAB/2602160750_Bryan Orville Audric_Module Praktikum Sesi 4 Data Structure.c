#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define SIZE 10007

struct HashChain{
	char BookTitle[50];
	char BookAuthor[25];
	char ISBN[13];
	int PageNumber;
	char BookID[31];
	struct HashChain *next;
};
struct HashChain *Chain[SIZE]={NULL};

char CurrentBookID[31];
int CurrentDataSize=0,BookOrder=0;

void InsertData(char *BookTitleIn, char *BookAuthorIn, char *ISBNIn, int PageNumberInput, int ChainKey){
	struct HashChain *newnode = (struct HashChain*)malloc(sizeof(struct HashChain));
	strcpy(newnode->BookTitle,BookTitleIn);
	strcpy(newnode->BookAuthor,BookAuthorIn);
	strcpy(newnode->ISBN,ISBNIn);
	strcpy(newnode->BookID,CurrentBookID);
	newnode->PageNumber=PageNumberInput;
	newnode->next=NULL;
	
	if(Chain[ChainKey]==NULL){
		Chain[ChainKey]=newnode;
	}else{
		struct HashChain *Current;
		Current = Chain[ChainKey];
		
		while(Current->next!=NULL){
			Current=Current->next;
		}
		Current->next=newnode;
	}
}

int SumOfASCII(char *BookTitleIn, char *BookAuthorIn, char *ISBNIn){
	
	char BookIDResult[31], LastThreeCharBookID[3];
	BookIDResult[0] = 'B';
	
	int CountDigit=0,DataSizeCopy = CurrentDataSize;
	while(DataSizeCopy!=0){
		DataSizeCopy = DataSizeCopy / 10;
		CountDigit++;
	}
	for(int i=1;i<6 - CountDigit;i++){
		BookIDResult[i]='0';
	}
	
	char StringCurrentBookOrder[6];
	
	sprintf(StringCurrentBookOrder, "%d", BookOrder);
	
	int j=0;
	for(int i=6 - CountDigit; StringCurrentBookOrder[j]!='\0'&& i<6 ;i++){
		BookIDResult[i]=StringCurrentBookOrder[j];
		j++;
	}
	BookIDResult[6] = '-';
	
	strcat(BookIDResult,ISBNIn);
	
	
	LastThreeCharBookID[0] = '-';
	
	int length = strlen(BookAuthorIn);
	
	int index=0;
	for(int i = 0 ;i<length;i++){
		if(BookAuthorIn[i]==' '){
			index = i+1;
			break;
		}
	}
	
	LastThreeCharBookID[1] = toupper(BookAuthorIn[index]);
	LastThreeCharBookID[2] = BookTitleIn[0];
	
	strcat(BookIDResult, LastThreeCharBookID);
	
	length = strlen(BookIDResult);
	
	int Sum=0;
	for(int i=0;BookIDResult[i]!='\0' && i<length;i++){
		Sum += BookIDResult[i];	
	}
	strcpy(CurrentBookID,BookIDResult);
	return Sum;
}

int HashKeyConversion(int Number){
	int key = Number % SIZE;
	return key;
}

void InsertBook(){
	char BookTitleInput[50], BookAuthorInput[25], ISBNInput[13];
	int PageNumberInput;
	
	printf("Input book title[5-50][unique]: ");
	fflush(stdin);
	scanf("%[^\n]",BookTitleInput);
	getchar();
	
	int length = strlen(BookTitleInput);
	
	while(length < 5 || length > 50){
		printf("Input book title[5-50][unique]: ");
		fflush(stdin);
		scanf("%[^\n]",BookTitleInput);
		getchar();
		
		length = strlen(BookTitleInput);	
	}
	
	int found=0;
	for(int i=0;i<SIZE;i++){
		if(Chain[i]!=NULL){
			struct HashChain *Current;
			Current = Chain[i];
			while(Current!=NULL){
				if(strcmp(Current->BookTitle,BookTitleInput)==0){
					found = 1;
					break;
					}
				Current = Current->next;
					}
				}
			}			
	
	while(found==1 || length < 5 || length > 50){
		
		printf("Input book title[5-50][unique]: ");
		fflush(stdin);
		scanf("%[^\n]",BookTitleInput);
		getchar();
		
		length = strlen(BookTitleInput);
		
		while(length < 5 || length > 50){
			printf("Input book title[5-50][unique]: ");
			fflush(stdin);
			scanf("%[^\n]",BookTitleInput);
			getchar();
			
			length = strlen(BookTitleInput);	
		}
		found = 0;
				
		for(int i=0;i<SIZE;i++){
			if(Chain[i]!=NULL){
				struct HashChain *Current;
				Current = Chain[i];
				while(Current!=NULL){
					if(strcmp(Current->BookTitle,BookTitleInput)==0){
						found = 1;
						break;
						}
					Current = Current->next;
					}
				}
			}		
	}
	
	printf("Input author name[3-25][Mr. ][Mrs. ]: ");
	fflush(stdin);
	scanf("%[^\n]",BookAuthorInput);
	getchar();
	
	length = strlen(BookAuthorInput);
	
	char Mr[] = "Mr. ";
	char Mrs[] = "Mrs. ";
	
	char *CheckMr = strstr(BookAuthorInput,Mr);
	char *CheckMrs = strstr(BookAuthorInput, Mrs);

	while(length < 3 || length > 25 || (CheckMr == NULL && CheckMrs==NULL)||BookAuthorInput[0]!='M'){
			
		printf("Input author name[3-25][Mr. ][Mrs. ]: ");
		fflush(stdin);
		scanf("%[^\n]",BookAuthorInput);
		getchar();
		
		length = strlen(BookAuthorInput);
		CheckMr = strstr(BookAuthorInput,Mr);
		CheckMrs = strstr(BookAuthorInput, Mrs);		
	}
	
	printf("Input ISBN[10-13][numeric]: ");
	scanf("%s",ISBNInput);
	getchar();
	
	length = strlen(ISBNInput);
	
	int RandomCharacterFound=0;
	for(int i=0;i<length;i++){
		if(isdigit(ISBNInput[i])==0){
			RandomCharacterFound=1;
			break;
		}
	}
	
	while(length < 10 ||  length > 13 || RandomCharacterFound==1){
		printf("Input ISBN[10-13][numeric]: ");
		scanf("%s",ISBNInput);
		getchar();
		
		length = strlen(ISBNInput);
		
		RandomCharacterFound=0;
		for(int i=0;i<length;i++){
			if(isdigit(ISBNInput[i])==0){
				RandomCharacterFound=1;
				break;
			}
		}	
	}
	
	printf("Input page number [>=16]: ");
	scanf("%d",&PageNumberInput);
	
	while(PageNumberInput<16){
		printf("Input page number [>=16]: ");
		scanf("%d",&PageNumberInput);
	}
	CurrentDataSize++;
	BookOrder++;
	int ASCII_Sum = SumOfASCII(BookTitleInput,BookAuthorInput,ISBNInput);
	
	int HashKey = HashKeyConversion(ASCII_Sum);
	InsertData(BookTitleInput,BookAuthorInput,ISBNInput,PageNumberInput,HashKey);
	printf("\nInsert success !\n");
}

void ViewBook(){
	
	if(CurrentDataSize==0){
		printf("There is no book(s)\n\n");
		return;
	}
	printf("|Book ID\t\t\t |Book Title\t\t\t |Book Author\t\t\t |ISBN\t\t\t |Page Number\n");
	printf("-----------------------------------------------------------------------------------------------------------------------------------------------------\n");
	for(int i=0;i<SIZE;i++){
		if(Chain[i]!=NULL){
			struct HashChain *Current;
			Current = Chain[i];
			while(Current!=NULL){
				printf("|%-20s\t\t |%-20s\t\t |%-20s\t\t |%-20s\t |%d\n",Current->BookID,Current->BookTitle,Current->BookAuthor,Current->ISBN,Current->PageNumber);
				Current = Current->next;
			}
		}
	}printf("\n");	
}

void RemoveBook(){
	char BookIDIn[31];
	if(CurrentDataSize==0){
		printf("There is no book(s)\n\n");
		return;
	}
	
	ViewBook();
	
	printf("Input book id to delete: ");
	fflush(stdin);
	scanf("%[^\n]",BookIDIn);
	getchar();
	
	int length=strlen(BookIDIn);
	int Sum=0;
	for(int i=0;BookIDIn[i]!='\0' && i<length;i++){
		Sum += BookIDIn[i];	
	}
	int BookFound=0;
	
	if(Chain[Sum]==NULL){
		printf("Book not found !\n");
		return;
	}else{
		if(strcmp(Chain[Sum]->BookID,BookIDIn)==0){
				printf("\n\nBook Id: %s\n",Chain[Sum]->BookID);
				printf("Book Title: %s\n",Chain[Sum]->BookTitle);
				printf("Book Author: %s\n",Chain[Sum]->BookAuthor);
				printf("Book ISBN: %s\n",Chain[Sum]->ISBN);
				printf("Page Number: %d\n",Chain[Sum]->PageNumber);
				printf("Are you sure[y/n]?: ");
				char Option;
				scanf("%c",&Option);
				getchar();
				while(Option!= 'y' && Option !='n'){
					printf("Are you sure[y/n]?: ");
					scanf("%c",&Option);
					getchar();
				}
				if(Option=='n'){
					printf("\n");
					return;
				}else{
					struct HashChain *deletenode = Chain[Sum];
					Chain[Sum] = Chain[Sum]->next;
					free(deletenode); 
				} 
		}else{
			struct HashChain *Current = Chain[Sum];
			while(Current!=NULL){
				if(strcmp(Current->next->BookID,BookIDIn)==0){
					printf("\n\nBook Id: %s\n",Current->BookID);
					printf("Book Title: %s\n",Current->BookTitle);
					printf("Book Author: %s\n",Current->BookAuthor);
					printf("Book ISBN: %s\n",Current->ISBN);
					printf("Page Number: %d\n",Current->PageNumber);
					printf("Are you sure[y/n]?: ");
					char Option;
					scanf("%c",&Option);
					getchar();
					while(Option!= 'y' && Option !='n'){
						printf("Are you sure[y/n]?: ");
						scanf("%c",&Option);
						getchar();
					}
					if(Option == 'n'){
						printf("\n");
						return;
					}
					else{
						struct HashChain *deletenode = Current->next;
						Current->next=Current->next->next;
						break;
					}
				}
				Current=Current->next;
			}
		}
	}
	CurrentDataSize--;
	printf("\n\nDelete success!\n");
}

int main(){
	
	int menu;
	do{
		printf("Bluejack Library\n");
		printf("=====================\n");
		printf("1. View Book\n");
		printf("2. Insert Book\n");
		printf("3. Remove Book\n");
		printf("4. Exit\n");
		printf(">> ");
		scanf("%d",&menu);
		
		switch(menu){
			case 1:
				system("cls");
				ViewBook();
				system("pause");
				system("cls");
				break;
			case 2:
				system("cls");
				InsertBook();
				system("pause");
				system("cls");
				break;
			case 3:
				system("cls");
				RemoveBook();
				system("pause");
				system("cls");
				break;
		}
	}while(menu!=4);
	
}
