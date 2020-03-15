/* 커서에 의한 선형 리스트(소스부) */
#include <stdio.h>
#include <stdlib.h>
#include "Member.h"
#include "ArrayLinkedList.h"

/*--- 삽입할 레코드의 인덱스를 구한다. ---*/
static Index GetIndex(List *list)
{
	if (list->deleted == NULL)
	{
		return ++(list->max);
	}
	else
	{
		// 프리리스트의 머리노드 구하기
		Index rec = list->deleted;
		list->deleted = list->n[rec].Dnext;
		return rec;
	}
}

/*--- 지정된 레코드를 삭제 리스트에 등록한다. ---*/
static void DeleteIndex(List* list, Index idx)
{
	if (list->deleted == NULL)
	{
		list->deleted = idx;
		list->n[idx].Dnext = NULL;
	}
	else
	{
		// 프리리스트의 기존 머리노드를 2번째로 옮기고
		// 매개변수 인덱스를 프리리스트의 새로운 머리노드로 지정
		Index ptr_tmp = list->deleted;
		list->deleted = idx;
		list->n[idx].Dnext = ptr_tmp;
	}
}

/*--- n이 가리키는 노드의 각 멤버에 값을 설정 ----*/
static void SetNode(Node* n, const Member* x, Index next)
{
	n->data = *x;
	n->next = next;
}

/*--- 선형 리스트를 초기화(가장 큰 요솟수는 size) ---*/
void Initialize(List* list, int size)
{
	list->n = calloc(size, sizeof(Node));
	list->head = NULL;
	list->crnt = NULL;
	list->max = NULL;
	list->deleted = NULL;
}

/*--- 함수 compare에 의해 x와 같은 것으로 판단되는 노드를 검색 ---*/
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

/*--- (Q3) 머리부터 n개 뒤의 노드에 대한 포인터 반환---*/
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

/*--- 머리에 노드를 삽입 ---*/
void InsertFront(List* list, const Member* x)
{
	// 기존 헤드 노드는 두번째로 옮기기
	Index ptr_tmp = list->head;
	// 삽입할 레코드의 인덱스를 구해서 crnt와 head에 삽입
	list->head = list->crnt = GetIndex(list);
	SetNode(&list->n[list->head], x, ptr_tmp);
}

/*--- 꼬리에 노드를 삽입 ---*/
void InsertRear(List* list, const Member* x)
{
	if (list->head == NULL)
	{
		InsertFront(list, x);
	}
	else
	{
		// 맨 뒤쪽의 노드 찾기
		Index ptr = list->head;
		while (list->n[ptr].next != NULL)
		{
			ptr = list->n[ptr].next;
		}
		// 삽입할 레코드의 인덱스를 구해서 crnt와 맨 뒤쪽 노드의 next에 삽입
		list->n[ptr].next = list->crnt = GetIndex(list);
		SetNode(&list->n[list->n[ptr].next], x, NULL);
	}
}

/*--- 머리노드를 삭제 ---*/
void RemoveFront(List* list)
{
	if (list->head != NULL)
	{
		// 머리노드의 뒤쪽 노드를 머리노드로 옮기기
		Index ptr_tmp = list->n[list->head].next;
		DeleteIndex(list, list->head);
		list->head = list->crnt = ptr_tmp;
	}
}

/*--- 꼬리노드를 삭제 ---*/
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
			// 맨 마지막 노드를 찾아서 삭제. 
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

/*--- 주목노드를 삭제 ---*/
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
			// 주목노드의 전 노드 찾기
			Index pre = list->head;
			while (list->n[pre].next != list->crnt)
			{
				pre = list->n[pre].next;
			}
			// 전 노드의 next에 주목노드의 next 대입 
			list->n[pre].next = list->n[list->crnt].next;
			DeleteIndex(list, list->crnt);
			list->crnt = pre;
		}
	}
}

/*--- (Q3)서로 같은 노드를, 가장 앞쪽의 노드를 남기고 모두 삭제 ---*/
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

/*--- 모든 노드를 삭제 ---*/
void Clear(List* list)
{
	while (list->head != NULL)
	{
		RemoveFront(list);
	}
	list->crnt = NULL;
}

/*--- 주목노드의 데이터를 나타냄 ---*/
void PrintCurrent(const List* list)
{
	if (list->crnt == NULL)
	{
		printf("주목노드가 없습니다.");
	}
	else
	{
		PrintMember(&list->n[list->crnt].data);
	}
}

/*--- 주목노드의 데이터를 나타냄(줄바꿈 문자 붙임) ---*/
void PrintLnCurrent(const List* list)
{
	PrintCurrent(list);
	putchar('\n');
}

/*--- 모든 노드의 데이터를 나타냄 ---*/
void Print(const List* list)
{
	if (list->head == NULL)
	{
		puts("노드가 없습니다.");
	}
	else
	{
		Index ptr = list->head;
		puts("[ 모두 보기 ]");
		while (ptr != NULL)
		{
			PrintLnMember(&list->n[ptr].data);
			ptr = list->n[ptr].next;
		}
	}
}

/*--- 선형 리스트의 뒤처리 ---*/
void Terminate(List* list)
{
	Clear(list);
	free(list->n);
}