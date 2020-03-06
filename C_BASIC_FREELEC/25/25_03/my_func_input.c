#include <stdio.h>
#include "my_struct.h"
#include "my_func_input.h"

int input_teacher_student_count(int* pteacer_count, int* pstudent_count)
{
	if (pteacer_count == NULL || pteacer_count == NULL) 
	{
		return 0;
	}

	printf("선생님 수 입력");
	scanf_s("%d", pteacer_count);
	printf("학생수 수 입력");
	scanf_s("%d", pstudent_count);

	if (*pteacer_count == 0 || *pstudent_count == 0)
	{
		return 0;
	}

	return 1;
}

void input_teacher_students(psimple_teacher pTeacher, int teacer_count, psimple_student pStudent, int student_count)
{

}
