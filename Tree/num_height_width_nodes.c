/******************************************************************************

                         Num Height Width Nodes Implementation

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

int numNodes(Node* pTree)
{
    if(pTree == NULL)
    {
        return 0;
    }
    

    int l1 = 1 + numNodes(pTree->left) + numNodes(pTree->right);
    return l1;
}

int height(Node* pTree)
{
    if(pTree == NULL)
    {
        return 0;
    }
    

    int l1 = 1 + numNodes(pTree->left);
    int l2 = 1 + numNodes(pTree->right);
    
    return ((l1 > l2) ? l1 : l2);
}

int width(Node* pTree)
{
    Node* Q[100];
    int head = 0;
    int tail = 0;
    
    if(pTree == NULL)
    {
        return 0;
    }
    Q[tail++] = pTree;
    int count = 1;
    int count2 = 0;
    int max_count = 1;
    while(head != tail)
    {
        Node* pop = Q[head++];
        while(count > 0)
        {
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
            count--;
        }
        max_count = (count2 > max_count) ? count2 : max_count;
        count = count2;
        count2 = 0;
    }
    return max_count;
}

int main()
{
    Node* pTree = NULL;
    
    int ch;
    do
    {
        printf("Enter 1 - Add  2 - Num Nodes 3 - Height  4 - Width 5 - Exit\n");
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
                int num = numNodes(pTree);
                printf("Number of nodes : %d\n", num);
                
                break;
            }
            case 3:
            {
                int h = height(pTree);
                printf("Height of tree is %d\n", h);
                break;
            }
            case 4:
            {
                int w = width(pTree);
                printf("Width of tree is %d\n", w);
                break;
            }
            case 5:
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