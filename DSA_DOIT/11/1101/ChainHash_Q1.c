/* ü�ι����� ������ �ؽ�(�ҽ�) */
#include <stdio.h>
#include <stdlib.h>
#include "Member.h"
#include "ChainHash.h"

/*--- �ؽ� �Լ�(key�� �ؽ� ���� ��ȯ) ---*/
static int hash(const char *key, int size)
{
	unsigned long h_sum = 0;

	// �̸��� �ƽ�Ű �ڵ尪�� �ջ�
	while (*key)
	{
		h_sum += *(key++);
	}
	return h_sum % size;
}

/*--- ����� �� ����� ���� ���� ----*/
static void SetNode(Node* n, const Member* x, const Node* next)
{
	n->data = *x;
	n->next = next;
}

/*--- �ؽ� ���̺� �ʱ�ȭ ---*/
int Initialize(ChainHash* h, int size)
{
	// �� ��Ŷ�� ����ų ������ �迭 ����
	if ((h->table = calloc(size, sizeof(Node*))) == NULL)
	{
		h->size = 0;
		return 0;
	}

	h->size = size;
	// �ؽ� ���̺��� �� ������ �� NULL�� �ʱ�ȭ
	for (int i = 0; i < size; ++i)
	{
		h->table[i] = NULL;
	}

	return 1;
}

/*--- �˻� ---*/
Node* Search(const ChainHash* h, const Member* x)
{
	int key = hash(x->name, h->size);
	Node* p = h->table[key];		// ��Ŷ�� ù��° ���

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

/*--- ������ �߰� ---*/
int Add(ChainHash* h, const Member* x)
{
	int key = hash(x->name, h->size);
	Node* p = h->table[key];		// ��Ŷ�� ù��° ���
	Node* temp;

	while (p != NULL)
	{
		// �̹� ��ϵǾ� ���� ���
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
	// ���� �Ҵ��� ��带 ��Ŷ�� ù��° ����
	SetNode(temp, x, h->table[key]);
	h->table[key] = temp;

	return 0;
}

/*--- ������ ���� ---*/
int Remove(ChainHash* h, const Member* x)
{
	int key = hash(x->name, h->size);
	Node* p = h->table[key];			// ��Ŷ�� ù��° ���
	Node** pp = &(h->table[key]);		// ��Ŷ�� ù��° ��忡 ���� ������

	while (p != NULL)
	{
		if (strcmp(p->data.name, x->name) == 0)
		{
			// ������尡 �ִ� ��ġ�� ���� ��� ����
			*pp = p->next;
			free(p);
			return 0;
		}
		pp = &p->next;
		p = p->next;
	}

	return 1;
}

/*--- �ؽ� ���̺� ����(dump) ---*/
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

/*--- ��� ������ ���� ---*/
void Clear(ChainHash* h)
{
	for (int i = 0; i < h->size; ++i)
	{
		Node* p = h->table[i];
		while (p != NULL)
		{
			// 2��° ��带 1��°�� ���� �ű� �� ����
			Node* next_tmp = p->next;
			free(p);
			p = next_tmp;
		}
	}
}

/*--- �ؽ� ���̺� ���� ---*/
void Terminate(ChainHash* h)
{
	Clear(h);
	free(h->table);
	h->size = 0;
}