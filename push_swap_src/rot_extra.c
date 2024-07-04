/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_extra.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vodebunm <vodebunm@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 09:53:09 by vodebunm          #+#    #+#             */
/*   Updated: 2024/07/04 08:31:48 by vodebunm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_src/push_swap.h"

//arranging of function into seperate file
void ra(t_push_swap_stack **a, bool value)
{
    rot_func(a);
    if (!value)// If the 'value' flag is false, print the operation message
    {
        ft_printf("The first element becomes the last one\n");
    }
}
void rb(t_push_swap_stack **b, bool value)
{
    rot_func(b);
    if (!value)// If the 'value' flag is false, print the operation message
    {
        ft_printf("The first element becomes the last one, shift elm by 1\n");
    }
}
void ss(t_push_swap_stack **a,t_push_swap_stack **b, bool value)
{
    swap_func(a);
	swap_func(b);
    if (!value)// If the 'value' flag is false, print the operation message
    {
        ft_printf("swap a and b at same time\n");
    }
}
void sa(t_push_swap_stack **a, bool value)
{
    swap_func(a);
    if (!value)// If the 'value' flag is false, print the operation message
    {
        ft_printf("swap a\n");
    }
}
void sb(t_push_swap_stack **b, bool value)
{
    swap_func(b);
    if (!value)// If the 'value' flag is false, print the operation message
    {
        ft_printf("swap b\n");
    }
}