#include<stdio.h>
#include<stdlib.h>
#include"LinkStack.h"
int main()
{
    int flag = 0, t = 0, k = 0;
    char ch;
    char a[100];
    LinkStack* head = (LinkStack*)malloc(sizeof(StackNode));
    head->count = 0;
    while (1)
    {
        system("cls");
        printf("                         \n\n");
        printf("---------------------------\n");
        printf(">>> A.初始化栈             \n");
        printf(">>> B.向栈内放入元素       \n");
        printf(">>> C.从栈中弹出元素       \n");
        printf(">>> D.清除栈内元素         \n");
        printf(">>> E.销毁栈               \n");
        printf(">>> F.检测栈的长度         \n");
        printf(">>> G.检测栈是否为空       \n");
        printf(">>> H.输出栈顶部元素       \n");
        printf(">>> I.退出程序             \n");
        printf("---------------------------\n");
        printf("目前栈内状况:");
        print(head);
        printf("---------------------------\n");
        printf("请输入的你的选择（字母）");
        gets(a);
        printf("你的输入是：");
        puts(a);
        printf("\n");
        ch = a[0];
        if (a[1] != '\0')
        {
            printf("你输入的太多了，请只输入一位字母");
            printf("\n");
            system("pause");
        }
        else
        {
            if (ch <= 'I' && ch >= 'A')
            {
                switch (ch)
                {
                case 'A':
                    initLStack(head);
                    flag = 1;
                    break;
                case 'B':
                    if (flag == 1)
                    {
                        int k;
                        printf("请输入你想要放入的数据:");
                        scanf_s("%d", &k);
                        printf("%d", k);
                        pushLStack(head, k);
                    }
                    else
                    {
                        printf("尚未初始化或者栈为空\n");
                    }
                    break;
                case 'C':
                    if (flag == 1)
                    {
                        ElemType* e = (ElemType*)malloc(sizeof(ElemType));
                        popLStack(head, e);
                    }
                    else
                    {
                        printf("尚未初始化或者栈为空\n");
                    }
                    break;
                case 'D':
                    if (flag == 1)
                    {
                        clearLStack(head);
                    }
                    else
                    {
                        printf("尚未初始化或者栈为空\n");
                    }
                    break;
                case 'E':
                    if (flag == 1)
                    {
                        destroyLStack(head);
                        flag = 0;
                    }
                    else
                    {
                        printf("尚未初始化或者栈为空\n");
                    }
                    break;
                case 'F':
                {
                    int* length = (int*)malloc(sizeof(int));
                    LStackLength(head, length);
                }
                break;
                case 'G':
                    if (flag == 1)
                    {
                        isEmptyLStack(head);
                    }
                    else
                    {
                        printf("尚未初始化或者栈为空\n");
                    }
                    break;
                case 'H':
                    if (flag == 1)
                    {
                        ElemType* e = (ElemType*)malloc(sizeof(ElemType));
                        getTopLStack(head, e);
                    }
                    else
                    {
                        printf("尚未初始化或者栈为空\n");
                    }
                    break;
                case 'I':
                    printf("程序结束\n");
                    exit(0);
                    break;
                }
                system("pause");
            }
            else
            {
                printf("请只输入一位字母而不是其他,并且请在A—I之间选择字母");
                printf("\n");
                system("pause");
            }
        }
    }
    return 0;
}

