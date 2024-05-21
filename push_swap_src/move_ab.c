/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vodebunm <vodebunm@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:47:32 by vodebunm          #+#    #+#             */
/*   Updated: 2024/05/21 13:06:52 by vodebunm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_src/push_swap.h"

int	rot_ab(t_list *a, t_list *b, int nbr)
{
	int	i;
	int	count;

	i = search_position_b(b, nbr);
	count = search_index_node(a, nbr);
	if (i < count)
		i = count;
	return (i);
}

int	move_ra_rrb(t_list *a, t_list *b, int nbr)
{
	int	i;
	int	position_b;

	i = 0;
	position_b = search_position_b(b, nbr);
	if (position_b != 0)
		i = ft_lstsize(b) - position_b;
	i = search_index_node(a, nbr) + i;
	return (i);
}

int	move_rra_rb(t_list *a, t_list *b, int nbr)
{
	int	i;
	int	count;

	i = 0;
	count = search_index_node(a, nbr);
	if (count != 0)
		i = ft_lstsize(a) - count;
	i = search_position_b(b, nbr) + i;
	return (i);
}

int	ft_rev_rot(t_list *a, t_list *b, int nbr)
{
	int	i;
	int	position_b;
	int	count_a;

	position_b = search_position_b(b, nbr);
	count_a = search_index_node(a, nbr);
	i = 0;
	if (position_b != 0)
		i = ft_lstsize(b) - position_b;
	if ((i < (ft_lstsize(a) - count_a)) && count_a)
		i = ft_lstsize(a) - count_a;
	return (i);
}
