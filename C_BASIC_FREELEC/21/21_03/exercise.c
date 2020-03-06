#include <stdio.h>

typedef enum _Grade {
	GRADE_F, GRADE_A = 100, GRADE_B
} Grade;

typedef struct _simple_student
{
	long number;
	Grade grade;
} simple_student, *psimple_student;

//char get_grade_char(Grade grade);
void print_student_info(simple_student student);

int main()
{
	simple_student student1 = { 1, GRADE_A };
	simple_student student2 = { 2, GRADE_B };
	simple_student student3 = { 3, GRADE_F };

	print_student_info(student1);
	print_student_info(student2);
	print_student_info(student3);

	return 0;
}
/*
char get_grade_char(Grade grade)
{

}
*/

void print_student_info(simple_student student)
{
	printf("학번: %d 점수: %d\n", student.number, student.grade);
}