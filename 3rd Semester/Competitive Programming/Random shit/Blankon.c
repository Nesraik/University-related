#include <stdio.h>

int main(){
	int size;
	int num1,num2;
	float div,div2;
	int num3,num4;
	scanf("%d %d %d",&size,&num1,&num2);
	div = num1/num2;
	int count=0;
	int count2=2;
	int count3=0;
	int k=0;
	float div3[size];
	for(int i=0;i<size;i++){
		scanf("%d %d",&num3,&num4);
		div2 = num3/num4;

		if(i==0){
			div3[k]=div2;
			k++;
			count++;
		}else{
			count++;
			for(int j=0;j<size;j++){
				if(div3[j]==div2){
					count--;
					count3++;
					break;
				}
			}
			if(count3==0){
				div3[k]=div2;
				k++;
			}
		}
		/*
		if(count2>0 && div2==div && ((num3 < num1 && num4< num2) || (num3>num1 && num4>num2))){
			count2--;
			count++;
			continue;
		}
		*/
	}
	
	printf("%d\n",count);
	
}
