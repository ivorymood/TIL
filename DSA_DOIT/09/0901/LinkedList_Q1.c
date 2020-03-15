/* �����͸� ����� ���� ����Ʈ(�ҽ�) */
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Member.h"

/*--- ��带 �������� ���� ---*/
static Node* AllocNode(void)
{
	return calloc(1, sizeof(Node));
}

/*--- n�� ����Ű�� ����� �� ����� ���� ���� ----*/
static void SetNode(Node* n, const Member* x, const Node* next)
{
	n->data = *x;
	n->next = (Node*)next;
}

/*--- ���� ����Ʈ�� �ʱ�ȭ ---*/
void Initialize(List* list)
{
	list->head = NULL;
	list->crnt = NULL;
}

/*--- �Լ� compare�� x�� ���� ��带 �˻� ---*/
Node* search(List* list, const Member* x, int compare(const Member* x, const Member* y))
{
	// ��� ������ �˻�����
	Node* ptr = list->head;

	while (ptr != NULL)
	{
		// Ű ���� ���� �˻� ������ ���
		if (compare(&ptr->data, x) == 0)
		{
			list->crnt = ptr;
			return ptr;
		}
		// ���� ��� ����
		ptr = ptr->next;
	}
	// �˻� ����
	return NULL;
}

/*--- �Ӹ��� ��带 ���� ---*/
void InsertFront(List* list, const Member* x)
{
	// ptr_tmp�� ���� ��� ��尡 ����Ű�� ��� A�� ���� ������ ����
	Node* ptr_tmp = list->head;
	// ��� ���� ���� ��忡 �� ��� allocation
	list->head = list->crnt = AllocNode();
	SetNode(list->head, x, ptr_tmp);
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
		Node* ptr = list->head;
		while (ptr->next != NULL)
		{
			ptr = ptr->next;
		}
		// �� ������ ����� ������ �� ��� allocation
		ptr->next = list->crnt = AllocNode();
		SetNode(ptr->next, x, NULL);
	}
}

/*--- �Ӹ� ��带 ���� ---*/
void RemoveFront(List* list)
{
	if (list->head != NULL)
	{
		// ptr_tmp�� �� ��° ��忡 ���� ������ ����
		Node* ptr_tmp = (list->head)->next;
		free(list->head);
		list->head = list->crnt = ptr_tmp;
	}
}

/*--- ���� ��带 ���� ---*/
void RemoveRear(List* list)
{
	if (list->head != NULL)
	{
		// ��尡 �ϳ���� �Ӹ���� ����
		if ((list->head)->next == NULL)
		{
			RemoveFront(list);
		}
		else
		{
			//�� ������ ���� �ڿ��� 2��° ��� ã��
			Node* ptr = list->head;
			Node* pre = NULL;
			while (ptr->next != NULL)
			{
				pre = ptr;
				ptr = ptr->next;
			}

			pre->next = NULL;
			free(ptr);
			list->crnt = pre;
		}
	}
}

/*--- ������ ��带 ���� ---*/
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
			// ptr�� ���� ����� ���� ��� ����
			Node* ptr = list->head;
			while (ptr->next != list->crnt)
			{
				ptr = ptr->next;
			}

			// ptr->next�� ���� ����� ���� ��� ����
			ptr->next = list->crnt->next;
			free(list->crnt);
			list->crnt = ptr;
		}
	}
}

/*--- (Q1)���� ���� ��带, ���� ������ ��带 ����� ��� ���� ---*/
void Purge(List* list, int compare(const Member* x, const Member* y))
{
	Node* std_ptr = list->head;
	while (std_ptr != NULL)
	{
		Node* cmp_ptr = std_ptr;
		Node* cmp_pre = std_ptr;

		while (cmp_pre->next != NULL)
		{
			// ���� ���� pre����� ���� ���
			cmp_ptr = cmp_pre->next;
			
			// ������ pre����� next �� �񱳳���� ������� ����
			if (compare(&std_ptr->data, &cmp_ptr->data) == 0)
			{
				cmp_pre->next = cmp_ptr->next;
				free(cmp_ptr);
			}
			// �ٸ��� pre��� �ڷ� ��ĭ �ű��
			else
			{
				cmp_pre = cmp_ptr;
			}
		}
		std_ptr = std_ptr->next;
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

/*--- ������ ����� �����͸� ��� ---*/
void PrintCurrent(const List* list)
{
	if (list->crnt == NULL)
	{
		printf("������ ��尡 �����ϴ�.");
	}
	else
	{
		PrintMember(&list->crnt->data);
	}
}

/*--- ������ ����� �����͸� ���(�ٹٲ� ���� ����) ---*/
void PrintLnCurrent(const List* list)
{
	PrintCurrent(list);
	putchar('\n');
}

/*--- ��� ����� �����͸� ����Ʈ ������� ��� ---*/
void Print(const List* list)
{
	if (list->head == NULL)
	{
		puts("��尡 �����ϴ�.");
	}
	else
	{
		Node* ptr = list->head;
		puts("[ ��� ����]");
		while (ptr != NULL)
		{
			PrintMember(&ptr->data);
			ptr = ptr->next;
		}
	}
}

/*--- ���� ����Ʈ ���� ---*/
void Terminate(List* list)
{
	Clear(list);
}