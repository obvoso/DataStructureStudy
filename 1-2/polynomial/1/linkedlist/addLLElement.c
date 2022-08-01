#include <stdlib.h>
#include "linkedlist.h"

int addLLElement(LinkedList* pList, int position, ListNode element)
{
	ListNode	*pos_node;
	ListNode	*next;
	ListNode	*new_element;

	if (position < 0 || position > pList->currentElementCount)
		return (FALSE);
	new_element = malloc(sizeof(ListNode));
	if (!new_element)
		return (FALSE);
	new_element->coef = element.coef;
	new_element->degree = element.degree;
	if (position == 0)
	{
		new_element->pLink = pList->headerNode.pLink;
		pList->headerNode.pLink = new_element;
	}
	else
	{
		pos_node = getLLElement(pList, position - 1);
		next = pos_node->pLink;
		pos_node->pLink = new_element;
		new_element->pLink = next;
	}
	pList->currentElementCount++;
	return (TRUE);
}
