#include <stdio.h>
#include <stdlib.h>
#include "duLinkedList.h"

/**
 *  @data        : void *InitList_DuL(DuLinkedList L)
 *	@description : initialize an empty linked list with only the head node
 *	@param		 : L(the head pointer)
 *	@return		 : L(the head pointer)
 *  @notice      : None
 */
void* InitList_DuL(DuLinkedList L)
{
    L = (DuLinkedList)malloc(sizeof(DuLNode));
    if (!L)
        printf("内存溢出");
    L->prior = NULL;
    L->next = NULL;
    printf("成功初始化列表\n");
    return L;
}

/**
 *  @data        : void DestroyList_DuL(DuLinkedList L)
 *	@description : destroy a linked list
 *	@param		 : L(the head pointer)
 *	@return		 : status
 *  @notice      : None
 */
void DestroyList_DuL(DuLinkedList L)
{
    DuLinkedList pNext;
    pNext = L;
    if (pNext->next == NULL)
        printf("后面没有了");
    while (pNext)
    {
        pNext = pNext->next;
        free(L);
        L = pNext;
    }
}

/**
 *  @data        : void *Insert_Node(DuLinkedList head)
 *	@description : insert node q before node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertBeforeList_DuL(DuLNode* p, DuLNode* q)
{
    DuLinkedList tem;
    if (p->prior == NULL)
    {
        p->prior = q;
        q->next = p;
        q->prior = NULL;
    }
    else
    {
        tem = p->prior;
        tem->next = q;
        q->next = p;
        p->prior = q;
        q->prior = tem;
    }
}
/**
 *  @name        : Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
void InsertAfterList_DuL(DuLNode* p, DuLNode* q) 
{
    DuLinkedList tem;
    if (p->next != NULL)
    {
        tem = (DuLinkedList)malloc(sizeof(DuLNode));
        tem = p->next;
        tem->prior = p;
        p->next = q;
        q->next = tem;
        tem->prior = q;
        q->prior = p;
    }
    else
    {
        p->next = q;
        q->prior = p;
    }
}
/**
 *  @name        : Status DeleteList_DuL(DuLNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : status
 *  @notice      : None
 */
void* DeleteList_DuL(DuLNode* p, ElemType* e)
{
    DuLinkedList q,tem;
    if (p->next == NULL)
    {
        printf("p后没有节点了");
    }
    else 
    {
        q = p->next;
        if (q->next == NULL)
        {
            e = q->data;
            free(q);
        }
        else
        {
            e = q->data;
            tem = q->next;
            p->next = tem;
            tem->prior = p;
            free(q);
        }
    }
}

/**
 *  @data        : void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : Status
 *  @notice      : None
 */
void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
{
    DuLinkedList p = L->next;
    while (p)
    {
        visit(p->data);
        p = p->next;
    }
    printf("\n");
}
void visit(ElemType e)
{
    printf("%d->", e);
}

/**
 *  @name        : void *Create(int n)
 *	@description : Create a linked list
 *	@param		 : int n
 *	@return		 : L(the head pointer)
 *  @notice      : None
 */
void* Create(int n)
{
    DuLinkedList h, p, s;
    h = (DuLinkedList)malloc(sizeof(DuLNode));

    if (h == NULL)
    {
        return OVERFLOW;
    }

    h->data = 0;
    h->prior = NULL;
    h->next = NULL;
    p = h;

    for (int i = 0; i < n; i++)
    {
        s = (DuLinkedList)malloc(sizeof(DuLNode));
        if (s == NULL)
        {
            return OVERFLOW;
        }
        p->next = s;
        printf("Please enter the data for No.%d node:", i + 1);
        scanf_s("%d", &s->data);
        s->prior = p;
        s->next = NULL;
        p = s;
    }
    printf("Successfully create a DuLinkedList!\n");
    return h;
}
