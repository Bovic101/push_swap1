/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_operation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vodebunm <vodebunm@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 12:29:16 by vodebunm          #+#    #+#             */
/*   Updated: 2024/08/11 02:49:55 by vodebunm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../push_swap_src/push_swap.h"

void join_lstnode(t_push_swap_stack **list, int val)
{
    t_push_swap_stack *new_node;
    t_push_swap_stack *lst_node;

    if (!list)
        return;

    new_node = malloc(sizeof(t_push_swap_stack));
    if (!new_node)
    {
        free_memory(list); // Handle memory allocation failure
        return;
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
//Function Loop until the stack pointer reaches the last data node
void push_activate(t_push_swap_stack **stack, t_push_swap_stack *last_datanode, char stack_variable)
{
	while (*stack != last_datanode)
	{
		if (stack_variable == 'a')
		{
			if (last_datanode->push_midval)// If the stack is 'a' and push_midval is true, rotate up, else rotate down
			{
				ra(stack, false);  // Rotate stack 'a' upwards//check
			}
			else
			{
				rra(stack, false); // Rotate stack 'a' downwards//check
			}
		}
		else if (stack_variable == 'b')
		{
			if (last_datanode->push_midval)// If the stack is 'b' and push_midval is true, rotate up, else rotate down
			{
				rb(stack, false);  // Rotate stack 'b' upwards//check
			}
			else
			{
				rrb(stack, false); // Rotate stack 'b' downwards//check
			}
		}
	}
}
