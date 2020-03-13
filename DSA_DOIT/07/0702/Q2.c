/* Q2 �迭�� ���Ұ� ���������� �����ϴ� int�� SortedIntSet*/
#include <stdio.h>
#include <stdlib.h>
#include "SortedIntSet.h"

int Initialize(SortedIntSet* s, int max)
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

// n�� �ִ� or �־���� ��ġ ã��
// flag : n�� ������ 0, ������ 1
int _search(const SortedIntSet *s, int n, int *flag)
{
	if (s->num <= 0)
	{
		return 0;
	}

	int pl = 0;
	int pr = s->num - 1;
	int pc;
	*flag = 1;

	do
	{
		pc = (pl + pr) / 2;
		if (s->set[pc] == n)
		{
			*flag = 0;
			return pc;
		}
		else if (s->set[pc] < n)
		{
			pl = pc + 1;
		}
		else
		{
			pr = pc - 1;
		}
	} while (pl <= pr);

	return pl;
}

int IsMember(const SortedIntSet* s, int n)
{
	int flag;
	int idx = _search(s, n, &flag);
	return flag ? idx : -1;
}

int IsFull(const SortedIntSet* s)
{
	return s->num >= s->max;
}

void Add(SortedIntSet* s, int n)
{
	int idx, flag;
	if (s->num < s->max)
	{
		idx = _search(s, n, &flag);
		if (flag == 1)
		{
			// idx��° ������ ��Ҹ� �ڷ� 1ĭ�� �ű�
			s->num++;
			for (int i = s->num - 1; i > idx; --i)
			{
				s->set[i] = s->set[i - 1];
			}
			s->set[idx] = n;
		}
	}
}

void Remove(SortedIntSet* s, int n)
{
	int idx, flag;

	if (s->num > 0)
	{
		idx = _search(s, n, &flag);
		if (flag == 0)
		{
			--s->num;
			// idx��° ������ ��ҵ��� ������ 1ĭ�� �ű�
			for (int i = idx; i < s->num; ++i)
			{
				s->set[i] = s->set[i + 1];
			}
		}
	}
}

int Capacity(const SortedIntSet* s)
{
	return s->max;
}

int Size(const SortedIntSet* s)
{
	return s->num;
}

void Assign(SortedIntSet* s1, const SortedIntSet* s2)
{
	int N = (s1->max < s2->num) ? s1->max : s2->num;

	for (int i = 0; i < N; ++i)
	{
		s1->set[i] = s2->set[i];
	}
	s1->num = N;
}

int Equal(const SortedIntSet* s1, const SortedIntSet* s2)
{
	if (Size(s1) != Size(s2))
	{
		return 0;
	}

	//������ ���ٸ�, ���� ��ġ�� ��Ұ� ���� �ٸ��� �ٸ� ����
	for (int i = 0; i < s1->num; ++i)
	{
		if (s1->set[i] != s2->set[i])
		{
			return 0;
		}
	}
	return 1;
}

SortedIntSet* Union(SortedIntSet* s1, const SortedIntSet* s2, const SortedIntSet* s3)
{
	s1->num = 0;
	int k2 = 0;
	int k3 = 0;

	while (k2 < s2->num && k3 < s3->num)
	{
		// s2, s3���� ���� ��Һ��� s1�� �߰�
		if (s2->set[k2] < s3->set[k3])
		{
			s1->set[s1->num++] = s2->set[k2++];
		}
		else if (s2->set[k2] > s3->set[k3])
		{
			s1->set[s1->num++] = s2->set[k3++];
		}
		// s2, s2 ��Ұ� ���� ���
		else
		{
			s1->set[s1->num++] = s2->set[k2++];
			k3++;
		}

		if (s1->num == s1->max)
		{
			return s1;
		}
	}

	if (k2 < s2->num)
	{
		while (k2 < s2->num && s1->num < s1->max)
		{
			s1->set[s1->num++] = s2->set[k2++];
		}
	}
	if (k3 < s3->num)
	{
		while (k3 < s3->num && s1->num < s1->max)
		{
			s1->set[s1->num++] = s2->set[k3++];
		}
	}
	return s1;
}

