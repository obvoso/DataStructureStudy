#include "heap.h"

int minLeftAddALElement(heap* pList, int position, heapNode element)
{
	int	tmp;
	int	idx;

	if (position < 0 || position > pList->currentElementCount)
		return (FALSE);
	if (position * 2 > pList->maxElementCount)
		return (FALSE);
	if (isheapFull(pList))
		return (FALSE);
	idx = position * 2;
	pList->pElement[idx] = element;
	while (idx && pList->pElement[idx / 2].data > pList->pElement[idx].data)
	{
		tmp = pList->pElement[idx / 2].data;
		pList->pElement[idx / 2].data = pList->pElement[idx].data;
		pList->pElement[idx].data = tmp;
	}
	pList->currentElementCount++;
	return (TRUE);
}

int minRightAddALElement(heap* pList, int position, heapNode element)
{
	int	tmp;
	int idx;
	
	if (position < 0 || position > pList->currentElementCount)
		return (FALSE);
	if (position * 2 + 1 > pList->maxElementCount)
		return (FALSE);
	if (isheapFull(pList))
		return (FALSE);
	idx = position * 2 + 1;
	pList->pElement[idx] = element;
	while (idx && pList->pElement[idx / 2].data > pList->pElement[idx].data)
	{
		tmp = pList->pElement[idx / 2].data;
		pList->pElement[idx / 2].data = pList->pElement[idx].data;
		pList->pElement[idx].data = tmp;
	}
	pList->currentElementCount++;
	return (TRUE);
}

int maxLeftAddALElement(heap* pList, int position, heapNode element)
{
	int	tmp;
	int	idx;

	if (position < 0 || position > pList->currentElementCount)
		return (FALSE);
	if (position * 2> pList->maxElementCount)
		return (FALSE);
	if (isheapFull(pList))
		return (FALSE);
	idx = position * 2;
	pList->pElement[idx] = element;
	while (idx && pList->pElement[idx / 2].data < pList->pElement[idx].data)
	{
		tmp = pList->pElement[idx / 2].data;
		pList->pElement[idx / 2].data = pList->pElement[idx].data;
		pList->pElement[idx].data = tmp;
	}
	pList->currentElementCount++;
	return (TRUE);
}

int maxRightAddALElement(heap* pList, int position, heapNode element)
{
	int	tmp;
	int	idx;

	if (position < 0 || position > pList->currentElementCount)
		return (FALSE);
	if (position * 2 + 1 > pList->maxElementCount)
		return (FALSE);
	if (isheapFull(pList))
		return (FALSE);
	idx = position * 2 + 1;
	pList->pElement[idx] = element;
	while (idx && pList->pElement[idx / 2].data < pList->pElement[idx].data)
	{
		tmp = pList->pElement[idx / 2].data;
		pList->pElement[idx / 2].data = pList->pElement[idx].data;
		pList->pElement[idx].data = tmp;
	}
	pList->currentElementCount++;
	return (TRUE);
}
