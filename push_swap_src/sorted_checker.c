/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vodebunm <vodebunm@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:34:33 by vodebunm          #+#    #+#             */
/*   Updated: 2024/05/19 18:46:45 by vodebunm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_src/push_swap.h"

int	sorted_checker(t_list *stack_a)
{
	int	i;

	i = obtain_value(stack_a);
	while (stack_a != 0)
	{
		if (i > obtain_value(stack_a))
			return (0);
		i = obtain_value(stack_a);
		stack_a = stack_a->next;
	}
	return (1);
}
