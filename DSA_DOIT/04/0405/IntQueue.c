/* int형 큐 IntQueue(소스) */
#include <stdio.h>
#include <stdlib.h>
#include "IntQueue.h"


/*--- 큐 초기화 ---*/
int Initialize(IntQueue* q, int max)
{
	q->num = q->front = q->rear = 0;
	if ((q->que = calloc(max, sizeof(int))) == NULL)
	{
		q->max = 0;
		return -1;
	}
	q->max = max;
	return 0;
}

/*--- 큐에 데이터를 인큐 ---*/
int Enque(IntQueue* q, int x)
{
	if (q->num >= q->max)
	{
		return -1;
	}

	q->num++;
	q->que[q->rear++] = x;
	if (q->rear == q->max)
	{
		q->rear = 0;
	}
	return 0;
}

/*--- 큐에서 데이터를 디큐 ---*/
int Deque(IntQueue* q, int* x)
{
	if (q->num <= 0)
	{
		return -1;
	}

	q->num--;
	*x = q->que[q->front++];
	if (q->front == q->max)
	{
		q->front = 0;
	}
	return 0;
}

/*--- 큐에서 데이터를 피크 ---*/
int Peek(const IntQueue* q, int* x)
{
	if (q->num <= 0)
	{
		return -1;
	}
	*x = q->que[q->front];
	return 0;
}

/*--- 모든 데이터를 삭제 ---*/
void Clear(IntQueue* q)
{
	q->num = q->front = q->rear = 0;
}

/*--- 큐의 최대 용량 ---*/
int Capacity(const IntQueue* q)
{
	return q->max;
}

/*--- 큐에 저장된 데이터의 개수 ---*/
int Size(const IntQueue* q)
{
	return q->num;
}

/*--- 큐가 비어 있는가? ---*/
int IsEmpty(const IntQueue* q)
{
	return q->num <= 0;
}

/*--- 큐가 가득 찼는가? ---*/
int IsFull(const IntQueue* q)
{
	return q->num >= q->max;
}

/*--- 큐에서 검색 ---*/
int Search(const IntQueue* q, int x)
{
	int idx;
	for (int i = 0; i < q->num; ++i)
	{
		if (q->que[idx = (i + q->front) % q->max] == x)
		{
			return idx;
		}
	}
	return -1;
}

int Search2(const IntQueue* q, int x)
{
	for (int i = 0; i < q->num; ++i)
	{
		if (q->que[(i + q->front) % q->max] == x)
		{
			return i;
		}
	}
	return -1;
}

/*--- 모든 데이터 출력 ---*/
void Print(const IntQueue* q)
{
	for (int i = 0; i < q->num; ++i)
	{
		printf("%d", q->que[(i + q->front) % q->max]);
	}
	putchar('\n');
}

/*--- 큐 종료 ---*/
void Terminate(IntQueue* q)
{
	if (q->que != NULL) free(q->que);
	q->max = q->num = q->front = q->rear = 0;
}