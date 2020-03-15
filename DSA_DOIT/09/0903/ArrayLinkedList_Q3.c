/* Ŀ���� ���� ���� ����Ʈ(�ҽ���) */
#include <stdio.h>
#include <stdlib.h>
#include "Member.h"
#include "ArrayLinkedList.h"

/*--- ������ ���ڵ��� �ε����� ���Ѵ�. ---*/
static Index GetIndex(List *list)
{
	if (list->deleted == NULL)
	{
		return ++(list->max);
	}
	else
	{
		// ��������Ʈ�� �Ӹ���� ���ϱ�
		Index rec = list->deleted;
		list->deleted = list->n[rec].Dnext;
		return rec;
	}
}

/*--- ������ ���ڵ带 ���� ����Ʈ�� ����Ѵ�. ---*/
static void DeleteIndex(List* list, Index idx)
{
	if (list->deleted == NULL)
	{
		list->deleted = idx;
		list->n[idx].Dnext = NULL;
	}
	else
	{
		// ��������Ʈ�� ���� �Ӹ���带 2��°�� �ű��
		// �Ű����� �ε����� ��������Ʈ�� ���ο� �Ӹ����� ����
		Index ptr_tmp = list->deleted;
		list->deleted = idx;
		list->n[idx].Dnext = ptr_tmp;
	}
}

/*--- n�� ����Ű�� ����� �� ����� ���� ���� ----*/
static void SetNode(Node* n, const Member* x, Index next)
{
	n->data = *x;
	n->next = next;
}

/*--- ���� ����Ʈ�� �ʱ�ȭ(���� ū ��ڼ��� size) ---*/
void Initialize(List* list, int size)
{
	list->n = calloc(size, sizeof(Node));
	list->head = NULL;
	list->crnt = NULL;
	list->max = NULL;
	list->deleted = NULL;
}

/*--- �Լ� compare�� ���� x�� ���� ������ �ǴܵǴ� ��带 �˻� ---*/
Index search(List* list, const Member* x, int compare(const Member* x, const Member* y))
{
	Index ptr = list->head;
	while (ptr != NULL)
	{
		if (compare(&list->n[ptr].data, x) == 0)
		{
			list->crnt = ptr;
			return ptr;
		}
		ptr = list->n[ptr].next;
	}
	return NULL;
}

/*--- (Q3) �Ӹ����� n�� ���� ��忡 ���� ������ ��ȯ---*/
Node* Retrieve(List* list, int n)
{
	Index ptr = list->head;
	while (n-- >= 0 && ptr != NULL)
	{
		if (n == 0)
		{
			list->crnt = ptr;
			return ptr;
		}
		ptr = list->n[ptr].next;
	}
	return NULL;
}

/*--- �Ӹ��� ��带 ���� ---*/
void InsertFront(List* list, const Member* x)
{
	// ���� ��� ���� �ι�°�� �ű��
	Index ptr_tmp = list->head;
	// ������ ���ڵ��� �ε����� ���ؼ� crnt�� head�� ����
	list->head = list->crnt = GetIndex(list);
	SetNode(&list->n[list->head], x, ptr_tmp);
}

/*--- ������ ��带 ���� ---*/
void InsertRear(List* list, const Member* x)
{
	if (list->head == NULL)
	{
		InsertFront(list, x);
	}
	else
	{
		// �� ������ ��� ã��
		Index ptr = list->head;
		while (list->n[ptr].next != NULL)
		{
			ptr = list->n[ptr].next;
		}
		// ������ ���ڵ��� �ε����� ���ؼ� crnt�� �� ���� ����� next�� ����
		list->n[ptr].next = list->crnt = GetIndex(list);
		SetNode(&list->n[list->n[ptr].next], x, NULL);
	}
}

/*--- �Ӹ���带 ���� ---*/
void RemoveFront(List* list)
{
	if (list->head != NULL)
	{
		// �Ӹ������ ���� ��带 �Ӹ����� �ű��
		Index ptr_tmp = list->n[list->head].next;
		DeleteIndex(list, list->head);
		list->head = list->crnt = ptr_tmp;
	}
}

/*--- ������带 ���� ---*/
void RemoveRear(List* list)
{
	if (list->head != NULL)
	{
		if (list->n[list->head].next = NULL)
		{
			RemoveFront(list);
		}
		else
		{
			// �� ������ ��带 ã�Ƽ� ����. 
			Index ptr = list->head;
			Index pre;
			while (list->n[ptr].next != NULL)
			{
				pre = ptr;
				ptr = list->n[ptr].next;
			}
			list->n[pre].next = NULL;
			DeleteIndex(list, ptr);
			list->crnt = ptr;
		}
	}
}

/*--- �ָ��带 ���� ---*/
void RemoveCurrent(List* list)
{
	if (list->head != NULL)
	{
		if (list->crnt == list->head)
		{
			RemoveFront(list);
		}
		else
		{
			// �ָ����� �� ��� ã��
			Index pre = list->head;
			while (list->n[pre].next != list->crnt)
			{
				pre = list->n[pre].next;
			}
			// �� ����� next�� �ָ����� next ���� 
			list->n[pre].next = list->n[list->crnt].next;
			DeleteIndex(list, list->crnt);
			list->crnt = pre;
		}
	}
}

/*--- (Q3)���� ���� ��带, ���� ������ ��带 ����� ��� ���� ---*/
void Purge(List* list, int compare(const Member* x, const Member* y))
{
	Index ptr_std = list->head;

	while (ptr_std != NULL)
	{
		Index ptr_nxt = ptr_std;
		Index ptr = ptr_std;

		while (list->n[ptr].next != NULL)
		{
			ptr_nxt = list->n[ptr].next;
			if (compare(&list->n[ptr_std].data, &list->n[ptr_nxt].data) == 0)
			{
				list->n[ptr].next = list->n[ptr_nxt].next;
				DeleteIndex(list, ptr_nxt);
			}
			else
			{
				ptr = ptr_nxt;
			}
		}
		ptr_std = list->n[ptr_std].next;
	}
	list->crnt = list->head;
}

/*--- ��� ��带 ���� ---*/
void Clear(List* list)
{
	while (list->head != NULL)
	{
		RemoveFront(list);
	}
	list->crnt = NULL;
}

/*--- �ָ����� �����͸� ��Ÿ�� ---*/
void PrintCurrent(const List* list)
{
	if (list->crnt == NULL)
	{
		printf("�ָ��尡 �����ϴ�.");
	}
	else
	{
		PrintMember(&list->n[list->crnt].data);
	}
}

/*--- �ָ����� �����͸� ��Ÿ��(�ٹٲ� ���� ����) ---*/
void PrintLnCurrent(const List* list)
{
	PrintCurrent(list);
	putchar('\n');
}

/*--- ��� ����� �����͸� ��Ÿ�� ---*/
void Print(const List* list)
{
	if (list->head == NULL)
	{
		puts("��尡 �����ϴ�.");
	}
	else
	{
		Index ptr = list->head;
		puts("[ ��� ���� ]");
		while (ptr != NULL)
		{
			PrintLnMember(&list->n[ptr].data);
			ptr = list->n[ptr].next;
		}
	}
}

/*--- ���� ����Ʈ�� ��ó�� ---*/
void Terminate(List* list)
{
	Clear(list);
	free(list->n);
}