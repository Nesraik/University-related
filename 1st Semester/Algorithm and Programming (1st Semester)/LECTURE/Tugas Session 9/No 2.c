#include <stdio.h>
#include <string.h>

int main(){

	char kata[100];
	printf("This program will rotate the characters of sentence/word.\n");
	printf("Enter a word/sentence: \n");
	scanf("%[^\n]",kata);
	getchar();
	printf("\n%s",strrev(kata));
	getchar();	
	return 0;
}
