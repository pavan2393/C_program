// Program to implement malloc in c
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#define SIZE (192)
typedef struct _header_t
{
    uint32_t bytes;
    uint32_t isalloc;
    struct _header_t* next;
    struct _header_t* prev;
} header_t;

uint8_t buffer[SIZE];
header_t* start = NULL;

void malloc_init()
{
    start = (header_t*)buffer;
    start->bytes = SIZE - sizeof(header_t);
    start->isalloc = 0;
    start->next = NULL;
    start->prev = NULL;
}

uint8_t* getHeader(uint8_t* pData)
{
    return (pData - sizeof(header_t));
}

uint8_t* getData(uint8_t* pHeader)
{
    return (pHeader + sizeof(header_t));
}

void createHeader(header_t* pHeader, uint32_t size, header_t* prev)
{
    pHeader->isalloc = 0;
    pHeader->bytes = size - sizeof(header_t);
    pHeader->next = NULL;
    pHeader->prev = prev;
}

void* myMalloc(uint32_t bytes)
{
    header_t* cur = start;
    while((cur))
    {
        if ((cur->bytes >=  bytes) && (cur->isalloc == 0))
            break;
        else
            cur = cur->next;
    }

    if(cur == NULL)
    {
        printf("No space\n");
        return NULL;
    }
    
    printf("allocating ptr\n");
    cur->isalloc = 1;
    
    uint8_t* address = getData((uint8_t*)cur) + bytes;
    uint32_t size = cur->bytes - bytes;
    if(size >= sizeof(header_t))
    {
        cur->next = (header_t*)address;
        createHeader((header_t*)address, size, cur);
    }
    else
    {
        bytes == size;
    }

    cur->bytes = bytes;
    uint8_t* pCur = (uint8_t*)cur;
    return (void*) (getData((uint8_t*)cur));
}

void myFree(void* ptr)
{
    uint8_t* pData = (uint8_t*) ptr;
    header_t* cur = start;
    while(cur)
    {
        if(pData == getData((uint8_t*)cur))
        {
            if(cur->isalloc == 1)
               break;
            else
            {
                printf("It is a free buffer\n");
                return;
            }  
        }
        else
            cur = cur->next;
    }


    if(cur == NULL)
    {
        printf("Invalid address\n");
        return;
    }
    
    printf("freeing ptr\n");
    cur->isalloc = 0;

    header_t* next = cur->next;
    //check with next headers
    while(next && (next ->isalloc == 0))
    {
        cur->bytes += (next->bytes + sizeof(header_t));
        cur->next = next->next;
        if(next->next)
        {
             (next->next)->prev  = cur;
        }

        next = next->next;
    }

    //check with prev headers
    header_t* prev = cur->prev;
    while(prev && (prev->isalloc == 0))
     {
          prev->bytes += (cur->bytes + sizeof(header_t));
          prev->next = cur->next;
          if(cur->next)
          {
             (cur->next)->prev  = prev;
          }

          cur = prev;
          prev = prev->prev;

     }
}

