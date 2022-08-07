#include "linkeddeque.h"

DequeNode* peekFrontLD(LinkedDeque* pDeque)
{
	if (isLinkedDequeEmpty(pDeque))
		return (NULL);
	return (pDeque->pFrontNode);
}
