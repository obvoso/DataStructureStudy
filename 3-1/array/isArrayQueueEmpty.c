#include "arrayqueue.h"

int isArrayQueueEmpty(ArrayQueue* pQueue)
{
	if (!pQueue)
		return (FALSE);
	// return (pQueue->front == pQueue->rear);
	return(!pQueue->currentElementCount);
}