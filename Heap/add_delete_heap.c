/******************************************************************************

                         Heap Operations

*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX (100)

typedef struct _heap
{
    int H[MAX];
    int N;
} Heap;


void init(Heap* heap)
{
    heap->N = 0;
}

void* add(Heap* heap, int data)
{
    int pos = heap->N;
    heap->H[pos] = data;
    int par = (pos - 1) / 2;
    
    while(pos > 0)
    {
        if(heap->H[pos] > heap->H[par])
        {
            int temp = heap->H[par];
            heap->H[par] = heap->H[pos];
            heap->H[pos] = temp;
            
            pos = par;
            par = (pos - 1)/2;
            
        }
        else
        {
            break;
        }
    }
    
    heap->N++;
}

void print(Heap* heap)
{
    int i;
    for(i = 0; i < (heap->N); i++)
    {
        printf("%d  ", heap->H[i]);
    }
    
    printf("\n");
}

void heapify(Heap* heap, int par)
{
    int max = par;
    int l = (2 * par) + 1;
    int r = (2 * par) + 2;
    
    if((l < (heap->N)) && (heap->H[l] > heap->H[par]))
    {
        par = l;
    }
    if((r < (heap->N)) && (heap->H[r] > heap->H[par]))
    {
        par = r;
    }
    
    if(par != max)
    {
        int temp = heap->H[par];
        heap->H[par] = heap->H[max];
        heap->H[max] = temp;
        
        heapify(heap, par);
    }
}

void delete(Heap* heap)
{
    if(heap->N <= 0)
    {
        printf("Heap is empty\n");
        return;
    }
    
    int data = heap->H[0];
    heap->N--;
    heap->H[0] = heap->H[heap->N];
    heapify(heap, 0);
    
    printf("Deleted element is %d\n", data);
}

int main()
{
    Heap heap;
    
    init(&heap);
    int ch;
    do
    {
        printf("1 - Add  2 - Delete 3 - Print 4 -Exit\n");
        scanf("%d", &ch);
        
        switch(ch)
        {
            case 1:
            {
                int data;
                printf("Enter data\n");
                scanf("%d", &data);
                
                add(&heap, data);
                break;
            }
            case 2:
            {
                delete(&heap);
                break;
            }
            case 3:
            {
                print(&heap);
                break;
            }
            
            default:
            {
                ch = 0;
                break;
            }
            
        }
        
    } while(ch != 0);
    return 0;
}