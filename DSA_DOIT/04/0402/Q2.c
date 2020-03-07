#include <stdio.h>
#include "IntDoubleStack.h"

int main(void)
{
	IntDoubleStack sF;
	IntDoubleStack sT;
	int x;
	printf("���� �ִ� ũ�� �Է� : ");
	scanf_s("%d", &x);

	if (Initialize(&sF, &sT, x) == -1) {
		puts("������ ������ �����߽��ϴ�.");
		return 1;
	}
	while (1) {
		int menu;
		int idx;
		printf("���� ������ ���� : ����:%d ����:%d / �ִ�뷮 �� : %d\n", Size(&sF), Size(&sT), ((Capacity(&sF) + Capacity(&sT)) - (Size(&sF) + Size(&sT))) / 2);
		printf("1) A�� Push 2) A���� Pop 3) A���� Peek 4) A�� ��� 5) A���� �˻� 6) A�� �ʱ�ȭ\n"
			"7) B�� Push 8) B���� Pop 9) B���� Peek 10) B�� ��� 11) B���� �˻� 12) B�� �ʱ�ȭ\n"
			"13) �� ���� / ���� �� ���� 0) ���� : ");
		scanf_s("%d", &menu);
		if (menu == 0) break;
		switch (menu) {
		case 1: /*--- A�� Ǫ�� ---*/
			printf("�����ͣ�");
			scanf_s("%d", &x);
			if (Push_F(&sF, &sT, x) == -1)
				puts("\a���� : Ǫ�ÿ� �����߽��ϴ�.");
			break;
		case 2: /*--- A���� �� ---*/
			if (Pop_F(&sF, &sT, &x) == -1)
				puts("\a���� : �˿� �����߽��ϴ�.");
			else
				printf("���� �����ʹ� %d�Դϴ�.\n", x);
			break;
		case 3: /*--- A���� ��ũ ---*/
			if (Peek_F(&sF, &x) == -1)
				puts("\a���� : ��ũ�� �����߽��ϴ�.");
			else
				printf("��ũ�� �����ʹ� %d�Դϴ�.\n", x);
			break;
		case 4: /*--- A ��� ---*/
			Print(&sF);
			break;
		case 5: /*--- A���� �˻� ---*/
			printf("�˻� �����ͣ�");
			scanf_s("%d", &x);
			if ((idx = Search(&sF, x)) == -1)
				puts("\a���� : �˻��� �����߽��ϴ�.");
			else
				printf("�����ʹ� �ε��� %d ��ġ�� �ֽ��ϴ�.\n", idx);
			break;
		case 6: /*--- A �ʱ�ȭ ---*/
			Clear_F(&sF, &sT);
			break;
		case 7: /*--- B�� Ǫ�� ---*/
			printf("�����ͣ�");
			scanf_s("%d", &x);
			if (Push_T(&sF, &sT, x) == -1)
				puts("\a���� : Ǫ�ÿ� �����߽��ϴ�.");
			break;
		case 8: /*--- B���� �� ---*/
			if (Pop_T(&sF, &sT, &x) == -1)
				puts("\a���� : �˿� �����߽��ϴ�.");
			else
				printf("���� �����ʹ� %d�Դϴ�.\n", x);
			break;
		case 9: /*--- B���� ��ũ ---*/
			if (Peek_T(&sT, &x) == -1)
				puts("\a���� : ��ũ�� �����߽��ϴ�.");
			else
				printf("��ũ�� �����ʹ� %d�Դϴ�.\n", x);
			break;
		case 10: /*--- B�� ��� ---*/
			Print(&sT);
			break;
		case 11: /*--- B���� �˻� ---*/
			printf("�˻� �����ͣ�");
			scanf_s("%d", &x);
			if ((idx = Search(&sT, x)) == -1)
				puts("\a���� : �˻��� �����߽��ϴ�.");
			else
				printf("�����ʹ� �ε��� %d ��ġ�� �ֽ��ϴ�.\n", idx);
			break;
		case 12: /*--- B �ʱ�ȭ ---*/
			Clear_T(&sF, &sT);
			break;
		case 13: /*--- �� ���� / ���� �� ���� �Ǵ� ---*/
			printf("���� A�� ��� %s.\n", IsEmpty(&sF) ? "�ֽ��ϴ�" : "���� �ʽ��ϴ�");
			printf("���� B�� ��� %s.\n", IsEmpty(&sT) ? "�ֽ��ϴ�" : "���� �ʽ��ϴ�");
			printf("������ ���� %s.\n", IsFull(&sF) || IsFull(&sT) ? "á���ϴ�" : "���� �ʾҽ��ϴ�");
			break;
		}
	}
	Terminate(&sF, &sT);
	return 0;
}