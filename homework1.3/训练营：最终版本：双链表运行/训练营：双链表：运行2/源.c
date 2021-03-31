#include <stdio.h>
#include <stdlib.h>
#include "duLinkedList.h"
static int* head;
int flag = 0;
void testcreate()
{
    int n;
    static int* head;
    printf("输入链表长度:");
    scanf("%d", &n);
    head = Create(n);
    printf("你输入的链表是：");
    TraverseList_DuL(head, visit);
}
void testvisit()
{
    int n;
    printf("输入链表长度:");
    scanf("%d", &n);
    head = Create(n);
    printf("你输入的链表是：");
    TraverseList_DuL(head, visit);
    
}
void testInitList()
{
    head = InitList_DuL(head);
   
}
void testDestroyList()
{
    if (flag)
    {
        DestroyList_DuL(head);
        flag = 0;
    }
    else
    {
        printf("链表已销毁.\n");
    }
}
void testinsertbefore()
{
    int n, t, i;
    DuLinkedList L2, q, p;
    printf("输入链表长度:");
    scanf("%d", &n);
    head = Create(n);//建立链表
    printf("你输入的链表：");
    TraverseList_DuL(head, visit);
    printf("\n");
    printf("输入你想要插入的数据：");
    scanf("%d", &t);
    L2 = (DuLinkedList)malloc(sizeof(DuLNode));
    L2->next = NULL;
    L2->data = t;
    q = L2;
    printf("你想要在哪个数据前插入：");
    scanf("%d", &t);
    for (p = head, i = 1; i <= n; i++)
    {
        if (p->data == t)
            break;
        p = p->next;
        while (i == n && p->data != t)
        {
            printf("没有找到你想要的节点");
            break;
        }
    }
    InsertBeforeList_DuL(p, q);
    printf("插入后链表：");
    TraverseList_DuL(head, visit);
    printf("\n\n");
}
void testinsertafter()
{
    int n, t, i;
    DuLinkedList L2, q, p;
    printf("输入链表长度:");
    scanf("%d", &n);
    head = Create(n);//建立链表
    printf("你输入的链表：");
    TraverseList_DuL(head, visit);
    printf("\n");
    printf("输入你想要插入的数据：");
    scanf("%d", &t);
    L2 = (DuLinkedList)malloc(sizeof(DuLNode));
    L2->next = NULL;
    L2->data = t;
    q = L2;
    printf("你想要在哪个数据后插入：");
    scanf("%d", &t);
    for (p = head, i = 1; i <= n; i++)
    {
        if (p->data == t)
            break;
        p = p->next;
        while (i == n && p->data != t)
            printf("没有找到你想要的节点");
    }
    InsertAfterList_DuL(p, q);
    printf("插入后链表：");
    TraverseList_DuL(head, visit);
    printf("\n\n");
}
void deletefirst()
{
    int n, t, i;
    DuLinkedList L2, q, p;
    printf("输入链表长度:");
    scanf("%d", &n);
    head = Create(n);//建立链表
    printf("你输入的链表：");
    TraverseList_DuL(head, visit);
    printf("\n");
    printf("你想要删去哪个节点后的节点：");
    scanf("%d", &t);
    for (p = head, i = 1; i <= n; i++)
    {
        if (p->data == t)
            break;
        p = p->next;
        while (i == n)
            printf("没有找到你想要的节点");
    }
    DeleteList_DuL(p, t);
    printf("删去的值是：%d", t);
    printf("删去后的链表：");
    TraverseList_DuL(head, visit);
    printf("\n\n");
    system("pause");
}

int main()
{
    static int* head;
    int flag = 0,t=0,k=0;
    char ch,a[100];
    flag = 1;
    while (flag != 0)
    {
        system("cls");
        printf("\n\n\n---------------------------\n");
        printf(">>> A.建立链表             \n");
        printf(">>> B.输出链表             \n");
        printf(">>> C.初始化链表.          \n");
        printf(">>> D.销毁链表             \n");
        printf(">>> E.在p前插入q           \n");
        printf(">>> F.在p后插入q           \n");
        printf(">>> G.删除p后第一个节点     \n");
        printf(">>> H.退出程序             \n");
        printf("---------------------------\n");
        printf("---------------------------\n");
        printf("----->>> 请输入你的选择:");
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
                case 'A':testcreate(); system("pause"); break;
                case 'B':testvisit(); system("pause"); break;
                case 'C':testInitList(); system("pause"); break;
                case 'D':testDestroyList(); system("pause"); break;
                case 'E':testinsertbefore(); system("pause"); break;
                case 'F':testinsertafter(); system("pause"); break;
                case 'G':deletefirst(); system("pause"); break;
                case 'H':flag = 0; system("pause"); break;
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