#include <stdio.h>
int main() {
	int a,b,c,count_limit,d,e,f,g,h;
	printf("Enter a Number: ");
	scanf("%d",&a);
	getchar();
	if(a<=7){
		for(b=1;b<=a;b++){
				if(b==1){printf("1. Monday\n");
				}
				if(b==2){printf("2. Tuesday\n");
				}
				if(b==3){printf("3. Wednesday\n");
				}
				if(b==4){printf("4. Thursday\n");
				}
				if(b==5){printf("5. Friday\n");
				}
				if(b==6){printf("6. Saturday\n");
				}
				if(b==7){printf("7. Sunday\n");
				}
		}
	}
	else{
		if(a%7==0){
			count_limit=a/7;
			for(c=1;c<=count_limit;c++){
				for(d=1;d<=7;d++){
					if(d==1){printf("1. Monday\n");
					}
					if(d==2){printf("2. Tuesday\n");
					}
					if(d==3){printf("3. Wednesday\n");
					}
					if(d==4){printf("4. Thursday\n");
					}
					if(d==5){printf("5. Friday\n");
					}
					if(d==6){printf("6. Saturday\n");
					}
					if(d==7){printf("7. Sunday\n");
					}
				}
			}
		}
		else{
			e = a%7;
			count_limit = a/7;
			for(f=1;f<=count_limit;f++){
				for(g=1;g<=7;g++){
					if(g==1){printf("1. Monday\n");
					}
					if(g==2){printf("2. Tuesday\n");
					}
					if(g==3){printf("3. Wednesday\n");
					}
					if(g==4){printf("4. Thursday\n");
					}
					if(g==5){printf("5. Friday\n");
					}
					if(g==6){printf("6. Saturday\n");
					}
					if(g==7){printf("7. Sunday\n");
					}
				}
			}
			for(h=1;h<=e;h++){
					if(h==1){printf("1. Monday\n");
					}
					if(h==2){printf("2. Tuesday\n");
					}
					if(h==3){printf("3. Wednesday\n");
					}
					if(h==4){printf("4. Thursday\n");
					}
					if(h==5){printf("5. Friday\n");
					}
					if(h==6){printf("6. Saturday\n");
					}
					if(h==7){printf("7. Sunday\n");
					}
			}
		}
	}
	getchar();
	return 0;
}
