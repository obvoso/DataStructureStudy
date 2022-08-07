#include "linkeddeque.h"

DequeNode* deleteRearLD(LinkedDeque* pDeque)
{
	DequeNode *del;

	if (isLinkedDequeEmpty(pDeque))
		return (NULL);
	del = pDeque->pRearNode;
	del->pLLink->pRLink = NULL;
	pDeque->pRearNode = del->pLLink;
	del->pLLink = NULL;
	pDeque->currentElementCount--;
	return (del);
}