/******************************************************************************

                         Kth Greatest Element

*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX (100)

void addHeap(int* heap, int data, int pos)
{
    heap[pos] = data;
    int par = (pos - 1) / 2;
    
    while(pos > 0)
    {
        if(heap[par] > heap[pos])
        {
            int temp = heap[par];
            heap[par] = heap[pos];
            heap[pos] = temp;
            pos = par;
            par = (pos - 1)/2;
        }
        else
        {
            break;
        }
    }
}


void heapify(int* A, int par, int N)
{
    int max = par;
    int l = (2 * par) + 1;
    int r = (2 * par) + 2;
    
    if((l < N) && (A[l] < A[par]))
    {
        par = l;
    }
    if((r < N) && (A[r] < A[par]))
    {
        par = r;
    }
    
    if(par != max)
    {
        int temp = A[par];
        A[par] = A[max];
        A[max] = temp;
        
        heapify(A, par, N);
    }
}


void findKGreatest(int* A, int N, int k)
{
    int count = 0;
    int* heap = (int*)(malloc(k * sizeof(int)));
    
    int i;
    for(i = 0; i < N; i++)
    {
        if(count < k)
        {
            addHeap(heap, A[i], count);
            count++;
        }
        else
        {
            if(A[i] > heap[0])
            {
                heap[0] = A[i];
                heapify(heap, 0, k);
            }
        }
    }
    
    printf("The %d (rd)(th) element in array is %d\n", k,heap[0]);
}

#define N (5)
int main()
{
    int A[N] = {900, 17, 16, 45, 0};
    findKGreatest(A, N, 3);
    return 0;
}