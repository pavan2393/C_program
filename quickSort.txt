/******************************************************************************

Quick Sort

*******************************************************************************/

#include <stdio.h>

int partition(int* A, int low, int high)
{
    int i = low;
    
    int j;
    int pivot = A[high];
    
    for(j = low; j < high; j++)
    {
        
        if(A[j] < pivot)
        {
            
            if(i != j)
            {
                int temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
            
            i++;
        }
    }
    
    A[high] = A[i];
    A[i] = pivot;
    
    return i;
}

void quickSort(int* A, int low, int high)
{
    if(low < high)
    {
        int pivot = partition(A, low, high);
        
        quickSort(A, low, pivot-1);
        quickSort(A, pivot, high);
    }
    
}

#define NUM (6)
int main()
{
    
    int A[NUM] = {26, 25, 0, 23, 22, 21};
    quickSort(A, 0, NUM-1);
    int i;
    for(i = 0; i < NUM; i++)
    {
        printf("%d  ", A[i]);
    }
    printf("\n");
    printf("Hello World");

    return 0;
}