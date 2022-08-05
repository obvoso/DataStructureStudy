#include "arrayqueue.h"

void deleteArrayQueue(ArrayQueue* pQueue)
{
	if (!pQueue)
		return ;
	if (isArrayQueueEmpty(pQueue))
		;
	else
		free(pQueue->pElement);
	free(pQueue);
}
