#include "linkedstack.h"
#include <stdlib.h>

int	isLinkedStackEmpty(LinkedStack* pStack)
{
	if (!pStack)
		return (FALSE);
	if (!pStack->pTopElement)
		return (TRUE);
	return (FALSE);
}