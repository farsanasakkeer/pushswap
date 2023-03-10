/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checking.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvaliyak <fvaliyak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 22:17:18 by fvaliyak          #+#    #+#             */
/*   Updated: 2023/02/14 18:35:13 by fvaliyak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	is_sorted(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->data > stack->next->data)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	ft_isdigit(int n)
{
	if ((n >= 48 && n <= 57) || n == ' ' || n == '+' \
	|| n == '-' || (n >= '\t' && n <= '\r'))
	{
		return (1);
	}
	return (0);
}

int	is_number(int n, char **arg)
{
	int	i;

	while (n > 1)
	{
		i = 0;
		while (arg[n - 1][i] == ' ' \
		|| (arg[n - 1][i] >= '\t' && arg[n - 1][i] <= '\r'))
		{
			i++;
		}
		if (arg[n - 1][i] == '+' || arg[n - 1][i] == '-')
			i++;
		while (arg[n - 1][i] && ft_isdigit(arg[n - 1][i]) == 1)
		{
			i++;
		}
		if (arg[n - 1][i] && ft_isdigit(arg[n - 1][i]) == 0)
			return (0);
		n--;
	}
	return (1);
}

int	check_duplicate(t_stack *stack, int data)
{
	while (stack != NULL)
	{
		if (stack->data == data)
			return (0);
		stack = stack->next;
	}
	return (1);
}
