/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_rot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vodebunm <vodebunm@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:18:25 by vodebunm          #+#    #+#             */
/*   Updated: 2024/08/11 02:57:35 by vodebunm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_src/push_swap.h"

// Continue rotating both stacks simultaneously
void rot_ab(t_push_swap_stack **a, t_push_swap_stack **b, t_push_swap_stack *closest_node)
{
    
    while (*b != closest_node->desired_node && *a != closest_node)
    {
        rr(a, b, false);//false send the operation message to the fd
    }
    index_position(*a);  // update the indices/positions of elements in stack
    index_position(*b);
}
void	rra(t_push_swap_stack **a, bool value)
{
	rev_rot_ab(a);
	if (!value)// If the 'value' flag is false, print the operation message
    {
        ft_printf("reverse rotate a \n");
    }
}

void	rrb(t_push_swap_stack **b, bool value)
{
	rev_rot_ab(b);
	if (!value)// If the 'value' flag is false, print the operation message
    {
        ft_printf("reverse rotate b\n");
    }
}
void	rrr(t_push_swap_stack **a, t_push_swap_stack **b, bool value)
{
	rev_rot_ab(a);
	rev_rot_ab(b);
	if (!value)// If the 'value' flag is false, print the operation message
    {
        ft_printf("reverse rotate both stack\n");
    }
}
