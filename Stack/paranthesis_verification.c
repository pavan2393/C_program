/******************************************************************************

                           Paranthesis Verification using Stack 

*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX (100)


bool verify(char* str)
{
    int i;
    int S[MAX];
    int sptr = -1;
    
    for(i = 0; str[i] != '\0'; i++)
    {
        if((str[i] == '(') || (str[i] == '[') || (str[i] == '{'))
        {
            S[++sptr] = str[i];
        }
        else
        {
            if(sptr < 0)
                return false;
            int c = S[sptr--];
            
            if(((c == '(') && (str[i] != ')')) || ((c == '[') && (str[i] != ']')) || ((c == '{') && (str[i] != '}')))
            {
                return false;
            }
        }
    }
    
    if(sptr >= 0)
    {
        return false;
    }
    
    return true;
}

int main()
{
    char str[MAX] = "((()))";
    if(verify(str) == true)
        printf("Paranthesis are valid\n");
    else
        printf("Paranthesis are invalid\n");
    return 0;
}