/* 체인법으로 구현한 해시(소스) */
#include <stdio.h>
#include <stdlib.h>
#include "Member.h"
#include "ChainHash.h"

/*--- 해시 함수(key의 해시 값을 반환) ---*/
static int hash(const char *key, int size)
{
	unsigned long h_sum = 0;

	// 이름의 아스키 코드값을 합산
	while (*key)
	{
		h_sum += *(key++);
	}
	return h_sum % size;
}

/*--- 노드의 각 멤버에 값을 설정 ----*/
static void SetNode(Node* n, const Member* x, const Node* next)
{
	n->data = *x;
	n->next = next;
}

/*--- 해시 테이블 초기화 ---*/
int Initialize(ChainHash* h, int size)
{
	// 각 버킷을 가리킬 포인터 배열 생성
	if ((h->table = calloc(size, sizeof(Node*))) == NULL)
	{
		h->size = 0;
		return 0;
	}

	h->size = size;
	// 해시 테이블의 각 포인터 값 NULL로 초기화
	for (int i = 0; i < size; ++i)
	{
		h->table[i] = NULL;
	}

	return 1;
}

/*--- 검색 ---*/
Node* Search(const ChainHash* h, const Member* x)
{
	int key = hash(x->name, h->size);
	Node* p = h->table[key];		// 버킷의 첫번째 노드

	while (p != NULL)
	{
		if (strcmp(p->data.name, x->name) == 0)
		{
			return p;
		}
		p = p->next;
	}
	return NULL;
}

/*--- 데이터 추가 ---*/
int Add(ChainHash* h, const Member* x)
{
	int key = hash(x->name, h->size);
	Node* p = h->table[key];		// 버킷의 첫번째 노드
	Node* temp;

	while (p != NULL)
	{
		// 이미 등록되어 있을 경우
		if (strcmp(p->data.name, x->name) == 0)
		{
			return 1;
		}
		p = p->next;
	}
	
	if ((temp = (Node*)calloc(1, sizeof(Node))) == NULL)
	{
		return 2;
	}
	// 새로 할당한 노드를 버킷의 첫번째 노드로
	SetNode(temp, x, h->table[key]);
	h->table[key] = temp;

	return 0;
}

/*--- 데이터 삭제 ---*/
int Remove(ChainHash* h, const Member* x)
{
	int key = hash(x->name, h->size);
	Node* p = h->table[key];			// 버킷의 첫번째 노드
	Node** pp = &(h->table[key]);		// 버킷의 첫번째 노드에 대한 포인터

	while (p != NULL)
	{
		if (strcmp(p->data.name, x->name) == 0)
		{
			// 삭제노드가 있던 위치에 다음 노드 대입
			*pp = p->next;
			free(p);
			return 0;
		}
		pp = &p->next;
		p = p->next;
	}

	return 1;
}

/*--- 해시 테이블 덤프(dump) ---*/
void Dump(const ChainHash* h)
{
	for (int i = 0; i < h->size; ++i)
	{
		Node* p = h->table[i];
		printf("%02d", i);
		while (p != NULL)
		{
			printf("-> %d (%s)", p->data.no, p->data.name);
			p = p->next;
		}
		putchar('\n');
	}
}

/*--- 모든 데이터 삭제 ---*/
void Clear(ChainHash* h)
{
	for (int i = 0; i < h->size; ++i)
	{
		Node* p = h->table[i];
		while (p != NULL)
		{
			// 2번째 노드를 1번째로 노드로 옮긴 후 해제
			Node* next_tmp = p->next;
			free(p);
			p = next_tmp;
		}
	}
}

/*--- 해시 테이블 종료 ---*/
void Terminate(ChainHash* h)
{
	Clear(h);
	free(h->table);
	h->size = 0;
}