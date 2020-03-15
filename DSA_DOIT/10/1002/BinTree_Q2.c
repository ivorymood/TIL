/* �����˻�Ʈ�� ���α׷�(�ҽ�) */
#include <stdio.h>
#include <stdlib.h>
#include "Member.h"
#include "BinTree.h"


/*--- �˻� ---*/
BinNode* Search(BinNode* p, const Member* x);

/*--- ����� ���� ---*/
BinNode* Add(BinNode* p, const Member* x);

/*--- ����� ���� ---*/
int Remove(BinNode** root, const Member* x);

/*--- ��� ��带 ��� ---*/
void PrintTree(const BinNode* p);

/*--- ��� ��� ���� ---*/
void FreeTree(BinNode* p);