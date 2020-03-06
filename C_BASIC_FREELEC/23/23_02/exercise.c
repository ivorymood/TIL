#include <io.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

int main(int argc, char** argv)
{
	int result = 0;
	int search_handle = 0;
	struct _finddata_t fileinfo = { 0 };
	char file_path[sizeof(argv[1])] = {0};
	char* pathf = "\\*.*";

	if (argc < 2)
	{
		printf("usage: %s [path]\n", argv[0]);
		return 0;
	}

	strcpy_s(file_path, sizeof(file_path), argv[1]);
	strcat_s(file_path, sizeof(file_path) + sizeof(pathf), pathf);

	printf("%s\n", file_path);

	search_handle = _findfirst(file_path, &fileinfo);
	if (search_handle != -1)
	{
		while (result != -1)
		{
			if (_A_SUBDIR == fileinfo.attrib)
			{
				printf("폴더 : %s, 크기 : %d\n", fileinfo.name, fileinfo.size);
			}
			else
			{
				printf("파일 : %s, 크기 : %d\n", fileinfo.name, fileinfo.size);
			}
			result = _findnext(search_handle, &fileinfo);
		}
		_findclose(search_handle);
	}
	else
	{
		printf("함수 _findfirst( ) [%s] 실패 : %d\n", file_path, errno);
	}

	return 0;
}