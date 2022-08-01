#ifndef _ARRAYSTACK_
#define _ARRAYSTACK_

typedef struct ArrayStackNodeType
{
	char data;
} ArrayStackNode;

typedef struct ArrayStackType
{
	int maxElementCount;		// �ִ� ���� ����
	int currentElementCount;	// ���� ������ ����
	ArrayStackNode *pElement;	// ���� ������ ���� 1���� �迭
} ArrayStack;

ArrayStack* createArrayStack(int maxElementCount);
void deleteArrayStack(ArrayStack* pStack);
int isArrayStackFull(ArrayStack* pStack);
int	isArraStackEmpty(ArrayStack *pStack);
ArrayStackNode* getALElement(ArrayStack* pStack, int position);
void displayArrayStack(ArrayStack* pStack);
void clearArrayStack(ArrayStack* pStack);
int getArrayStackLength(ArrayStack* pStack);
ArrayStackNode	*peekAS(ArrayStack *pStack);
ArrayStackNode	*popAS(ArrayStack *pStack);
int pushAS(ArrayStack* pStack, ArrayStackNode element);

#endif

#ifndef _COMMON_Stack_DEF_
#define _COMMON_Stack_DEF_

#define TRUE		1
#define FALSE		0

#endif