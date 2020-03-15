/* ȸ�� ������ Memeber(�ҽ���) */
#include "Member.h"

/*--- ȸ�� ��ȣ �� �Լ� ---*/
int MemberNoCmp(const Member* x, const Member* y)
{
	return x->no < y->no ? -1 : x->no > y->no ? 1 : 0;
}

/*--- ȸ�� �̸� �� �Լ� ---*/
int MemberNameCmp(const Member* x, const Member* y)
{
	return strcmp(x->name, y->name);
}

/*--- ȸ�� ������(��ȣ�� �̸�)�� ǥ��(�� �ٲ� ����) ---*/
void PrintMember(const Member* x)
{
	printf("%d %s", x->no, x->name);
}

/*--- ȸ�� ������(��ȣ�� �̸�)�� ǥ��(�� �ٲ� ����) ---*/
void PrintLnMember(const Member* x)
{
	printf("%d %s\n", x->no, x->name);
}

/*--- ȸ�� ������(��ȣ�� �̸�)�� �о� ���� ---*/
Member ScanMember(const char* message, int sw)
{
	Member temp;
	printf("%s�ϴ� �����͸� �Է��ϼ���.\n", message);
	if (sw & MEMBER_NO) { printf("��ȣ : "); scanf_s("%d", &temp.no); }
	if (sw & MEMBER_NAME) { printf("�̸� : "); scanf_s("%s", temp.name, 20); }

	return temp;
}