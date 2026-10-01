/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor-odebunmi <victor-odebunmi@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 12:25:32 by vodebunm          #+#    #+#             */
/*   Updated: 2026/10/01 17:19:55 by victor-odeb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_src/push_swap.h"

void	turk_implement(t_push_swap_stack *a, t_push_swap_stack *b)
{
	index_position(a);
	index_position(b);
	assign_t4a(a, b);
	push_cost4a(a, b);
	chose_closest_val(a);
}

void	rr(t_push_swap_stack **a, t_push_swap_stack **b, bool value)
{
	rot_func(a);
	rot_func(b);
	if (!value)
		ft_printf("rr\n");
}