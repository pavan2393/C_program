/******************************************************************************

                            Deleting Substring

*******************************************************************************/

#include <stdio.h>
#include <string.h>

void deleteString(char* str, int pos, int length)
{
    if((pos < 0) || (pos >= strlen(str)) || ((pos + length) > strlen(str)))
    {
        printf("Invalid position\n");
        return;
    }
    
    
    int len = strlen(str) - length + 1;
    char newStr[len];
    int k = 0;
    int j;
    int i = 0;
    
    while(k != pos)
    {
        newStr[k++] = str[i++];
    }
    
    for(j = (i + length); ((str[j] != '\0') && (k < len)); j++)
    {
        newStr[k++] = str[j];
    }
    
    newStr[k] = '\0';
    
    printf("Updated string is: %s ", newStr);
    
}


#define N (14)

int main()
{
    char str[N] = "My Name Pavan";
    
    deleteString(str, 3, 5);
    return 0;
}