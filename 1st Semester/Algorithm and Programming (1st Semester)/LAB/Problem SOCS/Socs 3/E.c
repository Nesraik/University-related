#include <stdio.h>
#include <string.h>
int main(){
	int a,b,c,d;
	char kata[101];
	scanf("%d",&a);
	for(b=1;b<=a;b++){
		scanf("%d\n",&c);
		scanf("%[^\n]",kata);
		printf("Case #%d: ",b);
		for(d=0;d<=c;d++){
		if(kata[d] >= 'a' && kata[d] <= 'z'){
		printf("%c",kata[d]);
		}
	}printf("\n");
	kata[0]='\0';
	}
	
	
	
	return 0;
}
