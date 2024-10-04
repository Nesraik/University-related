#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
struct node{
	char words[20];
	struct node *next;
};

struct node *Head,*Tail,*NewNode;

void CreateLinkedList(char inputstring[20]){
	
	NewNode = (struct node*) malloc(sizeof(struct node));
	strcpy(NewNode->words,inputstring);
	
	NewNode->next=NULL;
	Head=NewNode;
	Tail=Head;
	
}

void AppendLinkedList(char inputstring[20]){
	
	NewNode = (struct node*) malloc(sizeof(struct node));
	strcpy(NewNode->words,inputstring);
	
	NewNode->next=Head;
	Head = NewNode;
	
}

int main(){
	char wordcheck[200],optioninput[30],wordinput[200];
	struct node *key;
	int wordcount=0;
	do{
		int wordcount;
		system("cls");
		printf("Reverse Sentence\n");
		printf("================\n\n");
		printf("Input Sentence[minimum 5 words]: ");
		fflush(stdin);
		scanf("%[^\n]",wordcheck);
		getchar();
		strcpy(wordinput,wordcheck);
		
		char *word = strtok(wordcheck," ");
		while(word!=NULL){
			word = strtok(NULL, " ");
			wordcount++;
		}
		
		while(wordcount<5 && isalpha(wordcheck[0])!=1){
			wordcount=0;
			printf("Invalid Sentence\n");
			printf("Input Sentence: ");
			fflush(stdin);
			scanf("%[^\n]",wordcheck);
			getchar();
			strcpy(wordinput,wordcheck);
			
				word = strtok(wordcheck," ");
				while(word!=NULL){
				word = strtok(NULL, " ");
				wordcount++;
				}
		}
		
		word = strtok(wordinput," ");
		int i=0;
		while(word!=NULL){
			strrev(word);
			if(i==0){
				CreateLinkedList(word);
			}else{
				AppendLinkedList(word);
			}
			word = strtok(NULL, " ");
			i++;
		}
		
		key=Head;
		printf("\n\nThe Result is: ");
		while(key!=NULL){
			printf("%s ",key->words);
			key = key->next;
			}
		printf("\n\n\n");
		
		printf("Do you want to continue[yes|no] ?");
		scanf("%s",optioninput);
		
		while(strcmp(optioninput,"yes")!=0){
			system("cls");
			printf("Invalid Input\n");
			printf("Please input either [yes|no]!\n");
			printf("Do you want to continue[yes|no] ?");
			scanf("%s",optioninput);
			if(strcmp(optioninput,"no")==0){
				break;
			}
		}
	
	}while(strcmp(optioninput,"no")!=0);
}
