#include <stdio.h >

struct automobile{
	int year;
	char model[8];
	int engine_power;
	float weight;
};

int main(){
	struct automobile automobileType[5];
	for(int i=0;i<5;i++){
		printf("Automobile #%d\n",i+1);
		printf("Year: ");
		scanf("%d",&automobileType[i].year);
		getchar();
		printf("\nModel: ");
		scanf("%[^\n]",automobileType[i].model);
		getchar();
		printf("\nEngine Power: ");
		scanf("%d",&automobileType[i].engine_power);
		getchar();
		printf("\nWeight: ");
		scanf("%f",&automobileType[i].weight);
		getchar();
		printf("===========================\n");
	}
	for(int i=0;i<5;i++){
		printf("\nAutomobile %d\n",i+1);
		printf("Year: %d\n",automobileType[i].year);
		printf("Model: %s\n",automobileType[i].model);
		printf("Engine Power: %d\n",automobileType[i].engine_power);
		printf("Weight: %f",automobileType[i].weight);
		printf("===========================\n");
	}
	
	
	return 0;
}

