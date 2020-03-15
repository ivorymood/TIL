/* �����˻�Ʈ�� ���α׷�(���) */
#ifndef ___BinTree
#define ___BinTree

#include "Member.h"

/*--- ��� ---*/
typedef struct __bnode {
	Member data;			/* ������ */
	struct __bnode* left;	/* ���� �ڽ� ��� ������ */
	struct __bnode* right;	/* ������ �ڽ� ��� ������ */
} BinNode;

/*--- �˻� ---*/
BinNode* Search(BinNode* p, const Member* x);

/*--- ���� ���� Ű ���� ���� ����� ������ ��ȯ ---*/
BinNode* GetMinNode(const BinNode* p);

/*--- ���� ū Ű ���� ���� ����� ������ ��ȯ ---*/
BinNode* GetMaxNode(const BinNode* p);

/*--- ����� ���� ---*/
BinNode* Add(BinNode* p, const Member* x);

/*--- ����� ���� ---*/
int Remove(BinNode** root, const Member* x);

/*--- ��� ��带 ��� ---*/
void PrintTree(const BinNode* p);

/*--- ��� ��� ���� ---*/
void FreeTree(BinNode* p);
#endif