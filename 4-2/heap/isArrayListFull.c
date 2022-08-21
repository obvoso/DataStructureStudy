/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isheapFull.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhpar <chanhpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 09:33:48 by chanhpar          #+#    #+#             */
/*   Updated: 2022/07/22 09:34:30 by chanhpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heap.h"

int	isheapFull(heap *pList)
{
	return (pList->currentElementCount == pList->maxElementCount);
}
