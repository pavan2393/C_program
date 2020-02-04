/******************************************************************************

                         Depth First Search and Breadth First Search

*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX (100)

#define V (5)

void DFS(int v, int A[v][v])
{
    int stack[v];
    int visit[v];
    int sptr = -1;
    
    int i;
    for(i = 0; i < v ; i++)
    {
        visit[i] = 0;
    }
    
    stack[++sptr] = 0;
    visit[0] = 1;
    printf("%d ", 0);
    while(sptr >= 0)
    {
        int pop = stack[sptr];
        
        
        int i;
        for(i = 0; i < v; i++)
        {
            if((A[pop][i] == 1) && (visit[i] == 0))
            {
                printf("%d ", i);
                visit[i] = 1;
                stack[++sptr] = i;
                break;
            }
            
            
        }
        
        if(i == v)
        {
            sptr--;
        }
    }
    printf("\n");
}


void BFS(int v, int A[v][v])
{
    int queue[v];
    int visit[v];
    int head = 0;
    int tail = 0;
    
    int i;
    for(i = 0; i < v ; i++)
    {
        visit[i] = 0;
    }
    
    queue[tail++] = 0;
    visit[0] = 1;

    while(head != tail)
    {
        int pop = queue[head++];
        printf("%d ", pop);
        int j;
        for(j = 0; j < v; j++)
        {
            if((A[pop][j] == 1) && (visit[j] == 0))
            {
                visit[j] = 1;
                queue[tail++] = j;
            }
        }
    }
    printf("\n");
}

int main()
{
    int A[V][V] = {{0,1,0,0,1}, {1,0,1,0,1}, {0,1,0,1,0}, {0,0,1,0,0}, {1,1,0,0,0}};
    
    
    int ch;
    do
    {
        printf("Enter 1 - DFS  2 - BFS  3 - Exit\n");
        scanf("%d", &ch);
        
        switch(ch)
        {
            case 1:
            {
                DFS(V,A);
                break;
            }
            case 2:
            {
                BFS(V, A);
                
                break;
            }
            default:
            {
                ch = 0;
                break;
            }
        }
        
    } while (ch != 0);
    return 0;
}