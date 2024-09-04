#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
int val;//值
struct ListNode *next; //指向下一个节点的指针
}ListNode;
/* 指针类型需要节点类型才能正确链接节点，明确表示这个指针为结构体指针*/

/*申请新的节点*/
ListNode *newListNode(int val)
{
    ListNode *node;
    node = (ListNode*)malloc(sizeof(ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

/*在节点n0后插入p*/
void insert(ListNode *n0, ListNode *p)
{
    ListNode *n1 = n0->next;
    p->next  = n1;
    n0->next = p;
}

/*删除节点*/
void delete(ListNode *n0)
{
    if (NULL == n0->next)
    {
        return;
    }
    ListNode *p = n0->next;
    ListNode *n1 = p->next;
    n0->next = n1;
    free(p);
}

/*访问索引为index的节点*/
ListNode *access(ListNode *head, int index)
{
    for(int i=0; i<index;i++)
    {
        if(NULL == head)
        {
            return NULL;
        }
        head = head->next;
    }
}

/*单向链表打印*/
void print_list(ListNode *node) 
{
    while (NULL != node)
    {
        printf(" %d ->",node->val);
        node = node->next;        
    }
    printf(" NULL\n");
    return; 
}

int main(int argc, char const *argv[])
{
    ListNode *p = NULL;

    ListNode* n0 = newListNode(0);
    ListNode* n1 = newListNode(1);
    ListNode* n2 = newListNode(2);
    ListNode* n3 = newListNode(3);
    ListNode* n4 = newListNode(4);
    ListNode* n5 = newListNode(5);
    
    n0->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;

    
    insert(n0,n5);

    print_list(n0);
    return 0;
}
