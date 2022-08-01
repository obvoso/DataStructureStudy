#include <stdio.h>
#include "arraystack.h"

void	displayArrayStack(ArrayStack *pStack)
{
	int	i;

	i = 0;
	if (!pStack)
	{
		printf("NULL array\n");
		return ;
	}
	if (pStack->currentElementCount == 0)
	{
		printf("Empty array\n");
		return ;
	}
	while (i < pStack->currentElementCount)
	{
		printf("[%d]: %c\n", i, pStack->pElement[i].data);
		i++;
	}
}
