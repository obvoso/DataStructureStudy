#include <stdio.h>
#include "heap.h"

void	displayheap(heap *pList)
{
	int	i;

	i = 0;
	if (!pList)
	{
		printf("NULL array\n");
		return ;
	}
	if (pList->currentElementCount == 0)
	{
		printf("Empty array\n");
		return ;
	}
	while (i < pList->currentElementCount)
	{
		printf("[%d]: %d\n", i, pList->pElement[i].data);
		i++;
	}
}
