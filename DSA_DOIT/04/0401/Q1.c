/* int�� ���� IntStack�� ��� */
#include <stdio.h>
#include "IntStack.h"

int main(void)
{
	IntStack s;
	if (Initialize(&s, 64) == -1) {
		puts("���� ������ �����Ͽ����ϴ�.");
		return 1;
	}

	while (1) {
		int menu, x;

		printf("���� ������ �� : %d / %d\n", Size(&s), Capacity(&s));
		printf("(0)  ����      (1)  Initialize (2)  Push       (3) Pop        (4) Peek\n");
		printf("(5)  Clear     (6)  Capacity   (7)  Size       (8) IsEmpty    (9)IsFull\n");
		printf("(10) Search    (11) Print      (12) Terminate");
		scanf_s("%d", &menu);
		if (menu == 0) break;

		switch (menu) {
		case 1: /*--- �ʱ�ȭ ---*/
			if (s.stk != NULL)
			{
				puts("�̹� �ʱ�ȭ�� ������ �ֽ��ϴ�.");
				printf("�����ϰ� �ٽ� �ʱ�ȭ �Ͻðڽ��ϱ�? (0 : �� 1: �ƴϿ�)");
				scanf_s("%d", &x);
				if (!x)
				{
					Terminate(&s);
				}
			}
			printf("���� ũ�� : ");
			scanf_s("%d", &x);
			if (Initialize(&s, x) == -1) {
				puts("���� ������ �����Ͽ����ϴ�.");
			}
			break;

		case 2: /*--- Ǫ��---*/
			printf("������ : ");
			scanf_s("%d", &x);
			if (Push(&s, x) == -1)
				puts("\a���� : Ǫ�ÿ� �����Ͽ����ϴ�.");
			break;

		case 3: /*--- �� ---*/
			if (Pop(&s, &x) == -1)
				puts("\a���� : �˿� �����Ͽ����ϴ�.");
			else
				printf("�� �����ʹ� %d�Դϴ�.\n", x);
			break;

		case 4: /*--- ��ũ ---*/
			if (Peek(&s, &x) == -1)
				puts("\a���� : ��ũ�� �����Ͽ����ϴ�.");
			else
				printf("��ũ �����ʹ� %d�Դϴ�.\n", x);
			break;

		case 5: /*--- ���� ���� ---*/
			Clear(&s);
			printf("���� ���� �Ϸ�\n");
			break;

		case 6: /*--- ���� �뷮 ---*/
			printf("���� ���� �뷮�� %d �Դϴ� \n", Capacity(&s));
			break;

		case 7: /*--- ���ÿ� �׿��ִ� ������ �� ---*/
			printf("���� ���ÿ� �׿��ִ� ������ ���� %d �Դϴ� \n", Size(&s));
			break;

		case 8: /*--- ������ ����ִ��� Ȯ�� ---*/
			if (IsEmpty(&s))
			{
				printf("���� �������\n");
			}
			else
			{
				printf("���� ������� �ʽ��ϴ�\n");
			}
			break;

		case 9: /*--- ������ ����á���� Ȯ�� ---*/
			if (IsFull(&s))
			{
				printf("���� ����á��\n");
			}
			else
			{
				printf("���� ���� ������ �ֽ��ϴ�\n");
			}
			break;

		case 10: /*--- ���ÿ��� �˻� ---*/
			printf("ã���� �ϴ� ���� �Է� : ");
			scanf_s("%d", &x);
			x = Search(&s, x);
			printf("������ %d ��°�� �ֽ��ϴ�\n", x);
			break;

		case 11: /*--- ��� ---*/
			Print(&s);
			break;

		case 12: /*--- ���� ���� ---*/
			printf("���� ���� �Ͻðڽ��ϱ�? (0 : �� 1: �ƴϿ�)");
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