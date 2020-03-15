/* 포인터를 사용한 선형 리스트(소스) */
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Member.h"

/*--- 노드를 동적으로 생성 ---*/
static Node* AllocNode(void)
{
	return calloc(1, sizeof(Node));
}

/*--- n이 가리키는 노드의 각 멤버에 값을 설정 ----*/
static void SetNode(Node* n, const Member* x, const Node* next)
{
	n->data = *x;
	n->next = (Node*)next;
}

/*--- 선형 리스트를 초기화 ---*/
void Initialize(List* list)
{
	list->head = NULL;
	list->crnt = NULL;
}

/*--- 함수 compare로 x와 같은 노드를 검색 ---*/
Node* search(List* list, const Member* x, int compare(const Member* x, const Member* y))
{
	// 헤드 노드부터 검색시작
	Node* ptr = list->head;

	while (ptr != NULL)
	{
		// 키 값이 같아 검색 성공한 경우
		if (compare(&ptr->data, x) == 0)
		{
			list->crnt = ptr;
			return ptr;
		}
		// 다음 노드 선택
		ptr = ptr->next;
	}
	// 검색 실패
	return NULL;
}

/*--- 머리에 노드를 삽입 ---*/
void InsertFront(List* list, const Member* x)
{
	// ptr_tmp에 원래 헤드 노드가 가리키던 노드 A에 대한 포인터 대입
	Node* ptr_tmp = list->head;
	// 헤드 노드와 현재 노드에 새 노드 allocation
	list->head = list->crnt = AllocNode();
	SetNode(list->head, x, ptr_tmp);
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
		// 맨 마지막 노드 찾기
		Node* ptr = list->head;
		while (ptr->next != NULL)
		{
			ptr = ptr->next;
		}
		// 맨 마지막 노드의 다음에 새 노드 allocation
		ptr->next = list->crnt = AllocNode();
		SetNode(ptr->next, x, NULL);
	}
}

/*--- 머리 노드를 삭제 ---*/
void RemoveFront(List* list)
{
	if (list->head != NULL)
	{
		// ptr_tmp에 두 번째 노드에 대한 포인터 대입
		Node* ptr_tmp = (list->head)->next;
		free(list->head);
		list->head = list->crnt = ptr_tmp;
	}
}

/*--- 꼬리 노드를 삭제 ---*/
void RemoveRear(List* list)
{
	if (list->head != NULL)
	{
		// 노드가 하나라면 머리노드 삭제
		if ((list->head)->next == NULL)
		{
			RemoveFront(list);
		}
		else
		{
			//맨 마지막 노드와 뒤에서 2번째 노드 찾기
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

/*--- 선택한 노드를 삭제 ---*/
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
			// ptr에 현재 노드의 이전 노드 대입
			Node* ptr = list->head;
			while (ptr->next != list->crnt)
			{
				ptr = ptr->next;
			}

			// ptr->next에 현재 노드의 다음 노드 대입
			ptr->next = list->crnt->next;
			free(list->crnt);
			list->crnt = ptr;
		}
	}
}

/*--- (Q1)서로 같은 노드를, 가장 앞쪽의 노드를 남기고 모두 삭제 ---*/
void Purge(List* list, int compare(const Member* x, const Member* y))
{
	Node* std_ptr = list->head;
	while (std_ptr != NULL)
	{
		Node* cmp_ptr = std_ptr;
		Node* cmp_pre = std_ptr;

		while (cmp_pre->next != NULL)
		{
			// 비교할 노드는 pre노드의 다음 노드
			cmp_ptr = cmp_pre->next;
			
			// 같으면 pre노드의 next 에 비교노드의 다음노드 대입
			if (compare(&std_ptr->data, &cmp_ptr->data) == 0)
			{
				cmp_pre->next = cmp_ptr->next;
				free(cmp_ptr);
			}
			// 다르면 pre노드 뒤로 한칸 옮기기
			else
			{
				cmp_pre = cmp_ptr;
			}
		}
		std_ptr = std_ptr->next;
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

/*--- 선택한 노드의 데이터를 출력 ---*/
void PrintCurrent(const List* list)
{
	if (list->crnt == NULL)
	{
		printf("선택한 노드가 없습니다.");
	}
	else
	{
		PrintMember(&list->crnt->data);
	}
}

/*--- 선택한 노드의 데이터를 출력(줄바꿈 문자 포함) ---*/
void PrintLnCurrent(const List* list)
{
	PrintCurrent(list);
	putchar('\n');
}

/*--- 모든 노드의 데이터를 리스트 순서대로 출력 ---*/
void Print(const List* list)
{
	if (list->head == NULL)
	{
		puts("노드가 없습니다.");
	}
	else
	{
		Node* ptr = list->head;
		puts("[ 모두 보기]");
		while (ptr != NULL)
		{
			PrintMember(&ptr->data);
			ptr = ptr->next;
		}
	}
}

/*--- 선형 리스트 종료 ---*/
void Terminate(List* list)
{
	Clear(list);
}