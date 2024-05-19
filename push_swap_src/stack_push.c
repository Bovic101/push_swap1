/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vodebunm <vodebunm@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 11:17:20 by vodebunm          #+#    #+#             */
/*   Updated: 2024/05/19 18:47:03 by vodebunm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_src/push_swap.h"

static void	push(t_list **list_1, t_list **list_2)
{
	t_list	*tmp;

	if (list_2 == NULL)
		return ;
	tmp = *list_2;
	*list_2 = (*list_2)->next;
	tmp->next = *list_1;
	*list_1 = tmp;
}

void	push_a(t_list **a, t_list **b)
{
	ft_printf("pa\n");
	push(a, b);
}

void	push_b(t_list **b, t_list **a)
{
	ft_printf("pb\n");
	push(b, a);
}
