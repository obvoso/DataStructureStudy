/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clearheap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhpar <chanhpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 15:57:43 by chanhpar          #+#    #+#             */
/*   Updated: 2022/07/22 15:58:13 by chanhpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "heap.h"

void	clearheap(heap *pList)
{
	pList->currentElementCount = 0;
}
