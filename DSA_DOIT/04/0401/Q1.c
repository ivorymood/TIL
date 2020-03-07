/* int형 스택 IntStack의 사용 */
#include <stdio.h>
#include "IntStack.h"

int main(void)
{
	IntStack s;
	if (Initialize(&s, 64) == -1) {
		puts("스택 생성에 실패하였습니다.");
		return 1;
	}

	while (1) {
		int menu, x;

		printf("현재 데이터 수 : %d / %d\n", Size(&s), Capacity(&s));
		printf("(0)  종료      (1)  Initialize (2)  Push       (3) Pop        (4) Peek\n");
		printf("(5)  Clear     (6)  Capacity   (7)  Size       (8) IsEmpty    (9)IsFull\n");
		printf("(10) Search    (11) Print      (12) Terminate");
		scanf_s("%d", &menu);
		if (menu == 0) break;

		switch (menu) {
		case 1: /*--- 초기화 ---*/
			if (s.stk != NULL)
			{
				puts("이미 초기화된 스택이 있습니다.");
				printf("종료하고 다시 초기화 하시겠습니까? (0 : 예 1: 아니오)");
				scanf_s("%d", &x);
				if (!x)
				{
					Terminate(&s);
				}
			}
			printf("스택 크기 : ");
			scanf_s("%d", &x);
			if (Initialize(&s, x) == -1) {
				puts("스택 생성에 실패하였습니다.");
			}
			break;

		case 2: /*--- 푸시---*/
			printf("데이터 : ");
			scanf_s("%d", &x);
			if (Push(&s, x) == -1)
				puts("\a오류 : 푸시에 실패하였습니다.");
			break;

		case 3: /*--- 팝 ---*/
			if (Pop(&s, &x) == -1)
				puts("\a오류 : 팝에 실패하였습니다.");
			else
				printf("팝 데이터는 %d입니다.\n", x);
			break;

		case 4: /*--- 피크 ---*/
			if (Peek(&s, &x) == -1)
				puts("\a오류 : 피크에 실패하였습니다.");
			else
				printf("피크 데이터는 %d입니다.\n", x);
			break;

		case 5: /*--- 스택 비우기 ---*/
			Clear(&s);
			printf("스택 비우기 완료\n");
			break;

		case 6: /*--- 스택 용량 ---*/
			printf("현재 스택 용량은 %d 입니다 \n", Capacity(&s));
			break;

		case 7: /*--- 스택에 쌓여있는 데이터 수 ---*/
			printf("현재 스택에 쌓여있는 데이터 수는 %d 입니다 \n", Size(&s));
			break;

		case 8: /*--- 스택이 비어있는지 확인 ---*/
			if (IsEmpty(&s))
			{
				printf("ㅇㅇ 비어있음\n");
			}
			else
			{
				printf("ㄴㄴ 비어있지 않습니다\n");
			}
			break;

		case 9: /*--- 스택이 가득찼는지 확인 ---*/
			if (IsFull(&s))
			{
				printf("ㅇㅇ 가득찼음\n");
			}
			else
			{
				printf("ㄴㄴ 아직 여유가 있습니다\n");
			}
			break;

		case 10: /*--- 스택에서 검색 ---*/
			printf("찾고자 하는 숫자 입력 : ");
			scanf_s("%d", &x);
			x = Search(&s, x);
			printf("스택의 %d 번째에 있습니다\n", x);
			break;

		case 11: /*--- 출력 ---*/
			Print(&s);
			break;

		case 12: /*--- 스택 종료 ---*/
			printf("정말 종료 하시겠습니까? (0 : 예 1: 아니오)");
			scanf_s("%d", &x);
			if (!x)
			{
				Terminate(&s);
			}
			break;
		}
	}

	Terminate(&s);

	return 0;
}