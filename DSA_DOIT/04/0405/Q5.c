/* int형 큐 IntQueue를 사용하는 프로그램 */
#include <stdio.h>
#include "IntQueue.h"

int main(void)
{
	IntQueue que;

	if (Initialize(&que, 64) == -1) {
		puts("큐의 생성에 실패하였습니다.");
		return 1;
	}

	while (1) {
		int m, x;

		printf("현재 데이터 수 : %d / %d \n", Size(&que), Capacity(&que));
		printf("(0)  종료      (1)  Initialize (2)  Enque       (3) Deque        (4) Peek\n");
		printf("(5)  Clear     (6)  Capacity   (7)  Size       (8) IsEmpty    (9)IsFull\n");
		printf("(10) Search    (11) Print      (12) Terminate");
		scanf_s("%d", &m);

		if (m == 0) break;
		switch (m) {

		case 1: /*--- 큐 초기화 ---*/
			if (que.que != NULL)
			{
				puts("이미 초기화된 스택이 있습니다.");
				printf("종료하고 다시 초기화 하시겠습니까? (0 : 예 1: 아니오)");
				scanf_s("%d", &x);
				if (!x)
				{
					Terminate(&que);
				}
			}
			printf("스택 크기 : ");
			scanf_s("%d", &x);
			if (Initialize(&que, x) == -1) {
				puts("스택 생성에 실패하였습니다.");
			}

			break;

		case 2: /*--- 인큐 ---*/
			printf("데이터 : "); scanf_s("%d", &x);
			if (Enque(&que, x) == -1)
				puts("\a오류 : 인큐에 실패하였습니다.");
			break;

		case 3: /*--- 디큐 ---*/
			if (Deque(&que, &x) == -1)
				puts("\a오류 : 디큐에 실패하였습니다.");
			else
				printf("디큐한 데이터는 %d입니다.\n", x);
			break;

		case 4: /*--- 피크 ---*/
			if (Peek(&que, &x) == -1)
				puts("\a오류 : 피크에 실패하였습니다.");
			else
				printf("피크한 데이터는 %d입니다.\n", x);
			break;

		case 5: /*--- 모든 데이터를 삭제 ---*/
			Clear(&que);
			printf("큐 비우기 완료\n");
			break;

		case 6: /*--- 큐의 최대 용량 ---*/
			printf("현재 큐 용량은 %d 입니다 \n", Capacity(&que));
			break;

		case 7: /*--- 큐에 저장된 데이터의 개수 ---*/
			printf("현재 큐에 쌓여있는 데이터 수는 %d 입니다 \n", Size(&que));
			break;

		case 8: /*--- 큐가 비어 있는가? ---*/
			if (IsEmpty(&que))
			{
				printf("ㅇㅇ 비어있음\n");
			}
			else
			{
				printf("ㄴㄴ 비어있지 않습니다\n");
			}
			break;

		case 9: /*--- 큐가 가득 찼는가? ---*/
			if (IsFull(&que))
			{
				printf("ㅇㅇ 가득찼음\n");
			}
			else
			{
				printf("ㄴㄴ 아직 여유가 있습니다\n");
			}
			break;

		case 10: /*--- 큐에서 검색 ---*/
			printf("찾고자 하는 숫자 입력 : ");
			scanf_s("%d", &x);
			x = Search(&que, x);
			printf("큐의 %d 번째에 있습니다\n", x);
			break;

		case 11: /*--- 출력 ---*/
			Print(&que);
			break;

		case 12: /*--- 큐 종료 ---*/
			printf("정말 종료 하시겠습니까? (0 : 예 1: 아니오)");
			scanf_s("%d", &x);
			if (!x)
			{
				Terminate(&que);
			}
			break;
		}
	}

	Terminate(&que);

	return 0;
}