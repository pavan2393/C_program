// Program to perform merge sort
#include <stdio.h>

void merge(int* A, int* B, int* res, int lenA, int lenB)
{
    int i = 0, j = 0, k = 0;
    while((i < lenA ) && (j < lenB))
    {
        if(A[i] < B[j])
            res[k++] = A[i++];
        
        else
            res[k++] = B[j++];
    }

    while(i < lenA)
    {
        res[k++] = A[i++];
    }    

    while(j < lenB)
    {
        res[k++] = B[j++];
    }
}

void mergeSort(int* Array, int len)
{
    if(len < 2)
        return;

    int half = len / 2;

    int A[half];
    int B[len - half];
    int i = 0;
    for(i = 0; i < half; i++)
    {
        A[i] = Array[i];
    }

    int j = 0;
    for(; j < len - half; j++, i++)
   {
       B[j] = Array[i];
   }

    mergeSort(A, half);
    mergeSort(B, len-half);
    merge(A, B, Array, half, len-half);
}

int main()
{
    int A[7] = {5,7,9,8,1,6,3};

    mergeSort(A, 7);
    int i;
    for(i = 0; i < 7; i++)
        printf("%d ", A[i]);
}




