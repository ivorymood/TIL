/* �����˻�Ʈ�� ���α׷�(�ҽ�) */
#include <stdio.h>
#include <stdlib.h>
#include "Member.h"
#include "BinTree.h"

/*--- ��带 �������� �Ҵ� ---*/
static BinNode* AllocBinNode(void)
{
	return calloc(1, sizeof(BinNode));
}

/*--- ��� ��� �� ���� ----*/
static void SetBinNode(BinNode* n, const Member* x, const BinNode* left, const BinNode* right)
{
	n->data = *x;
	n->left = left;
	n->right = right;
}

/*--- �˻� ---*/
BinNode* Search(BinNode* p, const Member* x)
{
	int cond;
	if (p == NULL)
	{
		return NULL;
	}

	// �˻� ������
	if ((cond = MemberNoCmp(x, &p->data)) == 0)
	{
		return p;
	}
	// x�� ���� ��庸�� ������ ���� ����Ʈ����
	else if (cond < 0)
	{
		Search(p->left, x);
	}
	// x�� ���� ��庸�� ũ�� ������ ����Ʈ����
	else
	{
		Search(p->right, x);
	}
}

/*--- ���� ���� Ű ���� ���� ����� ������ ��ȯ ---*/
BinNode* GetMinNode(const BinNode* p)
{
	if (p == NULL)
	{
		return NULL;
	}

	while (p->left != NULL)
	{
		p = p->left;
	}
	return p;
}

/*--- ���� ū Ű ���� ���� ����� ������ ��ȯ ---*/
BinNode* GetMaxNode(const BinNode* p)
{
	if (p == NULL)
	{
		return NULL;
	}

	while (p->right != NULL)
	{
		p = p->right;
	}
	return p;
}

/*--- ����� ���� ---*/
BinNode* Add(BinNode* p, const Member* x)
{
	int cond;
	// �ش� ��ġ�� ����ִٸ� ���� allocation �� set
	if (p == NULL)
	{
		p = AllocBinNode();
		SetBinNode(p, x, NULL, NULL);
	}
	// �̹� ���� ��尡 ���� ���
	else if ((cond = MemberNoCmp(x, &p->data)) == 0)
	{
		printf("[����] %d�� �̹� ��ϵǾ� �ֽ��ϴ�. \n", x->no);
	}
	// x�� ���� ��庸�� ������ ���� ����Ʈ����
	else if (cond < 0)
	{
		p->left = Add(p->left, x);
	}
	// x�� ���� ��庸�� ũ�� ������ ����Ʈ����
	else
	{
		p->right = Add(p->right, x);
	}
	return p;
}

/*--- ����� ���� ---*/
int Remove(BinNode** root, const Member* x)
{
	BinNode* next, * temp;
	BinNode** left;
	BinNode** p = root;

	// ������ ��� ��ġ ã��
	while (1)
	{
		int cond;
		if (*p = NULL)
		{
			printf("[����] %d�� ��ϵǾ� ���� �ʽ��ϴ�. \n", x->no);
			return -1;
		}
		// �˻� ������
		else if ((cond = MemberNoCmp(x, &(*p)->data)) == 0)
		{
			break;
		}
		// x�� ���� ��庸�� ������ ���� ����Ʈ����
		else if (cond < 0)
		{
			p = &((*p)->left);
		}
		// x�� ���� ��庸�� ũ�� ������ ����Ʈ����
		else
		{
			p = &((*p)->right);
		}
	}

	// ������ ����� ���� ����Ʈ������ ���� ū ���(next) ���ϱ�
	if ((*p)->left == NULL)
	{
		// ������ ���ٸ� ������ ��尡 next
		next = (*p)->right;
	}
	else
	{
		// ������ ����� ���� ����Ʈ������ ���� �����ʿ� �ִ� ��� ���ϱ�
		left = &((*p)->left);
		while ((*left)->right != NULL)
		{
			left = &(*left)->right;
		}
		next = *left;

		// next��尡 �ִ� �ڸ��� next����� ���� ��� ��������
		*left = (*left)->left;

		// next����� left, right�� ������ ����� left, right ����
		next->left = (*p)->left;
		next->right = (*p)->right;
	}


	// ������ ��尡 �ִ� ��ġ�� next��� ����
	temp = *p;
	*p = next;

	// ������ ��� �޸� ����
	free(temp);

	return 0;
}

/*--- ��� ��带 ��� ---*/
void PrintTree(const BinNode* p)
{
	if (p != NULL)
	{
		PrintTree(p->left);
		PrintLnMember(&p->data);
		PrintTree(p->right);
	}
}

/*--- ��� ��� ���� ---*/
void FreeTree(BinNode* p)
{
	if (p != NULL)
	{
		FreeTree(p->left);
		FreeTree(p->right);
		free(p);
	}
}