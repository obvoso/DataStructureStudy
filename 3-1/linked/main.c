#include "linkeddeque.h"
#include <stdio.h>

static	void displayArrayQueue(LinkedDeque *pDeque)
{
	DequeNode *now;
	
	now = pDeque->pFrontNode;
	printf("\n----------------\n");
	while (now)
	{
		printf("%c\n", now->data);
		now = now->pRLink;
	}
	printf("\n----------------\n");
}

int	main()
{
	LinkedDeque *pDeque;
	DequeNode element;

	pDeque = createLinkedDeque();
	if (!pDeque)
		return (1);
	element.data = 'A';
	insertFrontLD(pDeque, element);
	displayArrayQueue(pDeque);
	element.data = 'B';
	insertFrontLD(pDeque, element);
	displayArrayQueue(pDeque);
	element.data = 'C';
	insertRearLD(pDeque, element);
	displayArrayQueue(pDeque);
	element.data = 'D';
	insertRearLD(pDeque, element);
	displayArrayQueue(pDeque);
	deleteRearLD(pDeque);
	displayArrayQueue(pDeque);
	deleteFrontLD(pDeque);
	displayArrayQueue(pDeque);
}