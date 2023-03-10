/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvaliyak <fvaliyak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:57:32 by fvaliyak          #+#    #+#             */
/*   Updated: 2023/02/14 21:20:59 by fvaliyak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <ctype.h>
# include <stddef.h>

typedef struct s_stack
{
	int				data;
	int				position;
	struct s_stack	*next;
}					t_stack;

void	displayList(t_stack *catchead);

long	int	ft_atoi(const char *str, t_stack *top);
t_stack	*create_node(t_stack *top, int data);
t_stack	*list_settings(int n, char **argc, t_stack *top);
t_stack	*convert_to_lst(int n, char **argc);

void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_b, t_stack **stack_a);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	sb(t_stack *list);
void	sa(t_stack *list);
void	swap_fn(t_stack *top);
void	rb(t_stack **stack_b);
void	ra(t_stack **stack_a);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);

void	exit_for_error(t_stack **stack_a, t_stack **stack_b);
void	free_stack(t_stack **stack);

int		is_sorted(t_stack *stack);
int		ft_isdigit(int n);
int		is_number(int n, char **arg);
int		check_duplicate(t_stack *stack, int data);

int		*ft_split(char const *s, char c, t_stack *top);
int		getword(const char *str, int start, int finish, t_stack *top);
int		occ(char const *s, char c);
size_t	ft_strlen(const char *s);


void	put_position(t_stack *stack);


t_stack *three_element_sort(t_stack *stack_a);

#endif