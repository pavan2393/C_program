/******************************************************************************

                         Insertion Sort

*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define N (5)

void insertionSort(int A[], int n)
{
    int i;
    
    for(i = 1; i < n; i++)
    {
        int hole = i;
        int data = A[i];
        int j = i-1;
        
        while((j >= 0) && (A[j] > data))
        {
            A[hole--] = A[j--];
        }
        
        A[hole] = data;
    }
}


int main()
{
    int A[N] = {5,1,2,4,3};
    insertionSort(A, N);
    
    int i;
    for(i = 0; i < N; i++)
        printf("%d  ", A[i]);
    printf("\n");
    return 0;
}