SortedIntSet* Intersection(SortedIntSet* s1, const SortedIntSet* s2, const SortedIntSet* s3)
{
	s1->num = 0;
	int k2 = 0;
	int k3 = 0;

	while (k2 < s2->num && k3 < s3->num)
	{
		// s2, s3 ����� ũ�Ⱑ �ٸ��� �ε����� ����
		if (s2->set[k2] < s3->set[k3])
		{
			k2++;
		}
		else if (s2->set[k2] > s3->set[k3])
		{
			k3++;
		}
		// s2, s2 ��Ұ� ���� ��� s1�� �߰�
		else
		{
			s1->set[s1->num++] = s2->set[k2++];
			k3++;

			if (s1->num == s1->max)
			{
				return s1;
			}
		}
	}
	return s1;
}

SortedIntSet* Difference(SortedIntSet* s1, const SortedIntSet* s2, const SortedIntSet* s3)
{
	s1->num = 0;
	int k2 = 0;
	int k3 = 0;

	while (k2 < s2->num && k3 < s3->num)
	{
		// s2�� �ִ� ��Ҹ� s1�� �߰�
		if (s2->set[k2] < s3->set[k3])
		{
			s1->set[s1->num++] = s2->set[k2++];
		}
		else if (s2->set[k2] > s3->set[k3])
		{
			k3++;
		}
		else
		{
			k2++;
			k3++;
		}

		if (s1->num == s1->max)
		{
			return s1;
		}
	}

	if (k2 < s2->num)
	{
		while (k2 < s2->num && s1->num < s1->max)
		{
			s1->set[s1->num++] = s2->set[k2++];
		}
	}
	return s1;
}

SortedIntSet* SymmetricDifference(SortedIntSet* s1, const SortedIntSet* s2, const SortedIntSet* s3)
{
	s1->num = 0;
	int k2 = 0;
	int k3 = 0;

	while (k2 < s2->num && k3 < s3->num)
	{
		// ���ο��� ���� ��Ҹ� s1�� �߰�
		if (s2->set[k2] < s3->set[k3])
		{
			s1->set[s1->num++] = s2->set[k2++];
		}
		else if (s2->set[k2] > s3->set[k3])
		{
			s1->set[s1->num++] = s3->set[k3++];
		}
		else
		{
			k2++;
			k3++;
		}

		if (s1->num == s1->max)
		{
			return s1;
		}
	}

	if (k2 < s2->num)
	{
		while (k2 < s2->num && s1->num < s1->max)
		{
			s1->set[s1->num++] = s2->set[k2++];
		}
	}
	if (k3 < s3->num)
	{
		while (k3 < s3->num && s1->num < s1->max)
		{
			s1->set[s1->num++] = s2->set[k3++];
		}
	}
	return s1;
}

SortedIntSet* ToUnion(SortedIntSet* s1, const SortedIntSet* s2)
{
	for (int i = 0; i < s2->num; ++i)
	{
		Add(s1, s2->set[i]);
	}
	return s1;
}

SortedIntSet* ToIntersection(SortedIntSet* s1, const SortedIntSet* s2)
{
	int i = 0;

	// Remove�Լ� : ������ ��Ҹ� ���� ��ġ�� �ű� 
	// --> ������ �ε����� ���� ���� ��Ҹ� �ٽ� �ѹ� �˻��ؾ���
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

SortedIntSet* ToDifference(SortedIntSet* s1, const SortedIntSet* s2)
{
	for (int i = 0; i < s2->num; ++i)
	{
		Remove(s1, s2->set[i]);
	}
	return s1;
}

int IsSubset(const SortedIntSet* s1, const SortedIntSet* s2)
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
		// s1�� ��Ұ� s2�� ������
		if (j == s2->num)
		{
			return 0;
		}
	}
	return 1;
}

int IsProperSubset(const SortedIntSet* s1, const SortedIntSet* s2)
{
	// s1�� ��� ������ s2�� ��� �������� ���ų� ũ��
	if (s1->num >= s2->num)
	{
		return 0;
	}

	return IsSubset(s1, s2);
}

void Print(const SortedIntSet* s)
{
	printf("{ ");
	for (int i = 0; i < s->num; ++i)
	{
		printf("%d ", s->set[i]);
	}
	printf("}");
}

void PrintLn(const SortedIntSet* s)
{
	Print(s);
	putchar('\n');
}

void Clear(SortedIntSet* s)
{
	s->num = 0;
}

void Terminate(SortedIntSet* s)
{
	if (s->set != NULL) {
		free(s->set);
		s->max = s->num = 0;
	}
}