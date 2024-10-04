#include <stdio.h>
#include <string.h>
struct Student
{
	char name[15];
	int num;	
} student[1001];
	
void merge(int left, int mid, int right)
{
	int i,j,k;
	int x=mid-left+1;
	int y=right-mid;
	
	struct Student L[x+1];
	struct Student R[y+1];
	
	for(i=0; i<x; i++)
	{
		L[i]=student[left+i];
	}
	for(j=0; j<y; j++)
	{
		R[j]=student[mid+j+1];
	}
	i=0;
	j=0;
	k=left;
	while(i<x && j<y)
	{
		if(L[i].num>R[j].num)
		{
			student[k]=L[i];
			i++;
		}
		else if(L[i].num==R[j].num)
		{
		    if(strcmp(L[i].name,R[j].name)<0)
			{
		        student[k]=L[i];
		        i++;
		    }
		    else
			{
		        student[k]=R[j];
		        j++;
		    }
		}
		else
		{
			student[k]=R[j];
			j++;
		}
		k++;
	}
	while (i<x)
	{
		student[k]=L[i];
		i++;
		k++;
	}
	while (j<y)
	{
		student[k]=R[j];
		j++;
		k++;
	}
}
	
void mergesort(int left, int right)
{
	int mid;
	if(left<right)
	{
		mid = (left+right)/2;
		mergesort(left,mid);
		mergesort(mid+1,right);
		merge(left,mid,right);
	}	
}

int main()
{
	int caselimit, size,rank;
	char names[15];
	scanf("%d", &caselimit); 
	getchar();
	for(int casenumber=1 ; casenumber <= caselimit;casenumber++)
	{
		scanf("%d", &size); 
		getchar();
		
		for(int i=0; i<size; i++)
		{
			scanf("%[^#]#%d", &student[i].name, &student[i].num); 
            getchar();
		}
		scanf("%s", names);
		getchar();
		mergesort(0,size-1);
		for(int i=0; i<size; i++)
		{
			if(strcmp(student[i].name, names)==0)
			{
				rank=i+1;
				break;	
			}
		}
		printf("Case #%d: %d\n", casenumber, rank);
	}
    getchar();
	return 0;
}
