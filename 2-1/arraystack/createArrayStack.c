#include <stdlib.h>
#include "arraystack.h"

ArrayStack* createArrayStack(int maxElementCount)
{
	ArrayStack	*newArrayStack;

	newArrayStack = malloc(sizeof(ArrayStack));
	if (!newArrayStack)
		return (NULL);
	newArrayStack->maxElementCount = maxElementCount;
	newArrayStack->currentElementCount = 0;
	newArrayStack->pElement = malloc(sizeof(ArrayStackNode) * maxElementCount);
	if (!newArrayStack->pElement)
	{
		free(newArrayStack);
		return (NULL);
	}
	return (newArrayStack);
}
