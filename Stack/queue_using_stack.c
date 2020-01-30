/******************************************************************************

                           Queue Implementation Uisng Stack 

*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX (100)
typedef struct _Stack
{
    int A[MAX];
    int sptr;
} Stack;

typedef struct _Queue
{
    Stack S1;
    Stack S2;
    int count;
    int max;
} Queue;


void init(Queue* Q, int max)
{
    Q->max = max;
    Q->S1.sptr = -1;
    Q->S2.sptr = -1;
    Q->count = 0;
}

void push(Queue* Q, int data)
{
    if(Q->count >= Q->max)
    {
        printf("Queue Full\n");
        return;
    }
    
    Q->S1.A[++(Q->S1.sptr)] = data;
    
    Q->count++;
}

int pop(Queue* Q)
{
    if(Q->count <= 0)
    {
        printf("Queue is Empty\n");
        return 0xFFFF;
    }
    
    if(Q->S2.sptr == -1)
    {
        while(Q->S1.sptr >= 0)
        {
            Q->S2.A[++(Q->S2.sptr)] = Q->S1.A[(Q->S1.sptr)--];
        }
    }
    
    int data = Q->S2.A[Q->S2.sptr];
    Q->S2.sptr--;
    Q->count--;
    
    return data;
}


int main()
{
    int ch;
    Queue Q;
    init(&Q, 5);
    
    do
    {
        printf("1 - Push  2 - Pop  3 - Exit\n");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
            {
                int data;
                printf("Enter data\n");
                scanf("%d", &data);
                push(&Q, data);
                break;
            }
            
            case 2:
            {
                int data = pop(&Q);
                if(data != 0xFFFF)
                {
                    printf("Popped data is %d\n", data);
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