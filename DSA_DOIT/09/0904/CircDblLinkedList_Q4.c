/* 원형 이중 연결 리스트(소스) */
#include <stdio.h>
#include <stdlib.h>
#include "CircDblLinkedList.h"

/*--- 하나의 노드를 동적으로 생성 ---*/
static Dnode* AllocDNode(void)
{
	return calloc(1, sizeof(Dnode));
}

/*--- 노드의 각 멤버에 값을 설정 ----*/
static void SetDNode(Dnode* n, const Member* x, const Dnode* prev, const Dnode* next)
{
	n->data = *x;
	n->prev = prev;
	n->next = next;
}

/*--- 리스트가 비어있는가? ---*/
static int IsEmpty(const Dlist* list)
{
	return list->head->next == list->head;
}

/*--- 리스트를 초기화 ---*/
void Initialize(Dlist* list)
{
	Dnode* dummyNode = AllocDNode();
	list->head = list->crnt = dummyNode;
	dummyNode->prev = dummyNode->next = dummyNode;
}

/*--- 주목노드의 데이터를 나타냄 ---*/
void PrintCurrent(const Dlist* list)
{
	if (IsEmpty(list))
	{
		printf("주목노드가 없습니다.");
	}
	else
	{
		PrintMember(&list->crnt->data);
	}
}

/*--- 주목노드의 데이터를 나타냄(줄바꿈 문자 붙임) ---*/
void PrintLnCurrent(const Dlist* list)
{
	PrintCurrent(list);
	putchar('\n');
}

/*--- 함수 compare로 x와 같은 노드를 검색 ---*/
Dnode* search(Dlist* list, const Member* x, int compare(const Member* x, const Member* y))
{
	// 더미노드의 다음 노드부터 검색
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

/*--- (Q4) 머리부터 n개 뒤의 노드에 대한 포인터 반환---*/
Dnode* Retrieve(Dlist* list, int n)
{
	// 더미노드의 다음 노드부터 검색
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

/*--- 모든 노드의 데이터를 리스트 순서로 나타냄 ---*/
void Print(const Dlist* list)
{
	if (IsEmpty(list))
	{
		puts("노드가 없습니다.");
	}
	else
	{
		Dnode* ptr = list->head->next;
		puts("[ 모두 보기 ]");
		while (ptr != list->head)
		{
			PrintLnMember(&ptr->data);
			ptr = ptr->next;
		}
	}
}

/*--- 모든 노드의 데이터를 리스트 순서 거꾸로 나타냄 ---*/
void PrintReverse(const Dlist* list)
{
	if (IsEmpty(list))
	{
		puts("노드가 없습니다.");
	}
	else
	{
		// 더미노드의 앞쪽 노드(= 맨 뒤 노드)부터 검색
		Dnode* ptr = list->head->prev;
		puts("[ 모두 보기 ]");
		while (ptr != list->head)
		{
			PrintLnMember(&ptr->data);
			ptr = ptr->prev;
		}
	}
}

/*--- 주목노드를 하나 뒤쪽으로 나아가도록 ---*/
int Next(Dlist* list)
{
	if (IsEmpty(list) || list->crnt->next == list->head)
	{
		return 0;
	}
	list->crnt = list->crnt->next;
	return 1;
}

/*--- 주목노드를 하나 앞쪽으로 되돌아가도록 ---*/
int Prev(Dlist* list)
{
	if (IsEmpty(list) || list->crnt->prev == list->head)
	{
		return 0;
	}
	list->crnt = list->crnt->prev;
	return 1;
}

/*--- p가 가리키는 노드 바로 뒤에 노드를 삽입 ---*/
void InsertAfter(Dlist* list, Dnode* p, const Member* x)
{
	Dnode* ptr_new = AllocDNode();
	Dnode* org_nxt = p->next;
	p->next = p->next->prev = ptr_new;
	SetDNode(ptr_new, x, p, org_nxt);
	list->crnt = ptr_new;
}

/*--- 머리에 노드를 삽입 ---*/
void InsertFront(Dlist* list, const Member* x)
{
	// 더미노드 바로 뒤에 삽입
	InsertAfter(list, list->head, x);
}

/*--- 꼬리에 노드를 삽입 ---*/
void InsertRear(Dlist* list, const Member* x)
{
	// 더미노드의 앞 노드(=맨 뒤 노드) 뒤에 삽입
	InsertAfter(list, list->head->prev, x);
}

/*--- p가 가리키는 노드를 삭제 ---*/
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

/*--- 머리노드를 삭제 ---*/
void RemoveFront(Dlist* list)
{
	if (!IsEmpty(list))
	{
		Remove(list, list->head->next);
	}
}

/*--- 꼬리노드를 삭제 ---*/
void RemoveRear(Dlist* list)
{
	if (!IsEmpty(list))
	{
		Remove(list, list->head->prev);
	}
}

/*--- 주목노드를 삭제 ---*/
void RemoveCurrent(Dlist* list)
{
	if (list->crnt != list->head)
	{
		Remove(list, list->crnt);
	}
}

/*--- (Q4)서로 같은 노드를, 가장 앞쪽의 노드를 남기고 모두 삭제 ---*/
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

/*--- 모든 노드를 삭제 ---*/
void Clear(Dlist* list)
{
	while (!IsEmpty(list))
	{
		RemoveFront(list);
	}
}

/*--- 원형 이중연결 리스트의 뒤처리 ---*/
void Terminate(Dlist* list)
{
	Clear(list);
	free(list->head);
}