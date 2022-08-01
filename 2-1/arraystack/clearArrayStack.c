/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clearArrayStack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo <soo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 15:57:43 by chanhpar          #+#    #+#             */
/*   Updated: 2022/08/01 17:09:11 by soo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "arraystack.h"

void	clearArrayStack(ArrayStack *pStack)
{
	pStack->currentElementCount = 0;
}
