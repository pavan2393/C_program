/******************************************************************************

                         Add Delete Insert Invert Linked List

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

Node* add(Node* start, int data)
{
    Node* pNode = getNode();
    pNode->data = data;
    if(start == NULL)
    {
        start = pNode;
    }
    else
    {
        Node* cur = start;
        while(cur->next)
        {
            cur = cur->next;
        }
        
        cur->next = pNode;
    }
    
    return start;
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

Node* delete(Node* start, int pos)
{
    Node* cur = start;
    Node* prev = NULL;
    
    int curPos = 1;
    
    if(start == NULL)
    {
        printf("No Node in List\n");
        return start;
    }
    if(pos < 1)
    {
        printf("Invalid position\n");
        return start;
    }
    
    
    while((cur != NULL) && (curPos < pos))
    {
        printf("Entered\n");
        prev = cur;
        cur = cur->next;
        curPos++;
    }
    
    if(cur == NULL)
    {
        printf("Invalid position\n");
        return start;
    }
    
    if(prev == NULL)
    {
        start = cur->next;
    }
    else
    {
        prev->next = cur->next;
    }
    
    free(cur);
    
    return start;
}

Node* insert(Node* start, int data, int pos)
{
    Node* cur = start;
    Node* prev = NULL;
    Node* pNode = getNode();
    pNode->data = data;
    
    int curPos = 1;
    
    if(pos < 1)
    {
        printf("Invalid position\n");
        return start;
    }
    
    
    while((cur != NULL) && (curPos < pos))
    {
        printf("Entered\n");
        prev = cur;
        cur = cur->next;
        curPos++;
    }
    
    if(curPos < pos)
    {
        printf("Invalid position\n");
        return start;
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

Node* invert(Node* start)
{
    Node* cur = start;
    Node* prev = NULL;
    
    while(cur)
    {
        Node* next = cur->next;
        cur->next = prev;
        prev = cur;
        
        cur = next;
    }
    
    return prev;
}

int main()
{
    Node* start = NULL;

    int ch;
    
    
    do
    {
        printf("1 - Insert  2 - Delete  3 - Print  4 - Invert 5 - Print\n");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
            {
                int data;
                printf("Enter data\n");
                scanf("%d", &data);
                start = add(start, data);
                break;
            }
            
            case 2:
            {
                int pos;
                printf("Enter the position\n");
                scanf("%d", &pos);
                start = delete(start, pos);
                break;
            }
            case 3:
            {
                int pos, data;
                printf("Enter the data and position\n");
                scanf("%d%d", &data, &pos);
                start = insert(start, data, pos);
                break;
            }
            case 4:
            {
                start = invert(start);
                break;
            }
            case 5:
            {
                print(start);
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