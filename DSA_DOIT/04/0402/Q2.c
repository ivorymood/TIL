#include <stdio.h>
#include "IntDoubleStack.h"

int main(void)
{
	IntDoubleStack sF;
	IntDoubleStack sT;
	int x;
	printf("스택 최대 크기 입력 : ");
	scanf_s("%d", &x);

	if (Initialize(&sF, &sT, x) == -1) {
		puts("스택의 생성에 실패했습니다.");
		return 1;
	}
	while (1) {
		int menu;
		int idx;
		printf("현재 데이터 개수 : 앞쪽:%d 뒤쪽:%d / 최대용량 합 : %d\n", Size(&sF), Size(&sT), ((Capacity(&sF) + Capacity(&sT)) - (Size(&sF) + Size(&sT))) / 2);
		printf("1) A에 Push 2) A에서 Pop 3) A에서 Peek 4) A를 출력 5) A에서 검색 6) A를 초기화\n"
			"7) B에 Push 8) B에서 Pop 9) B에서 Peek 10) B를 출력 11) B에서 검색 12) B를 초기화\n"
			"13) 빈 상태 / 가득 찬 상태 0) 종료 : ");
		scanf_s("%d", &menu);
		if (menu == 0) break;
		switch (menu) {
		case 1: /*--- A에 푸시 ---*/
			printf("데이터：");
			scanf_s("%d", &x);
			if (Push_F(&sF, &sT, x) == -1)
				puts("\a오류 : 푸시에 실패했습니다.");
			break;
		case 2: /*--- A에서 팝 ---*/
			if (Pop_F(&sF, &sT, &x) == -1)
				puts("\a오류 : 팝에 실패했습니다.");
			else
				printf("팝한 데이터는 %d입니다.\n", x);
			break;
		case 3: /*--- A에서 피크 ---*/
			if (Peek_F(&sF, &x) == -1)
				puts("\a오류 : 피크에 실패했습니다.");
			else
				printf("피크한 데이터는 %d입니다.\n", x);
			break;
		case 4: /*--- A 출력 ---*/
			Print(&sF);
			break;
		case 5: /*--- A에서 검색 ---*/
			printf("검색 데이터：");
			scanf_s("%d", &x);
			if ((idx = Search(&sF, x)) == -1)
				puts("\a오류 : 검색에 실패했습니다.");
			else
				printf("데이터는 인덱스 %d 위치에 있습니다.\n", idx);
			break;
		case 6: /*--- A 초기화 ---*/
			Clear_F(&sF, &sT);
			break;
		case 7: /*--- B로 푸시 ---*/
			printf("데이터：");
			scanf_s("%d", &x);
			if (Push_T(&sF, &sT, x) == -1)
				puts("\a오류 : 푸시에 실패했습니다.");
			break;
		case 8: /*--- B에서 팝 ---*/
			if (Pop_T(&sF, &sT, &x) == -1)
				puts("\a오류 : 팝에 실패했습니다.");
			else
				printf("팝한 데이터는 %d입니다.\n", x);
			break;
		case 9: /*--- B에서 피크 ---*/
			if (Peek_T(&sT, &x) == -1)
				puts("\a오류 : 피크에 실패했습니다.");
			else
				printf("피크한 데이터는 %d입니다.\n", x);
			break;
		case 10: /*--- B를 출력 ---*/
			Print(&sT);
			break;
		case 11: /*--- B에서 검색 ---*/
			printf("검색 데이터：");
			scanf_s("%d", &x);
			if ((idx = Search(&sT, x)) == -1)
				puts("\a오류 : 검색에 실패했습니다.");
			else
				printf("데이터는 인덱스 %d 위치에 있습니다.\n", idx);
			break;
		case 12: /*--- B 초기화 ---*/
			Clear_T(&sF, &sT);
			break;
		case 13: /*--- 빈 상태 / 가득 찬 상태 판단 ---*/
			printf("스택 A는 비어 %s.\n", IsEmpty(&sF) ? "있습니다" : "있지 않습니다");
			printf("스택 B는 비어 %s.\n", IsEmpty(&sT) ? "있습니다" : "있지 않습니다");
			printf("스택은 가득 %s.\n", IsFull(&sF) || IsFull(&sT) ? "찼습니다" : "차지 않았습니다");
			break;
		}
	}
	Terminate(&sF, &sT);
	return 0;
}