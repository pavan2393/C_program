//Calculate x ^ y
#include <stdio.h>

int cal(int org_num, int num, int expo, int count)
{
    if(expo == 0)
        return 1;
    if(expo == 1)
        return num;
    
    if((2 * count) >= expo)
    {
        return (num * cal(org_num, org_num, (expo-count), 1));
    }
    else
    {
        return (cal(org_num, (num*num), expo, (2*count)));
    }
}


int main()
{
    int num, expo;
    
    printf("enter num and exp\n");
    scanf("%d%d", &num, &expo);
    
    printf("result of %d^%d is %d\n", num, expo, cal(num, num, expo, 1));
    
}