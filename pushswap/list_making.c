/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_making.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvaliyak <fvaliyak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:47:06 by fvaliyak          #+#    #+#             */
/*   Updated: 2023/02/14 18:50:57 by fvaliyak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

long	int	ft_atoi(const char *str, t_stack *top)
{
	long int	nb;
	int			isneg;
	int			i;

	nb = 0;
	isneg = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		isneg *= -1;
		i++;
	}
	if (!str[i])
		exit_for_error(NULL, NULL);
	while (str[i] <= 57 && str[i] >= 48)
		nb = (nb * 10) + (str[i++] - '0');
	if (((nb * isneg) < -2147483648 || (nb * isneg) > 2147483647) \
	|| str[i] != '\0')
		exit_for_error(&top, NULL);
	return (nb * isneg);
}

int	ft_strchr(const char *s, int c)
{
	while (*s || c == '\0')
	{
		if (*s == (char)c)
			return (1);
		s++;
	}
	return (0);
}

t_stack	*create_node(t_stack *top, int data)
{
	t_stack	*newnode;

	newnode = (t_stack *)malloc(sizeof(t_stack));
	newnode->data = data;
	if (top == NULL)
	{
		top = newnode;
		top->next = NULL;
	}
	else
	{
		newnode->next = top;
		top = newnode;
	}
	return (top);
}

t_stack	*list_settings(int n, char **argc, t_stack *top)
{
	int	len;
	int	*a;

	if (ft_strchr(argc[n - 1], ' ') == 1)
	{
		a = ft_split(argc[n - 1], ' ', top);
		len = occ(argc[n - 1], ' ');
		if (len == 0)
			exit_for_error(&top, NULL);
		while (len > 0)
		{
			if (check_duplicate(top, a[--len]) == 0)
				exit_for_error(&top, NULL);
			top = create_node(top, a[len]);
		}
	}
	else
	{
		if (check_duplicate(top, ft_atoi(argc[n - 1], top)) == 0)
			exit_for_error(&top, NULL);
		top = create_node(top, ft_atoi(argc[n - 1], top));
	}
	return (top);
}

t_stack	*convert_to_lst(int n, char **argc)
{
	t_stack		*top;

	top = NULL;
	while (n > 1)
	{
		top = list_settings(n, argc, top);
		n--;
	}
	return (top);
}
