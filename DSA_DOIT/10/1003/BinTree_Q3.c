/* 이진검색트리 프로그램(소스) */
#include <stdio.h>
#include <stdlib.h>
#include "Member.h"
#include "BinTree.h"

/*--- 노드를 동적으로 할당 ---*/
static BinNode* AllocBinNode(void)
{
	return calloc(1, sizeof(BinNode));
}

/*--- 노드 멤버 값 설정 ----*/
static void SetBinNode(BinNode* n, const Member* x, const BinNode* left, const BinNode* right)
{
	n->data = *x;
	n->left = left;
	n->right = right;
}

/*--- 검색 ---*/
BinNode* Search(BinNode* p, const Member* x)
{
	int cond;
	if (p == NULL)
	{
		return NULL;
	}

	// 검색 성공시
	if ((cond = MemberNoCmp(x, &p->data)) == 0)
	{
		return p;
	}
	// x가 현재 노드보다 작으면 왼쪽 서브트리로
	else if (cond < 0)
	{
		Search(p->left, x);
	}
	// x가 현재 노드보다 크면 오른쪽 서브트리로
	else
	{
		Search(p->right, x);
	}
}

/*--- 가장 작은 키 값을 갖는 노드의 포인터 반환 ---*/
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

/*--- 가장 큰 키 값을 갖는 노드의 포인터 반환 ---*/
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

/*--- 노드의 삽입 ---*/
BinNode* Add(BinNode* p, const Member* x)
{
	int cond;
	// 해당 위치가 비어있다면 새로 allocation 후 set
	if (p == NULL)
	{
		p = AllocBinNode();
		SetBinNode(p, x, NULL, NULL);
	}
	// 이미 같은 노드가 있을 경우
	else if ((cond = MemberNoCmp(x, &p->data)) == 0)
	{
		printf("[오류] %d는 이미 등록되어 있습니다. \n", x->no);
	}
	// x가 현재 노드보다 작으면 왼쪽 서브트리로
	else if (cond < 0)
	{
		p->left = Add(p->left, x);
	}
	// x가 현재 노드보다 크면 오른쪽 서브트리로
	else
	{
		p->right = Add(p->right, x);
	}
	return p;
}

/*--- 노드의 삭제 ---*/
int Remove(BinNode** root, const Member* x)
{
	BinNode* next, * temp;
	BinNode** left;
	BinNode** p = root;

	// 삭제할 노드 위치 찾기
	while (1)
	{
		int cond;
		if (*p = NULL)
		{
			printf("[오류] %d는 등록되어 있지 않습니다. \n", x->no);
			return -1;
		}
		// 검색 성공시
		else if ((cond = MemberNoCmp(x, &(*p)->data)) == 0)
		{
			break;
		}
		// x가 현재 노드보다 작으면 왼쪽 서브트리로
		else if (cond < 0)
		{
			p = &((*p)->left);
		}
		// x가 현재 노드보다 크면 오른쪽 서브트리로
		else
		{
			p = &((*p)->right);
		}
	}

	// 삭제할 노드의 왼쪽 서브트리에서 가장 큰 노드(next) 구하기
	if ((*p)->left == NULL)
	{
		// 왼쪽이 없다면 오른쪽 노드가 next
		next = (*p)->right;
	}
	else
	{
		// 삭제할 노드의 왼쪽 서브트리에서 가장 오른쪽에 있는 노드 구하기
		left = &((*p)->left);
		while ((*left)->right != NULL)
		{
			left = &(*left)->right;
		}
		next = *left;

		// next노드가 있던 자리에 next노드의 왼쪽 노드 가져오기
		*left = (*left)->left;

		// next노드의 left, right에 삭제할 노드의 left, right 대입
		next->left = (*p)->left;
		next->right = (*p)->right;
	}


	// 삭제할 노드가 있던 위치에 next노드 대입
	temp = *p;
	*p = next;

	// 삭제할 노드 메모리 해제
	free(temp);

	return 0;
}

/*--- 모든 노드를 출력 ---*/
void PrintTree(const BinNode* p)
{
	if (p != NULL)
	{
		PrintTree(p->left);
		PrintLnMember(&p->data);
		PrintTree(p->right);
	}
}

/*--- 모든 노드 삭제 ---*/
void FreeTree(BinNode* p)
{
	if (p != NULL)
	{
		FreeTree(p->left);
		FreeTree(p->right);
		free(p);
	}
}