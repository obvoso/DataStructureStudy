#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

int	addPolyNodeLast(LinkedList* pList, float coef, int degree)
{
	int	ret = FALSE;

	ListNode node = {0,}; //생성, 초기화?
	node.coef = coef;
	node.degree = degree;

	if (pList != NULL)
	{
		int	length = getLinkedListLength(pList);
		ret = addLLElement(pList, length, node);
	}
	return (ret);
}

static	void initLinkedList(LinkedList *pListA, LinkedList *pListB)
{

		addPolyNodeLast(pListA, -1, 3);
		addPolyNodeLast(pListA, 3, 1);
		addPolyNodeLast(pListA, 2, 0);

		addPolyNodeLast(pListB, 5, 3);
		addPolyNodeLast(pListB, 1, 1);
		addPolyNodeLast(pListB, 3, 0);
}

LinkedList	*addPolyNode(LinkedList *pListA, LinkedList *pListB)
{
	LinkedList *ret;
	ListNode	*NodeA;
	ListNode	*NodeB;

	NodeA = pListA->headerNode.pLink;
	NodeB = pListB->headerNode.pLink;
	ret = createLinkedList();
	while(NodeA && NodeB)
	{
		if (NodeA->degree > NodeB->degree)
		{
			addPolyNodeLast(ret, NodeA->coef, NodeA->degree);
			NodeA = NodeA->pLink;
		}
		else if (NodeA->degree == NodeB->degree)
		{
			addPolyNodeLast(ret, NodeA->coef + NodeB->coef, NodeA->degree);
			NodeA = NodeA->pLink;
			NodeB = NodeB->pLink;
		}
		else
		{
			addPolyNodeLast(ret, NodeB->coef, NodeB->degree);
			NodeB = NodeB->pLink;
		}
	}
	//남은 노드
	while (NodeA)
	{
		addPolyNodeLast(ret, NodeA->coef, NodeA->degree);
		NodeA = NodeA->pLink;
	}
	while (NodeB)
	{
		addPolyNodeLast(ret, NodeB->coef, NodeB->degree);
		NodeB = NodeB->pLink;
	}
	ret->currentElementCount = getLinkedListLength(ret);
	deleteLinkedList(pListA);
	deleteLinkedList(pListB);
	return (ret);
}

int	main(void)
{
	LinkedList *pListA;
	LinkedList *pListB;
	LinkedList	*ret;
	ListNode *now;

	pListA = createLinkedList();
	pListB = createLinkedList();
	initLinkedList(pListA, pListB);

	now = pListA->headerNode.pLink;
	while (now)
	{
		if (!now->pLink)
			printf("%dx^%d\n", (int)now->coef, now->degree);
		else
			printf("%dx^%d + ", (int)now->coef, now->degree);
		now = now->pLink;
	}
	now = pListB->headerNode.pLink;
	while (now)
	{
		if (!now->pLink)
			printf("%dx^%d\n", (int)now->coef, now->degree);
		else
			printf("%dx^%d + ", (int)now->coef, now->degree);
		now = now->pLink;
	}

	ret = addPolyNode(pListA, pListB);
	
	now = ret->headerNode.pLink;
	while (now)
	{
		if (!now->pLink)
			printf("%dx^%d\n", (int)now->coef, now->degree);
		else
			printf("%dx^%d + ", (int)now->coef, now->degree);
		now = now->pLink;
	}
}