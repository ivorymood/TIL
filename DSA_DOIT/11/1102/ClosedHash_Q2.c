#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Member.h"
#include "ClosedHash.h"

/*--- 해시 함수(key의 해시 값을 반환) ---*/
static int hash(const char* key, int size)
{
	unsigned long h_sum = 0;

	// 이름의 아스키 코드값을 합산
	while (*key)
	{
		h_sum += *(key++);
	}
	return h_sum % size;
}

/*--- 재해시 함수(key의 재해시 값을 반환) ---*/
static int rehash(int key, int size)
{
	return (key + 1) % size;
}

/*--- 버킷의 각 멤버에 값을 설정 ----*/
static void SetBucket(Bucket* n, const Member* x, Status stat)
{
	n->data = *x;
	n->stat = stat;
}

int Initialize(ClosedHash* h, int size)
{
	// 버킷 테이블 메모리 할당
	if ((h->table = calloc(size, sizeof(Bucket))) == NULL)
	{
		h->size = 0;
		return 0;
	}

	// 버킷의 각 stat에 empty로 초기화
	h->size = size;
	for (int i = 0; i < size; ++i)
	{
		h->table[i].stat = Empty;
	}
	return 1;
}

Bucket* Search(const ClosedHash* h, const Member* x)
{
	int key = hash(x->name, h->size);
	Bucket* p = &(h->table[key]);

	// Empty : 같은 해시 값의 데이터가 존재 하지 않음
	// Deleted : 같은 해시 값의 데이터가 다른 버킷에 저장됨
	for (int i = 0; p->stat != Empty && i < h->size; ++i)
	{
		if (p->stat == Occupied && strcmp(p->data.name, x->name) == 0)
		{
			return p;
		}
		// 찾지 못하면 재해시 한 값으로 다음 버킷 찾기
		key = rehash(key, h->size);
		p = &(h->table[key]);
	}
	return NULL;
}

int Add(ClosedHash* h, const Member* x)
{
	int key = hash(x->name, h->size);
	Bucket* p = &(h->table[key]);

	// 이미 존재하는 데이터일때
	if (Search(h, x))
	{
		return 1;
	}

	for (int i = 0; i < h->size; ++i)
	{
		if (p->stat == Empty || p->stat == Deleted)
		{
			SetBucket(p, x, Occupied);
			return 0;
		}
		// 찾지 못하면 재해시 한 값으로 다음 버킷 찾기
		key = rehash(key, h->size);
		p = &(h->table[key]);
	}
	return 2;
}

int Remove(ClosedHash* h, const Member* x)
{
	// 삭제할 버킷의 포인터
	Bucket* p = Search(h, x);

	if (p == NULL)
	{
		return 1;
	}

	p->stat = Deleted;
	return 0;
}

void Dump(const ClosedHash* h)
{
	for (int i = 0; i < h->size; ++i)
	{
		printf("%02d : ", i);

		switch (h->table[i].stat)
		{
		case Occupied : 
			printf("%d (%s)\n", h->table[i].data.no, h->table[i].data.name);
			break;
		case Empty:
			printf("-- Empty --\n");
			break;
		case Deleted:
			printf("-- Deleted --\n");
			break;
		}
	}
}

void Clear(ClosedHash* h)
{
	for (int i = 0; i < h->size; ++i)
	{
		h->table[i].stat = Empty;
	}
}

void Terminate(ClosedHash* h)
{
	Clear(h);
	free(h->table);
	h->size = 0;
}
