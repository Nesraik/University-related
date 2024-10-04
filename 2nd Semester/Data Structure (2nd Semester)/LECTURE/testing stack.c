#include <stdio.h>
#include <stdlib.h>

struct stack{
	int no;
	struct stack *next;
};
struct stack *top,*newstack;

void Addstack(int input){
	newstack = (struct stack*)malloc(sizeof(struct stack));
	newstack->no=input;
	
	if(top==NULL){
		newstack->next=NULL;
		top=newstack;
	}else{
		newstack->next=top;
		top=newstack;
	}
}
	
int Pop(){
	int number;
	struct stack *deletestack;
	if(top!=NULL){
		deletestack=top;
		number=top->no;
		top=top->next;
		free(deletestack);
	}
}	

int main(){
	
	Addstack(3);
	Addstack(2);
	Addstack(1);
	
	int number=Pop();
	
	printf("%d",number);
	
	
	
}
