#include "simdef.h"

DequeNode* deleteRearLD(LinkedDeque* pDeque)
{
	DequeNode *del;

	if (isLinkedDequeEmpty(pDeque))
		return (NULL);
	del = pDeque->pRearNode;
	if (pDeque->currentElementCount > 1)
		del->pLLink->pRLink = NULL;
	pDeque->pRearNode = del->pLLink;
	del->pLLink = NULL;
	pDeque->currentElementCount--;
	if (!pDeque->currentElementCount)
		pDeque->pFrontNode = NULL;
	return (del);
}