#include "linkedstack.h"
#include <stdlib.h>

void	deleteLinkedStack(LinkedStack* pStack)
{
	StackNode	*now;
	StackNode	*tmp;

	now = pStack->pTopElement;
	if (!now)
		return ;
	while (now && pStack->currentElementCount--)
	{
		tmp = now;
		now = now->pLink;
		free(tmp);
	}
	free(pStack);
}