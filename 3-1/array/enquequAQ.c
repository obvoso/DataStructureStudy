#include "arrayqueue.h"

int enqueueAQ(ArrayQueue* pQueue, ArrayQueueNode element)
{
	if (!pQueue)
		return (FALSE);
	if (isArrayQueueFull(pQueue))
		return (FALSE);
	if (!isArrayQueueEmpty(pQueue))
		pQueue->rear = (pQueue->rear + 1) % pQueue->maxElementCount;
	pQueue->pElement[pQueue->rear].data = element.data;
	pQueue->currentElementCount++;
	return (TRUE);
}