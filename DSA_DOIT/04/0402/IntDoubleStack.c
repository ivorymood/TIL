/* 하나의 배열을 공유하는 2개의 int형 스택 IntDoubleStack (소스) */
#include <stdio.h>
#include <stdlib.h>
#include "IntDoubleStack.h"

/*--- 스택 초기화 ---*/
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

/*---앞쪽 스택에 데이터를 푸시---*/
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

/*---뒤쪽 스택에 데이터를 푸시---*/
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

/*--- 앞쪽 스택에서 데이터를 팝 ---*/
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

/*--- 뒤쪽 스택에서 데이터를 팝 ---*/
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

/*--- 앞쪽 스택에서 데이터를 피크 ---*/
int Peek_F(const IntDoubleStack* sF, int* x)
{
	if (sF->ptr <= 0)
		return -1;
	*x = sF->stk[sF->ptr - 1];
	return 0;
}

/*--- 뒤쪽 스택에서 데이터를 피크 ---*/
int Peek_T(const IntDoubleStack* sT, int* x)
{
	if (sT->ptr <= 0)
		return -1;
	*x = *(sT->stk - (sT->ptr - 1));
	return 0;
}

/*--- 앞쪽 스택 비우기 ---*/
void Clear_F(IntDoubleStack* sF, IntDoubleStack* sT)
{
	int sF_length = sF->ptr - 1;
	sF->ptr = 0;
	sT->max += sF_length;
}

/*--- 뒤쪽 스택 비우기 ---*/
void Clear_T(IntDoubleStack* sF, IntDoubleStack* sT)
{
	int sT_length = sT->ptr - 1;
	sT->ptr = 0;
	sF->max += sT_length;
}

/*--- 스택 용량 ---*/
int Capacity(const IntDoubleStack* s)
{
	return s->max;
}

/*--- 스택에 쌓여 있는 데이터 수 ---*/
int Size(const IntDoubleStack* s)
{
	return s->ptr;
}

/*--- 스택이 비어 있는가? ---*/
int IsEmpty(const IntDoubleStack* s)
{
	return s->ptr <= 0;
}

/*--- 스택은 가득 찼는가? ---*/
int IsFull(const IntDoubleStack* s)
{
	return s->ptr >= s->max;
}

/*--- 스택에서 검색 ---*/
int Search(const IntDoubleStack* s, int x)
{
	int i;

	for (i = s->ptr - 1; i >= 0; i--)	/* 꼭대기(top) → 바닥(bottom)으로 선형 검색 */
		if (s->stk[i] == x)
			return i;		/* 검색 성공 */
	return -1;				/* 검색 실패 */
}

/*--- 모든 데이터 표시 ---*/
void Print(const IntDoubleStack* s)
{
	int i;

	for (i = 0; i < s->ptr; i++)		/* 바닥(bottom) → 꼭대기(top)로 스캔 */
		printf("%d ", s->stk[i]);
	putchar('\n');
}

/*--- 스택 종료 ---*/
void Terminate(IntDoubleStack* sF, IntDoubleStack* sT)
{
	if (sF->stk != NULL)
		free(sF->stk);		/* 배열을 삭제 */
	sT->stk = NULL;
	sF->max = sF->ptr = sT->max = sT->ptr = 0;
}
