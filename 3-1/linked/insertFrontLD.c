#include "linkeddeque.h"

int insertFrontLD(LinkedDeque* pDeque, DequeNode element)
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
		pDeque->pFrontNode->pLLink = new;
		new->pRLink = pDeque->pFrontNode;
		pDeque->pFrontNode = new;
	}
	pDeque->currentElementCount++;
	return (TRUE);
}