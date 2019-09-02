//Memcpy for 32bit aligned
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int cal(int num)
{
    if((num & (num+1)) == 0)
    {
        printf("Cannot calculate\n");
        return -1;
    }
    
    //calculate rightmost set bit(rm);
    int rm1 = num & ((~num) + 1);
    if((rm1 & 1) == 0)
    {
        num = num & (~rm1);
        num |= (rm1 >> 1);
        return num;
    }
    
    // find the right most string (rms)
    int rms = num & (~(num + rm1));
    int num_wo_rms = num & (~rms);
    
    // find the next right most set bit
    int rm2 = (num_wo_rms) & ((~num_wo_rms) + 1);
    num = num & (~rm2);
    
    // right shift the next rm bit by 1 in num
    rm2 >>= 1;
    num |= rm2;
    
    // clear the rms
    num &= (~rms);
    
    //append the rms after the next rm bit
    while(rms > 0)
    {
        num |= (rm2 >> 1);
        rm2 >>= 1;
        rms = rms & (rms - 1);
    }
    
    return num;
}


int main()
{
    int num;
    printf("Enter num\n");
    scanf("%d", &num);
    
    int res = cal(num);
    
    if(res != 1)
    {
        printf("lesser number with same number of set bits is %d\n", res);
    }
}


