/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_operation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vodebunm <vodebunm@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 12:29:16 by vodebunm          #+#    #+#             */
/*   Updated: 2024/08/09 22:28:42 by vodebunm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../push_swap_src/push_swap.h"

void	join_lstnode(t_push_swap_stack **list, int val)// function join a newwode to the end of a linkedlist
{
	t_push_swap_stack	*new_node;
	t_push_swap_stack	*lst_node;
	
	if (!list)
		return ;
	new_node = malloc(sizeof(t_push_swap_stack));
	if (!new_node)
	{
		return ;
	}
	new_node->next = NULL;
	new_node->data = val;
	if (!(*list))
	{
		*list = new_node;
		new_node->prevnode = NULL;
	}
	else
	{
		lst_node = *list;
		while (lst_node->next != NULL)
		{
			lst_node = lst_node->next;
		}
		lst_node->next = new_node;
		new_node->prevnode = lst_node;
	}
}


