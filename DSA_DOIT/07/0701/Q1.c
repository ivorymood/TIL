#include <stdio.h>
#include <stdlib.h>
#include "IntSet.h"

/*--- 집합 초기화 ---*/
int Initialize(IntSet* s, int max)
{
	s->num = 0;
	if ((s->set = calloc(max, sizeof(int))) == NULL)
	{
		s->max = 0;
		return -1;
	}
	s->max = max;
	return 0;
}

/*--- 집합 s에 n이 들어있는지 확인 ---*/
int IsMember(const IntSet* s, int n)
{
	for (int i = 0; i < s->num; ++i)
	{
		if (s->set[i] == n)
		{
			return i;
		}
	}
	return -1;
}

/*--- 집합 s에 n을 추가 ---*/
void Add(IntSet* s, int n)
{
	if ((s->num < s->max) && (IsMember(s, n) == -1))
	{
		s->set[s->num++] = n;
	}
}

/*--- 집합 s에서 n을 삭제 ---*/
void Remove(IntSet* s, int n)
{
	int idx;
	if ((idx = IsMember(s, n)) != -1)
	{
		s->set[idx] = s->set[--s->num];		/* 마지막 요소를 삭제 위치로 옮김 */
	}
}

/*--- 집합 s에 넣을 수 있는 최대 원소 개수를 반환 ---*/
int Capacity(const IntSet* s)
{
	return s->max;
}

/*--- 집합 s의 원소 개수 ---*/
int Size(const IntSet* s)
{
	return s->num;
}

/*--- 집합 s2를 s1에 대입 ---*/
void Assign(IntSet* s1, const IntSet* s2)
{
	int N = (s1->max < s2->num) ? s1->max : s2->num;

	for (int i = 0; i < N; ++i)
	{
		s1->set[i] = s2->set[i];
	}
	s1->num = N;
}

/*--- 집합 s1과 s2가 같은지 확인 ---*/
int Equal(const IntSet* s1, const IntSet* s2)
{
	// 크기가 다를 경우
	if (Size(s1) != Size(s2))
	{
		return 0;
	}

	int j;
	for (int i = 0; i < s1->num; ++i)
	{
		for (j = 0; j < s2->num; ++j)
		{
			if (s1->set[i] == s2->set[j])
			{
				break;
			}
		}
		// s1의 원소를 s2에서 발견하지 못했을 경우
		if (j == s2->num)
		{
			return 0;
		}
	}
	return 1;
}

/*--- 집합 s2와 s3의 합집합을 s1에 대입 ---*/
IntSet* Union(IntSet* s1, const IntSet* s2, const IntSet* s3)
{
	Assign(s1, s2);
	for (int i = 0; i < s3->num; ++i)
	{
		Add(s1, s3->set[i]);
	}
	return s1;
}

/*--- 집합 s2와 s3의 교집합을 s1에 대입 ---*/
IntSet* Intersection(IntSet* s1, const IntSet* s2, const IntSet* s3)
{
	s1->num = 0;
	for (int i = 0; i < s2->num; ++i)
	{
		for (int j = 0; j < s3->num; ++j)
		{
			if (s2->set[i] == s3->set[j])
			{
				Add(s1, s2->set[i]);
			}
		}
	}
	return s1;
}

/*--- 집합 s2에서 s3을 뺀 차집합을 s1에 대입 ---*/
IntSet* Difference(IntSet* s1, const IntSet* s2, const IntSet* s3)
{
	s1->num = 0;
	int j;
	for (int i = 0; i < s2->num; ++i)
	{
		for (j = 0; j < s3->num; ++j)
		{
			if (s2->set[i] == s3->set[j])
			{
				break;
			}
		}
		// s3에 없는 s2요소를 s1에 추가
		if (j == s3->num)
		{
			Add(s1, s2->set[i]);
		}
	}
	return s1;
}

/*--- 집합 s의 모든 원소를 ​​출력 ---*/
void Print(const IntSet* s)
{
	printf("{ ");
	for (int i = 0; i < s->num; ++i)
	{
		printf("%d ", s->set[i]);
	}
	printf("}");
}

/*--- 집합 s의 모든 원소를 ​​출력(줄 바꿈 문자 포함) ---*/
void PrintLn(const IntSet* s)
{
	Print(s);
	putchar('\n');
}

/*--- 집합을 메모리에서 제거 ---*/
void Terminate(IntSet* s)
{
	if (s->set != NULL)
	{
		free(s->set);
		s->max = s->num = 0;
	}
}

/*--- ■ 집합이 가득 찼다면 1, 아니면 0을 반환 ---*/
int IsFull(const IntSet* s)
{
	return s->num >= s->max;
}

/*--- ■ 집합 s2, s3의 대칭 차를 s1에 대입하는 함수 ---*/
IntSet* SymmetricDifference(IntSet* s1, const IntSet* s2, const IntSet* s3)
{
	s1->num = 0;

	for (int i = 0; i < s2->num; ++i)
	{
		if (IsMember(s3, s2->set[i]) == -1)
		{
			Add(s1, s2->set[i]);
		}
	}
	for (int i = 0; i < s3->num; ++i)
	{
		if (IsMember(s2, s3->set[i]) == -1)
		{
			Add(s1, s3->set[i]);
		}
	}
	return s1;
}

/*--- ■ 집합 s1에 s2의 모든 원소를 추가하는 함수(s1 포인터 반환) ---*/
IntSet* ToUnion(IntSet* s1, const IntSet* s2)
{
	for (int i = 0; i < s2->num; ++i)
	{
		Add(s1, s2->set[i]);
	}
	return s1;
}

/*--- ■ 집합 s1에서 s2에 들어 있지 않은 모든 원소를 삭제하는 함수(s1 포인터 반환) ---*/
IntSet* ToIntersection(IntSet* s1, const IntSet* s2)
{
	int i = 0;

	// Remove함수 : 마지막 요소를 삭제 위치로 옮김 
	// --> 삭제한 인덱스에 새로 생긴 요소를 다시 한번 검사해야함
	while (i < s1->num)
	{
		if (IsMember(s2, s1->set[i]) == -1)
		{
			Remove(s1, s1->set[i]);
		}
		else
		{
			i++;
		}
	}

	return s1;
}

/*--- ■ 집합 s1에서 s2에 들어 있는 모든 원소를 삭제하는 함수(s1 포인터 반환) ---*/
IntSet* ToDifference(IntSet* s1, const IntSet* s2)
{
	for (int i = 0; i < s2->num; ++i)
	{
		Remove(s1, s2->set[i]);
	}
	return s1;
}

/*--- ■ 집합 s1이 s2의 부분집합이면 1, 아니면 0을 반환 ---*/
int IsSubset(const IntSet* s1, const IntSet* s2)
{
	int j;
	for (int i = 0; i < s1->num; ++i)
	{
		for (j = 0; j < s2->num; ++j)
		{
			if (s1->set[i] == s2->set[j])
			{
				break;
			}
		}
		// s1의 요소가 s2에 없으면
		if (j == s2->num)
		{
			return 0;
		}
	}
	return 1;
}

/*--- ■ 집합 s1이 s2의 진부분집합이면 1, 아니면 0을 반환 ---*/
int IsProperSubset(const IntSet* s1, const IntSet* s2)
{
	// s1의 요소 개수가 s2의 요소 개수보다 같거나 크면
	if (s1->num >= s2->num)
	{
		return 0;
	}

	return IsSubset(s1, s2);
}

/*--- ■ 집합의 모든 원소를 삭제하는 함수 ---*/
void Clear(IntSet* s)
{
	s->num = 0;
}