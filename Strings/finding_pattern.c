/******************************************************************************

                            Finding Pattern

*******************************************************************************/

#include <stdio.h>
#include <string.h>

int findPattern(char* str, char* pattern)
{
    int i = 0;
    int j = 0;
    int len = strlen(str) - strlen(pattern);

    while(i <= len)
    {
        for(j = 0; pattern[j] != '\0'; j++)
        {
            if(str[i+j] != pattern[j])
                break;
        }
        
        if(pattern[j] == '\0')
            return i;
        i++;
    }
    
    return -1;
}


#define N (17)

int main()
{
    char str[N] = "My Name is Pavan";
    char pattern[7] = "is";
    
    int index = findPattern(str, pattern);
    
    if(index == -1)
    {
        printf("Pattern not found\n");
    }
    else
    {
        printf("Pattren found at index %d\n", index);
    }
    
    return 0;
}