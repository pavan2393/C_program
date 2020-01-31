/******************************************************************************

                          Queue Implementation Using Single Linked List

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

void findIntersection(Node* start1, Node* start2)
{
    if((start1 == NULL) || (start2 == NULL))
    {
        printf("Nodes do not intersect\n");
        return;
    }
    
    Node* cur = start1;
    Node* pNode = getNode();
    
    while(cur->next)
    {
        Node* next = cur->next;
        cur->next = pNode;
        cur = next;
    }
    
    cur->next = pNode;
    
    cur = start2;
    while(cur)
    {
        if(cur->next == pNode)
        {
            printf("Nodes intersect at %d\n", cur->data);
            return;
        }
        cur = cur->next;
    }
    
    printf("Nodes do not intersect\n");
}

int main()
{
    Node* start1 = NULL;
    Node* start2 = NULL;

    start1 = getNode();
    Node* cur = start1;
    cur->data = 1;
    
    Node* intersect;
    int i;
    for(i = 1; i < 10; i++)
    {
        cur->next = getNode();
        
        cur = cur->next;
        cur->data = i;
        
        if(i == 7)
        {
            intersect = cur;
        }
    }
    
    start2 = getNode();
    cur = start2;
    int j = 50;
    cur->data = j;
    
    for(i = 1; i < 4; i++)
    {
        cur->next = getNode();
        cur = cur->next;
        cur->data = i+j; 
    }
    
    cur->next = intersect;
    printf("Linked List 1 : \n");
    print(start1);

    printf("Linked List 2 : \n");
    print(start2);
    
    findIntersection(start1, start2);
    return 0;
}