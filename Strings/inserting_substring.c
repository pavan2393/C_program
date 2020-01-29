/******************************************************************************

                            Inserting Substring

*******************************************************************************/

#include <stdio.h>
#include <string.h>

void insertString(char* str, char* subStr, int pos)
{
    if((pos < 0) || (pos >= strlen(str)))
    {
        printf("Invalid position\n");
        return;
    }
    
    int len = strlen(str) + strlen(subStr) + 1;
    char newStr[len];
    
    int i = 0;
    int j = 0;
    int k = 0;
    
    while(str[i] != '\0')
    {
        if(k != pos)
        {
            newStr[k++] = str[i++];
        }
        else
        {
            for(j = 0; subStr[j] != '\0'; j++)
            {
                newStr[k++] = subStr[j];
            }
        }

    }
    
    newStr[k] = '\0';
    
    printf("Updated string is: %s ", newStr);
  
}


#define N (14)
#define M (4)
int main()
{
    char str[N] = "My Name Pavan";
    char sub[M] = "is ";
    
    insertString(str, sub, 13);
    return 0;
}