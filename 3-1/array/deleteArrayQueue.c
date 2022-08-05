#include "arrayqueue.h"

void deleteArrayQueue(ArrayQueue* pQueue)
{
	ArrayQueueNode *del;

	if (!pQueue)
		return ;
	if (isArrayQueueEmpty(pQueue))
		;
	else
	{
		while (isArrayQueueEmpty(pQueue))
		{
			del = dequeueAQ(pQueue);
			free(del);
		}
	}
	free(pQueue);
}
