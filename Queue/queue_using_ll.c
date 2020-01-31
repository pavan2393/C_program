/******************************************************************************

                          Queue Implementation Using Single Linked List

*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX (100)

typedef struct _Node
{
    int data;
    struct _Node* next;
} Node;

typedef struct _Queue
{
    Node* head;
    Node* tail;
    int count;
    int max;
} Queue;

void init (Queue* Q, int max)
{
    Q->head = NULL;
    Q->tail = NULL;
    Q->count = 0;
    Q->max = max;
}

Node* getNode()
{
    Node* pNode = (Node*)(malloc(sizeof(Node)));
    pNode->next = NULL;
    return pNode;
}

void push(Queue* Q, int data)
{
    Node* pNode = getNode();
    pNode->data = data;
    
    if(Q->count >= Q->max)
    {
        printf("Queue is full\n");
        return;
    }
    if(Q->head == NULL)
    {
        Q->head = pNode;
    }
    else
    {
        Q->tail->next = pNode;
    }
    
    Q->tail = pNode;
    Q->count++;
}

int pop(Queue* Q)
{
    if(Q->count <= 0)
    {
        printf("Queue is Empty\n");
        return 0xFFFF;
    }
    
    int data = Q->head->data;
    Node* temp = Q->head;
    
    Q->head = Q->head->next;
    
    if(Q->head == NULL)
    {
        Q->tail = NULL;
    }
    
    Q->count--;
    
    free(temp);
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