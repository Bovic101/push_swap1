/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor-odebunmi <victor-odebunmi@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 12:31:12 by vodebunm          #+#    #+#             */
/*   Updated: 2026/10/01 18:42:39 by victor-odeb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_src/push_swap.h"

void	a_b(t_push_swap_stack **a, t_push_swap_stack **b)
{
	t_push_swap_stack	*node;
	t_push_swap_stack	*target;

	node = obtain_closest_v(*a);
	if (!node || !node->desired_node)
		return ;
	target = node->desired_node;
	if (node->push_midval && target->push_midval)
		rot_ab(a, b, node);
	else if (!node->push_midval && !target->push_midval)
		rrot_both(a, b, node);
	push_activate(a, node, 'a');
	push_activate(b, target, 'b');
	pb(b, a, false);
}

void	b_a(t_push_swap_stack **a, t_push_swap_stack **b)
{
	t_push_swap_stack	*node;
	t_push_swap_stack	*target;

	if (!a || !b || !*b)
		return ;
	node = obtain_closest_v(*b);
	if (!node || !node->desired_node)
		return ;
	target = node->desired_node;
	if (node->push_midval && target->push_midval)
		rot_ab(a, b, target);
	else if (!node->push_midval && !target->push_midval)
		rrot_both(a, b, target);
	push_activate(a, target, 'a');
	push_activate(b, node, 'b');
	pa(a, b, false);
}

void	swap_func(t_push_swap_stack **stack)
{
	t_push_swap_stack	*first;
	t_push_swap_stack	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prevnode = first;
	second->prevnode = first->prevnode;
	second->next = first;
	first->prevnode = second;
	*stack = second;
}
