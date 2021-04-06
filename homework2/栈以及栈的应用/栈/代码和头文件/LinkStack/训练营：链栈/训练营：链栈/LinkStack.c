#include<stdio.h>
#include<stdlib.h>
#include"LinkStack.h"

Status initLStack(LinkStack* s)//初始化栈
{
    s->top = (StackNode*)malloc(sizeof(StackNode));
    if (!s->top)
        return ERROR;
    s->top = NULL;
    s->count = 0;
    printf("成功初始化链栈\n");
    return SUCCESS;
}
Status isEmptyLStack(LinkStack* s)//判断是否为空
{
    if (s->top == NULL)
    {
        printf("栈为空\n");
        return SUCCESS;
    }
    else 
    {
        printf("栈不为空\n");
        return ERROR;
    }
}
Status getTopLStack(LinkStack* s, ElemType* e)
{
    if (isEmptyLStack(s) == SUCCESS)
    {
        return ERROR;
    }
    *e = s->top->data;
    printf("栈顶元素为：%d\n", *e);
    return SUCCESS;
}
Status clearLStack(LinkStack* s)
{
    StackNode* p = NULL,*q;
    if (isEmptyLStack(s) == SUCCESS)
    {
        return ERROR;
    }
    p = s->top;
    while (p)
    {
        q = p->next;
        free(p);
        p = q;
    }
    s->count = 0;
    printf("成功清空栈\n");
    return SUCCESS;
}
Status destroyLStack(LinkStack* s)
{
    StackNode* p = NULL, * q;
    if (isEmptyLStack(s) == SUCCESS)
    {
        return ERROR;
    }
    p = s->top;
    for (int i = s->count; i > 0; i--)
    {
        q = p->next;
        free(q);
        p = q;
    }
    s->count = 0;
    printf("栈已经被销毁\n");
    return SUCCESS;
}
Status LStackLength(LinkStack* s, int* length)
{
    if (isEmptyLStack(s) == SUCCESS)
    {
        return ERROR;
    }
    *length = s->count;
    printf("栈的长度为：%d\n", *length);
    return SUCCESS;
}
Status pushLStack(LinkStack* s, ElemType data)
{
    StackNode* p = (StackNode*)malloc(sizeof(StackNode));
    if (!p)return ERROR;
    p->data = data;
    p->next = s->top;
    s->top = p;
    s->count++;
    printf("成功将%d放入栈\n", data);
    return SUCCESS;
}
Status popLStack(LinkStack* s, ElemType* data)
{
    if (isEmptyLStack(s) == SUCCESS)
    {
        return ERROR;
    }
    StackNode* p;
    p = s->top;
    *data = p->data;
    s->top = p->next;
    s->count--;
    free(p);
    printf("成功将%d从栈中去除\n", *data);
    return SUCCESS;
}
Status print(LinkStack* s)
{
    int i;
    StackNode* p=s->top;
    if (isEmptyLStack(s) == SUCCESS)
    {
        return ERROR;
    }
    else if (s->count == 0)
    {
        return ERROR;
    }
    for (i = s->count; i > 0; i--)
    {
        printf("|%d", p->data);
        p = p->next;
    }
    printf("\n");
    return SUCCESS;
}

