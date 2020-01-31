/******************************************************************************

                         Merge Sorted Linked List

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

void print(Node* start)
{
    Node* cur = start;
    
    while(cur)
    {
        printf("%d", cur->data);
        if(cur->next)
            printf("->");
        
        cur = cur->next;
    }
    
    printf("\n");
}


Node* mergeList(Node* start1, Node* start2)
{
    Node* i = start1;
    Node* j = start2;
    Node* k = NULL;
    Node* start = NULL;
    Node* item;
    
    while(i && j)
    {
        if(i->data < j->data)
        {
            item = i;
            i = i->next;
        }
        else
        {
            item = j;
            j = j->next;
        }
        
        if(k == NULL)
        {
            start = item;
        }
        else
        {
            k->next = item;
        }
        
        k = item;
    }
    
    if(i)
    {
        if(k == NULL)
        {
            start = i;
        }
        else
        {
            k->next = i;
        }
    }
    
    if(j)
    {
        if(k == NULL)
        {
            start = j;
        }
        else
        {
            k->next = j;
        }
    }
    
    return start;
}

int main()
{
    Node* start1 = NULL;
    Node* start2 = NULL;
    start1 = getNode();
    Node* cur = start1;
    cur->data = 1;
    
    int i;
    int k = 3;
    for(i = 2; i < 10; i++)
    {
        cur->next = getNode();
        
        cur = cur->next;
        cur->data = i+k;
    }
    
    k = 2;
    start2 = getNode();
    cur = start2;
    cur->data = 2;
    
    for(i = 0; i < 4; i++)
    {
        cur->next = getNode();
        
        cur = cur->next;
        cur->data = i+k;
    }
    
    
    
    printf("Linked List 1: \n");
    print(start1);
    
    printf("Linked List 2: \n");
    print(start2);

    Node* start = mergeList(start1, start2);
    printf("Sorted list is :\n");
    print(start);
    
    return 0;
}