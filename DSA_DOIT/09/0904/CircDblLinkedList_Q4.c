/* ���� ���� ���� ����Ʈ(�ҽ�) */
#include <stdio.h>
#include <stdlib.h>
#include "CircDblLinkedList.h"

/*--- �ϳ��� ��带 �������� ���� ---*/
static Dnode* AllocDNode(void)
{
	return calloc(1, sizeof(Dnode));
}

/*--- ����� �� ����� ���� ���� ----*/
static void SetDNode(Dnode* n, const Member* x, const Dnode* prev, const Dnode* next)
{
	n->data = *x;
	n->prev = prev;
	n->next = next;
}

/*--- ����Ʈ�� ����ִ°�? ---*/
static int IsEmpty(const Dlist* list)
{
	return list->head->next == list->head;
}

/*--- ����Ʈ�� �ʱ�ȭ ---*/
void Initialize(Dlist* list)
{
	Dnode* dummyNode = AllocDNode();
	list->head = list->crnt = dummyNode;
	dummyNode->prev = dummyNode->next = dummyNode;
}

/*--- �ָ����� �����͸� ��Ÿ�� ---*/
void PrintCurrent(const Dlist* list)
{
	if (IsEmpty(list))
	{
		printf("�ָ��尡 �����ϴ�.");
	}
	else
	{
		PrintMember(&list->crnt->data);
	}
}

/*--- �ָ����� �����͸� ��Ÿ��(�ٹٲ� ���� ����) ---*/
void PrintLnCurrent(const Dlist* list)
{
	PrintCurrent(list);
	putchar('\n');
}

/*--- �Լ� compare�� x�� ���� ��带 �˻� ---*/
Dnode* search(Dlist* list, const Member* x, int compare(const Member* x, const Member* y))
{
	// ���̳���� ���� ������ �˻�
	Dnode* ptr = list->head->next;
	while (ptr != list->head)
	{
		if (compare(&ptr->data, x) == 0)
		{
			list->crnt = ptr;
			return ptr;
		}
		ptr = ptr->next;
	}
	return NULL;
}

/*--- (Q4) �Ӹ����� n�� ���� ��忡 ���� ������ ��ȯ---*/
Dnode* Retrieve(Dlist* list, int n)
{
	// ���̳���� ���� ������ �˻�
	Dnode* ptr = list->head->next;
	while (n-- >= 0 && ptr != list->head)
	{
		if (n == 0)
		{
			list->crnt = ptr;
			return ptr;
		}
		ptr = ptr->next;
	}
	return NULL;
}

/*--- ��� ����� �����͸� ����Ʈ ������ ��Ÿ�� ---*/
void Print(const Dlist* list)
{
	if (IsEmpty(list))
	{
		puts("��尡 �����ϴ�.");
	}
	else
	{
		Dnode* ptr = list->head->next;
		puts("[ ��� ���� ]");
		while (ptr != list->head)
		{
			PrintLnMember(&ptr->data);
			ptr = ptr->next;
		}
	}
}

/*--- ��� ����� �����͸� ����Ʈ ���� �Ųٷ� ��Ÿ�� ---*/
void PrintReverse(const Dlist* list)
{
	if (IsEmpty(list))
	{
		puts("��尡 �����ϴ�.");
	}
	else
	{
		// ���̳���� ���� ���(= �� �� ���)���� �˻�
		Dnode* ptr = list->head->prev;
		puts("[ ��� ���� ]");
		while (ptr != list->head)
		{
			PrintLnMember(&ptr->data);
			ptr = ptr->prev;
		}
	}
}

/*--- �ָ��带 �ϳ� �������� ���ư����� ---*/
int Next(Dlist* list)
{
	if (IsEmpty(list) || list->crnt->next == list->head)
	{
		return 0;
	}
	list->crnt = list->crnt->next;
	return 1;
}

/*--- �ָ��带 �ϳ� �������� �ǵ��ư����� ---*/
int Prev(Dlist* list)
{
	if (IsEmpty(list) || list->crnt->prev == list->head)
	{
		return 0;
	}
	list->crnt = list->crnt->prev;
	return 1;
}

/*--- p�� ����Ű�� ��� �ٷ� �ڿ� ��带 ���� ---*/
void InsertAfter(Dlist* list, Dnode* p, const Member* x)
{
	Dnode* ptr_new = AllocDNode();
	Dnode* org_nxt = p->next;
	p->next = p->next->prev = ptr_new;
	SetDNode(ptr_new, x, p, org_nxt);
	list->crnt = ptr_new;
}

/*--- �Ӹ��� ��带 ���� ---*/
void InsertFront(Dlist* list, const Member* x)
{
	// ���̳�� �ٷ� �ڿ� ����
	InsertAfter(list, list->head, x);
}

/*--- ������ ��带 ���� ---*/
void InsertRear(Dlist* list, const Member* x)
{
	// ���̳���� �� ���(=�� �� ���) �ڿ� ����
	InsertAfter(list, list->head->prev, x);
}

/*--- p�� ����Ű�� ��带 ���� ---*/
void Remove(Dlist* list, Dnode* p)
{
	p->prev->next = p->next;
	p->next->prev = p->prev;
	list->crnt = p->prev;
	free(p);
	if (list->crnt == list->head)
	{
		list->crnt = list->head->next;
	}
}

/*--- �Ӹ���带 ���� ---*/
void RemoveFront(Dlist* list)
{
	if (!IsEmpty(list))
	{
		Remove(list, list->head->next);
	}
}

/*--- ������带 ���� ---*/
void RemoveRear(Dlist* list)
{
	if (!IsEmpty(list))
	{
		Remove(list, list->head->prev);
	}
}

/*--- �ָ��带 ���� ---*/
void RemoveCurrent(Dlist* list)
{
	if (list->crnt != list->head)
	{
		Remove(list, list->crnt);
	}
}

/*--- (Q4)���� ���� ��带, ���� ������ ��带 ����� ��� ���� ---*/
void Purge(Dlist* list, int compare(const Member* x, const Member* y))
{
	Dnode* ptr_std = list->head->next;
	while (ptr_std != list->head)
	{
		Dnode* ptr_nxt = ptr_std;
		Dnode* ptr = ptr_std;
		while (ptr->next != list->head)
		{
			ptr_nxt = ptr->next;
			if (compare(&ptr_std->data, &ptr_nxt->data) == 0)
			{
				ptr->next = ptr_nxt->next;
				free(ptr_nxt);
			}
			else
			{
				ptr = ptr_nxt;
			}
		}
		ptr_std = ptr_std->next;
	}
	list->crnt = list->head;
}

/*--- ��� ��带 ���� ---*/
void Clear(Dlist* list)
{
	while (!IsEmpty(list))
	{
		RemoveFront(list);
	}
}

/*--- ���� ���߿��� ����Ʈ�� ��ó�� ---*/
void Terminate(Dlist* list)
{
	Clear(list);
	free(list->head);
}