#include <stdio.h>
#include <errno.h>
#include <string.h>

typedef struct _my_student
{
	char name[12];
	int age;
	int gender;
} my_student;

int main()
{
	FILE* pfile = NULL;
	char* file_path = "c:\\temp\\2.bin";
	int result = 0;

	char buffer[1024] = { 0 };
	my_student student = { 0 };

	int count = 0;

	printf("�Է��� �л� ���� �� ���Դϱ�?");
	scanf_s("%d", &count);

	if (count <= 0)
	{
		return 0;
	}

	result = fopen_s(&pfile, file_path, "wb");

	if (result == 0)
	{
		printf("����[%s], ���[wb] fopen( ) ����\n", file_path);

		// �л����� ���Ͽ� �Է�
		fwrite(&count, sizeof(int), 1, pfile);

		for (int i = 0; i < count; i++)
		{
			printf("�̸���? ");
			scanf_s("%s", buffer, sizeof(buffer));
			memcpy(&student.name, buffer, sizeof(student.name));

			printf("���̴�? ");
			scanf_s("%d", &student.age);

			printf("������? (1: ����, 2:���� )");
			scanf_s("%d", &student.gender);
			
			//write
			result = fwrite(&student, sizeof(student), 1, pfile);

			printf("fwrite( ) ��� : %d\n", result);
		}

		fclose(pfile);
	}
	else 
	{
		printf("����[%s], ���[wb], fopen( ) ����, ������ȣ : %d\n", file_path, errno);
	}

	return 0;
}