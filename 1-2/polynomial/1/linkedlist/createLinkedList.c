#include <stdlib.h>
#include "linkedlist.h"

LinkedList	*createLinkedList(void)
{
	LinkedList	*linkedlist;

	linkedlist = malloc(sizeof(LinkedList));
	if (!linkedlist)
		return (NULL);
	linkedlist->currentElementCount = 0;
	linkedlist->headerNode.coef = 0;
	linkedlist->headerNode.degree = 0;
	linkedlist->headerNode.pLink = NULL;
	return (linkedlist);
}
