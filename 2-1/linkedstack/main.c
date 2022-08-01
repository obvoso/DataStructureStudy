#include "linkedstack.h"
#include <stdio.h>
#include <stdlib.h>

int	main()
{
	StackNode	*now;
	LinkedStack	*head;
	StackNode	element;
	int		i;
	
	head = createLinkedStack();
	i = 0;
	while (i < 10)
	{
		element.data = i + 'a';
		element.pLink = NULL;
		pushLS(head, element);
		printf("peek : %c\n", peekLS(head)->data);
		++i;
	}
	i = 0;
	now = head->pTopElement;
	printf("init 10\n");
	while (i++ < head->currentElementCount)
	{
		printf("data : %c\n", now->data);
		now = now->pLink;
	}
	now =  popLS(head);
	printf("\npop : %c\n", now->data);
	free(now);
	now =  popLS(head);
	printf("\npop : %c\n", now->data);
	free(now);
	
	element.data = '9';
	pushLS(head, element);
	printf("\npeek after push : %c\n", peekLS(head)->data);
}