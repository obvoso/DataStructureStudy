#include "arrayqueue.h"

ArrayQueueNode *peekAQ(ArrayQueue* pQueue)
{
	ArrayQueueNode	*ret;
	int				idx;

	if (!pQueue)
		return (NULL);
	if (isArrayQueueEmpty(pQueue))
		return (FALSE);
	ret = (ArrayQueueNode *)malloc(sizeof(ArrayQueueNode));
	if (!ret)
		return (FALSE);
	idx = (pQueue->front) % pQueue->maxElementCount;
	ret->data = pQueue->pElement[idx].data;
	return (ret);
}
