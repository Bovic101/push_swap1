/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vodebunm <vodebunm@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 22:02:58 by vodebunm          #+#    #+#             */
/*   Updated: 2024/05/22 02:03:02 by vodebunm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_src/push_swap.h"

static void	swap(t_list **lst)
{
	t_list	*tmp;

	if (*lst == NULL || (*lst)->next == NULL)
		return ;
	tmp = *lst;
	*lst = (*lst)->next;
	tmp->next = tmp->next->next;
	(*lst)->next = tmp;
}

void	swap_a(t_list **a)
{
	ft_printf("sa\n");
	swap(a);
}

void	swap_b(t_list **b)
{
	ft_printf("sb\n");
	swap(b);
}

void	swap_ss(t_list **a, t_list **b)
{
	ft_printf("ss\n");
	swap(a);
	swap(b);
}
