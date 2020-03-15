/* ���� ���� ���� ����Ʈ�� ����ϴ� ���α׷� */
#include <stdio.h>
#include "Member.h"
#include "CircDblLinkedList.h"

/*--- �޴� ---*/
typedef enum {
	TERMINATE, INS_FRONT, INS_REAR, RMV_FRONT, RMV_REAR, PRINT_CRNT,
	RMV_CRNT, SRCH_NO, SRCH_NAME, RETRIEVE, PRINT_ALL, NEXT, PREV, CLEAR, PURGE
} Menu;

/*--- �޴� ���� ---*/
Menu SelectMenu(void)
{
	int i, ch;
	char* mstring[] = {
		"�Ӹ��� ��带 ����",      "������ ��带 ����",     "�Ӹ� ��带 ����",
		"���� ��带 ����",        "������ ��带 ���",     "������ ��带 ����",
		"��ȣ�� �˻�",             "�̸����� �˻�",          "n��° ��� ��ȯ",
		"��� ��带 ���",		   "������ ��带 ��������", "������ ��带 ��������", 
		"��� ��带 ����",		   "�ߺ� ��� ����"
	};

	putchar('\n');
	do {
		for (i = TERMINATE; i < PURGE; i++) {
			printf("(%2d) %-22.22s ", i + 1, mstring[i]);
			if ((i % 3) == 2)
				putchar('\n');
		}
		printf("(0) ���� : ");
		scanf_s("%d", &ch);
	} while (ch < TERMINATE || ch > PURGE);

	return (Menu)ch;
}

/*--- ���� ---*/
int main(void)
{
	Menu menu;
	Dlist list;
	Initialize(&list);		/* ���� ���� ���� ����Ʈ�� �ʱ�ȭ */
	do {
		Member x;
		int n = 0;
		switch (menu = SelectMenu()) {

			/* �Ӹ��� ��带 ���� */
		case INS_FRONT:
			x = ScanMember("�Ӹ��� ����", MEMBER_NO | MEMBER_NAME);
			InsertFront(&list, &x);
			break;

			/* ������ ��带 ���� */
		case INS_REAR:
			x = ScanMember("������ ����", MEMBER_NO | MEMBER_NAME);
			InsertRear(&list, &x);
			break;

			/* �Ӹ� ��带 ���� */
		case RMV_FRONT:
			RemoveFront(&list);
			break;

			/* ���� ��带 ���� */
		case RMV_REAR:
			RemoveRear(&list);
			break;

			/* ������ ����� �����͸� ��� */
		case PRINT_CRNT:
			PrintLnCurrent(&list);
			break;

			/* ������ ��带 ���� */
		case RMV_CRNT:
			RemoveCurrent(&list);
			break;

			/* ��ȣ�� �˻� */
		case SRCH_NO:
			x = ScanMember("�˻�", MEMBER_NO);
			if (search(&list, &x, MemberNoCmp) != NULL)
				PrintLnCurrent(&list);
			else
				puts("�� ��ȣ�� �����Ͱ� �����ϴ�.");
			break;

			/* �̸����� �˻� */
		case SRCH_NAME:
			x = ScanMember("�˻�", MEMBER_NAME);
			if (search(&list, &x, MemberNameCmp) != NULL)
				PrintLnCurrent(&list);
			else
				puts("�� �̸��� �����Ͱ� �����ϴ�.");
			break;

			/*--- (Q4) �Ӹ����� n�� ���� ��忡 ���� ������ ��ȯ---*/
		case RETRIEVE:
			printf("n �Է� : ");
			scanf_s("%d", &n);
			if (Retrieve(&list, n) != NULL)
			{
				PrintCurrent(&list);
			}
			else
			{
				printf("%d ��°�� �����Ͱ� �����ϴ�.", n);
			}
			break;

			break;

			/* ��� ����� �����͸� ��� */
		case PRINT_ALL:
			Print(&list);
			break;

			/* ������ ��� �������� ���� */
		case NEXT:
			Next(&list);
			break;

			/* ������ ��� �������� ���� */
		case PREV:
			Prev(&list);
			break;

			/* ��� ��带 ���� */
		case CLEAR:
			Clear(&list);
			break;

			/*--- (Q4)���� ���� ��带, ���� ������ ��带 ����� ��� ���� ---*/
		case PURGE:
			Purge(&list, MemberNoCmp);
			break;
		}
	} while (menu != TERMINATE);

	Terminate(&list);			/* ���� ���� ���� ����Ʈ ���� */

	return 0;
}