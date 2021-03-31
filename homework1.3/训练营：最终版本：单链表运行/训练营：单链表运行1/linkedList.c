#include "linkedList.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 *  @name        : Status InitList(LinkList *L);
 *	@description : initialize an empty linked list with only the head node without value
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList(LinkedList* L)
{
	*L = (LinkedList)malloc(sizeof(LNode));
	if (!L)
	{
		return ERROR;
	}
	(*L)->next = NULL;
	return SUCCESS;
}

/**
 *  @name        : void DestroyList(LinkedList *L)
 *	@description : destroy a linked list, free all the nodes
 *	@param		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void DestroyList(LinkedList* L) 
{
	if ((*L) == NULL) 
	{
		printf("链表为空");
	}
	LNode* t = (*L), * q;
	while (t != NULL) 
	{
		q = t->next;
		free(t);
		t = q;
	}
}

/**
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : Status
 *  @notice      : None
 */
Status InsertList(LNode* p, LNode* q) 
{
	if (p == NULL)
	{
		p = q;
	}
	else
	{
		q->next = p->next;
		p->next = q;
	}
	return SUCCESS;
}
/**
 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : Status
 *  @notice      : None
 */
Status DeleteList(LNode* p, ElemType* e) 
{
	if (p->next == NULL) 
	{
		return ERROR;
	}
	*e = p->next->data;
	p->next = p->next->next;
	return SUCCESS;
}

/**
 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : None
 *  @notice      : None
 */
void TraverseList(LinkedList L, void (*visit)(ElemType e)) 
{
	LinkedList p = L;
	while (p != NULL) 
	{
		printf("%d ", p->data);
		p = p->next;
	}
}
void visit(ElemType e)
{
	printf("%d->", e);
}

/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : find the first node in the linked list according to e
 *	@param		 : L(the head node), e
 *	@return		 : Status
 *  @notice      : None
 */
Status SearchList(LinkedList L, ElemType e) 
{
	LinkedList p = L;
	while (p != NULL) 
	{
		if (p->data == e) 
		{
			return SUCCESS;
		}
		p = p->next;
	}
	return ERROR;
}

LNode* reverse(LNode** now) 
{
	LNode* t = (*now)->next;
	LNode* p;
	if (t == NULL) 
	{
		return *now;
	}
	p = reverse(&t);
	t->next = (*now);
	return p;
}

/**
 *  @name        : Status ReverseList(LinkedList *L)
 *	@description : reverse the linked list
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status ReverseList(LinkedList* L) 
{
	if (IsLoopList(*L) == ERROR) 
	{
		return ERROR;
	}
	LinkedList p = *L;
	p = reverse(L);
	(*L)->next = NULL;
	*L = p;
	return SUCCESS;
}

/**
 *  @name        : Status IsLoopList(LinkedList L)
 *	@description : judge whether the linked list is looped
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status IsLoopList(LinkedList L) 
{
	if (L == NULL)
	{
		return SUCCESS;
	}
	LNode* p1, * p2;
	p1 = L;
	p2 = L->next;
	while (p1 != NULL && p2 != NULL) 
	{
		if (p1 == p2) 
		{
			return ERROR;
		}
		if (p2->next == NULL) 
		{
			return SUCCESS;
		}
		p1 = p1->next;
		p2 = p2->next->next;
	}
	return SUCCESS;
}

/**
 *  @name        : LNode* ReverseEvenList(LinkedList *L)
 *	@description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 *	@param		 : L(the head node)
 *	@return		 : LNode(the new head node)
 *  @notice      : choose to finish
 */
LNode* ReverseEvenList(LinkedList* L) 
{
	if (IsLoopList(*L) == ERROR) 
	{
		return NULL;
	}
	LNode* p1, * p2;
	int t;
	p1 = (*L);
	p2 = p1->next;
	while (p2 != NULL)
	{
		if (p2->data % 2 == 0)
		{
			t = p2->data;
			p2->data = p1->data;
			p1->data = t;
		}
		p2 = p2->next;
		p1 = p1->next;
	}
	return (*L);
}

/**
 *  @name        : LNode* FindMidNode(LinkedList *L)
 *	@description : find the middle node in the linked list
 *	@param		 : L(the head node)
 *	@return		 : LNode
 *  @notice      : choose to finish
 */
LNode* FindMidNode(LinkedList* L) 
{
	if (IsLoopList(*L) == ERROR) 
	{
		return NULL;
	}
	int len = 0;
	LNode* t = (*L);
	while (t != NULL) 
	{
		len++;
		t = t->next;
	}
	t = (*L);
	int mid = len / 2;
	while (mid--) 
	{
		t = t->next;
	}
	return t;
}

