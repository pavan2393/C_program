/******************************************************************************

                         BST Implementation

*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX (100)

typedef struct _Node
{
    int val;
    struct _Node* left;
    struct _Node* right;
} Node;

Node* getNode(void)
{
    Node* pNode = (Node*)(malloc(sizeof(Node)));
    
    pNode->left = NULL;
    pNode->right = NULL;
    return pNode;
}


void invert(Node* pTree)
{
     if(!pTree)
     {
         return;
     }
     
     Node* temp = pTree->left;
     pTree->left = pTree->right;
     pTree->right = temp;
     
     invert(pTree->left);
     invert(pTree->right);
}

Node* add (Node* pTree, int val)
{
    if(pTree == NULL)
    {
        Node* pNode = getNode();
        pNode->val = val;
        pTree = pNode;
        return pNode;
    }
    
    if(val < pTree->val)
    {
        pTree->left = add(pTree->left, val);
    }
    else
    {
        pTree->right = add(pTree->right, val);
    }
    
    return pTree;
    
}

void levelOrder(Node* pTree)
{
    if(pTree == NULL)
    {
        return;
    }
    
    int count = 1;
    int index = 0;
    int count2 = 0;
    
    Node* Q[MAX];
    int head = 0;
    int tail = 0;
    
    Q[tail++] = pTree;
    
    while(head != tail)
    {
        while(index < count)
        {
            Node* pop = Q[head++];
            printf("%d   ", pop->val);
            if(pop->left)
            {
                count2++;
                Q[tail++] = pop->left;
            }
            if(pop->right)
            {
                count2++;
                Q[tail++] = pop->right;
            }
            
            index++;
        }
        
        count = count2;
        index = 0;
        count2 = 0;
    }
    
    printf("\n");
}

void top(Node* pTree, int* pos, int* neg, int* np, int* nn, int loc)
{
    if(pTree == NULL)
    {
        return;
    }
    if(loc >= 0)
    {
        if(pos[loc] == -1)
        {
            *np = (loc > (*np)) ? loc : (*np);
            pos[loc] = pTree->val;
        }
    }
    else
    {
        int absLoc = abs(loc);
        if(neg[absLoc] == -1)
        {
            *nn = (absLoc > ()*nn) ? absLoc : (*nn);
            neg[absLoc] = pTree->val;
        }
    }
    
    top(pTree->left, pos, neg, np, nn, loc-1);
    top(pTree->right, pos, neg, np, nn, loc+1);
}

int* topView(Node* pTree, int* max)
{
    if(pTree == NULL)
    {
        return NULL;
    }
    
    int pos[MAX];
    int neg[MAX];
    int num_pos = 0;
    int num_neg = 0;
    int j = 0;
    int i = 0;
    
    for(i = 0; i < MAX; i++)
    {
        pos[i] = -1;
        neg[i] = -1;
    }
    top(pTree, pos, neg, &num_pos, &num_neg, 0);
    
    *max = num_neg+num_pos;
    printf("max is %d\n", *max);
    int* out = (int*)(malloc((num_neg + num_pos) * sizeof(int)));
    
    i = 0;
    for(j = num_neg; j >= 1; j--)
    {
        out[i++] = neg[j];
    }
    
    for(j = 0; j <= num_pos; j++)
    {
        out[i++] = pos[j];
    }
    
    return out;
}

int main()
{
    Node* pTree = NULL;
    
    int ch;
    do
    {
        printf("Enter 1 - Add  2 - Top View  3 - Level Order 4 - Exit\n");
        scanf("%d", &ch);
        
        switch(ch)
        {
            case 1:
            {
                int val;
                printf("Enter data\n");
                scanf("%d", &val);
                pTree = add(pTree, val);
                break;
            }
            case 2:
            {
                int max = 0;
                int* out = topView(pTree, &max);
                
                int i;
                for(i = 0; i < max; i++)
                {
                    printf("%d  ", out[i]);
                    printf("\n");
                }
                
                free(out);
                break;
            }
            case 3:
            {
                levelOrder(pTree);
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