//Program to create hash implementation in C
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define HASH_TABLE_SIZE  (5)

int hash[HASH_TABLE_SIZE];
int value[HASH_TABLE_SIZE];

uint32_t getKey(uint32_t val)
{
    return (val % HASH_TABLE_SIZE);
}

void hash_init()
{
    int i;
    for(i = 0; i < HASH_TABLE_SIZE; i++)
    {
        hash[i] = -1;
        value[i] = -1;
    }
}
void pushHash(uint32_t val, int data)
{
    uint32_t key = getKey(val);
    uint32_t i = key;
    while(hash[i] != -1)
    {
        i = (i+1) % HASH_TABLE_SIZE;
        if(i == key)
        {
              printf("Hash table full\n");
              return;
        }
    }

    hash[i] = data;
    value[i] = val;
}

int getHash(uint32_t val)
{
    uint32_t key = getKey(val);
    uint32_t i = key;
    while(hash[i] != -1)
    {
        
        if(value[i] == val)
        {
                return hash[i];
        }

        else if(((i + 1) % HASH_TABLE_SIZE) == key) 
        {
              printf("val not found in hash table\n");
              return -1;
        }
        i = (i + 1) % HASH_TABLE_SIZE;
        
    }

    printf("val not found in hash table\n");
    return -1;
}


void hashDelete(uint32_t val)
{
     uint32_t key = getKey(val);
     uint32_t i = key;
    while(hash[i] != -1)
    {
        
        if(value[i] == val)
        {
            printf("deleting hash[%d]: %d\n", value[i], hash[i]);
            hash[i] = -1;
            value[i] = -1;
            return;
        }

        else if(((i + 1) % HASH_TABLE_SIZE) == key) 
        {
              printf("val not found in hash table\n");
              return;
        }
        i = (i + 1) % HASH_TABLE_SIZE;
        
    }

    printf("val not found in hash table\n");
}
 


int main()
{
    hash_init();
    int ch;
    
do
{
    printf("Enter 1 for hashpush and 2 for hashget 3 to hash delete\n");
    scanf("%d", & ch);
    uint32_t val, key;
    printf("Enter val\n");
    scanf("%d", &val);
    switch(ch)
    {
    case 1:
    {
        int data;
        printf("Enter data\n");
        scanf("%d", &data);
        pushHash(val, data);
        break;
    }
    case 2:
    {
        int data = getHash(val);
        if(data != -1)
        {
            printf(" hash[%d]: %d\n", val, data);
        }
        break;
    }
    case 3:
    {
        hashDelete(val);
        break;
    }
    
    default:
        ch = 0;
        break;
    

}
}while(ch != 0);

}


