#include <ctype.h>
#include <stdio.h>
int main(){ 
	isalpha(int c);
	//a syntax to check whether the given input(character) is an alphabet or not. It will return a non-zero values if its alphabet
	// and will return 0 if its not.	
	isupper(int c);
	//a syntax to check whether the given input(character) is in uppercase or not
	islower(int c);
	//a syntax to check whether the given input(character) is in lowercase or not.
	isdigit(int c);
	//a syntax to check whether the given input(character) is a digit or not. It will return a non-zero values if its digit (0 - 9)
	// and will return 0 if its not.
	isalnum(int c);
	// a combination of isalpha and isdigit functions which is to check whether the given input(character) is a digit or alphabet. If it is
	// it will return non-zero value and will return 0 if its anything else beside digit or alphabet.
	isspace(int c);
	// a syntax to check whether the given input(chracter) is a white-space character or not.
	toupper(int c);
	// a syntax to convert given input(character) that is lowercase to uppercase.
	tolower(int c);
	// a syntax to convert given input(character) that is uppercase to lowercase.
	return 0;
}
