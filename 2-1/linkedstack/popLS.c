#include "linkedstack.h"
#include <stdlib.h>

StackNode* popLS(LinkedStack* pStack)
{
	StackNode	*ret;

	if (!pStack || isLinkedStackEmpty(pStack))
		return (FALSE);
	ret = pStack->pTopElement;
	pStack->pTopElement = pStack->pTopElement->pLink;
	pStack->currentElementCount--;
	return (ret);
}