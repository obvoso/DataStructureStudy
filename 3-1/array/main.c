#include "arrayqueue.h"
#include <stdio.h>

int	main()
{
	ArrayQueue *pQueue;
	ArrayQueueNode element;
	ArrayQueueNode *tmp;

	pQueue = createArrayQueue(4);
	if (!pQueue)
		return (1);
	for(int i = 0; i < 5; i++)
	{
		element.data = i + '0';
		enqueueAQ(pQueue, element);
	}
	tmp = peekAQ(pQueue);
	printf("peek : %c\n", tmp->data);
	free(tmp);
	tmp = dequeueAQ(pQueue);
	printf("dequeue 1 : %c\n", tmp->data);
	free(tmp);
	tmp = dequeueAQ(pQueue);
	printf("dequeue 2 : %c\n", tmp->data);
	free(tmp);
	enqueueAQ(pQueue, element);
	printf("enqueue %c\n", element.data);
	while (!isArrayQueueEmpty(pQueue))
	{
		tmp = dequeueAQ(pQueue);
		printf("empty dequeue: %c\n", tmp->data);
		free(tmp);
	}
}