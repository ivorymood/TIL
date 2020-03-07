#include <stdio.h>
#include "ArrayIntQueue.h"


/*--- 큐 초기화 ---*/
int Initialize(ArrayIntQueue* q, int max)
{
	q->num = 0;
	if ((q->que = calloc(max, sizeof(int))) == NULL)
	{
		q->max = 0;
		return -1;
	}
	q->max = max;
	return 0;
}

/*--- 큐에 데이터를 인큐 ---*/
int Enque(ArrayIntQueue* q, int x)
{
	if (q->num >= q->max)
	{
		return -1;
	}
	q->que[q->num++] = x;
	return 0;
}

/*--- 큐에서 데이터를 디큐 ---*/
int Deque(ArrayIntQueue* q, int* x)
{
	if (q->num <= 0)
	{
		return -1;
	}

	*x = q->que[0];
	for (int i = 1; i < q->num - 1; ++i)
	{
		q->que[i - 1] = q->que[i];
	}
	q->num--;

	return 0;
}

/*--- 큐에서 데이터를 피크 ---*/
int Peek(const ArrayIntQueue* q, int* x)
{
	if (q->num <= 0)
	{
		return -1;
	}
	*x = q->que[0];
	return 0;
}

/*--- 모든 데이터를 삭제 ---*/
void Clear(ArrayIntQueue* q)
{
	q->num = 0;
}

/*--- 큐의 최대 용량 ---*/
int Capacity(const ArrayIntQueue* q)
{
	return q->max;
}

/*--- 큐에 저장된 데이터의 개수 ---*/
int Size(const ArrayIntQueue* q)
{
	return q->num;
}

/*--- 큐가 비어 있는가? ---*/
int IsEmpty(const ArrayIntQueue* q)
{
	return q->num <= 0;
}

/*--- 큐가 가득 찼는가? ---*/
int IsFull(const ArrayIntQueue* q)
{
	return q->num >= q->max;
}

/*--- 큐에서 검색 ---*/
int Search(const ArrayIntQueue* q, int x)
{
	for (int i = 0; i < q->num; ++i)
	{
		if (q->que[i] == x)
		{
			return i;
		}
	}
	return -1;
}

/*--- 모든 데이터 출력 ---*/
void Print(const ArrayIntQueue* q)
{
	for (int i = 0; i < q->num; ++i)
	{
		printf("%d", q->que[i]);
	}
	putchar('\n');
}

/*--- 큐 종료 ---*/
void Terminate(ArrayIntQueue* q)
{
	if (q->que != NULL) free(q->que);
	q->max = q->num = 0;
}