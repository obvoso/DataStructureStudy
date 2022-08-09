#include "arrayqueue.h"

int isArrayQueueFull(ArrayQueue* pQueue)
{
	if (!pQueue)
		return (FALSE);
	return (pQueue->maxElementCount == pQueue->currentElementCount);
}
