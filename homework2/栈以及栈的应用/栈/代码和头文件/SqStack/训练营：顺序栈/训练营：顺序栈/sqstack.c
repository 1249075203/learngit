#include"sqstack.h"
#include <stdio.h>
#include <stdlib.h>
Status initStack(SqStack* s, int sizes)
{
    s->elem = (ElemType*)malloc(sizes * sizeof(ElemType));
    if (sizes <= 0)
    {
        printf("栈的大小必须大于0\n");
        return ERROR;
    }
    else
    {
        s->size = sizes; 
        s->top = -1; 
        printf("成功建立一个大小为%d的栈.\n", sizes);
        return SUCCESS;
    }
}
Status isEmptyStack(SqStack* s)
{
    if (test(s))
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
Status getTopStack(SqStack* s, ElemType* e)
{
    if (test(s))
    {
        printf("栈内无元素\n");
        return ERROR;
    }
    else
    {
        *e = s->elem[s->top];
        printf("栈内顶部元素是 %d.\n", *e);
        return SUCCESS;
    }
}
Status clearStack(SqStack* s)
{
    if (s == NULL)
    {
        printf("栈为空，无需清空\n");
        return ERROR;
    }
    else
    {
        s->top = -1;
        printf("成功清空栈\n");
        return SUCCESS;
    }
}
Status destroyStack(SqStack* s)
{
    free(s->elem);
    s->elem = NULL;
    printf("成功销毁栈\n");
    return SUCCESS;

}
Status stackLength(SqStack* s, int* length)
{
    if (test(s))
    {
        printf("栈为空，长度为0\n");
        return ERROR;
    }
    else
    {
        *length = s->top + 1;
        printf("栈高度为：%d.\n", *length);
        return SUCCESS;
    }
}
Status pushStack(SqStack* s, ElemType data)
{
    if (s == NULL || (s->size <= s->top + 1))
    {
        printf("栈已经满了，无法继续添加元素\n");
        return ERROR;
    }
    else
    {
        s->top = s->top + 1;
        s->elem[s->top] = data;
        printf("成功将%d放入栈\n", data);
        return SUCCESS;
    }
}
Status popStack(SqStack* s, ElemType* data)
{
    if (test(s))
    {
        printf("栈内无元素可弹出\n");
        return ERROR;
    }
    else
    {
        *data = s->elem[s->top];
        s->top = s->top-1;
        printf("成功将%d从栈内弹出\n", *data);
        return SUCCESS;
    }
}
Status print(SqStack* s)
{
	int i;
	if (test(s))
	{
		printf("栈为空");
		return ERROR;
	}
	else if (s->size == 0)
	{
		printf("栈内无元素");
		return ERROR;
	}
	else
	{
		for (i = 0; i <= s->top; i++)printf("%d|", s->elem[i]);
	}
	printf("\n");
	return SUCCESS;
}
int InputNumber()
{
	int i;
	scanf_s("%d", &i);
	return i;
}
Status test(SqStack* s)//检测栈是否为空或者不存在
{
    if (s == NULL || s->top == -1)
        return SUCCESS;
    else
        return ERROR;
}
