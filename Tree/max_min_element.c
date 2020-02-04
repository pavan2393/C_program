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

int maxElement(Node* pTree)
{
    if(pTree == NULL)
    {
        return 0;
    }
    
    int l1 = maxElement(pTree->left);
    int l2 = maxElement(pTree->right);
    
    int greater = (l1 > l2) ? l1 : l2;
    return(greater > pTree->val) ? greater : pTree->val;
}

int minElement(Node* pTree)
{
    if(pTree == NULL)
    {
        return 0;
    }
    
    int l1 = -1;
    int l2 = -1;
    if(pTree->left)
        l1 = minElement(pTree->left);
    if(pTree->right)
        l2 = minElement(pTree->right);
    
    if((l1 == -1) && (l2 == -1))
    {
        return pTree->val;
    }
    
    int lower;
    if(l2 == -1)
    {
        lower = l1;
    }
    
    else if(l1 == -1)
    {
        lower = l2;
    }
    else
    {
        lower = (l1 < l2) ? l1 : l2;
    }
    return ((lower < pTree->val)? lower : pTree->val);
}

int main()
{
    Node* pTree = NULL;
    
    int ch;
    do
    {
        printf("Enter 1 - Add  2 - Max Element  3 - Min Element  4 - Level Order 5 - Exit\n");
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
                int max = maxElement(pTree);
                printf("The max element is : %d\n", max);
                
                break;
            }
            case 3:
            {
                int min = minElement(pTree);
                printf("The min element is : %d\n", min);
                
                break;
            }
            case 4:
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