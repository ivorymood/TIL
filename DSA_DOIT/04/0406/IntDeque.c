#include <stdio.h>
#include <stdlib.h>
#include "IntDeque.h"

/*--- ť �ʱ�ȭ ---*/
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

/*--- ���� ť�� �����͸� ��ť ---*/
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

/*--- ���� ť�� �����͸� ��ť ---*/
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

/*--- ���� ť���� �����͸� ��ť ---*/
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

/*--- ���� ť���� �����͸� ��ť ---*/
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

/*--- ���� ť���� �����͸� ��ũ ---*/
int PeekFront(const IntDequeue* q, int* x)
{
	if (q->num <= 0)
	{
		return -1;
	}
	*x = q->que[q->front];
	return 0;
}

/*--- ���� ť���� �����͸� ��ũ ---*/
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

/*--- ��� �����͸� ���� ---*/
void Clear(IntDequeue* q)
{
	q->num = q->front = q->rear = 0;
}

/*--- ť�� �ִ� �뷮 ---*/
int Capacity(const IntDequeue* q)
{
	return q->max;
}

/*--- ť�� ����� �������� ���� ---*/
int Size(const IntDequeue* q)
{
	return q->num;
}

/*--- ť�� ��� �ִ°�? ---*/
int IsEmpty(const IntDequeue* q)
{
	return q->num <= 0;
}

/*--- ť�� ���� á�°�? ---*/
int IsFull(const IntDequeue* q)
{
	return q->num >= q->max;
}

/*--- ť���� �˻� ---*/
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

/*--- ť���� �˻� ---*/
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

/*--- ��� ������ ��� ---*/
void Print(const IntDequeue* q)
{
	for (int i = 0; i < q->num; ++i)
	{
		printf("%d\t", q->que[(i + q->front) % q->max]);
	}
	putchar('\n');
}

/*--- ť ���� ---*/
void Terminate(IntDequeue* q)
{
	if (q->que != NULL) free(q->que);
	q->max = q->num = q->front = q->rear = 0;
}
