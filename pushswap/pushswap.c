/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvaliyak <fvaliyak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:33:42 by fvaliyak          #+#    #+#             */
/*   Updated: 2023/02/14 21:44:01 by fvaliyak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	displayList(t_stack *catchead)
{
	t_stack	*temp;

	if (catchead == NULL)
	{
		printf("\nList is empty\n");
		return ;
	}
	//printf("elements of list are : ");
	temp = catchead;
	while (temp != NULL)
	{
		printf("\n%d %d", temp->data,temp->position);
		temp = temp->next;
	}
	printf("\n");
}

// t_stack *three_element_sort(t_stack *stack_a)
// {
	
// 	return(0);
// }

int	large_value_pos(t_stack *stack)
{
	t_stack	*tmp;
	int		large;
	int		pos;

	tmp = stack;
	large = tmp->data;
	pos = tmp->position;
	while (tmp->next)
	{
		tmp = tmp->next;
		if (large < tmp->data)
		{
			large = tmp->data;
			pos = tmp->position;
		}
		
	}
	return (pos);
}

void	put_position(t_stack *stack)
{
	t_stack	*tmp;
	int		i;

	tmp = stack;
	i = 1;
	while (tmp)
	{
		tmp->position = i;
		tmp = tmp->next;
		i++;
	}
}

int	main(int argn, char **argc)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int	flag;

	if (argn < 2)
		return (0);
	flag = is_number(argn, argc);
	if (flag == 0)
	{
		exit_for_error(NULL,NULL);
	}
	stack_b = NULL;
	stack_a = convert_to_lst(argn, argc);
	printf("\ninitially stack a: ");
	displayList(stack_a);

	if((is_sorted(stack_a))==1)
	{
		printf("\nsorted");
		
		
	}
	else
	{
		printf("\nnot sorted");
		put_position(stack_a);
		printf("\n%d ",argn);
		if (argn == 3)
			sa(stack_a);
		else if (argn == 4)
		{
			printf("\nposition %d ",large_value_pos(stack_a));
			
		}
		


	}

	printf("\n------\n");
	printf("\nstack a is :");
	displayList(stack_a);
	printf("stack b is :");
	displayList(stack_b);

	return (0);
}
