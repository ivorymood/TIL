#pragma once
#include "my_struct.h"

#ifndef _MY_FUNC_INPUT
#define _MY_FUNC_INPUT

int input_teacher_student_count(int* pteacer_count, int* pstudent_count);
void input_teacher_students(psimple_teacher pTeacher, int teacer_count, psimple_student pStudent, int student_count);

#endif 