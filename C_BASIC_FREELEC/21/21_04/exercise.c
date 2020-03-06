#include <stdio.h>

typedef enum _GradeType 
{
	TYPE_GRADE,
	TYPE_SCORE
} GradeType;

typedef struct _my_score
{
	GradeType type;
	union
	{
		char grade;
		int score;
	} result;
} my_score;

int main()
{
	int grade_type = TYPE_GRADE;
	my_score myScore = { 0 };

	printf("���� Ÿ���� �Է��� �ּ���(0: ���, 1: ����)?");
	scanf_s("%d", &grade_type);

	switch (grade_type)
	{
	case TYPE_GRADE:
		printf("����� �Է��� �ּ��� (A~F)? ");
		char temp[10] = { 0 };
		scanf_s("%s", temp, 2);
		myScore.result.grade = temp[0];
		//scanf_s("%c", &myScore.result.grade, 4);
		break;
	case TYPE_SCORE:
		printf("������ �Է��� �ּ��� (0~100)? ");
		scanf_s("%d", &myScore.result.score);
		break;
	default:
		printf("�߸��� ���� Ÿ���Դϴ�.");
		break;
	}
	
	switch (grade_type)
	{
	case TYPE_GRADE:
		printf("�Է��Ͻ� ����� %c �Դϴ�. ", myScore.result.grade);
		break;
	case TYPE_SCORE:
		printf("�Է��Ͻ� ������ %d �Դϴ�. ", myScore.result.score);
		break;
	default:
		break;
	}

	return 0;
}