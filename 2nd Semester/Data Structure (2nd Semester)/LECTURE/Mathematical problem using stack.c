#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct stack{
	char operators;
	struct stack *next;
};

struct stacknum{
	double number;
	struct stacknum *nextnum;
};
struct stack *top,*newstack;
struct stacknum *topnum,*newstacknum;

void Push(char operatorinput){
	newstack=(struct stack*)malloc(sizeof(struct stack));
	newstack->operators=operatorinput;
	
	if(top==NULL){
		newstack->next=NULL;
		top=newstack;
	}else{
		newstack->next=top;
		top=newstack;
	}
}

void PushNum(double numinput){
	newstacknum = (struct stacknum*)malloc(sizeof(struct stacknum));
	newstacknum->number=numinput;
	
	if(topnum==NULL){
		newstacknum->nextnum=NULL;
		topnum=newstacknum;
	}else{
		newstacknum->nextnum=topnum;
		topnum=newstacknum;
	}
}

void Popnum(){
	struct stacknum *deletestack;
	
	deletestack=topnum;
	topnum=topnum->nextnum;
	free(deletestack);
	
}

void Pop(){
	struct stack *deletestack;
	
	deletestack=top;
	top=top->next;
	free(deletestack);
	
}

int OperatorCheck(char Operatorinput){
	
	if(Operatorinput=='+'||Operatorinput=='-'||Operatorinput=='*'||Operatorinput=='/'){
		return 1;
	}return 0;
}

void PushAnswer(char *Postfix,int limit){
	struct stacknum *current,*current2;
	double result=0,num1=0,num2=0;
	int j=0;
	int convertnum;
	char convert[2];
	
	for(int i =0;i<limit;i++){
		if(isdigit(Postfix[i])){
			memset(convert, '\0', 2);
            j = 0;
            while (isdigit(Postfix[i]))
            {
                convert[j] = Postfix[i];
                i++;
                j++;
            }
            PushNum((double)atoi(convert));
		}else if(OperatorCheck(Postfix[i])){
			num1 = topnum->number;
			num2 = topnum->nextnum->number;
			switch(Postfix[i]){
				case '+':
					result=num2+num1;
					Popnum();
					Popnum();
					PushNum(result);
					break;
				case '-':
					result=num2-num1;
					Popnum();
					Popnum();
					PushNum(result);
					break;
				case '/':
					result= num2/num1;
					Popnum();
					Popnum();
					PushNum(result);
					break;
				case '*':
					result=num2*num1;
					Popnum();
					Popnum();
					PushNum(result);
					break;
				default:
					break;
				}
			}
		}
	}
	
int Priority(char OperatorCheck){
	if(OperatorCheck=='+'||OperatorCheck=='-'){
		return 1;
	}else if(OperatorCheck=='*'||OperatorCheck=='/'){
		return 2;
	}else if(OperatorCheck=='('|| OperatorCheck==')'){
		return 0;
	}else{
		return -1;
	}
	
}



int main(){
	struct stack *currentstack;
	struct stacknum *currentnum;
	char equation[100];
	char Postfix[30];
	int checklinkedlist;
	int checkarray;
	printf("Expected Input: ");
	scanf("%[^\n]",equation);
	
	int length = strlen(equation);
	int j=0;
	for(int i=0;i<length;i++){
		if(equation[i]!=' '&&equation[i]!='\0'){
			if(isdigit(equation[i])==1){
				while (isdigit(equation[i]))
	            {
	                Postfix[j] = equation[i];
	                i++;
	                j++;
	            }
	            Postfix[j] = ' ';
	            j++;
	            i--;
			}else if(OperatorCheck(equation[i])){
				while(top!=NULL && Priority(equation[i])<=Priority(top->operators)){
					Postfix[j]=top->operators;
					j++;
					Pop();
				}
				Push(equation[i]);
			}else if(equation[i]=='('){
				Push(equation[i]);
			}else if(equation[i]==')'){
				while(top->operators!='('){
					Postfix[j]=top->operators;
					j++;
					Pop();
				}
				Pop();
			}
		}	
	}
	
	while(top!=NULL){
		Postfix[j]=top->operators;
		j++;
		Pop();	
	}
	
	PushAnswer(Postfix,j);
	printf("Expected Output: %lf",topnum->number);
	
}
