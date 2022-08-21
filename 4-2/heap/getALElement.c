/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getALElement.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 09:56:09 by chanhpar          #+#    #+#             */
/*   Updated: 2022/08/21 17:15:46 by soo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "heap.h"

heapNode	*getALElement(heap *pList, int position)
{
	if (position < 0 || position >= pList->currentElementCount)
		return (NULL);
	return (pList->pElement + position);
}
