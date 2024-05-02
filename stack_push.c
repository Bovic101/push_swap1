/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vodebunm <vodebunm@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 11:17:20 by vodebunm          #+#    #+#             */
/*   Updated: 2024/05/02 11:17:47 by vodebunm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	push(t_list **list_1, t_list **list_2)
{
	t_list	*temp;

	if (list_2 == NULL)
		return ;
	temp = *list_2;
	*list_2 = (*list_2)->next;
	temp->next = *list_1;
	*list_1 = temp;
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
