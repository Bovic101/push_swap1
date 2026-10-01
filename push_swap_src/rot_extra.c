/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_extra.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor-odebunmi <victor-odebunmi@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 09:53:09 by vodebunm          #+#    #+#             */
/*   Updated: 2026/10/01 17:19:07 by victor-odeb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_src/push_swap.h"

void	ra(t_push_swap_stack **a, bool value)
{
	rot_func(a);
	if (!value)
		ft_printf("ra\n");
}

void	rb(t_push_swap_stack **b, bool value)
{
	rot_func(b);
	if (!value)
		ft_printf("rb\n");
}

void	sa(t_push_swap_stack **a, bool value)
{
	swap_func(a);
	if (!value)
		ft_printf("sa\n");
}

void	sb(t_push_swap_stack **b, bool value)
{
	swap_func(b);
	if (!value)
		ft_printf("sb\n");
}

void	ss(t_push_swap_stack **a, t_push_swap_stack **b, bool value)
{
	swap_func(a);
	swap_func(b);
	if (!value)
		ft_printf("ss\n");
}