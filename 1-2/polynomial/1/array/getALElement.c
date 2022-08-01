/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getALElement.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhpar <chanhpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 09:56:09 by chanhpar          #+#    #+#             */
/*   Updated: 2022/07/22 16:10:03 by chanhpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "arraylist.h"

ArrayListNode	*getALElement(ArrayList *pList, int position)
{
	if (position < 0 || position >= pList->currentElementCount)
		return (NULL);
	return (pList->pElement + position);
}
