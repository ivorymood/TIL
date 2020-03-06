#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_student_num();
int alloc_students_score(int num_student, int** ppscore_kor, int** ppscore_eng, int** pscore_math, int** pscore_total);
char** alloc_student_name(int num_student);
void input_student_info(int num_student, int* pscore_kor, int* pscore_eng, int* pscore_math, char** ppstudent_name);
int calc_student_total_score(int num_student, int* pscore_kor, int* pscore_eng, int* pscore_math, int* pscore_total);
void print_students_score(int num_student, int* pscore_total, char** ppstudent_name);
void print_courses_average_score(int num_student, int* pscore_kor, int* pscore_eng, int* pscore_math);
void dealloc_students_name(int num_student, char** ppstudent_name);
void dealloc_students_scores(int* pscore_kor, int* pscore_eng, int* pscore_math, int* pscore_total);

int main()
{
	int num_student = 0;
	int* pscore_kor = NULL;
	int* pscore_eng = NULL;
	int* pscore_math = NULL;
	int* pscore_total = NULL;
	char** ppstudent_name = NULL;

	// �л��� �Է�
	num_student = get_student_num();
	if (num_student <= 0)
	{
		printf("�л����� 0���� Ŀ�� �մϴ� \n");
		return 0;
	}

	// �л� �� ��ŭ 3���� �޸� �Ҵ�
	if (alloc_students_score(num_student, &pscore_kor, &pscore_eng, &pscore_math, &pscore_total))
	{
		// �л� ����ŭ, �л� �̸� �迭 �Ҵ�
		ppstudent_name = (char**)alloc_student_name(num_student);
		if (ppstudent_name == NULL)
		{
			return 0;
		}

		// �л����� ���� �Է�
		input_student_info(num_student, pscore_kor, pscore_eng, pscore_math, ppstudent_name);

		// �л��� ������ ���
		// 0: ����, �׿� ��: ����
		if (calc_student_total_score(num_student, pscore_kor, pscore_eng, pscore_math, pscore_total))
		{
			printf("�л���: %d\n", num_student);
			
			// �л��� ���� ���
			print_students_score(num_student, pscore_total, ppstudent_name);

			// ���� ��� ���� �� ���� ��� ���
			print_courses_average_score(num_student, pscore_kor, pscore_eng, pscore_math);
		}
		else
		{
			printf("���� ��꿡 �����߽��ϴ� \n");
		}

		// �޸� ���� - �л� �̸� ���ڿ�
		dealloc_students_name(num_student, ppstudent_name);
	}
	else
	{
		printf("�޸� �Ҵ� ����: alloc_students_score()\n");
	}

	// �޸� ���� - ���� ����
	dealloc_students_scores(pscore_kor, pscore_eng, pscore_math, pscore_total);

	return 0;
}

int get_student_num()
{
	int student_num = 0;

	printf("�л�����?");
	scanf_s("%d", &student_num);

	return student_num;
}

int alloc_students_score(int num_student, int** ppscore_kor, int** ppscore_eng, int** ppscore_math, int** ppscore_total)
{
	int count = 0;
	*ppscore_kor = (int*)malloc(sizeof(int) * num_student);
	if (*ppscore_kor != NULL) count++;
	*ppscore_eng = (int*)malloc(sizeof(int) * num_student);
	if (*ppscore_kor != NULL) count++;
	*ppscore_math = (int*)malloc(sizeof(int) * num_student);
	if (*ppscore_kor != NULL) count++;
	*ppscore_total = (int*)malloc(sizeof(int) * num_student);
	if (*ppscore_kor != NULL) count++;

	if (count < 4)
	{
		if (*ppscore_kor != NULL) free(ppscore_kor);
		if (*ppscore_eng != NULL) free(ppscore_eng);
		if (*ppscore_math != NULL) free(ppscore_math);
		if (*ppscore_total != NULL) free(ppscore_total);
		return 0;
	}
	return count;
}

