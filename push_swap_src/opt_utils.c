/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vodebunm <vodebunm@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 23:44:15 by vodebunm          #+#    #+#             */
/*   Updated: 2024/05/21 04:24:34 by vodebunm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_src/push_swap.h"

int	rotate_linked_list(t_list **a, t_list **b, int nbr, char s)
{
	if (s == 'a')
	{
		while (obtain_value(*a) != nbr && search_position_b(*b, nbr) > 0)
			rotate_rr(a, b);
		while (obtain_value(*a) != nbr)
			rotate_a(a);
		while (search_position_b(*b, nbr) > 0)
			rotate_b(b);
		push_b(b, a);
	}
	else
	{
		while (obtain_value(*b) != nbr && search_position_a(*a, nbr) > 0)
			rotate_rr(a, b);
		while (obtain_value(*b) != nbr)
			rotate_b(b);
		while (search_position_a(*a, nbr) > 0)
			rotate_a(a);
		push_a(a, b);
	}
	return (-1);
}

int	rev_rot_linklist(t_list **a, t_list **b, int nbr, char s)
{
	if (s == 'a')
	{
		while (obtain_value(*a) != nbr && search_position_b(*b, nbr) > 0)
			rev_rot_ab(a, b);
		while (obtain_value(*a) != nbr)
			rev_rot_a(a);
		while (search_position_b(*b, nbr) > 0)
			rev_rot_b(b);
		push_b(b, a);
	}
	else
	{
		while (obtain_value(*b) != nbr && search_position_a(*a, nbr) > 0)
			rev_rot_ab(a, b);
		while (obtain_value(*b) != nbr)
			rev_rot_b(b);
		while (search_position_a(*a, nbr) > 0)
			rev_rot_a(a);
		push_a(a, b);
	}
	return (-1);
}

int	rev_rot_a_rot_b(t_list **a, t_list **b, int nbr, char s)
{
	if (s == 'a')
	{
		while (obtain_value(*a) != nbr)
			rev_rot_a(a);
		while (search_position_b(*b, nbr) > 0)
			rotate_b(b);
		push_b(b, a);
	}
	else
	{
		while (search_position_a(*a, nbr) > 0)
			rev_rot_a(a);
		while (obtain_value(*b) != nbr)
			rotate_b(b);
		push_a(a, b);
	}
	return (-1);
}

int	rot_a_revrot_b(t_list **a, t_list **b, int nbr, char s)
{
	if (s == 'a')
	{
		while (obtain_value(*a) != nbr)
			rotate_a(a);
		while (search_position_b(*b, nbr) > 0)
			rev_rot_b(b);
		push_b(b, a);
	}
	else
	{
		while (search_position_a(*a, nbr) > 0)
			rotate_a(a);
		while (obtain_value(*b) != nbr)
			rev_rot_b(b);
		push_a(a, b);
	}
	return (-1);
}
