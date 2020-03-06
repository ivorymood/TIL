#include <stdio.h>
#include <stdlib.h>
#include "my_struct.h"
#include "my_func_input.h"
#include "my_func_print.h"

int main()
{
	int student_count = 0, teacher_count = 0;
	psimple_teacher pTeacher = NULL;
	psimple_student pStudent = NULL;

	if (0 == input_teacher_student_count(&teacher_count, &student_count))
	{
		return 0;
	}

	pTeacher = (psimple_teacher)malloc(sizeof(simple_teacher) * teacher_count);
	pStudent = (psimple_student)malloc(sizeof(simple_student) * student_count);

	if (pTeacher == NULL || pStudent == NULL)
	{
		printf("메모리 할당에 실패했습니다 \n");
		return 0;
	}

	input_teacher_students(pTeacher, teacher_count, pStudent, student_count);
	print_teacher_students(pTeacher, teacher_count, pStudent, student_count);

	if (pTeacher != NULL) free(pTeacher);
	if (pStudent != NULL) free(pStudent);

	return 0;
}