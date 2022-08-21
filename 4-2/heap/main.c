#include <stdio.h>
#include "heap.h"

int	main(void)
{
	heap		*pList;
	heapNode	element;
	int				index;

	pList = NULL;
	displayheap(pList);
	pList = createheap(10);
	displayheap(pList);

	printf("=====ADD=======\n");
	index = 0;
	while (index < 7)
	{
		element.data = index;
		if (addALElement(pList, index, element) == FALSE)
		{
			printf("error at index %d\n", index);
			break ;
		}
		index++;
	}
	displayheap(pList);
	printf("=====REMOVE=======\n");
	removeALElement(pList, 6);
	displayheap(pList);
	clearheap(pList);
	displayheap(pList);
	return (0);
}
