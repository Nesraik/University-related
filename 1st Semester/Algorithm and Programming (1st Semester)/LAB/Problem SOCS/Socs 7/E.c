#include <stdio.h>

unsigned long long int sum(unsigned long long int n)
{
    return (n*(n+1)*(2*n+1)/6);
}
unsigned long long int binary(unsigned long long int lower,unsigned long long int upper,unsigned long long int number)
{
    unsigned long long int mid=(lower+upper)/2;
    while(lower<upper)
    {
        if(sum(mid)>number)
        {
            if(sum(mid-1)<number)
            {
                return mid;
            }
            else
            {
                return binary(lower,mid-1,number);
            }
        }
        else if(sum(mid)<number)
        {
            return binary(mid+1, upper, number);
        }
        else return mid;
    }
}
int main()
{
    int caselimit;
    scanf("%d",&caselimit);
    for(int casenumber=1;casenumber<=caselimit;casenumber++)
    {
        unsigned long long int number;
        scanf("%llu",&number);
        unsigned long long result;
        printf("Case #%d: %llu\n",casenumber,binary(1,2000000,number));
    }
    return 0;
}
