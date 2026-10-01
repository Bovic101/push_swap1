/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_rot_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor-odebunmi <victor-odebunmi@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:22:12 by vodebunm          #+#    #+#             */
/*   Updated: 2026/10/01 17:18:45 by victor-odeb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_src/push_swap.h"

void	rev_rot_ab(t_push_swap_stack **stack)
{
	t_push_swap_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	last = *stack;
	while (last->next)
		last = last->next;
	last->prevnode->next = NULL;
	last->next = *stack;
	last->prevnode = NULL;
	(*stack)->prevnode = last;
	*stack = last;
}

void	activate_push(t_push_swap_stack **stack1,
		t_push_swap_stack **stack2)
{
	t_push_swap_stack	*node;

	if (!stack1 || !stack2 || !*stack2)
		return ;
	node = *stack2;
	*stack2 = node->next;
	if (*stack2)
		(*stack2)->prevnode = NULL;
	node->prevnode = NULL;
	node->next = *stack1;
	if (*stack1)
		(*stack1)->prevnode = node;
	*stack1 = node;
}

void	pb(t_push_swap_stack **b, t_push_swap_stack **a, bool value)
{
	activate_push(b, a);
	if (!value)
		ft_printf("pb\n");
}

void	pa(t_push_swap_stack **a, t_push_swap_stack **b, bool value)
{
	activate_push(a, b);
	if (!value)
		ft_printf("pa\n");
}

void	rot_func(t_push_swap_stack **stack)
{
	t_push_swap_stack	*first;
	t_push_swap_stack	*new_head;
	t_push_swap_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	new_head = first->next;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = first;
	first->prevnode = last;
	first->next = NULL;
	new_head->prevnode = NULL;
	*stack = new_head;
}
