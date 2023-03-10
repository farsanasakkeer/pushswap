/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvaliyak <fvaliyak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 19:26:20 by fvaliyak          #+#    #+#             */
/*   Updated: 2023/02/07 19:27:06 by fvaliyak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	rra(t_stack **stack_a)
{
	t_stack	*temp;
	t_stack	*tail;

	temp = *stack_a;
	while ((*stack_a)->next != NULL)
	{
		if ((*stack_a)->next->next == NULL)
			tail = *stack_a;
		*stack_a = (*stack_a)->next;
	}
	(*stack_a)->next = temp;
	tail->next = NULL;
}

void	rrb(t_stack **stack_b)
{
	t_stack	*temp;
	t_stack	*tail;

	temp = *stack_b;
	while ((*stack_b)->next != NULL)
	{
		if ((*stack_b)->next->next == NULL)
			tail = *stack_b;
		*stack_b = (*stack_b)->next;
	}
	(*stack_b)->next = temp;
	tail->next = NULL;
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}
