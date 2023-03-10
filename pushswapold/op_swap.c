/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvaliyak <fvaliyak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 21:32:04 by fvaliyak          #+#    #+#             */
/*   Updated: 2023/02/07 19:32:33 by fvaliyak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	swap_fn(t_stack *top)
{
	int	temp;

	if (!top || top->next == NULL)
		return ;
	temp = top->data;
	top->data = top->next->data;
	top->next->data = temp;
}

void	sa(t_stack *top)
{
	swap_fn(top);
}

void	sb(t_stack *list)
{
	swap_fn(list);
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	sa(stack_a);
	sb(stack_b);
}
