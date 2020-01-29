/******************************************************************************
             Binary Search
*******************************************************************************/

#include <stdio.h>

int binarySearch(int A[], int N, int target)
{
    int start = 0;
    int end = N-1;
    
    if(N == 0)
        return -1;
        
    while(start <= end)
    {
        int mid = (start + end) / 2;
        if(A[mid] == target)
        {
            return mid;
        }
        else if(target > A[mid])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    
    return -1;
}

#define NUM (7)
int main()
{
    
    int A[NUM] = {0, 1, 4, 5, 6, 9, 17};
    int item = 7;
    int index =  binarySearch(A, NUM, item);
    
    if(index == -1)
    {
        printf("Element not found\n");
    }
    else
    {
        printf("%d found at index: %d\n", item, index);
    }

    return 0;
}