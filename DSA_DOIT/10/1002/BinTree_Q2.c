/* 이진검색트리 프로그램(소스) */
#include <stdio.h>
#include <stdlib.h>
#include "Member.h"
#include "BinTree.h"


/*--- 검색 ---*/
BinNode* Search(BinNode* p, const Member* x);

/*--- 노드의 삽입 ---*/
BinNode* Add(BinNode* p, const Member* x);

/*--- 노드의 삭제 ---*/
int Remove(BinNode** root, const Member* x);

/*--- 모든 노드를 출력 ---*/
void PrintTree(const BinNode* p);

/*--- 모든 노드 삭제 ---*/
void FreeTree(BinNode* p);