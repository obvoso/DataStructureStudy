#include "simdef.h"

void deleteLinkedDeque(LinkedDeque* pDeque)
{
	DequeNode *now;
	DequeNode *tmp;

	if (isLinkedDequeEmpty(pDeque))
		free(pDeque);
	else
	{
		now = pDeque->pFrontNode;
		while (now && pDeque->currentElementCount--)
		{
			tmp = now;
			now = now->pRLink;
			free(tmp);
		}
		free(pDeque);
	}
}
