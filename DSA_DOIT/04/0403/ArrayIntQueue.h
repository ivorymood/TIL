/* int�� ť ArrayIntQueue */
#ifndef ___ArrayIntQueue
#define ___ArrayIntQueue

/*--- ť�� �����ϴ� ����ü ---*/
typedef struct {
	int max;		/* ť�� �ִ� �뷮 */
	int num;		/* ������ ��ڼ� */
	int* que;		/* ť�� ����Ű�� ������ */
} ArrayIntQueue;

/*--- ť �ʱ�ȭ ---*/
int Initialize(ArrayIntQueue* q, int max);

/*--- ť�� �����͸� ��ť ---*/
int Enque(ArrayIntQueue* q, int x);

/*--- ť���� �����͸� ��ť ---*/
int Deque(ArrayIntQueue* q, int* x);

/*--- ť���� �����͸� ��ũ ---*/
int Peek(const ArrayIntQueue* q, int* x);

/*--- ��� �����͸� ���� ---*/
void Clear(ArrayIntQueue* q);

/*--- ť�� �ִ� �뷮 ---*/
int Capacity(const ArrayIntQueue* q);

/*--- ť�� ����� �������� ���� ---*/
int Size(const ArrayIntQueue* q);

/*--- ť�� ��� �ִ°�? ---*/
int IsEmpty(const ArrayIntQueue* q);

/*--- ť�� ���� á�°�? ---*/
int IsFull(const ArrayIntQueue* q);

/*--- ť���� �˻� ---*/
int Search(const ArrayIntQueue* q, int x);

/*--- ��� ������ ��� ---*/
void Print(const ArrayIntQueue* q);

/*--- ť ���� ---*/
void Terminate(ArrayIntQueue* q);
#endif