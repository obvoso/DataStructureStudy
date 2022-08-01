#include "linkedstack.h"
#include <stdlib.h>

int	pushLS(LinkedStack* pStack, StackNode element)
{
	StackNode *new;

	if (!pStack || isLinkedStackFull(pStack))
		return (FALSE);
	new = (StackNode*)malloc(sizeof(StackNode));
	if (!new)
		return (FALSE);
	new->data = element.data;
	new->pLink = pStack->pTopElement;
	pStack->pTopElement = new;
	pStack->currentElementCount++;
	return (TRUE);
}