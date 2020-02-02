/******************************************************************************

                         Heap Operations

*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX (100)


void heapify(int* A, int par, int N)
{
    int max = par;
    int l = (2 * par) + 1;
    int r = (2 * par) + 2;
    
    if((l < N) && (A[l] > A[par]))
    {
        par = l;
    }
    if((r < N) && (A[r] > A[par]))
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


void heapSort(int* A, int N)
{
    int i = (N/2) - 1;
    for(; i >= 0; i--)
    {
        heapify(A, i, N);
    }
    
    for(i = 0; i < N-1; i++)
    {
        int temp = A[0];
        A[0] = A[N-1-i];
        A[N-1-i] = temp;
        heapify(A, 0, N-1-i);
    }
}

#define N (5)
int main()
{
    int A[N] = {9, 1, 7, 2, 0};
    heapSort(A, N);
    
    int i;
    printf("Sorted Array is:\n");
    for(i = 0; i < N; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
    return 0;
}