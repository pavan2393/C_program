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


void inorder(Node* pTree)
{
     if(pTree)
     {
         inorder(pTree->left);
         printf("%d ", pTree->val);
         inorder(pTree->right);
     }
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

int main()
{
    Node* pTree = NULL;
    
    int ch;
    do
    {
        printf("Enter 1 - Add 2 - Level Order  3 - In order 4 - Exit\n");
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
                levelOrder(pTree);
                break;
            }
            case 3:
            {
                inorder(pTree);
                printf("\n");
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