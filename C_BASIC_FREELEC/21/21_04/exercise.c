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

	printf("성적 타입을 입력해 주세요(0: 등급, 1: 점수)?");
	scanf_s("%d", &grade_type);

	switch (grade_type)
	{
	case TYPE_GRADE:
		printf("등급을 입력해 주세요 (A~F)? ");
		char temp[10] = { 0 };
		scanf_s("%s", temp, 2);
		myScore.result.grade = temp[0];
		//scanf_s("%c", &myScore.result.grade, 4);
		break;
	case TYPE_SCORE:
		printf("점수를 입력해 주세요 (0~100)? ");
		scanf_s("%d", &myScore.result.score);
		break;
	default:
		printf("잘못된 성적 타입입니다.");
		break;
	}
	
	switch (grade_type)
	{
	case TYPE_GRADE:
		printf("입력하신 등급은 %c 입니다. ", myScore.result.grade);
		break;
	case TYPE_SCORE:
		printf("입력하신 점수는 %d 입니다. ", myScore.result.score);
		break;
	default:
		break;
	}

	return 0;
}