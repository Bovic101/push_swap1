/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vodebunm <vodebunm@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 12:30:42 by vodebunm          #+#    #+#             */
/*   Updated: 2024/06/01 04:10:58 by vodebunm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_src/push_swap.h"

void	stack_a_init(t_push_swap_stack **a, char **argv)
{
	int		i;
	long	value;

	i = 0;
	while (argv[i])
	{
		value = ft_atol(argv[i]);

		if (format_check(argv[i]) ||
			value > INT_MAX || value < INT_MIN ||
			remove_duplicate(*a, (int)value))//need attetion
		{
			free_memory(a);//To do
			return;
		}

		join_lstnode(a, (int)value);//To do
		i++;
	}
}