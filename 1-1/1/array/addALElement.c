/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addALElement.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhpar <chanhpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 09:34:47 by chanhpar          #+#    #+#             */
/*   Updated: 2022/07/22 16:02:05 by chanhpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arraylist.h"

int addALElement(ArrayList* pList, int position, ArrayListNode element)
{
	int	index;

	if (position < 0 || position > pList->currentElementCount)
		return (FALSE);
	if (isArrayListFull(pList))
		return (FALSE);
	index = pList->currentElementCount;
	while (index > position)
	{
		pList->pElement[index] = pList->pElement[index - 1];
		index--;
	}
	pList->pElement[position] = element;
	pList->currentElementCount++;
	return (TRUE);
}
