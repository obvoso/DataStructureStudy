#include "arraystack.h"

int pushAS(ArrayStack* pStack, ArrayStackNode element)
{
	int	index;

	if (isArrayStackFull(pStack))
		return (FALSE);
	index = pStack->currentElementCount;
	pStack->pElement[index] = element;
	pStack->currentElementCount++;
	return (TRUE);
}
