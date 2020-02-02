/******************************************************************************

                         Closed Hash Table Implementation

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
} Node;

Node H[MAX];
int maximum;

void init(int max)
{
    maximum = max;
    int i;
    for(i = 0; i < max; i++)
    {
        H[i].key = -1;
    }
}

void add (int key, int val)
{
    int index = (key % maximum);
    int count = 0;
    while((H[index].key != -1) && (H[index].key != key))
    {
        if(count >= maximum)
        {
            printf("Hash is full\n");
            return;
        }
        
        count++;
        index = (index + 1) % maximum;
    }
    
    H[index].key = key;
    H[index].val = val;
}

void delete(int key)
{
    int index = (key % maximum);
    int count = 0;
    while(H[index].key != -1)
    {
        if(count >= maximum)
        {
            printf("Key not found\n");
            return;
        }
        
        if (H[index].key == key)
        {
            printf("Deleted key %d\n", key);
            H[index].key = -1;
            return;
        }
        
        count++;
        index = (index + 1) % maximum;
    }
    
     printf("Key not found\n");
}

int search(int key)
{
    int index = (key % maximum);
    int count = 0;
    while(H[index].key != -1)
    {
        if(count >= maximum)
        {
            printf("Key not found\n");
            return 0xFFFF;
        }
        
        if (H[index].key == key)
        {
            return H[index].val;
        }
        
        count++;
        index = (index + 1) % maximum;
    }
    
     printf("Key not found\n");
     return 0xFFFF;
    
}

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