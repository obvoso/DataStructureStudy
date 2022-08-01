#include <stdio.h>
#include "arraystack.h"

int	main(void)
{
	ArrayStack		*pStack;
	ArrayStackNode	element;
	int				index;

	pStack = NULL;
	displayArrayStack(pStack);
	pStack = createArrayStack(10);
	displayArrayStack(pStack);

	printf("=====ADD=======\n");
	index = 0;
	while (index < 7)
	{
		element.data = index + 'a';
		if (pushAS(pStack, element) == FALSE)
		{
			printf("error at index %d\n", index);
			break ;
		}
		index++;
	}
	displayArrayStack(pStack);
	printf("=====REMOVE=======\n");
	popAS(pStack);
	displayArrayStack(pStack);
	clearArrayStack(pStack);
	displayArrayStack(pStack);
	return (0);
}
