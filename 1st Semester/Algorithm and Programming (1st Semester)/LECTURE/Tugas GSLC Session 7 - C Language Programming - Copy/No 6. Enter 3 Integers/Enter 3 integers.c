#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int start;
	int step_by;
	int stop;
	printf("Enter three integers: ");
	scanf("%d %d %d", &start,&step_by,&stop);
	getchar();
	for(start; start<=stop; start= start + step_by){
		printf("%d ",start);
	}getchar();
	return 0;
}
