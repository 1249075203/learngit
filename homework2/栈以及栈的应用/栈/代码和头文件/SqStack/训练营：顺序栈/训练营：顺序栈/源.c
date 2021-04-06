#include <stdio.h>
#include <stdlib.h>
#include "sqstack.h"

int main()
{
    int flag = 0,t = 0, k = 0;
    char ch;
    char a[100];
    SqStack* head = (SqStack*)malloc(sizeof(SqStack)); 
    while (1)
    {
        system("cls");
        printf("                 \n\n");
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
        printf("\n");
        printf("---------------------------\n");
        printf("请输入你想要的选择(字母）:");
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
                printf("你的最后选择是：%c\n", ch);
                switch (ch)
                {
                case 'A': 
                {
                    {
                        head = (SqStack*)malloc(sizeof(SqStack));
                        printf("请输入栈的长的:");
                        initStack(head, InputNumber());
                    }
                    flag = 1; 
                }
                break;
                case 'B':
                {
                    if (flag == 1)
                    {
                        printf("输入你想要放入栈的数据:");
                        pushStack(head, InputNumber());
                    }
                    else
                    {
                        printf("尚未初始化栈\n");
                    }
                }
                break;
                case 'C':
                {
                    if (flag == 1)
                    {
                        ElemType* e = (ElemType*)malloc(sizeof(ElemType));
                        popStack(head, e);
                    }
                    else
                    {
                        printf("尚未初始化栈\n");
                    }
                }
                    break;
                case 'D':
                {
                    if (flag == 1)
                    {
                        clearStack(head);
                    }
                    else
                    {
                        printf("尚未初始化栈\n");
                    }
                }
                    break;
                case 'E':
                {
                    if (flag == 1)
                    {
                        destroyStack(head);
                        flag = 0;
                    }
                    else
                    {
                        printf("尚未初始化栈\n");
                    }
                }
                    break;
                case 'F':
                {
                    int* length = (int*)malloc(sizeof(int));
                    stackLength(head, length);
                }
                break;
                case 'G':
                {
                    if (flag == 1)
                    {
                        isEmptyStack(head);
                    }
                    else
                    {
                        printf("栈不存在\n");
                    }
                }
                    break;
                case 'H':
                {
                    if (flag == 1)
                    {
                        ElemType* e = (ElemType*)malloc(sizeof(ElemType));
                        getTopStack(head, e);
                    }
                    else
                    {
                        printf("栈不存在\n");
                    }
                }
                    break;
                case 'I':
                {
                    printf("程序结束");
                    exit(0);
                    break;
                }
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