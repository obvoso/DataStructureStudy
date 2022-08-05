#include "arrayqueue.h"

ArrayQueueNode *dequeueAQ(ArrayQueue* pQueue)
{
	ArrayQueueNode *ret;

	if (!pQueue)
		return (FALSE);
	if (isArrayQueueEmpty(pQueue))
		return (FALSE);
	ret = (ArrayQueueNode *)malloc(sizeof(ArrayQueueNode));
	if (!ret)
		return (FALSE);
	ret->data = pQueue->pElement[pQueue->front].data;
	pQueue->front = (pQueue->front + 1) % pQueue->maxElementCount;
	pQueue->currentElementCount--;
	return (ret);
}