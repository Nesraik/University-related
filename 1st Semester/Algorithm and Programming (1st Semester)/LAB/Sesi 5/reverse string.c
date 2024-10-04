#include <stdio.h>

int main(){
	char word[300];
	int wordlength = 0,order,orderlimit;
	printf("This program will reverse inputted word/sentence.\n");
	scanf("%[^\n]",word);
	for(int i=0;word[i]!='\0';i++){
		wordlength++;
	}
	for(order=wordlength-1;order>=0;order--){
		printf("%c",word[order]);
	}
	
	
	
	
	return 0;
}
