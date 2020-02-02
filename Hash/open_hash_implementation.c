/******************************************************************************

                         Open Hash Table Implementation

*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX (100)

typedef struct _Node
{
    int key;
    int val;
    struct _Node* next;
} Node;

Node* H[MAX];
int maximum;

void init(int max)
{
    maximum = max;
    int i;
    for(i = 0; i < max; i++)
    {
        H[i] = NULL;
    }
}

void add (int key, int val)
{
    Node* pNode = (Node*)(malloc(sizeof(Node)));
    pNode->next = NULL;
    pNode->key = key;
    pNode->val = val;
    
    int index = (key % maximum);
    Node* cur = H[index];

    Node* prev = NULL;
    while(cur)
    {
        if(cur->key == key)
        {
            cur->val = val;
            return;
        }
        
        prev = cur;
        cur = cur->next;
    }
    
    if(prev == NULL)
    {
        H[index] = pNode;
    }
    else
    {
        prev->next = pNode;
    }
}

void delete(int key)
{
    int index = (key % maximum);
    Node* cur = H[index];
    Node* prev = NULL;
    
    while(cur)
    {
        if(cur->key == key)
        {
            break;
        }
        
        prev = cur;
        cur = cur->next;
    }
    
    if(cur == NULL)
    {
        printf("Key not found\n");
        return;
    }
    
    printf("Deleted Key %d\n", key);
    if(prev == NULL)
    {
        H[index] = cur->next;
    }
    else
    {
        
        prev->next = cur->next;
    }
    
    free(cur);
}

int search(int key)
{   
    int index = (key % maximum);
    Node* cur = H[index];
    Node* prev = NULL;
    
    while(cur)
    {
        if(cur->key == key)
        {
            return cur->val;
        }
        
        prev = cur;
        cur = cur->next;
    }
    
    printf("Key not found\n");
    return 0xFFFF;
}

#define N (5)
int main()
{
    init(5);
    int ch;
    do
    {
        printf("Enter 1 - Add 2 - Delete  3 - Search\n");
        scanf("%d", &ch);
        
        switch(ch)
        {
            case 1:
            {
                int key, val;
                printf("Enter key and value\n");
                scanf("%d%d", &key, &val);
                add(key, val);
                break;
            }
            case 2:
            {
                int key;
                printf("Enter key to be deleted\n");
                scanf("%d", &key);
                delete(key);
                break;
            }
            case 3:
            {
                int key;
                printf("Enter key to be searched\n");
                scanf("%d", &key);
                int val = search(key);
                if(val != 0xFFFF)
                {
                    printf("Value for key %d is %d\n", key, val);
                }
                break;
            }
            default:
            {
                ch = 0;
                break;
            }
        }
        
    } while (ch != 0);
    return 0;
}