/******************************************************************************

                           Square Matrix Transpose

*******************************************************************************/

#include <stdio.h>
#define R (3)
#define C (3)

void transpose(int r, int c, int A[r][c])
{
    if(r != c)
    {
        printf("Rectangular Matrix Transpose not supported\n");
        return;
    }
    
    int i, j; 
    
    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
        {
            if(i > j)
            {
                int temp = A[i][j];
                A[i][j] = A[j][i];
                A[j][i] = temp;
            } 
        }
            
    }
}


int main()
{
    
    int A[R][C] = {{0, 1, 4}, {5, 1, 2}, {1, 2, 3}};
    transpose(R, C, A);
    
    printf("Transposed matrix is \n");
    
    int i, j;
    for(i = 0; i < R; i++)
    {
        for(j = 0; j < C; j++)
        {
            printf("%d  ", A[i][j]);
        }
        
        printf("\n");
    }

    return 0;
}