#include "../linkedstack.h"
#include <stdio.h>
#include <stdlib.h>

int	checkBracketMatchingTwo(LinkedStack *paren, char symbol)
{
	StackNode	*tmp;

	if (isLinkedStackEmpty(paren))
	{
		deleteLinkedStack(paren);
		return (FALSE);
	}
	else
	{
		tmp = popLS(paren);
		if (!((symbol == ')' && tmp->data == '(') || \
			(symbol == ']' && tmp->data == '[') || \
			(symbol == '}' && tmp->data == '{')))
		{
			free(tmp);
			deleteLinkedStack(paren);
			return (FALSE);
		}
		free(tmp);
	}
	return (TRUE);
}

int	checkBracketMatching(LinkedStack *expr)
{
	LinkedStack	*paren;
	StackNode	*now;

	char	symbol;

	if (!expr)
		return (FALSE);
	paren = createLinkedStack();
	now = expr->pTopElement;
	while(now)
	{
		symbol = now->data;
		if (symbol == '(' || symbol == '[' || symbol == '{')
		{
			pushLS(paren, *now);
		}
		else if (symbol == ')' || symbol == ']' || symbol == '}')
		{
			if (!checkBracketMatchingTwo(paren, symbol))
				return (FALSE);
		}
		now = now->pLink;
	}
	if (!isLinkedStackEmpty(paren))
		return (FALSE);
	return (TRUE);
}

int main()
{
	LinkedStack	*head;
	StackNode	element;
	
	head = createLinkedStack();
	element.pLink = NULL;
	element.data = '}';
	pushLS(head, element);
	element.data = 'C';
	pushLS(head, element);
	element.data = '*';
	pushLS(head, element);
	element.data = ')';
	pushLS(head, element);
	element.data = 'B';
	pushLS(head, element);
	element.data = '+';
	pushLS(head, element);
	element.data = 'A';
	pushLS(head, element);
	element.data = '(';
	pushLS(head, element);
	element.data = '{';
	pushLS(head, element);
	printf("paren check result : %d\n", checkBracketMatching(head));
}