#include "linkeddeque.h"

int insertRearLD(LinkedDeque* pDeque, DequeNode element)
{
	DequeNode *new;

	new = (DequeNode *)malloc(sizeof(DequeNode));
	if (!new)
		return (FALSE);
	new->data = element.data;
	new->pLLink = NULL;
	new->pRLink = NULL;
	if (isLinkedDequeEmpty(pDeque))
	{
		pDeque->pFrontNode = new;
		pDeque->pRearNode = new;
	}
	else
	{
		pDeque->pRearNode->pRLink = new;
		new->pLLink = pDeque->pRearNode;
		pDeque->pRearNode = new;
	}
	pDeque->currentElementCount++;
	return (TRUE);
}
