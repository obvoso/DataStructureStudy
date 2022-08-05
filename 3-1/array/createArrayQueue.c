#include "arrayqueue.h"

ArrayQueue* createArrayQueue(int maxElementCount)
{
	ArrayQueue	*newArrayQueue;

	newArrayQueue = malloc(sizeof(ArrayQueue));
	if (!newArrayQueue)
		return (NULL);
	newArrayQueue->maxElementCount = maxElementCount;
	newArrayQueue->currentElementCount = 0;
	newArrayQueue->front = 0;
	newArrayQueue->rear = 0;
	newArrayQueue->pElement = malloc(sizeof(ArrayQueueNode) * maxElementCount);
	if (!newArrayQueue->pElement)
	{
		free(newArrayQueue);
		return (NULL);
	}
	return (newArrayQueue);
}