/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor-odebunmi <victor-odebunmi@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 00:24:43 by vodebunm          #+#    #+#             */
/*   Updated: 2026/10/01 17:21:37 by victor-odeb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../push_swap_src/push_swap.h"

t_push_swap_stack	*max_stackval(t_push_swap_stack *stack)
{
	t_push_swap_stack	*max;

	max = NULL;
	while (stack)
	{
		if (!max || stack->data > max->data)
			max = stack;
		stack = stack->next;
	}
	return (max);
}

t_push_swap_stack	*min_stackval(t_push_swap_stack *stack)
{
	t_push_swap_stack	*min;

	min = NULL;
	while (stack)
	{
		if (!min || stack->data < min->data)
			min = stack;
		stack = stack->next;
	}
	return (min);
}

int	get_stack_len(t_push_swap_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}