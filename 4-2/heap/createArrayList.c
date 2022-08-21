
#include <stdlib.h>
#include "heap.h"

heap* createheap(int maxElementCount)
{
	heap	*newheap;

	newheap = malloc(sizeof(heap));
	if (!newheap)
		return (NULL);
	newheap->maxElementCount = maxElementCount;
	newheap->currentElementCount = 0;
	newheap->pElement = malloc(sizeof(heapNode) * maxElementCount);
	if (!newheap->pElement)
	{
		free(newheap);
		return (NULL);
	}
	return (newheap);
}
