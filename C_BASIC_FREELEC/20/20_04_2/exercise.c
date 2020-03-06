#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct simple_student
{
	char name[20];
	int age;
	long number;
	int score;

	struct simple_student* pnext;
};

void add_student(struct simple_student *pstudents, struct simple_student student);
void print_student_info(struct simple_student* pstudent);

int main()
{
	struct simple_student students = { 0 };
	struct simple_student temp_student = { 0 };

	strcpy_s(temp_student.name, 20, "홍길동");
	temp_student.age = 20;
	temp_student.number = 1001;
	temp_student.score = 90;
	temp_student.pnext = NULL;
	add_student(&students, temp_student);

	strcpy_s(temp_student.name, 20, "이영희");
	temp_student.age = 19;
	temp_student.number = 1002;
	temp_student.score = 50;
	temp_student.pnext = NULL;
	add_student(&students, temp_student);

	print_student_info(&students);

	return 0;
}

void add_student(struct simple_student* pstudents, struct simple_student student)
{
	if (pstudents == NULL)
	{
		printf("오류!! add_student()에 NULL이 전달됨 \n");
		return;
	}

	struct simple_student* pfirst_student = NULL;
	struct simple_student* pnew_student = NULL;

	pfirst_student = pstudents->pnext;
	pnew_student = (struct simple_student*) malloc(sizeof(struct simple_student));

	if (pnew_student == NULL)
	{
		printf("오류!! add_student()에서 malloc()가 실패함 \n");
	}

	*pnew_student = student;
	pnew_student->pnext = NULL;

	pstudents->pnext = pnew_student;

	if (pfirst_student != NULL)
	{
		pnew_student->pnext = pfirst_student;
	}
}

void print_student_info(struct simple_student* pstudent)
{
	if (pstudent == NULL)
	{
		printf("오류!! print_student_info()에 NULL이 전달됨 \n");
		return;
	}

	struct simple_student* pnext_student = NULL;
	pnext_student = pstudent->pnext;

	while (pnext_student != NULL)
	{
		printf("이름: %s\n", pnext_student->name);
		printf("나이: %d\n", pnext_student->age);
		printf("학번: %ld\n", pnext_student->number);
		printf("점수: %d\n", pnext_student->score);

		pnext_student = pnext_student->pnext;
	}

}