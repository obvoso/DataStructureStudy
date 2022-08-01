#include <stdlib.h>
#include "arraystack.h"

void deleteArrayStack(ArrayStack* pStack)
{
	free(pStack->pElement);
	free(pStack);
}
