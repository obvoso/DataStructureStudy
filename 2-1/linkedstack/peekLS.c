#include "linkedstack.h"
#include <stdlib.h>

StackNode* peekLS(LinkedStack* pStack)
{
	if (!pStack || isLinkedStackEmpty(pStack))
		return (FALSE);
	return (pStack->pTopElement);
}