#include <stdio.h>

int main(){
	char temp[100];
	scanf("%s",temp);// The output of this code if the input is "Good Morning" is "Good"
	gets(temp);// The output of this code if the input is "Good Morning" is "Good Morning"
	return 0;
// scanf("%s",temp) and gets(temp) has similar function except for one thing.
// scanf("%s",temp) get a string input that has no whitespace in between while gets(temp) get a line of string input including the whitespace.
// hence scanf("%s",temp) only gets "Good" instead of "Good Morning" because there is whitespace in between	
}
