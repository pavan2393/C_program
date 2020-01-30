/******************************************************************************

                            Stack Implementation Using LL 

*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _Node
{
    int data;
    struct _Node* next;
} Node;

Node* sptr = NULL;

Node* getNode()
{
    Node* pNode = (Node*)(malloc(sizeof(Node)));
    pNode->next = NULL;
    return pNode;
}

void push(int data)
{
    Node* pNode = getNode();
    pNode->data = data;
    
    pNode->next = sptr;
    sptr = pNode;
}

int pop()
{
    if(sptr == NULL)
    {
        printf("Stack Empty\n");
        return 0xFFFF;
    }
    
    Node* pNode = sptr;
    sptr = sptr->next;
    
    int data = pNode->data;
    free(pNode);
    return data;
}


#define N (17)

int main()
{
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
                push(data);
                break;
            }
            
            case 2:
            {
                int data = pop();
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