char** alloc_student_name(int num_student)
{
	char** ppstudent_name = NULL;
	ppstudent_name = (char**)malloc(sizeof(char*) * num_student);
	return ppstudent_name;
}

void input_student_info(int num_student, int* pscore_kor, int* pscore_eng, int* pscore_math, char** ppstudent_name)
{
	int name_len = 0;
	char szBuffer[1024] = { 0 };

	for (int i = 0; i < num_student; i++) 
	{
		printf("%d��° �л� �̸���?", i);
		scanf_s("%s", szBuffer, 1024);

		name_len = strlen(szBuffer);
		if (name_len > 0)
		{
			ppstudent_name[i] = (char*)malloc(name_len + 1);
			strcpy_s(ppstudent_name[i], name_len + 1, szBuffer);
		}

		printf("%d��° �л� ����������?", i);
		scanf_s("%d", &pscore_kor[i]);
		printf("%d��° �л� ����������?", i);
		scanf_s("%d", &pscore_eng[i]);
		printf("%d��° �л� ����������?", i);
		scanf_s("%d", &pscore_math[i]);
	}
}

int calc_student_total_score(int num_student, int* pscore_kor, int* pscore_eng, int* pscore_math, int* pscore_total)
{
	if (num_student == 0 || pscore_kor == NULL || pscore_eng == NULL || pscore_math == NULL || pscore_total == NULL)
	{
		return 0;
	}

	int count = 0;
	for (int i = 0; i < num_student; i++)
	{
		pscore_total[i] = pscore_kor[i] + pscore_eng[i] + pscore_math[i];
		count++;
	}
	return count;
}

void print_students_score(int num_student, int* pscore_total, char** ppstudent_name)
{
	if (num_student == 0 || pscore_total == NULL || ppstudent_name == NULL)
	{
		return;
	}
	for (int i = 0; i < num_student; i++)
	{
		printf("%d��° �л� �̸�: %s\n", i, ppstudent_name[i]);
		printf("%d��° �л� ���� ���: %d\n", i, pscore_total[i] / 3);
	}
}

void print_courses_average_score(int num_student, int* pscore_kor, int* pscore_eng, int* pscore_math)
{
	int total_kor = 0;
	int total_eng = 0;
	int total_math = 0;

	for (int i = 0; i < num_student; i++)
	{
		total_kor += pscore_kor[i];
		total_eng += pscore_eng[i];
		total_math += pscore_math[i];
	}

	printf("���� ���: %d\n", total_kor / num_student);
	printf("���� ���: %d\n", total_eng / num_student);
	printf("���� ���: %d\n", total_math / num_student);
	printf("���� ���: %d\n", (total_kor + total_eng + total_math)/ num_student / 3);
}

void dealloc_students_name(int num_student, char** ppstudent_name)
{
	if (num_student <= 0 || ppstudent_name == NULL)
	{
		return;
	}

	for (int i = 0; i < num_student; i++)
	{
		if (ppstudent_name[i] != NULL) free(ppstudent_name[i]);
	}
	if (ppstudent_name != NULL) free(ppstudent_name);
}

void dealloc_students_scores(int* pscore_kor, int* pscore_eng, int* pscore_math, int* pscore_total)
{
	if (pscore_kor != NULL) free(pscore_kor);
	if (pscore_eng != NULL) free(pscore_eng);
	if (pscore_math != NULL) free(pscore_math);
	if (pscore_total != NULL) free(pscore_total);
}

int getAverageFrom2DArray(int** ppArray, int index, int type)
{
	if (ppArray == NULL || type < 0 || type > 2)
	{
		return -1;
	}

	int size = 0;
	int total = 0;

	// ��
	if (type == 1)
	{
		size = sizeof(*ppArray) / sizeof(int);
		for (int i = 0; i < size; i++)
		{
			total += ppArray[index][i];
		}
	}

	// ��
	if (type == 2)
	{
		size = sizeof(ppArray) / sizeof(int*);
		for (int i = 0; i < size; i++)
		{
			total += ppArray[i][index];
		}
	}

	return total / size;
}