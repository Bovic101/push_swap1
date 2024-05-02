/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ba.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vodebunm <vodebunm@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:38:55 by vodebunm          #+#    #+#             */
/*   Updated: 2024/05/06 18:39:17 by vodebunm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_rev_rot_a(t_list *a, t_list *b, int nbr)
{
	int	i;
	int	place_a;
	int	index_b;

	i = 0;
	place_a = ft_find_place_a(a, nbr);
	index_b = ft_find_index(b, nbr);
	if (place_a != 0)
		i = ft_lstsize(a) - place_a;
	if ((i < (ft_lstsize(b) - index_b)) && index_b)
		i = ft_lstsize(b) - index_b;
	return (i);
}

int	ft_rotate_a(t_list *a, t_list *b, int nbr)
{
	int	i;
	int	index_b;

	i = ft_find_place_a(a, nbr);
	index_b = ft_find_index(b, nbr);
	if (i < index_b)
		i = index_b;
	return (i);
}

int	ft_rra_rb_a(t_list *a, t_list *b, int nbr)
{
	int	i;
	int	place_a;

	i = 0;
	place_a = ft_find_place_a(a, nbr);
	if (place_a != 0)
		i = ft_lstsize(a) - place_a;
	i = ft_find_index(b, nbr) + i;
	return (i);
}

int	ft_ra_rrb_a(t_list *a, t_list *b, int nbr)
{
	int	i;
	int	index_b;

	i = 0;
	index_b = ft_find_index(b, nbr);
	if (index_b != 0)
		i = ft_lstsize(b) - index_b;
	i = ft_find_place_a(a, nbr) + i;
	return (i);
}
