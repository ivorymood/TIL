#pragma once

#ifndef _MY_STRUCT
#define _MY_STRUCT
typedef struct _simple_teacher
{
	char name[20];
	int age;
	long number;
} simple_teacher, * psimple_teacher;
#endif

typedef struct _simple_student
{
	char name[20];
	int age;
	long number;
	psimple_teacher pTeacher;
} simple_student, *psimple_student;

