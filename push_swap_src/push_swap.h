/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vodebunm <vodebunm@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 01:04:31 by vodebunm          #+#    #+#             */
/*   Updated: 2024/06/01 04:27:20 by vodebunm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"
# include	<stdbool.h>
#include	<limits.h>

typedef struct push_swap_stack
{
    int data;
    int count;
    int nearval_cal;
    bool nearval;
    bool push_midval;
    struct push_swap_stack *next;
    struct push_swap_stack *prevnode;
    struct push_swap_stack *endpoint_node;
} t_push_swap_stack;

void	join_lstnode(t_push_swap_stack **list, int val);
void	stack_a_init(t_push_swap_stack **a, char **argv);


#endif