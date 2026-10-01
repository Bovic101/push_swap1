/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_func_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor-odebunmi <victor-odebunmi@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:13:23 by vodebunm          #+#    #+#             */
/*   Updated: 2026/10/01 18:41:59 by victor-odeb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../push_swap_src/push_swap.h"

int	rm_copy(t_push_swap_stack *a, int num)
{
	while (a)
	{
		if (a->data == num)
			return (1);
		a = a->next;
	}
	return (0);
}

void	free_mystack(t_push_swap_stack **stack)
{
	t_push_swap_stack	*next;

	if (!stack)
		return ;
	while (*stack)
	{
		next = (*stack)->next;
		free(*stack);
		*stack = next;
	}
}

void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

int	format_check(const char *str)
{
	int	i;

	if (!str || !*str)
		return (1);
	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (1);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

void	turk_implement_b(t_push_swap_stack *a, t_push_swap_stack *b)
{
	t_push_swap_stack	*best;
	t_push_swap_stack	*node;
	int					a_size;
	int					b_size;
	int					a_cost;
	int					b_cost;

	if (!a || !b)
		return ;
	index_position(a);
	index_position(b);
	assign_t4b(a, b);
	a_size = get_stack_len(a);
	b_size = get_stack_len(b);
	best = NULL;
	node = b;
	while (node)
	{
		a_cost = node->desired_node->count;
		if (!node->desired_node->push_midval)
			a_cost = a_size - node->desired_node->count;
		b_cost = node->count;
		if (!node->push_midval)
			b_cost = b_size - node->count;
		if (node->push_midval == node->desired_node->push_midval)
		{
			if (a_cost > b_cost)
				node->nearval_cal = a_cost;
			else
				node->nearval_cal = b_cost;
		}
		else
			node->nearval_cal = a_cost + b_cost;
		node->nearval = false;
		if (!best || node->nearval_cal < best->nearval_cal)
			best = node;
		node = node->next;
	}
	if (best)
		best->nearval = true;
}

t_push_swap_stack	*obtain_closest_v(t_push_swap_stack *stack)
{
	while (stack)
	{
		if (stack->nearval)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	free_memory(t_push_swap_stack **a)
{
	free_mystack(a);
	ft_putstr_fd("Error\n", 2);
}