/******************************************************************************

                          Queue Implementation Using Single Linked List

*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX (100)

typedef struct _Queue
{
    int A[MAX];
    int head;
    int tail;
} Queue;

typedef struct _Stack
{
    Queue Q1;
    Queue Q2;
    int count;
    int max;
} Stack;

void init (Stack* S, int max)
{
    S->Q1.tail = 0;
    S->Q1.head = 0;
    S->Q2.tail = 0;
    S->Q2.head = 0;
    S->count = 0;
    S->max = max;
}


void push(Stack* S, int data)
{
    
    if(S->count >= S->max)
    {
        printf("Stack is full\n");
        return;
    }
    
    while(S->Q1.head < S->Q1.tail)
    {
        S->Q2.A[(S->Q2.tail)++] = S->Q1.A[(S->Q1.head)++];
    }
    
    S->Q1.A[(S->Q1.tail)++] = data;
    
    while(S->Q2.head < S->Q2.tail)
    {
        S->Q1.A[(S->Q1.tail)++] = S->Q2.A[(S->Q2.head)++];
    }
    
    S->count++;
}

int pop(Stack* S)
{
    if(S->count <= 0)
    {
        printf("Queue is Empty\n");
        return 0xFFFF;
    }
    
    int data = S->Q1.A[(S->Q1.head)++];
    S->count--;
    return data;
}


int main()
{
    Stack S;
    init(&S, 5);
    int ch;
    
    
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
            default:
            {
                ch = 0;
                break;
            }
        }
        
    } while(ch!= 0);
    
    return 0;
}