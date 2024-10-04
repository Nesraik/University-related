#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
	int length,i;
	char word[300];
	printf("This program will convert the first letter of every word to be uppercase.\n");
	printf("Enter a phrase: ");
	gets(word);
	for(int i=0;word[i]!='\0';i++){
		length++;
	}
	for(int i=0;word[i]!='\0';i++){
		if(i==0){
			printf("%c",toupper(word[i]));
			continue;
		}
		if(word[i]==' '){
			i++;
			printf(" %c",toupper(word[i]));
			continue;
		}
		printf("%c",word[i]);
	}
	return 0;
}
