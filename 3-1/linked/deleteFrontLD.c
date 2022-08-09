#include "linkeddeque.h"

DequeNode* deleteFrontLD(LinkedDeque* pDeque)
{
	DequeNode *del;

	if (isLinkedDequeEmpty(pDeque))
		return (NULL);
	del = pDeque->pFrontNode;
	if (pDeque->currentElementCount > 1)
		del->pRLink->pLLink = NULL;
	pDeque->pFrontNode = del->pRLink;
	del->pRLink = NULL;
	pDeque->currentElementCount--;
	if (!pDeque->currentElementCount)
		pDeque->pRearNode = NULL;
	return (del);
}
