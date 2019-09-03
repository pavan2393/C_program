//program to reverse a BST

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>


typedef struct _Node_t
{
    int data;
    struct _Node_t* left;
    struct _Node_t* right;
} Node;

Node* getNode(int data)
{
    Node* pNode = (Node*)(malloc(sizeof(Node)));
    pNode->data = data;
    pNode->left = NULL;
    pNode->right = NULL;
    return pNode;
}

void createTree(Node** pTree, int data)
{
    if(*pTree == NULL)
    {
        Node* pNode = getNode(data);
        *pTree = pNode;
         return;
    }

    if(data > (*pTree)->data)
    {
        createTree(&((*pTree)->right), data);
    }
    else
    {
        createTree(&((*pTree)->left), data);
    } 
}

void preOrder(Node* pTree)
{
    if(pTree == NULL)
        return;
    printf("%d \n", pTree->data);
    preOrder(pTree->left);
    preOrder(pTree->right);

}

void reverse(Node* pTree)
{
    if(pTree == NULL)
        return;
    
    reverse(pTree->left);
    reverse(pTree->right);

    Node* temp = pTree->left;
    pTree->left = pTree->right;
    pTree->right = temp;
}


int main()
{
    Node* pTree = NULL;
    int ch;
    do
    {
        printf("1 : Add     2: Traverse\n");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
            {
                int data;
                printf("Enter data\n");
                scanf("%d", &data);
                createTree(&pTree, data);
                break;
            }

            case 2:
            {
                preOrder(pTree);
                break;
            }
            case 3:
            {
                reverse(pTree);
                break;
            }
            default:
            {
                ch = 0;
                break;
            }

        }
    }while(ch != 0);
}
