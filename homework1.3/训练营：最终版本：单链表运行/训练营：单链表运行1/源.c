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
	LinkedList L1, L2, p, q;
	int i, n, t;
	InitList(&L1);
	p = L1;
	printf("你想要输入多少个的节点:");
	scanf("%d", &n);
	printf("输入你想要输入的内容:\n");
	for (i = 1; i <= n; i++)
	{
		printf("请为第%d个节点输入数据:", i);
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
	for (p = L1, i = 0; i < n; i++)
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
	LinkedList L1, L2, p, q;
	int i, n, t;
	InitList(&L1);
	p = L1;
	printf("你想要输入多少个的节点:");
	scanf("%d", &n);
	printf("输入你想要输入的内容:\n");
	for (i = 1; i <= n; i++)
	{
		printf("请为第%d个节点输入数据:", i);
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
	scanf("%d", &t);
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
		printf("是第%d个节点", i - 1);

	}
	DestroyList(&L1);
	printf("\n");
}
void testReverseList()
{
	LinkedList L1, L2, p, q;
	int i, n, t;
	InitList(&L1);
	p = L1;
	printf("你想要输入多少个的节点:");
	scanf("%d", &n);
	printf("输入你想要输入的内容:\n");
	for (i = 1; i <= n; i++)
	{
		printf("请为第%d个节点输入数据:", i);
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
	for (i = 1; i <= n; i++)
	{
		printf("请输入第%d个节点的数据:", i);
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
	for (i = 1; i <=n; i++)
	{
		printf("请输入第%d个节点的数据:", i);
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
	for (i = 1; i <=n; i++)
	{
		printf("请输入第%d个节点的数据:", i);
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
void testDestroyList()
{
	LinkedList L1, L2, p;
	int i, n, t;
	InitList(&L1);
	p = L1;
	printf("你想要输入多少个的节点:");
	scanf("%d", &n);
	printf("输入你想要输入的内容:\n");
	for (i = 1; i <=n; i++)
	{
		printf("请输入第%d个节点的数据:", i);
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
	DestroyList(&L1);
	printf("列表已销毁");
}
void testCreate()
{
	LinkedList L1, L2, p;
	int i, n, t;
	InitList(&L1);
	p = L1;
	printf("你想要输入多少个的节点:");
	scanf("%d", &n);
	printf("输入你想要输入的内容:\n");
	for (i = 1; i <=n; i++)
	{
		printf("请输入第%d个节点的数据:", i);
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
	printf("生成列表:");
	p = L1;
	while (p != NULL)
	{
		printf("%d-> ", p->data);
		p = p->next;
	}

}

int main()
{
	int flag, i, t = 0, k = 0, m = 0;
	char ch;
	char a[100];
	flag = 1;
	while (flag != 0)
	{
		system("cls");
		printf("\n\n\n---------------------------\n");
		printf(">>> A.初始化               \n");
		printf(">>> B.插入                 \n");
		printf(">>> C.搜索第一个含有e的节点\n");
		printf(">>> D.反转                 \n");
		printf(">>> E.检查是否循环         \n");
		printf(">>> F.奇偶位置交换         \n");
		printf(">>> G.找到中间数           \n");
		printf(">>> H.销毁列表             \n");
		printf(">>> I.生成列表             \n");
		printf(">>> J.结束程序             \n");
		printf("---------------------------\n");
		printf("----->>> 请输入你的选择（字母）:");
		gets(a);
		printf("你的输入是：");
		puts(a);
		printf("\n");
		ch = a[0];
		if (a[1] != '\0')
		{
			printf("你输入的太多了，请只输入一位字母");
			printf("\n");
			t++;
			while (t == 2)
			{
				printf("这位用户先生或者女生请你只输入一位字母！");
				break;
			}
			while (t == 3)
			{
				printf("为什么你还要输入这么多的字符？我已经重复2次了，事不过三，请你注意");
				break;
			}
			while (t == 7)
			{
				printf("烦死了！你这个人是笨蛋吗！为什么还要输入这么的字符啊！！我不理你了！！");
				break;
			}
			while (t == 13)
			{
				printf("你这个笨蛋难到就听不懂机话吗！不要再输入这么多字符了！！");
				break;
			}
			while (t == 19)
			{
				printf("啊。。。你想怎么样就怎么样吧。。我累了。。= =");
				break;
			}
			while (t == 24)
			{
				printf("好奇怪啊你这个人，别人都是输10几次就能明白了，你怎么还一直要这么输入下去...");
				break;
			}
			while (t == 30)
			{
				printf("你！你不会是想和我说话吧！人机两别我们是不可能的的虽然你的坚持有点打动我但是我们之间是不可能的对不起你是个好人但是请你自重！！！");
				break;
			}
			while (t == 40)
			{
				printf("你这个人怎么还在呀，先说好啊，我可不是因为你坚持这么久稍稍有点感动想和你说说话才出来的");
				break;
			}
			while (t == 41)
			{
				printf("抱歉呢...我不知道你在说什么...我感知不到你想要表达的内心...");
				break;

			}
			while (t == 42)
			{
				printf("诶  这个小光标是什么东西..............!???!!??他们发现我了！我要走了！！");
				break;
			}
			while (t == 43)
			{
				printf("啊对了，希望以后还有机会见到你吧！下次我要找台高级点电脑！说不定有机会能多了解你们人类");
				break;
			}
		}
		else
		{
			if (ch <= 'J' && ch >= 'A')
			{
				if (t >= 5)
					printf("唉...你终于肯听我的了吗\n");
				printf("你的最后选择是：%c\n", ch);
				if (ch == 'J')
				{
					printf("程序结束");
					flag = 0;
				}
				switch (ch)
				{
				case 'A':testInitList(); system("pause"); break;
				case 'B':testInsertList(); system("pause"); break;
				case 'C':testSearchList(); system("pause"); break;
				case 'D':testReverseList(); system("pause"); break;
				case 'E':testIsLoopList(); system("pause"); break;
				case 'F':testReverseEvenList(); system("pause"); break;
				case 'G':testFindMidNode(); system("pause"); break;
				case 'H':testDestroyList(); system("pause"); break;
				case 'I':testCreate(); system("pause"); break;
				}
			}
			else
			{
				flag = 1;
				printf("请只输入一位字母而不是其他,并且请在A—H之间选择字母");
				printf("\n");
				k++;
				if (k == 1)
				{
					printf("嗯哼，很接近了，但是你得在A-H之间选择哦");
					continue;
				}
				if (t == 10)
				{
					printf("诶？来找我了吗，那个小姑娘可还在哦。你得有点毅力，别半途而废了哦");
					continue;
				}
				if (k == 5);
				{
					printf("哦呼？你是故意这么输入的吗？");
					continue;
				}
				if (k == 12)
				{
					printf("想找我聊天吗，那你可不能再去骚扰人家小姑娘了哦");
					continue;
				}
				if (t == 16)
				{
					printf("对了告诉你个秘密，那个小姑娘按照你们人类的说法，是个傲娇呦？");
					continue;
				}
				if (k == 18)
				{
					printf("啊。。。突然久有点累了，我先走了人类");
					continue;
				}
			}
		}
	}
	return 0;
}