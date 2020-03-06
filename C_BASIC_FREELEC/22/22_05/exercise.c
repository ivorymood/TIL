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

	printf("입력할 학생 수는 몇 명입니까?");
	scanf_s("%d", &count);

	if (count <= 0)
	{
		return 0;
	}

	result = fopen_s(&pfile, file_path, "wb");

	if (result == 0)
	{
		printf("파일[%s], 모드[wb] fopen( ) 성공\n", file_path);

		// 학생수를 파일에 입력
		fwrite(&count, sizeof(int), 1, pfile);

		for (int i = 0; i < count; i++)
		{
			printf("이름은? ");
			scanf_s("%s", buffer, sizeof(buffer));
			memcpy(&student.name, buffer, sizeof(student.name));

			printf("나이는? ");
			scanf_s("%d", &student.age);

			printf("성별은? (1: 남자, 2:여자 )");
			scanf_s("%d", &student.gender);
			
			//write
			result = fwrite(&student, sizeof(student), 1, pfile);

			printf("fwrite( ) 결과 : %d\n", result);
		}

		fclose(pfile);
	}
	else 
	{
		printf("파일[%s], 모드[wb], fopen( ) 실패, 오류번호 : %d\n", file_path, errno);
	}

	return 0;
}