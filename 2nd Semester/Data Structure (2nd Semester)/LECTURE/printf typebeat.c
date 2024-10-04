#include <stdio.h>
#include <stdlib.h>

struct node{
	int no;
	struct node *left;
	struct node *right;
};



int main(){
	printf("%p\n",NULL);
	printf("%p",0);
}
