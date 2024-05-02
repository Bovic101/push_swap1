/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vodebunm <vodebunm@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:34:33 by vodebunm          #+#    #+#             */
/*   Updated: 2024/05/06 16:34:51 by vodebunm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_sorted(t_list *stack_a)
{
	int	i;

	i = get_content(stack_a);
	while (stack_a != 0)
	{
		if (i > get_content(stack_a))
			return (0);
		i = get_content(stack_a);
		stack_a = stack_a->next;
	}
	return (1);
}
