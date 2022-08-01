#include <stdlib.h>
#include "arraystack.h"

ArrayStackNode	*popAS(ArrayStack *pStack)
{
	if (!pStack->currentElementCount)
		return (FALSE);
	pStack->currentElementCount--;
	return (&pStack->pElement[pStack->currentElementCount]);
}
