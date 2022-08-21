/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   removeALElement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 09:49:01 by chanhpar          #+#    #+#             */
/*   Updated: 2022/08/21 20:10:39 by soo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heap.h"

void	maxRemoveHeapElement(heap *pList, int parent, int child)
{
	int	temp;

	temp = pList->pElement[pList->currentElementCount].data;
	pList->currentElementCount--;
	while (pList->currentElementCount >= child)
	{
		if ((child <= pList->currentElementCount) && pList->pElement[child].data < pList->pElement[child + 1].data)
			child++;
		if (temp >= pList->pElement[child].data)
			break ;
		pList->pElement[parent].data = pList->pElement[child].data;
		parent = child;
		child *= 2;
	}
	pList->pElement[parent].data = temp;
}

void	minRemoveHeapElement(heap *pList, int parent, int child)
{
	int	temp;

	temp = pList->pElement[pList->currentElementCount].data;
	pList->currentElementCount--;
	while (pList->currentElementCount >= child)
	{
		if ((child <= pList->currentElementCount) && pList->pElement[child].data > pList->pElement[child + 1].data)
			child++;
		if (temp <= pList->pElement[child].data)
			break ;
		pList->pElement[parent].data = pList->pElement[child].data;
		parent = child;
		child *= 2;
	}
	pList->pElement[parent].data = temp;
}

int	removeALElement(heap* pList)
{
	int	parent;
	int	child;

	parent = 1;
	child = 2;
	if (!pList || pList->currentElementCount < 1)
		return (FALSE);
	if (pList->currentElementCount >= child)
	{
		if (pList->pElement[parent].data > pList->pElement[child].data)
			maxRemoveHeapElement(pList, parent, child);
		else
			minRemoveHeapElement(pList, parent, child);
	}
	return (TRUE);
}
