/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createArrayList.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhpar <chanhpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 09:01:04 by chanhpar          #+#    #+#             */
/*   Updated: 2022/07/22 09:33:13 by chanhpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "arraylist.h"

ArrayList* createArrayList(int maxElementCount)
{
	ArrayList	*newArrayList;

	newArrayList = malloc(sizeof(ArrayList));
	if (!newArrayList)
		return (NULL);
	newArrayList->maxElementCount = maxElementCount;
	newArrayList->currentElementCount = 0;
	newArrayList->pElement = malloc(sizeof(ArrayListNode) * maxElementCount);
	if (!newArrayList->pElement)
	{
		free(newArrayList);
		return (NULL);
	}
	return (newArrayList);
}
