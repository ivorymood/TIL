/* int�� �� Intdequeue */
#ifndef ___IntDequeue
#define ___IntDequeue
/*--- ť�� �����ϴ� ����ü ---*/
typedef struct {
	int max;		/* ť�� �ִ� �뷮 */
	int num;		/* ���� ��ڼ� */
	int front;		/* �� �� ��Ҹ� ����Ű�� Ŀ�� */
	int rear;		/* �� �� ��Ҹ� ����Ű�� Ŀ�� */
	int* que;		/* ť�� ����Ű�� ������ */
} IntDequeue;

/*--- ť �ʱ�ȭ ---*/
int Initialize(IntDequeue* q, int max);

/*--- ���� ť�� �����͸� ��ť ---*/
int EnqueFront(IntDequeue* q, int x);

/*--- ���� ť�� �����͸� ��ť ---*/
int EnqueRear(IntDequeue* q, int x);

/*--- ���� ť���� �����͸� ��ť ---*/
int DequeFront(IntDequeue* q, int* x);

/*--- ���� ť���� �����͸� ��ť ---*/
int DequeRear(IntDequeue* q, int* x);

/*--- ���� ť���� �����͸� ��ũ ---*/
int PeekFront(const IntDequeue* q, int* x);

/*--- ���� ť���� �����͸� ��ũ ---*/
int PeekRear(const IntDequeue* q, int* x);

/*--- ��� �����͸� ���� ---*/
void Clear(IntDequeue* q);

/*--- ť�� �ִ� �뷮 ---*/
int Capacity(const IntDequeue* q);

/*--- ť�� ����� �������� ���� ---*/
int Size(const IntDequeue* q);

/*--- ť�� ��� �ִ°�? ---*/
int IsEmpty(const IntDequeue* q);

/*--- ť�� ���� á�°�? ---*/
int IsFull(const IntDequeue* q);

/*--- ť���� �˻� ---*/
int Search(const IntDequeue* q, int x);

/*--- ť���� �˻� ---*/
int Search2(const IntDequeue* q, int x);

/*--- ��� ������ ��� ---*/
void Print(const IntDequeue* q);

/*--- ť ���� ---*/
void Terminate(IntDequeue* q);
#endif