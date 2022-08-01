#include <stdlib.h>
#include "arraystack.h"

ArrayStackNode	*peekAS(ArrayStack *pStack)
{
	if (!pStack->currentElementCount)
		return (FALSE);
	return (&pStack->pElement[pStack->currentElementCount - 1]);
}
