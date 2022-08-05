#include "arrayqueue.h"
#include <stdio.h>

static	void displayArrayQueue(ArrayQueue *pQueue)
{
	printf("\n----------------\n");
	printf("max : %d\ncur : %d\nfront: %d\nrear: %d\n", pQueue->maxElementCount, pQueue->currentElementCount, pQueue->front, pQueue->rear);
	printf("\n----------------\n");
}

int	main()
{
	ArrayQueue *pQueue;
	ArrayQueueNode element;
	ArrayQueueNode *tmp;

	pQueue = createArrayQueue(4);
	if (!pQueue)
		return (1);
	displayArrayQueue(pQueue);
	for(int i = 0; i < 5; i++)
	{
		element.data = i + '0';
		enqueueAQ(pQueue, element);
	}
	displayArrayQueue(pQueue);
	tmp = dequeueAQ(pQueue);
	free(tmp);
	displayArrayQueue(pQueue);
	tmp = peekAQ(pQueue);
	displayArrayQueue(pQueue);
	enqueueAQ(pQueue, element);
	displayArrayQueue(pQueue);
	deleteArrayQueue(pQueue);
}