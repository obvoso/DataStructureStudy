#include "simdef.h"

DequeNode* peekRearLD(LinkedDeque* pDeque)
{
	if (isLinkedDequeEmpty(pDeque))
		return (NULL);
	return (pDeque->pRearNode);
}