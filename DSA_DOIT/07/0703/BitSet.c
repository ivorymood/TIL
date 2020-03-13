/* 비트 벡터에 의한 정수 집합 연산(소스 부분) */
#include <stdio.h>
#include "BitSet.h"

/*--- 집합 s에 n이 들어있는지 확인 ---*/
int IsMember(BitSet s, int n)
{
	return s & SetOf(n);
}

/*--- 집합 s에 n을 추가 ---*/
void Add(BitSet* s, int n)
{
	*s |= SetOf(n);
}

/*--- 집합 s에서 n을 삭제 ---*/
void Remove(BitSet* s, int n)
{
	*s &= ~SetOf(n);
}

/*--- 집합 s의 원소 개수를 반환 ---*/
int Size(BitSet s)
{
	int n = 0;
	for (; s != BitSetNull; n++)
		s &= s - 1;
	return n;
}

/*--- 집합 s의 모든 원소를 ​​출력 ---*/
void Print(BitSet s)
{
	int i;
	printf("{ ");
	for (i = 0; i < BitSetBits; i++)
		if (IsMember(s, i))
			printf("%d ", i);
	printf("}");
}

/*--- 집합 s의 모든 원소를 ​​출력(줄 바꿈 문자 포함) ---*/
void PrintLn(BitSet s)
{
	Print(s);
	putchar('\n');
}

/*--- 집합 s1, s2의 대칭 차집합 ​​출력 ---*/
void PrintSymmetricDifference(BitSet s1, BitSet s2)
{
	int isMember_s1;
	int isMember_s2;

	printf("{ ");
	for (int i = 0; i < BitSetBits; ++i)
	{
		isMember_s1 = IsMember(s1, i);
		isMember_s2 = IsMember(s2, i);

		if (isMember_s1 && isMember_s2)
		{
			continue;
		}
		if (isMember_s1 || isMember_s2)
		{
			printf("%d ", i);
		}
	}
	printf("}");
	putchar('\n');
}