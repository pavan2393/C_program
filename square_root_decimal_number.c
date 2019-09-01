// Find square root of a decimal number

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    double num;
    printf("Enter number\n");
    scanf("%lf", &num);

    if(num == 1)
        return 1;

    double start = 1;
    double end = num;
    if(num < 1)
    {
        start = num;
        end = 1;
    }

    while(1)
    {
        double mid = (start + end) / 2;
        double square = mid * mid;
        double diff;
        if(square > num)
        {
            diff = square - num;  
        }
        else
        {
            diff = num - square;
        }

        if(diff <= 0.0001)
        {
            printf("Square root of %lf is %lf\n", num, mid);
            return 0;
        }
        
        if(square > num) 
            end = mid;
        else
            start = mid;
    }
    return 0;
}
