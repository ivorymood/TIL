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

	printf("������ ����?");
	scanf_s("%d", &teacher_size);
	printf("�л� ����?");
	scanf_s("%d", &student_size);

	psimple_teacher = (struct simple_teacher*) malloc(sizeof(struct simple_teacher) * teacher_size);
	if (psimple_teacher == NULL) return 0;
	psimple_student = (struct simple_student*) malloc(sizeof(struct simple_student) * student_size);
	if (psimple_student == NULL) return 0;


	for (int i = 0; i < teacher_size; i++)
	{
		printf("������ �̸� �Է� : ");
		scanf_s("%s", psimple_teacher[i].name, 20);
		
		printf("������ ���� �Է� : ");
		scanf_s("%d", &psimple_teacher[i].age);
		printf("������ ���� �Է� : ");
		scanf_s("%d", &psimple_teacher[i].number);
	}

	for (int i = 0; i < student_size; i++)
	{
		printf("�л� �̸� �Է� : ");
		scanf_s("%s", psimple_student[i].name, 20);

		printf("�л� ���� �Է� : ");
		scanf_s("%d", &psimple_student[i].age);
		printf("�л� ���� �Է� : ");
		scanf_s("%d", &psimple_student[i].number);
	}

	for (int i = 0; i < teacher_size; i++)
	{
		printf("������ �̸�: %s, ���� %d, ���� %d\n", psimple_teacher[i].name, psimple_teacher[i].age, psimple_teacher[i].number);
	}

	for (int i = 0; i < student_size; i++)
	{
		printf("�л� �̸�: %s, ���� %d, ���� %d\n", psimple_student[i].name, psimple_student[i].age, psimple_student[i].number);
	}

	if (psimple_teacher != NULL) free(psimple_teacher);
	if (psimple_student != NULL) free(psimple_student);
	return 0;
}