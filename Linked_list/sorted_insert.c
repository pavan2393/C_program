/******************************************************************************

                          Sorted Insert in Linked List

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

Node* insertSorted(Node* start, int data)
{
    Node* cur = start;
    Node* prev = NULL;
    
    Node* pNode = getNode();
    pNode->data = data;
    while(cur && (data > cur->data))
    {
        prev = cur;
        cur = cur->next;
    }
    
    if(prev == NULL)
    {
        start = pNode;
    }
    else
    {
        prev->next = pNode;
    }
    
    pNode->next = cur;
    
    return start;
}

int main()
{
    Node* start = NULL;

    start = getNode();
    Node* cur = start;
    cur->data = 1;
    
    int i;
    for(i = 2; i < 10; i++)
    {
        cur->next = getNode();
        
        cur = cur->next;
        cur->data = i;
    }
    
    printf("Linked List: \n");
    print(start);

    int data;
    printf("Enter the data to be inserted\n");
    scanf("%d", &data);
    
    start = insertSorted(start, data);
    
    printf("Linked List after addition : \n");
    print(start);
    
    return 0;
}