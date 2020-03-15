/* 이진검색트리를 사용하는 프로그램 */
#include <stdio.h>
#include "Member.h"
#include "BinTree.h"

/*--- 메뉴 ---*/
typedef enum {
	TERMINATE, ADD, REMOVE, SEARCH, MIN, MAX, PRINT
} Menu;

/*--- 메뉴 선택 ---*/
Menu SelectMenu(void)
{
	int ch;
	do {
		printf("(1) 삽입 (2) 삭제 (3) 검색 (4) 최소값 (5) 최대값 (6) 출력 (0) 종료 : ");
		scanf_s("%d", &ch);
	} while (ch < TERMINATE || ch > PRINT);
	return (Menu)ch;
}

/*--- 메인 함수 ---*/
int main(void)
{
	Menu menu;
	BinNode* root = NULL;	/* 이진검색트리의 뿌리 노드 포인터 */
	do {
		Member x;
		BinNode* temp;
		switch (menu = SelectMenu()) {

			/*--- 노드를 삽입 ---*/
		case ADD:
			x = ScanMember("삽입", MEMBER_NO | MEMBER_NAME);
			root = Add(root, &x);
			break;

			/*--- 노드를 삭제 ---*/
		case REMOVE:
			x = ScanMember("삭제", MEMBER_NO);
			Remove(&root, &x);
			break;

			/*--- 노드를 검색 ---*/
		case SEARCH:
			x = ScanMember("검색", MEMBER_NO);
			if ((temp = Search(root, &x)) != NULL)
				PrintLnMember(&temp->data);
			break;
			
			/*--- 가장 작은 키 값을 갖는 노드의 포인터 반환 ---*/
		case MIN:
			if ((temp = GetMinNode(root)) != NULL)
			{
				PrintLnMember(&temp->data);
			}
			break;

			/*--- 가장 큰 키 값을 갖는 노드의 포인터 반환 ---*/
		case MAX:
			if ((temp = GetMaxNode(root)) != NULL)
			{
				PrintLnMember(&temp->data);
			}
			break;

			/*--- 모든 노드를 출력 ---*/
		case PRINT:
			puts("【 모든 노드 출력 】");
			PrintTree(root);
			break;
		}
	} while (menu != TERMINATE);

	FreeTree(root);

	return 0;
}