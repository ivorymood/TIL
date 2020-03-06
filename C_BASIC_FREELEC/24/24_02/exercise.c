#include <stdio.h>

#define LOG_ERROR 1
#define LOG_INFO 2

#define LOGPRINT(PREFIX, LEVEL, ARGS) \
if (g_log_level >= LEVEL) \
{ \
	printf("[%s][%s] ", #PREFIX, #LEVEL); \
	if (LEVEL == LOG_ERROR) \
	{ \
		printf("[%s: %d] ", __FILE__, __LINE__); \
	} \
	printf ARGS; \
} 
	


int g_log_level = LOG_INFO;

int func1(int _input);

int main()
{
	int errno = 0;

	LOGPRINT(main(), LOG_INFO, ("START\n"));

	errno = func1(100);
	
	if (errno)
	{
		LOGPRINT(func1(), LOG_ERROR, ("func1() 오류, 에러코드: %d\n", errno));
	}
	else
	{
		LOGPRINT(func1(), LOG_INFO, ("func1() 성공 \n"));
	}

	LOGPRINT(main(), LOG_INFO, ("END\n"));

	return 0;
}

int func1(int _input)
{
	int ret = 0;

	LOGPRINT(func1(), LOG_INFO, ("START- %d\n", _input));

	printf("오류 코드를 입력하세요(0: 성공, 그외: 오류코드)");
	scanf_s("%d", &ret);

	LOGPRINT(func1(), LOG_INFO, ("END = %d\n", ret));

	return ret;
}