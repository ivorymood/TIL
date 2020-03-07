/* int�� ť IntQueue�� ����ϴ� ���α׷� */
#include <stdio.h>
#include "IntQueue.h"

int main(void)
{
	IntQueue que;

	if (Initialize(&que, 64) == -1) {
		puts("ť�� ������ �����Ͽ����ϴ�.");
		return 1;
	}

	while (1) {
		int m, x;

		printf("���� ������ �� : %d / %d \n", Size(&que), Capacity(&que));
		printf("(0)  ����      (1)  Initialize (2)  Enque       (3) Deque        (4) Peek\n");
		printf("(5)  Clear     (6)  Capacity   (7)  Size       (8) IsEmpty    (9)IsFull\n");
		printf("(10) Search    (11) Print      (12) Terminate");
		scanf_s("%d", &m);

		if (m == 0) break;
		switch (m) {

		case 1: /*--- ť �ʱ�ȭ ---*/
			if (que.que != NULL)
			{
				puts("�̹� �ʱ�ȭ�� ������ �ֽ��ϴ�.");
				printf("�����ϰ� �ٽ� �ʱ�ȭ �Ͻðڽ��ϱ�? (0 : �� 1: �ƴϿ�)");
				scanf_s("%d", &x);
				if (!x)
				{
					Terminate(&que);
				}
			}
			printf("���� ũ�� : ");
			scanf_s("%d", &x);
			if (Initialize(&que, x) == -1) {
				puts("���� ������ �����Ͽ����ϴ�.");
			}

			break;

		case 2: /*--- ��ť ---*/
			printf("������ : "); scanf_s("%d", &x);
			if (Enque(&que, x) == -1)
				puts("\a���� : ��ť�� �����Ͽ����ϴ�.");
			break;

		case 3: /*--- ��ť ---*/
			if (Deque(&que, &x) == -1)
				puts("\a���� : ��ť�� �����Ͽ����ϴ�.");
			else
				printf("��ť�� �����ʹ� %d�Դϴ�.\n", x);
			break;

		case 4: /*--- ��ũ ---*/
			if (Peek(&que, &x) == -1)
				puts("\a���� : ��ũ�� �����Ͽ����ϴ�.");
			else
				printf("��ũ�� �����ʹ� %d�Դϴ�.\n", x);
			break;

		case 5: /*--- ��� �����͸� ���� ---*/
			Clear(&que);
			printf("ť ���� �Ϸ�\n");
			break;

		case 6: /*--- ť�� �ִ� �뷮 ---*/
			printf("���� ť �뷮�� %d �Դϴ� \n", Capacity(&que));
			break;

		case 7: /*--- ť�� ����� �������� ���� ---*/
			printf("���� ť�� �׿��ִ� ������ ���� %d �Դϴ� \n", Size(&que));
			break;

		case 8: /*--- ť�� ��� �ִ°�? ---*/
			if (IsEmpty(&que))
			{
				printf("���� �������\n");
			}
			else
			{
				printf("���� ������� �ʽ��ϴ�\n");
			}
			break;

		case 9: /*--- ť�� ���� á�°�? ---*/
			if (IsFull(&que))
			{
				printf("���� ����á��\n");
			}
			else
			{
				printf("���� ���� ������ �ֽ��ϴ�\n");
			}
			break;

		case 10: /*--- ť���� �˻� ---*/
			printf("ã���� �ϴ� ���� �Է� : ");
			scanf_s("%d", &x);
			x = Search(&que, x);
			printf("ť�� %d ��°�� �ֽ��ϴ�\n", x);
			break;

		case 11: /*--- ��� ---*/
			Print(&que);
			break;

		case 12: /*--- ť ���� ---*/
			printf("���� ���� �Ͻðڽ��ϱ�? (0 : �� 1: �ƴϿ�)");
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