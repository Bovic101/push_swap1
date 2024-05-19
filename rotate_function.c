/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vodebunm <vodebunm@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 22:05:07 by vodebunm          #+#    #+#             */
/*   Updated: 2024/05/19 04:00:27 by vodebunm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_remove_front(t_list **list)
{
	t_list	*first_node;

	first_node = *list;
	if (*list == NULL)
		return (NULL);
	if (first_node->next == NULL)
	{
		*list = NULL;
		return (first_node);
	}
	*list = (*list)->next;
	first_node->next = NULL;
	return (first_node);
}

static void	rotate(t_list **list)
{
	t_list	*first;

	if (*list == NULL || (*list)->next == NULL)
		return ;
	first = ft_remove_front(list);
	ft_lstadd_back(list, first);
}

void	rotate_a(t_list **a)
{
	ft_printf("ra\n");
	rotate(a);
}

void	rotate_b(t_list **b)
{
	ft_printf("rb\n");
	rotate(b);
}

void	rotate_rr(t_list **a, t_list **b)
{
	ft_printf("rr\n");
	rotate(a);
	rotate(b);
}
