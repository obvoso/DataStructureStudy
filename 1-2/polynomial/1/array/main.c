#include <stdio.h>
#include "arraylist.h"

int	main(void)
{
	ArrayList		*pList;
	ArrayListNode	element;
	int				index;

	pList = NULL;
	displayArrayList(pList);
	pList = createArrayList(10);
	displayArrayList(pList);

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
	displayArrayList(pList);
	printf("=====REMOVE=======\n");
	removeALElement(pList, 6);
	displayArrayList(pList);
	clearArrayList(pList);
	displayArrayList(pList);
	return (0);
}
