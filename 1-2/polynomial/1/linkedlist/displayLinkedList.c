#include <stdio.h>
#include "linkedlist.h"

void	displayLinkedList(LinkedList *pList)
{
	int			i;
	ListNode	*curr;

	i = 0;
	if (!pList)
	{
		printf("NULL list\n");
		return ;
	}
	if (pList->currentElementCount == 0)
	{
		printf("Empty list\n");
		return ;
	}
	curr = pList->headerNode.pLink;
	while (i < pList->currentElementCount)
	{
		printf("[%d]: %d\n", i, curr->data);
		i++;
		curr = curr->pLink;
	}
}
