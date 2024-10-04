#include <stdio.h>
#include <string.h>
int main(){
	char string[300];
	int stringlength,length;
	gets(string);
	length=strlen(string);
	while (length<5 || length >30){//To validate length of string should no more than 30 or no less than 5
		printf("Enter another string (should no less than 5 letter or no more than 30 letter): \n");
		gets(string);
		for(int i=0;string[i]!='\0';i++){
		length++;
		}
		length=strlen(string);
	}
	printf("End of the loop");
	
	
	
}
