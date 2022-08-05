#include "arrayqueue.h"

ArrayQueueNode *peekAQ(ArrayQueue* pQueue)
{
	if (!pQueue)
		return (NULL);
	if (isArrayQueueEmpty(pQueue))
		return (FALSE);
	return (&(pQueue->pElement[pQueue->front]));
}
