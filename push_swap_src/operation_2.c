/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor-odebunmi <victor-odebunmi@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 09:42:26 by vodebunm          #+#    #+#             */
/*   Updated: 2026/10/01 17:48:55 by victor-odeb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_src/push_swap.h"

void	index_position(t_push_swap_stack *stack)
{
	int	len;
	int	i;

	if (!stack)
		return ;
	len = get_stack_len(stack);
	i = 0;
	while (stack)
	{
		stack->count = i;
		stack->push_midval = (i <= len / 2);
		stack->nearval = false;
		stack = stack->next;
		i++;
	}
}

void	assign_t4a(t_push_swap_stack *a, t_push_swap_stack *b)
{
	t_push_swap_stack	*node;
	t_push_swap_stack	*target;

	while (a)
	{
		target = NULL;
		node = b;
		while (node)
		{
			if (node->data < a->data
				&& (!target || node->data > target->data))
				target = node;
			node = node->next;
		}
		if (!target)
			target = max_stackval(b);
		a->desired_node = target;
		a = a->next;
	}
}

void	push_cost4a(t_push_swap_stack *a, t_push_swap_stack *b)
{
	int	a_size;
	int	b_size;
	int	a_cost;
	int	b_cost;

	a_size = get_stack_len(a);
	b_size = get_stack_len(b);
	while (a)
	{
		a_cost = a->count;
		if (!a->push_midval)
			a_cost = a_size - a->count;
		b_cost = a->desired_node->count;
		if (!a->desired_node->push_midval)
			b_cost = b_size - a->desired_node->count;
		if (a->push_midval == a->desired_node->push_midval)
		{
			if (a_cost > b_cost)
				a->nearval_cal = a_cost;
			else
				a->nearval_cal = b_cost;
		}
		else
			a->nearval_cal = a_cost + b_cost;
		a = a->next;
	}
}

void	chose_closest_val(t_push_swap_stack *stack)
{
	t_push_swap_stack	*best;

	best = NULL;
	while (stack)
	{
		stack->nearval = false;
		if (!best || stack->nearval_cal < best->nearval_cal)
			best = stack;
		stack = stack->next;
	}
	if (best)
		best->nearval = true;
}

void	assign_t4b(t_push_swap_stack *a, t_push_swap_stack *b)
{
	t_push_swap_stack	*node;
	t_push_swap_stack	*target;

	while (b)
	{
		target = NULL;
		node = a;
		while (node)
		{
			if (node->data > b->data
				&& (!target || node->data < target->data))
				target = node;
			node = node->next;
		}
		if (!target)
			target = min_stackval(a);
		b->desired_node = target;
		b = b->next;
	}
}
