/******************************************************************************

                            Matrix Multiplication

*******************************************************************************/

#include <stdio.h>
#define R1 (2)
#define C1 (3)
#define R2 (3)
#define C2 (2)

void matrixMul(int r1, int c1, int A[r1][c1], int r2, int c2, int B[r2][c2])
{
    if(c1 != r2)
    {
        printf("Matrices cannot be multiplied\n");
        return;
    }
    
    int i, j; 
    int r = 0, c = 0;
    int sum = 0;
    int C[r1][c2];
    for(r = 0; r < r1; r++)
    {
        for(i = 0; i < c2; i++)
        {
            for(j = 0; j < c1; j++)
            {
                sum += (A[r][j] * B[j][c]); 
            }
            
            C[r][c] = sum;
            c++;
            sum = 0;
        }
        
        c= 0;
    }
    
    printf("Multiplied matrix is \n");
    
    for(i = 0; i < r1; i++)
    {
        for(j = 0; j < c2; j++)
        {
            printf("%d  ", C[i][j]);
        }
        
        printf("\n");
    }
}


int main()
{
    
    int A[R1][C1] = {{0, 1, 4}, {5, 1, 2}};
    int B[R2][C2] = {{0, 1,},{4, 5}, {1, 2}};
    
    matrixMul(R1, C1, A, R2, C2, B);

    return 0;
}