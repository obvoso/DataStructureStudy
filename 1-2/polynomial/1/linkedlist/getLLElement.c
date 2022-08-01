#include <stdlib.h>
#include "linkedlist.h"

ListNode* getLLElement(LinkedList* pList, int position)
{
	ListNode	*curr;
	int			index;

	if (position < 0 || position >= pList->currentElementCount)
		return (NULL);
	curr = pList->headerNode.pLink;
	index = 0;
	while (index < position)
	{
		curr = curr->pLink;
		index++;
	}
	return (curr);
}
