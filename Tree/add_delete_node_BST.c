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
         printf("%d\n", pTree->val);
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

bool findNode(Node* pTree, Node** pNode, Node** par, int val)
{
    if(!pTree)
    {
        return false;
    }
    
    bool l1 = false;
    bool l2 = false;
    
    if(val == pTree->val)
    {
        *pNode = pTree;
        return true;
    }
    
    else if(val < pTree->val)
    {
        *par = pTree;
        l1 = findNode(pTree->left, pNode, par, val);
    }
    else
    {
        *par = pTree;
        l2 = findNode(pTree->right, pNode, par, val);
    }
    
    return (l1 || l2);
}


void deleteLeaf(Node* pNode, Node* par)
{
    if(pNode == par->left)
    {
        par->left = NULL;
    }
    else
    {
        par->right = NULL;
    }
    
    free(pNode);
}

void delOneChild(Node* pNode, Node* par)
{
    if(pNode == par->left)
    {
        if(pNode->left)
        {
            par->left = pNode->left;
        }
        else
        {
            par->left = pNode->right;
        }
    }
    else
    {
        if(pNode->left)
        {
            par->right = pNode->left;
        }
        else
        {
            par->right = pNode->right;
        }
        
    }
    
    free(pNode);
}

void delTwoChild(Node* pNode, Node* par)
{
    Node* leftMost = pNode->right;
    Node* leftpar = pNode;
    
    while(leftMost->left != NULL)
    {
        leftpar = leftMost;
        leftMost = leftMost->left;
    }
    
    pNode->val = leftMost->val;
    if(leftMost->left || leftMost->right)
    {
         delOneChild(leftMost, leftpar);
    }
    else
    {
        deleteLeaf(leftMost, leftpar);
    }
}

Node* delete(Node* pTree, int val)
{
    if(pTree == NULL)
    {
        printf("No Node to delete\n");
    }
    
    Node* pNode;
    Node* par = pTree;
    bool status = findNode(pTree, &pNode, &par, val);
    if(status == false)
    {
        printf("Node does not exist\n");
    }
    else
    {
        if((!pNode->left) && (!pNode->right))
        {
            deleteLeaf(pNode, par);
        }
        else if(pNode->left && pNode->right)
        {
            delTwoChild(pNode, par);
        }
        else
        {
            delOneChild(pNode, par);
        }
    }
}

int main()
{
    Node* pTree = NULL;
    
    int ch;
    do
    {
        printf("Enter 1 - Add 2 - Delete  3 - Inorder 4 - Exit\n");
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
                int val;
                printf("Enter data\n");
                scanf("%d", &val);
                delete(pTree, val);
                break;
            }
            case 3:
            {
                inorder(pTree);
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