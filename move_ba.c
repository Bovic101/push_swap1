/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ba.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vodebunm <vodebunm@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:38:55 by vodebunm          #+#    #+#             */
/*   Updated: 2024/05/19 05:05:11 by vodebunm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_rev_rot_a(t_list *a, t_list *b, int nbr)
{
	int	i;
	int	position_a;
	int	count_b;

	i = 0;
	position_a = search_position_a(a, nbr);
	count_b = ft_find_index(b, nbr);
	if (position_a != 0)
		i = ft_lstsize(a) - position_a;
	if ((i < (ft_lstsize(b) - count_b)) && count_b)
		i = ft_lstsize(b) - count_b;
	return (i);
}

int	ft_rotate_a(t_list *a, t_list *b, int nbr)
{
	int	i;
	int	count_b;

	i = search_position_a(a, nbr);
	count_b = ft_find_index(b, nbr);
	if (i < count_b)
		i = count_b;
	return (i);
}

int	ft_rra_rb_a(t_list *a, t_list *b, int nbr)
{
	int	i;
	int	place_a;

	i = 0;
	place_a = search_position_a(a, nbr);
	if (place_a != 0)
		i = ft_lstsize(a) - place_a;
	i = ft_find_index(b, nbr) + i;
	return (i);
}

int	ft_ra_rrb_a(t_list *a, t_list *b, int nbr)
{
	int	i;
	int	count_b;

	i = 0;
	count_b = ft_find_index(b, nbr);
	if (count_b != 0)
		i = ft_lstsize(b) - count_b;
	i = search_position_a(a, nbr) + i;
	return (i);
}
