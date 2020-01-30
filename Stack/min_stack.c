/******************************************************************************

                           Min Stack Implementation 

*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX (100)
typedef struct _Stack
{
    int A[MAX];
    int B[MAX];
    int sptr;
    int max;
    int count;
} Stack;

void init(Stack* S, int max)
{
    S->max = max;
    S->sptr = -1;
    S->count = 0;
}

void push(Stack* S, int data)
{
    if(S->count >= S->max)
    {
        printf("Stack Full\n");
        return;
    }
    
    S->A[S->sptr+1] = data;
    if(S->sptr == -1)
    {
        S->B[(S->sptr)+1] = data;
    }
    else
    {
        S->B[(S->sptr)+1] = (data < (S->B[S->sptr])) ? data : (S->B[S->sptr]);
    }
    
    S->sptr++;
    S->count++;
}

int pop(Stack* S)
{
    if(S->count <= 0)
    {
        printf("Stack is Empty\n");
        return 0xFFFF;
    }
    
    int data = S->A[S->sptr];
    S->sptr--;
    S->count--;
    
    return data;
}

int min(Stack* S)
{
    if(S->count <= 0)
    {
        printf("Stack is Empty\n");
        return 0xFFFF;
    }
    return S->B[S->sptr];
}


int main()
{
    int ch;
    Stack S;
    init(&S, 5);
    
    do
    {
        printf("1 - Push  2 - Pop  3 - Min  4 - Exit\n");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
            {
                int data;
                printf("Enter data\n");
                scanf("%d", &data);
                push(&S, data);
                break;
            }
            
            case 2:
            {
                int data = pop(&S);
                if(data != 0xFFFF)
                {
                    printf("Popped data is %d\n", data);
                }
                break;
            }
            case 3:
            {
                int data = min(&S);
                if(data != 0xFFFF)
                {
                    printf("Min element in Stack is %d\n", data);
                }
                break;
            }
            default:
            {
                ch = 0;
                break;
            }
        }
        
    } while(ch!= 0);
    
    return 0;
}