#include <stdio.h>
#include <string.h>

struct simple_teacher {

	char name[20];
	char class_name[10];
	int age;
};

int main()
{
	struct simple_teacher teacher1 = {"ȫ�浿", "����", 38};
	struct simple_teacher teacher2 = { 0 };

	strcpy_s(teacher2.name, 20, "��ö��");
	strcpy_s(teacher2.class_name, 10, "����");
	teacher2.age = 39;

	printf("�̸� %s\n", teacher1.name);
	printf("������ %s\n", teacher1.class_name);
	printf("���� %d\n", teacher1.age);

	printf("�̸� %s\n", teacher2.name);
	printf("������ %s\n", teacher2.class_name);
	printf("���� %d\n", teacher2.age);

	return 0;
}