//Program to find if a linked list is a palindrome

#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include <stdbool.h>

typedef struct _Node
{
    int data;
    struct _Node* next;
} Node;

Node* getNode()
{
    Node* pNode = (Node*)malloc(sizeof(Node));
    pNode->next = NULL;
    return pNode;
}

Node* head=NULL;

void push(int data)
{
    Node* pNode = getNode();
    pNode->data = data;
    if(head == NULL)
        head = pNode;
    else
    {
        Node* cur = head;
        while(cur->next != NULL)
        {
            cur = cur->next;
        }
        cur->next = pNode;
    }    
}

bool check (Node* revCur, Node** cur)
{
    if(revCur == NULL)
        return true;
    bool res = check(revCur->next, cur);
    if((res == true) && (revCur->data == (*cur)->data))
    {
        *cur = (*cur)->next;
        return true;
    }

    return false;
}





