#include <stdio.h>

struct Address{
	char street[40];
	int number;
	char city[100];
	char province[100];
};
struct DOB{
	int date, month ,year;
};
typedef struct Students{
	int studentnumber;
	char Name[300];
	struct Address address;
	char BirthPlace[200];
	struct DOB dob;
}Student;
int main(){	
	return 0;
}
