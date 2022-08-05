#include "arrayqueue.h"

int isArrayQueueFull(ArrayQueue* pQueue)
{
	if (!pQueue)
		return (FALSE);
	// return((pQueue->rear + 1) % pQueue->maxElementCount == pQueue->front);
	return (pQueue->maxElementCount == pQueue->currentElementCount);
}
