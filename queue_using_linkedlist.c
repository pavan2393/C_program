// queue using linked list
#include <stdio.h>
#include <stdlib.h>

typedef struct _Node
{
    int data;
    struct _Node* next;
} Node;

typedef struct _Q
{
    Node* head;
    Node* tail;
    int count;
    int max;
} Q;

Q q;

void q_init(int max_elements)
{
    q.head = NULL;
    q.tail = NULL;
    q.count = 0;
    q.max = max_elements; 
}

Node* createNode(void)
{
    Node* pNode = (Node*) (malloc(sizeof(Node)));
    pNode->next = NULL;
    return pNode;
}

void push(int data)
{
    if(q.count < q.max)
    {
        Node* pNode = createNode();
        pNode->data = data;
        if(q.head == NULL)
        {
            q.head = pNode;
        }
        if(q. tail != NULL)
        {
            q.tail->next = pNode;
        } 

        q.tail = pNode;
        q.count++;
        
    }
    else
    {
        printf("queue  full\n");
    }
}

int pop(void)
{
    int data;

    if(q.count == 0)
    {
        printf("queue is empty\n");
        return 0xFF;
    }

    data = q.head->data;
    Node* temp = q.head;
    q.head = q.head->next;

     if(q.head == NULL)
         q.tail = NULL;

     q.count--;
     free(temp);
     return data;
}


int main(void)
{
    q_init(5);
    int ch;

    do
    {
        printf("Enter 1 to push\n Enter 2 to pop\n");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
            {
                int data;
                printf("Enter data\n");
                scanf("%d", &data);
                push(data);
                break;
            }

            case 2:
            {
                int data = pop();
                if (data != 0xFF)
                    printf("popped data is %d\n", data);
                break;
            }
            default:
            {
                ch = 0;
            }
        } 
 
    } while(ch != 0);
}
