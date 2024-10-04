#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(){
	int length,forward,backward;
	char word[300];
	printf("This program will check whether a word is palindrome or not.\n");
	printf("Enter a word: ");
	scanf("%s",word);
	length=strlen(word);
	for(int i=0;i<length;i++){
		word[i]=tolower(word[i]);
	}
	backward=length-1;
	forward=0;
	while(backward>forward){
		if(word[forward++]!=word[backward--]){
			word[0]=toupper(word[0]);
			printf("%s is not a palindrome",word);
			return 0;
		}
	}
	word[0]=toupper(word[0]);
	printf("%s is a palindrome",word);
	return 0;
}
