#include <stdio.h>
#include <stdlib.h>
#include "duLinkedList.h"

int main()
{
    static int* head;// Head of DuLinkedList.
    int flag = 0; // Whether exist DuLinkedList.
    int ch;
    while (SUCCESS)
    {
        system("cls");
        printf("\n\n\n---------------------------\n");
        printf(">>> 1.建立链表             \n");
        printf(">>> 2.输出链表             \n");
        printf(">>> 3.初始化链表.          \n");
        printf(">>> 4.销毁链表             \n");
        printf(">>> 5.在p前插入q           \n");
        printf(">>> 6.在p后插入q           \n");
        printf(">>> 7.删除p后第一个节      \n");
        printf(">>> 8.推出程序             \n");
        printf("---------------------------\n");
        printf("---------------------------\n");
        printf("----->>> Please input your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
            {
        case 1:
        {
            int n;
            printf("输入链表长度:");
            scanf("%d", &n);
            head = Create(n);
            system("pause");
            break;
        }
        case 2:
        {   
            int n;
            printf("输入链表长度:");
            scanf("%d", &n);
            head = Create(n);
            TraverseList_DuL(head, visit);
            system("pause");
        }
            break;
        case 3:
        {
            head = InitList_DuL(head);
            system("pause");
        }
            break;
        case 4:
        {
            if (flag)
        {
            DestroyList_DuL(head);
            flag = 0;
        }
            else
            {
                printf("No LinkedList.\n");
                system("pause");
        }   
         }
            break;
        case 5:
        {
            int n,t,i;
            DuLinkedList L2,q,p;
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
                while (i == n)
                    printf("没有找到你想要的节点");
            }
            InsertBeforeList_DuL(p, q);
            printf("插入后链表：");
            TraverseList_DuL(head, visit);
            printf("\n\n");
            system("pause");
        }
            break;
        case 6:
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
                while (i == n)
                    printf("没有找到你想要的节点");
            }
            InsertAfterList_DuL(p, q);
            printf("插入后链表：");
            TraverseList_DuL(head, visit);
            printf("\n\n");
            system("pause");
        }
            break;
        case 7:
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
            printf("删去的值是：%d",t);
            printf("删去后的链表：");
            TraverseList_DuL(head, visit);
            printf("\n\n");
            system("pause");
        }

          break;
        case 8:
            exit(0);
        default:
            break;
            }
        }
        return 0;
    }
 
}