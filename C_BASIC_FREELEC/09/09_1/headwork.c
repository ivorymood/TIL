#include <stdio.h>

int get_student_num();
int check_student_num(int student_num);
void get_student_scores(int score_kor[100], int num_student);
int calc_total_score(int score_kor[100], int num_student);
double calc_averate_score(int total_score, int num_student);
void print_score(int num_student, int total_score, double average_score);

int main()
{
	int num_student = 0;
	int score_student[100] = { 0 };
	int total_score = 0;
	double average_score = 0;

	num_student = get_student_num();

	if (check_student_num(num_student) < 0)
	{
		return -1;
	}
	
	get_student_scores(score_student, num_student);

	total_score = calc_total_score(score_student, num_student);
	
	average_score = calc_averate_score(total_score, num_student);

	print_score(num_student, total_score, average_score);

	return 0;
}

int get_student_num()
{
	int num_student = 0;

	printf("학생수는? ");
	scanf_s("%d", &num_student);
	printf("학생수 : %d \n", num_student);

	return num_student;
}

int check_student_num(int student_num)
{
	if (student_num < 0 || student_num > 100)
	{
		return -1;
	}
	return 0;
}

void get_student_scores(int score_kor[100], int num_student)
{
	for (int i = 0; i < num_student; i++)
	{
		printf("%d 번째 학생 점수는?", i + 1);
		scanf_s("%d", &score_kor[i]);
	}
}

int calc_total_score(int score_kor[100], int num_student)
{
	int total_score = 0;
	for (int i = 0; i < num_student; i++)
	{
		total_score += score_kor[i];
	}
	return total_score;
}

double calc_averate_score(int total_score, int num_student)
{
	return (double)total_score / num_student;
}

void print_score(int num_student, int total_score, double average_score) 
{
	printf("학생수 : %d \n총점 : %d\n평균 : %f", num_student, total_score, average_score);
}