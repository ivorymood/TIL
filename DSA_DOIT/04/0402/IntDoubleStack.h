/* 하나의 배열을 공유하는 2개의 int형 스택 IntDoubleStack(헤더) */
#ifndef ___IntDoubleStack
#define ___IntDoubleStack

/*--- 스택을 구현하는 구조체 ---*/
typedef struct {
	int max;		/* 스택 용량 */
	int ptr;		/* 스택 포인터 */
	int* stk;		/* 스택의 첫 요소에 대한 포인터 */
} IntDoubleStack;

/*--- 스택 초기화 ---*/
int Initialize(IntDoubleStack* sA, IntDoubleStack* sB, int max);

/*---앞쪽 스택에 데이터를 푸시---*/
int Push_F(IntDoubleStack* sF, IntDoubleStack* sT, int x);

/*---뒤쪽 스택에 데이터를 푸시---*/
int Push_T(IntDoubleStack* sF, IntDoubleStack* sT, int x);

/*--- 뒤쪽 스택에서 데이터를 팝 ---*/
int Pop_T(IntDoubleStack* sF, IntDoubleStack* sT, int* x);

/*--- 앞쪽 스택에서 데이터를 팝 ---*/
int Pop_F(IntDoubleStack* sF, IntDoubleStack* sT, int* x);

/*--- 앞쪽 스택에서 데이터를 피크 ---*/
int Peek_F(const IntDoubleStack* sF, int* x);

/*--- 뒤쪽 스택에서 데이터를 피크 ---*/
int Peek_T(const IntDoubleStack* sT, int* x);

/*--- 앞쪽 스택 비우기 ---*/
void Clear_F(IntDoubleStack* sF, IntDoubleStack* sT);

/*--- 뒤쪽 스택 비우기 ---*/
void Clear_T(IntDoubleStack* sF, IntDoubleStack* sT);

/*--- 스택의 최대 용량 ---*/
int Capacity(const IntDoubleStack* s);

/*--- 스택의 데이터 개수 ---*/
int Size(const IntDoubleStack* s);

/*--- 스택이 비어 있나요? ---*/
int IsEmpty(const IntDoubleStack* s);

/*--- 스택이 가득 찼나요? ---*/
int IsFull(const IntDoubleStack* s);

/*--- 스택에서 검색 ---*/
int Search(const IntDoubleStack* s, int x);

/*--- 모든 데이터 출력 ---*/
void Print(const IntDoubleStack* s);

/*--- 스택 종료 ---*/
void Terminate(IntDoubleStack* sF, IntDoubleStack* sT);

#endif