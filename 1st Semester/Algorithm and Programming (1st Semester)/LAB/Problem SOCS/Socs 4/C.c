#include <stdio.h>

int main(){
	int meat,veggies,egg;
	scanf("%d %d %d",&meat,&veggies,&egg);
	if(meat>veggies && meat>egg){
		if(veggies>egg){
		printf("Daging\n");
		printf("Sayur\n");
		printf("Telur\n");
	}else{
		printf("Daging\n");
		printf("Telur\n");
		printf("Sayur\n");
	}
}
	else if(veggies>meat&&veggies>egg){
		if(meat>egg){
		printf("Sayur\n");
		printf("Daging\n");
		printf("Telur\n");
	}else{
		printf("Sayur\n");
		printf("Telur\n");
		printf("Daging\n");
	}
}
	else if(egg>meat&&egg>veggies){
		if(meat>veggies){
		printf("Telur\n");
		printf("Daging\n");
		printf("Sayur\n");
	}else{
		printf("Telur\n");
		printf("Sayur\n");
		printf("Daging\n");
	}
}
	else{
	}
	return 0;
}
