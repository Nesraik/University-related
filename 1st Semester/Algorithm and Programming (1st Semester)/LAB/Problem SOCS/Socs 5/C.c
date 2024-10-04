#include <stdio.h>
#include <string.h>

int main(){
	int casenumber,caselimit,i,j,k,length,size;
	char word[1000],letter[1000][1000];
	scanf("%d",&caselimit);
	for(casenumber=1;casenumber<=caselimit;casenumber++){	
	scanf("%s",word);
	scanf("%d",&size);
	for( i = 0;i<size;i++){
		for( j = 0;j<2;j++){
			scanf("%c",&letter[i][j]);
			letter[i][j]=getchar();
	}
}
	length=strlen(word);
	for( i = 0;i<size;i++){
			for( k=0;k<length;k++){
				if(word[k]==letter[i][0]){
				word[k]=letter[i][1];
			}
		}
	}	
	printf("Case #%d: ",casenumber);
	for( i = 0;i<length;i++){
		printf("%c",word[i]);
	}printf("\n");
}
	return 0;
}
