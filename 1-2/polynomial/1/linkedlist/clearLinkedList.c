#include <stdlib.h>
#include "linkedlist.h"

void clearLinkedList(LinkedList* pList)
{
	ListNode	*curr;
	ListNode	*temp;

	curr = pList->headerNode.pLink;
	while (curr)
	{
		temp = curr;
		curr = curr->pLink;
		free(temp);
	}
	pList->headerNode.pLink = NULL;
	pList->currentElementCount = 0;
}
