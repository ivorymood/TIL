/* 원형 이중 연결 리스트를 사용하는 프로그램 */
#include <stdio.h>
#include "Member.h"
#include "CircDblLinkedList.h"

/*--- 메뉴 ---*/
typedef enum {
	TERMINATE, INS_FRONT, INS_REAR, RMV_FRONT, RMV_REAR, PRINT_CRNT,
	RMV_CRNT, SRCH_NO, SRCH_NAME, RETRIEVE, PRINT_ALL, NEXT, PREV, CLEAR, PURGE
} Menu;

/*--- 메뉴 선택 ---*/
Menu SelectMenu(void)
{
	int i, ch;
	char* mstring[] = {
		"머리에 노드를 삽입",      "꼬리에 노드를 삽입",     "머리 노드를 삭제",
		"꼬리 노드를 삭제",        "선택한 노드를 출력",     "선택한 노드를 삭제",
		"번호로 검색",             "이름으로 검색",          "n번째 노드 반환",
		"모든 노드를 출력",		   "선택한 노드를 뒤쪽으로", "선택한 노드를 앞쪽으로", 
		"모든 노드를 삭제",		   "중복 노드 삭제"
	};

	putchar('\n');
	do {
		for (i = TERMINATE; i < PURGE; i++) {
			printf("(%2d) %-22.22s ", i + 1, mstring[i]);
			if ((i % 3) == 2)
				putchar('\n');
		}
		printf("(0) 종료 : ");
		scanf_s("%d", &ch);
	} while (ch < TERMINATE || ch > PURGE);

	return (Menu)ch;
}

/*--- 메인 ---*/
int main(void)
{
	Menu menu;
	Dlist list;
	Initialize(&list);		/* 원형 이중 연결 리스트를 초기화 */
	do {
		Member x;
		int n = 0;
		switch (menu = SelectMenu()) {

			/* 머리에 노드를 삽입 */
		case INS_FRONT:
			x = ScanMember("머리에 삽입", MEMBER_NO | MEMBER_NAME);
			InsertFront(&list, &x);
			break;

			/* 꼬리에 노드를 삽입 */
		case INS_REAR:
			x = ScanMember("꼬리에 삽입", MEMBER_NO | MEMBER_NAME);
			InsertRear(&list, &x);
			break;

			/* 머리 노드를 삭제 */
		case RMV_FRONT:
			RemoveFront(&list);
			break;

			/* 꼬리 노드를 삭제 */
		case RMV_REAR:
			RemoveRear(&list);
			break;

			/* 선택한 노드의 데이터를 출력 */
		case PRINT_CRNT:
			PrintLnCurrent(&list);
			break;

			/* 선택한 노드를 삭제 */
		case RMV_CRNT:
			RemoveCurrent(&list);
			break;

			/* 번호로 검색 */
		case SRCH_NO:
			x = ScanMember("검색", MEMBER_NO);
			if (search(&list, &x, MemberNoCmp) != NULL)
				PrintLnCurrent(&list);
			else
				puts("그 번호의 데이터가 없습니다.");
			break;

			/* 이름으로 검색 */
		case SRCH_NAME:
			x = ScanMember("검색", MEMBER_NAME);
			if (search(&list, &x, MemberNameCmp) != NULL)
				PrintLnCurrent(&list);
			else
				puts("그 이름의 데이터가 없습니다.");
			break;

			/*--- (Q4) 머리부터 n개 뒤의 노드에 대한 포인터 반환---*/
		case RETRIEVE:
			printf("n 입력 : ");
			scanf_s("%d", &n);
			if (Retrieve(&list, n) != NULL)
			{
				PrintCurrent(&list);
			}
			else
			{
				printf("%d 번째의 데이터가 없습니다.", n);
			}
			break;

			break;

			/* 모든 노드의 데이터를 출력 */
		case PRINT_ALL:
			Print(&list);
			break;

			/* 선택한 노드 다음으로 진행 */
		case NEXT:
			Next(&list);
			break;

			/* 선택한 노드 앞쪽으로 진행 */
		case PREV:
			Prev(&list);
			break;

			/* 모든 노드를 삭제 */
		case CLEAR:
			Clear(&list);
			break;

			/*--- (Q4)서로 같은 노드를, 가장 앞쪽의 노드를 남기고 모두 삭제 ---*/
		case PURGE:
			Purge(&list, MemberNoCmp);
			break;
		}
	} while (menu != TERMINATE);

	Terminate(&list);			/* 원형 이중 연결 리스트 종료 */

	return 0;
}