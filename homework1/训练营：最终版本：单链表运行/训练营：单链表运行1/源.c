#include <stdio.h>
#include "linkedList.h"
void testInitList() 
{
	LinkedList L1, L2;
	if (InitList(&L1) == ERROR) 
	{
		printf("初始化失败\n");
		exit(1);
	}
	else 
	{
		printf("初始化成功\n");
	}
	DestroyList(&L1);
	printf("\n");
}
void testInsertList()
{
	LinkedList L1, L2, p,q;
	int i, n, t, k;
	InitList(&L1);
	p = L1;
	printf("你想要输入多少个的节点:");
	scanf("%d", &n);
	printf("输入你想要输入的内容:\n");
	for (i = 1; i <= n; i++)
	{
		printf("Please enter the data for No.%d node:", i );
		scanf("%d", &t);
		if (i == 0)
			L1->data = t;
		else
		{
			InitList(&L2);
			L2->data = t;
			InsertList(p, L2);
			p = p->next;
		}
	}
	printf("插入前链表为: ");
	TraverseList(L1, NULL);
	printf("\n");
	printf("输入你想要插入的数据:");
	scanf("%d", &t);
	InitList(&L2);
	L2->data = t;
	q = L2;
	printf("输入你想要在哪个数据后插入:");
	scanf("%d", &t);
	for (p=L1,i=0;i<n ; i++)
	{
		if (p->data == t)
			break;
		p = p->next;
	}
	InsertList(p, q);
	printf("插入后: ");
	TraverseList(L1, NULL);
	DestroyList(&L1);
	printf("\n\n");
}
void testSearchList() 
{
	LinkedList L1, L2, p;
	int i, n, t;
	InitList(&L1);
	p = L1;
	printf("你想要输入多少个的节点:");
	scanf("%d", &n);
	printf("输入你想要输入的内容:\n");
	for (i = 1; i <= n; i++)
	{

		printf("Please enter the data for No.%d node:", i );
		scanf("%d", &t);
		if (i == 0)
			L1->data = t;
		else
		{
			InitList(&L2);
			L2->data = t;
			InsertList(p, L2);
			p = p->next;
		}
	}
	p = L1;
	printf("输入你想要寻找的目标e:");
	scanf("%d",&t);
	if (SearchList(L1, t) == ERROR) 
	{
		printf("未找到目标\n");
		exit(1);
	}
	else 
	{
		printf("找到目标\n");
		p = L1;
		for (i = 1; i <= n; i++)
		{
			if (p->data == t)break;
			else
				p = p->next;
		}
		printf("是第%d个节点", i-1);
		
	}
	DestroyList(&L1);
	printf("\n");
}
void testReverseList() 
{
	LinkedList L1, L2, p;
	int i, n, t;
	InitList(&L1);
	p = L1;
	printf("你想要输入多少个的节点:");
	scanf("%d", &n);
	printf("输入你想要输入的内容:\n");
	for (i = 1; i <= n; i++)
	{
		printf("Please enter the data for No.%d node:", i);
		scanf("%d", &t);
		if (i == 0)
			L1->data = t;
		else
		{
			InitList(&L2);
			L2->data = t;
			InsertList(p, L2);
			p = p->next;
		}
	}
	printf("test ReverseList\n");
	printf("反转前:");
	p = L1;
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
	ReverseList(&L1);
	p = L1;
	printf("反转后:");
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n\n");
	DestroyList(&L1);
}
void testIsLoopList() 
{
	LinkedList L1, L2, p;
	int i, n, t;
	InitList(&L1);
	p = L1;
	printf("你想要输入多少个的节点:");
	scanf("%d", &n);
	printf("输入你想要输入的内容:\n");
	for (i = 1; i = n; i++)
	{
		printf("Please enter the data for No.%d node:", i);
		scanf("%d", &t);
		if (i == 0)
			L1->data = t;
		else
		{
			InitList(&L2);
			L2->data = t;
			InsertList(p, L2);
			p = p->next;
		}
	}
	if (IsLoopList(L1) == ERROR)
	{
		printf("链表不循环\n");
		exit(1);
	}
	else 
	{
		printf("链表循环\n");
	}
	printf("\n");
	DestroyList(&L1);
}
void testReverseEvenList() 
{
	LinkedList L1, L2, p;
	int i, n, t;
	InitList(&L1);
	p = L1;
	printf("你想要输入多少个的节点:");
	scanf("%d", &n);
	printf("输入你想要输入的内容:\n");
	for (i = 1; i = n; i++)
	{
		printf("Please enter the data for No.%d node:", i);
		scanf("%d", &t);
		if (i == 0)
			L1->data = t;
		else
		{
			InitList(&L2);
			L2->data = t;
			InsertList(p, L2);
			p = p->next;
		}
	}
	printf("test ReverseEvenList\n");
	printf("奇偶调换前:");
	p = L1;
	while (p != NULL) 
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
	L1 = ReverseEvenList(&L1);
	p = L1;
	printf("奇偶调换后:");
	while (p != NULL) 
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n\n");
	DestroyList(&L1);
}
void testFindMidNode() 
{
	LinkedList L1, L2, p;
	int i, n, t;
	InitList(&L1);
	p = L1;
	printf("你想要输入多少个的节点:");
	scanf("%d", &n);
	printf("输入你想要输入的内容:\n");
	for (i = 0; i < n; i++)
	{
		printf("Please enter the data for No.%d node:", i);
		scanf("%d", &t);
		if (i == 0)
			L1->data = t;
		else
		{
			InitList(&L2);
			L2->data = t;
			InsertList(p, L2);
			p = p->next;
		}
	}
	printf("尝试寻找中间节点\n");
	printf("L1:");
	p = L1;
	while (p != NULL) 
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
	p = FindMidNode(&L1);
	printf("中间节点数据为: %d\n\n", p->data);
	DestroyList(&L1);
}
int main() 
{
	int ch,flag;
	flag = 1;
	while (flag != 0)
	{
		system("cls");
		printf("\n\n\n---------------------------\n");
		printf(">>> 1.初始化               \n");
		printf(">>> 2.插入                 \n");
		printf(">>> 3.搜索第一个含有e的节点\n");
		printf(">>> 4.反转                 \n");
		printf(">>> 5.检查是否循环         \n");
		printf(">>> 6.奇偶位置交换         \n");
		printf(">>> 7.找到中间数           \n");
		printf(">>> 8.结束程序             \n");
		printf("---------------------------\n");
		printf("若想要结束程序，请选择0");
		printf("----->>> 请输入你的选择（数字）:");
		scanf("%d", &ch);
		if (ch == 8)flag = 0;
		switch (ch)
		{
		case 1:testInitList(); system("pause"); break;
		case 2:testInsertList(); system("pause"); break;
		case 3:testSearchList(); system("pause"); break;
		case 4:testReverseList(); system("pause"); break;
		case 5:testIsLoopList(); system("pause"); break;
		case 6:testReverseEvenList(); system("pause"); break;
		case 7:testFindMidNode(); system("pause"); break;
		}
	}
	return 0;
}
