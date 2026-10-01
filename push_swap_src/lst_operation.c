/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_operation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor-odebunmi <victor-odebunmi@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 12:29:16 by vodebunm          #+#    #+#             */
/*   Updated: 2026/10/01 17:18:24 by victor-odeb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../push_swap_src/push_swap.h"

void	join_lstnode(t_push_swap_stack **list, int val)
{
	t_push_swap_stack	*new_node;
	t_push_swap_stack	*last;

	if (!list)
		return ;
	new_node = malloc(sizeof(t_push_swap_stack));
	if (!new_node)
	{
		free_memory(list);
		return ;
	}
	new_node->data = val;
	new_node->count = 0;
	new_node->nearval_cal = 0;
	new_node->nearval = false;
	new_node->push_midval = false;
	new_node->next = NULL;
	new_node->prevnode = NULL;
	new_node->desired_node = NULL;
	if (!*list)
	{
		*list = new_node;
		return ;
	}
	last = *list;
	while (last->next)
		last = last->next;
	last->next = new_node;
	new_node->prevnode = last;
}

void	push_activate(t_push_swap_stack **stack,
		t_push_swap_stack *last_datanode, char stack_variable)
{
	if (!stack || !*stack || !last_datanode)
		return ;
	while (*stack != last_datanode)
	{
		if (stack_variable == 'a')
		{
			if (last_datanode->push_midval)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else
		{
			if (last_datanode->push_midval)
				rb(stack, false);
			else
				rrb(stack, false);
		}
	}
}
