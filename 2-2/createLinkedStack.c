#include "linkedstack.h"
#include <stdlib.h>

LinkedStack* createLinkedStack()
{
	LinkedStack *new;

	new = (LinkedStack*)malloc(sizeof(LinkedStack));
	if (!new)
		return (FALSE);
	new->currentElementCount = 0;
	new->pTopElement = NULL;
	return (new);
}