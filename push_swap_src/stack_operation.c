/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor-odebunmi <victor-odebunmi@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 12:30:42 by vodebunm          #+#    #+#             */
/*   Updated: 2026/10/01 18:27:41 by victor-odeb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_src/push_swap.h"

static int	parse_number(const char *str, int *value)
{
	int			sign;
	long long	num;
	long long	limit;

	if (format_check(str))
		return (1);
	sign = 1;
	num = 0;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (sign < 0)
		limit = -(long long)INT_MIN;
	else
		limit = INT_MAX;
	while (*str)
	{
		if (num > (limit - (*str - '0')) / 10)
			return (1);
		num = num * 10 + (*str - '0');
		str++;
	}
	*value = (int)(num * sign);
	return (0);
}

void	stack_a_init(t_push_swap_stack **a, char **argv)
{
	int	i;
	int	value;

	i = 0;
	while (argv[i])
	{
		if (parse_number(argv[i], &value) || rm_copy(*a, value))
		{
			free_mystack(a);
			ft_putstr_fd("Error\n", 2);
			return ;
		}
		join_lstnode(a, value);
		if (!*a)
			return ;
		i++;
	}
}

bool	sorted_stack(t_push_swap_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->data > stack->next->data)
			return (false);
		stack = stack->next;
	}
	return (true);
}

void	alt_sorter(t_push_swap_stack **a)
{
	t_push_swap_stack	*maxval;

	if (!a || !*a || !(*a)->next)
		return ;
	maxval = max_stackval(*a);
	if (maxval == *a)
		ra(a, false);
	else if (maxval == (*a)->next)
		rra(a, false);
	if ((*a)->data > (*a)->next->data)
		sa(a, false);
}

void	turks_sorter(t_push_swap_stack **a, t_push_swap_stack **b)
{
	int	a_length;

	if (!a || !*a || !b)
		return ;
	a_length = get_stack_len(*a);
	if (a_length-- > 3 && !sorted_stack(*a))
		pb(b, a, false);
	if (a_length-- > 3 && !sorted_stack(*a))
		pb(b, a, false);
	while (a_length-- > 3 && !sorted_stack(*a))
	{
		turk_implement(*a, *b);
		a_b(a, b);
	}
	alt_sorter(a);
	while (*b)
	{
		turk_implement_b(*a, *b);
		b_a(a, b);
	}
	index_position(*a);
	data_value(a);
}

void	data_value(t_push_swap_stack **a)
{
	t_push_swap_stack	*min_val;

	if (!a || !*a)
		return ;
	index_position(*a);
	min_val = min_stackval(*a);
	while (*a != min_val)
	{
		if (min_val->push_midval)
			ra(a, false);
		else
			rra(a, false);
	}
}