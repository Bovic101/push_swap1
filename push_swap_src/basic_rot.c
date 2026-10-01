/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_rot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor-odebunmi <victor-odebunmi@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:18:25 by vodebunm          #+#    #+#             */
/*   Updated: 2026/10/01 17:19:23 by victor-odeb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_src/push_swap.h"

void	rot_ab(t_push_swap_stack **a, t_push_swap_stack **b,
		t_push_swap_stack *closest_node)
{
	if (!a || !b || !closest_node)
		return ;
	while (*a != closest_node && *b != closest_node->desired_node)
		rr(a, b, false);
	index_position(*a);
	index_position(*b);
}

void	rrot_both(t_push_swap_stack **a, t_push_swap_stack **b,
		t_push_swap_stack *closest_node)
{
	if (!a || !b || !closest_node)
		return ;
	while (*a != closest_node && *b != closest_node->desired_node)
		rrr(a, b, false);
	index_position(*a);
	index_position(*b);
}

void	rra(t_push_swap_stack **a, bool value)
{
	rev_rot_ab(a);
	if (!value)
		ft_printf("rra\n");
}

void	rrb(t_push_swap_stack **b, bool value)
{
	rev_rot_ab(b);
	if (!value)
		ft_printf("rrb\n");
}

void	rrr(t_push_swap_stack **a, t_push_swap_stack **b, bool value)
{
	rev_rot_ab(a);
	rev_rot_ab(b);
	if (!value)
		ft_printf("rrr\n");
}
