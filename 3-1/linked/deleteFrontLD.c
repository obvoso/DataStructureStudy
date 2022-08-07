#include "linkeddeque.h"

DequeNode* deleteFrontLD(LinkedDeque* pDeque)
{
	DequeNode *del;

	if (isLinkedDequeEmpty(pDeque))
		return (NULL);
	del = pDeque->pFrontNode;
	del->pRLink->pLLink = NULL;
	pDeque->pFrontNode = del->pRLink;
	del->pRLink = NULL;
	pDeque->currentElementCount--;
	return (del);
}
