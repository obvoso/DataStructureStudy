#include <stdlib.h>
#include "linkedlist.h"

int	removeLLElement(LinkedList *pList, int position)
{
	ListNode	*temp;
	ListNode	*pos_node;

	if (position < 0 || position >= pList->currentElementCount)
		return (FALSE);
	if (position == 0)
	{
		temp = pList->headerNode.pLink;
		pList->headerNode.pLink = temp->pLink;
		free(temp);
	}
	else
	{
		pos_node = getLLElement(pList, position - 1);
		temp = pos_node->pLink;
		pos_node->pLink = temp->pLink;
		free(temp);
	}
	pList->currentElementCount--;
	return (TRUE);
}
