/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vodebunm <vodebunm@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 22:02:58 by vodebunm          #+#    #+#             */
/*   Updated: 2024/05/02 11:13:27 by vodebunm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	swap(t_list **lst)
{
	t_list	*temp;

	if (*lst == NULL || (*lst)->next == NULL)
		return ;
	temp = *lst;
	*lst = (*lst)->next;
	temp->next = temp->next->next;
	(*lst)->next = temp;
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
