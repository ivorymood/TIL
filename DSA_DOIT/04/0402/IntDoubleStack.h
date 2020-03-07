/* �ϳ��� �迭�� �����ϴ� 2���� int�� ���� IntDoubleStack(���) */
#ifndef ___IntDoubleStack
#define ___IntDoubleStack

/*--- ������ �����ϴ� ����ü ---*/
typedef struct {
	int max;		/* ���� �뷮 */
	int ptr;		/* ���� ������ */
	int* stk;		/* ������ ù ��ҿ� ���� ������ */
} IntDoubleStack;

/*--- ���� �ʱ�ȭ ---*/
int Initialize(IntDoubleStack* sA, IntDoubleStack* sB, int max);

/*---���� ���ÿ� �����͸� Ǫ��---*/
int Push_F(IntDoubleStack* sF, IntDoubleStack* sT, int x);

/*---���� ���ÿ� �����͸� Ǫ��---*/
int Push_T(IntDoubleStack* sF, IntDoubleStack* sT, int x);

/*--- ���� ���ÿ��� �����͸� �� ---*/
int Pop_T(IntDoubleStack* sF, IntDoubleStack* sT, int* x);

/*--- ���� ���ÿ��� �����͸� �� ---*/
int Pop_F(IntDoubleStack* sF, IntDoubleStack* sT, int* x);

/*--- ���� ���ÿ��� �����͸� ��ũ ---*/
int Peek_F(const IntDoubleStack* sF, int* x);

/*--- ���� ���ÿ��� �����͸� ��ũ ---*/
int Peek_T(const IntDoubleStack* sT, int* x);

/*--- ���� ���� ���� ---*/
void Clear_F(IntDoubleStack* sF, IntDoubleStack* sT);

/*--- ���� ���� ���� ---*/
void Clear_T(IntDoubleStack* sF, IntDoubleStack* sT);

/*--- ������ �ִ� �뷮 ---*/
int Capacity(const IntDoubleStack* s);

/*--- ������ ������ ���� ---*/
int Size(const IntDoubleStack* s);

/*--- ������ ��� �ֳ���? ---*/
int IsEmpty(const IntDoubleStack* s);

/*--- ������ ���� á����? ---*/
int IsFull(const IntDoubleStack* s);

/*--- ���ÿ��� �˻� ---*/
int Search(const IntDoubleStack* s, int x);

/*--- ��� ������ ��� ---*/
void Print(const IntDoubleStack* s);

/*--- ���� ���� ---*/
void Terminate(IntDoubleStack* sF, IntDoubleStack* sT);

#endif