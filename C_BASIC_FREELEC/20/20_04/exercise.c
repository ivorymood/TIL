#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct simple_teacher 
{
	char name[20];
	int age;
	int number;
};

struct simple_student
{
	char name[20];
	int age;
	int number;

	struct simple_teacher* pTeacher;
};

int main()
{
	int teacher_size = 0;
	int student_size = 0;
	struct simple_teacher* psimple_teacher = NULL;
	struct simple_student* psimple_student = NULL;

	printf("선생님 수는?");
	scanf_s("%d", &teacher_size);
	printf("학생 수는?");
	scanf_s("%d", &student_size);

	psimple_teacher = (struct simple_teacher*) malloc(sizeof(struct simple_teacher) * teacher_size);
	if (psimple_teacher == NULL) return 0;
	psimple_student = (struct simple_student*) malloc(sizeof(struct simple_student) * student_size);
	if (psimple_student == NULL) return 0;


	for (int i = 0; i < teacher_size; i++)
	{
		printf("선생님 이름 입력 : ");
		scanf_s("%s", psimple_teacher[i].name, 20);
		
		printf("선생님 나이 입력 : ");
		scanf_s("%d", &psimple_teacher[i].age);
		printf("선생님 교번 입력 : ");
		scanf_s("%d", &psimple_teacher[i].number);
	}

	for (int i = 0; i < student_size; i++)
	{
		printf("학생 이름 입력 : ");
		scanf_s("%s", psimple_student[i].name, 20);

		printf("학생 나이 입력 : ");
		scanf_s("%d", &psimple_student[i].age);
		printf("학생 교번 입력 : ");
		scanf_s("%d", &psimple_student[i].number);
	}

	for (int i = 0; i < teacher_size; i++)
	{
		printf("선생님 이름: %s, 나이 %d, 교번 %d\n", psimple_teacher[i].name, psimple_teacher[i].age, psimple_teacher[i].number);
	}

	for (int i = 0; i < student_size; i++)
	{
		printf("학생 이름: %s, 나이 %d, 교번 %d\n", psimple_student[i].name, psimple_student[i].age, psimple_student[i].number);
	}

	if (psimple_teacher != NULL) free(psimple_teacher);
	if (psimple_student != NULL) free(psimple_student);
	return 0;
}