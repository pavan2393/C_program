// Program for buffer manager

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define SLOT_SIZE  (1024)
#define NUM_SLOTS  (10)

uint8_t buffer[NUM_SLOTS][SLOT_SIZE];

uintptr_t* Queue[NUM_SLOTS];
int head, tail;
int num_buffers = 0;

void buffer_manager_init()
{
    int i;
    tail = 0;
    head = 0;
    for (i = 0; i < NUM_SLOTS; i++)
    {
        Queue[tail] = (uintptr_t*)buffer[i];
        tail = (tail + 1) % NUM_SLOTS;
        num_buffers++;
    }
}

void* getBuffer()
{
    if(num_buffers > 0)
    {
        void* ret =  (void*)Queue[head];
        head = (head + 1) % NUM_SLOTS;
        num_buffers--;
        return ret;
    }
    else
    {
        printf("Out of buffers\n");
        return NULL;
    }
}

void putBuffer(void* buf)
{
    uintptr_t* pushBuf = (uintptr_t*)buf;
    
    if(pushBuf == NULL)
    {
        printf("buffer pointer is NULL\n");
        return;
    }

    if(num_buffers >= NUM_SLOTS)
    {
        printf("All buffers already in free list\n");
        return;
    }

    uint32_t rem = (((uint32_t) (uintptr_t)pushBuf) - ((uint32_t) (uintptr_t) buffer[0])) & (SLOT_SIZE - 1);
    printf("rem is %d\n", rem);
    if(rem != 0)
    {
        printf("Invalid buffer address\n");
        return;
    }

    int i = head;
    int count = 0;

    while(count < num_buffers)
    {
        if(pushBuf == Queue[i])
        {
            printf("Buffer already released\n");
            return;
        }
        
        count++;
        i = (i+1) % NUM_SLOTS;
    }


    Queue[tail] = pushBuf;
    tail = (tail + 1) % NUM_SLOTS;
    num_buffers++;
}


int main(void)
{
    buffer_manager_init();
    uintptr_t* buff[11];
    int i = 0;
    for(i = 0; i < 11; i++)
        buff[i] = (uintptr_t*)getBuffer();
    //uint32_t* buff2 = (uint32_t*)getBuffer();

    //buff += 2;

    putBuffer((void*)buff[0]+1);
    putBuffer((void*)buff[1]);

}
