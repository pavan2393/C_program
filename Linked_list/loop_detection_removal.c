/******************************************************************************

                         Loop Detection ad Removal

*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct _Node
{
    int data;
    struct _Node* next;
} Node;


Node* getNode()
{
    Node* pNode = (Node*)(malloc(sizeof(Node)));
    pNode->next = NULL;
    return pNode;
}

void print(Node* start, Node* loop)
{
    Node* cur = start;
    int loopSeen = 0;
    
    while(cur)
    {
        if(cur == loop)
        {
            if(loopSeen == 1)
            {
                printf("loop(%d)", cur->data);
                break;
            }
            else
            {
                loopSeen = 1;
            }
        }
        
        printf("%d", cur->data);
        if(cur->next)
            printf("->");
        
        cur = cur->next;
    }
    
    printf("\n");
}

bool detect(Node* start)
{
    Node* s = start;
    Node* f = start;
    
    while(f && f->next)
    {
        s = s->next;
        f = f->next->next;
        
        if(s == f)
        {
            return true;
        }
    }
    
    return false;
}

Node* breakLoop(Node* start)
{
    Node* s = start;
    Node* f = start;
    
    while(f && f->next)
    {
        s = s->next;
        f = f->next->next;
        
        if(s == f)
        {
            break;
        }
    }
    
    Node* ptr1 = start;
    Node* ptr2 = s;
    
    while(ptr2->next != ptr1->next)
    {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    
    ptr2->next = NULL;
    
    return start;
}

int main()
{
    Node* start = NULL;

    start = getNode();
    Node* cur = start;
    cur->data = 0;
    Node* loop;
    
    int i;
    for(i = 0; i < 10; i++)
    {
        cur->next = getNode();
        
        cur = cur->next;
        cur->data = i+1;
        
        if(i == 4)
        {
            loop = cur;
        }
    }
    
    cur->next = loop;
    printf("Linked List : \n");
    print(start, loop);
    
    if(detect(start))
    {
        printf("Loop Exists\n");
        
        printf("Breaking loop\n");
        start = breakLoop(start);
        
        printf("List after loop breaking:\n");
        print(start, loop);
    }
    else
    {
        printf("Loop does not exist\n");
    }
    return 0;
}