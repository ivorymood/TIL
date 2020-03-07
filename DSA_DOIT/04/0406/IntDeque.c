#include <stdio.h>
#include <stdlib.h>
#include "IntDeque.h"

/*--- 큐 초기화 ---*/
int Initialize(IntDequeue* q, int max)
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

/*--- 앞쪽 큐에 데이터를 인큐 ---*/
int EnqueFront(IntDequeue* q, int x)
{
	if (q->num >= q->max)
	{
		return -1;
	}

	q->num++;
	if (--q->front < 0)
	{
		q->front = q->max - 1;
	}
	q->que[q->front] = x;
	return 0;
}

/*--- 뒤쪽 큐에 데이터를 인큐 ---*/
int EnqueRear(IntDequeue* q, int x)
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

/*--- 앞쪽 큐에서 데이터를 디큐 ---*/
int DequeFront(IntDequeue* q, int* x)
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

/*--- 뒤쪽 큐에서 데이터를 디큐 ---*/
int DequeRear(IntDequeue* q, int* x)
{
	if (q->num <= 0)
	{
		return -1;
	}

	q->num--;
	if (--q->rear < 0)
	{
		q->rear = q->max - 1;
	}
	*x = q->que[q->rear];
	return 0;
}

/*--- 앞쪽 큐에서 데이터를 피크 ---*/
int PeekFront(const IntDequeue* q, int* x)
{
	if (q->num <= 0)
	{
		return -1;
	}
	*x = q->que[q->front];
	return 0;
}

/*--- 뒤쪽 큐에서 데이터를 피크 ---*/
int PeekRear(const IntDequeue* q, int* x)
{
	if (q->num <= 0)
	{
		return -1;
	}

	int r = q->rear - 1;
	if (r < 0)
	{
		r = q->max - 1;
	}

	*x = q->que[r];
	return 0;
}

/*--- 모든 데이터를 삭제 ---*/
void Clear(IntDequeue* q)
{
	q->num = q->front = q->rear = 0;
}

/*--- 큐의 최대 용량 ---*/
int Capacity(const IntDequeue* q)
{
	return q->max;
}

/*--- 큐에 저장된 데이터의 개수 ---*/
int Size(const IntDequeue* q)
{
	return q->num;
}

/*--- 큐가 비어 있는가? ---*/
int IsEmpty(const IntDequeue* q)
{
	return q->num <= 0;
}

/*--- 큐가 가득 찼는가? ---*/
int IsFull(const IntDequeue* q)
{
	return q->num >= q->max;
}

/*--- 큐에서 검색 ---*/
int Search(const IntDequeue* q, int x)
{
	for (int i = 0; i < q->num; i++) {
		if (q->que[(i + q->front) % q->max] == x)
		{
			return i;
		}
	}
	return -1;
}

/*--- 큐에서 검색 ---*/
int Search2(const IntDequeue* q, int x)
{
	for (int i = 0; i < q->num; i++)
	{
		if (q->que[(i + q->front) % q->max] == x)
		{
			return i;
		}
	}
	return -1;
}

/*--- 모든 데이터 출력 ---*/
void Print(const IntDequeue* q)
{
	for (int i = 0; i < q->num; ++i)
	{
		printf("%d\t", q->que[(i + q->front) % q->max]);
	}
	putchar('\n');
}

/*--- 큐 종료 ---*/
void Terminate(IntDequeue* q)
{
	if (q->que != NULL) free(q->que);
	q->max = q->num = q->front = q->rear = 0;
}
