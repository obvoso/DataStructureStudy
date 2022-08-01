/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clearArrayList.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhpar <chanhpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 15:57:43 by chanhpar          #+#    #+#             */
/*   Updated: 2022/07/22 15:58:13 by chanhpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "arraylist.h"

void	clearArrayList(ArrayList *pList)
{
	pList->currentElementCount = 0;
}
