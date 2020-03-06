#include <stdio.h>
#include <string.h>

struct simple_teacher {

	char name[20];
	char class_name[10];
	int age;
};

int main()
{
	struct simple_teacher teacher1 = {"홍길동", "영어", 38};
	struct simple_teacher teacher2 = { 0 };

	strcpy_s(teacher2.name, 20, "김철수");
	strcpy_s(teacher2.class_name, 10, "수학");
	teacher2.age = 39;

	printf("이름 %s\n", teacher1.name);
	printf("담당과목 %s\n", teacher1.class_name);
	printf("나이 %d\n", teacher1.age);

	printf("이름 %s\n", teacher2.name);
	printf("담당과목 %s\n", teacher2.class_name);
	printf("나이 %d\n", teacher2.age);

	return 0;
}