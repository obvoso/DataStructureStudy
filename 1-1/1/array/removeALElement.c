/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   removeALElement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhpar <chanhpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 09:49:01 by chanhpar          #+#    #+#             */
/*   Updated: 2022/07/22 17:05:31 by chanhpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arraylist.h"

int	removeALElement(ArrayList* pList, int position)
{
	if (position < 0 || position >= pList->currentElementCount)
		return (FALSE);
	while (position < pList->currentElementCount)
	{
		pList->pElement[position] = pList->pElement[position + 1];
		position++;
	}
	pList->currentElementCount--;
	return (TRUE);
}
