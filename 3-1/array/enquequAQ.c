#include "arrayqueue.h"

int enqueueAQ(ArrayQueue* pQueue, ArrayQueueNode element)
{
	if (!pQueue)
		return (FALSE);
	if (isArrayQueueFull(pQueue))
		return (FALSE);
	pQueue->pElement[pQueue->rear].data = element.data;
	pQueue->rear = (pQueue->rear + 1) % pQueue->maxElementCount;
	pQueue->currentElementCount++;
	return (TRUE);
}