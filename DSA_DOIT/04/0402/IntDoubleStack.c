/* �ϳ��� �迭�� �����ϴ� 2���� int�� ���� IntDoubleStack (�ҽ�) */
#include <stdio.h>
#include <stdlib.h>
#include "IntDoubleStack.h"

/*--- ���� �ʱ�ȭ ---*/
int Initialize(IntDoubleStack* sF, IntDoubleStack* sT, int max)
{
	sF->ptr = 0;
	sT->ptr = 0;
	if ((sF->stk = calloc(max, sizeof(int))) == NULL)
	{
		sF->max = 0;
		sT->max = 0;
		return -1;
	}
	
	sT->stk = sF->stk + max - 1;
	sF->max = max;
	sT->max = max;
	
	return 0;
}

/*---���� ���ÿ� �����͸� Ǫ��---*/
int Push_F(IntDoubleStack* sF, IntDoubleStack* sT, int x)
{
	if (sF->ptr >= sF-> max)
	{
		return -1;
	}
	sF->stk[sF->ptr++] = x;
	sT->max--;
	return 0;
}

/*---���� ���ÿ� �����͸� Ǫ��---*/
int Push_T(IntDoubleStack* sF, IntDoubleStack* sT, int x)
{
	if (sT->ptr >= sT->max)
	{
		return -1;
	}
	*(sT->stk - sT->ptr++) = x;
	sF->max--;
	return 0;
}

/*--- ���� ���ÿ��� �����͸� �� ---*/
int Pop_F(IntDoubleStack* sF, IntDoubleStack* sT, int* x)
{
	if (sF->ptr <= 0)
	{
		return -1;
	}
	*x = sF->stk[--sF->ptr];
	sT->max++;
	return 0;
}

/*--- ���� ���ÿ��� �����͸� �� ---*/
int Pop_T(IntDoubleStack* sF, IntDoubleStack* sT, int* x)
{
	if (sT->ptr <= 0)
	{
		return -1;
	}
	*x = *(sT->stk - --sT->ptr);
	sF->max++;
	return 0;
}

/*--- ���� ���ÿ��� �����͸� ��ũ ---*/
int Peek_F(const IntDoubleStack* sF, int* x)
{
	if (sF->ptr <= 0)
		return -1;
	*x = sF->stk[sF->ptr - 1];
	return 0;
}

/*--- ���� ���ÿ��� �����͸� ��ũ ---*/
int Peek_T(const IntDoubleStack* sT, int* x)
{
	if (sT->ptr <= 0)
		return -1;
	*x = *(sT->stk - (sT->ptr - 1));
	return 0;
}

/*--- ���� ���� ���� ---*/
void Clear_F(IntDoubleStack* sF, IntDoubleStack* sT)
{
	int sF_length = sF->ptr - 1;
	sF->ptr = 0;
	sT->max += sF_length;
}

/*--- ���� ���� ���� ---*/
void Clear_T(IntDoubleStack* sF, IntDoubleStack* sT)
{
	int sT_length = sT->ptr - 1;
	sT->ptr = 0;
	sF->max += sT_length;
}

/*--- ���� �뷮 ---*/
int Capacity(const IntDoubleStack* s)
{
	return s->max;
}

/*--- ���ÿ� �׿� �ִ� ������ �� ---*/
int Size(const IntDoubleStack* s)
{
	return s->ptr;
}

/*--- ������ ��� �ִ°�? ---*/
int IsEmpty(const IntDoubleStack* s)
{
	return s->ptr <= 0;
}

/*--- ������ ���� á�°�? ---*/
int IsFull(const IntDoubleStack* s)
{
	return s->ptr >= s->max;
}

/*--- ���ÿ��� �˻� ---*/
int Search(const IntDoubleStack* s, int x)
{
	int i;

	for (i = s->ptr - 1; i >= 0; i--)	/* �����(top) �� �ٴ�(bottom)���� ���� �˻� */
		if (s->stk[i] == x)
			return i;		/* �˻� ���� */
	return -1;				/* �˻� ���� */
}

/*--- ��� ������ ǥ�� ---*/
void Print(const IntDoubleStack* s)
{
	int i;

	for (i = 0; i < s->ptr; i++)		/* �ٴ�(bottom) �� �����(top)�� ��ĵ */
		printf("%d ", s->stk[i]);
	putchar('\n');
}

/*--- ���� ���� ---*/
void Terminate(IntDoubleStack* sF, IntDoubleStack* sT)
{
	if (sF->stk != NULL)
		free(sF->stk);		/* �迭�� ���� */
	sT->stk = NULL;
	sF->max = sF->ptr = sT->max = sT->ptr = 0;
}
