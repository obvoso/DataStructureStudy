#include "mapdef.h"
#include <stdlib.h>

int	pushLS(LinkedStack* pStack, StackNode element)
{
	StackNode *new;

	if (!pStack || isLinkedStackFull(pStack))
		return (FALSE);
	new = (StackNode*)malloc(sizeof(StackNode));
	if (!new)
		return (FALSE);
	new->mapPos = element.mapPos;
	new->pLink = pStack->pTopElement;
	pStack->pTopElement = new;
	pStack->currentElementCount++;
	return (TRUE);
}