/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vodebunm <vodebunm@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:47:32 by vodebunm          #+#    #+#             */
/*   Updated: 2024/05/06 19:47:50 by vodebunm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

include "../includes/push_swap.h"

int	ft_rev_rot(t_list *a, t_list *b, int nbr)
{
	int	i;
	int	place_b;
	int	index_a;

	place_b = ft_find_place_b(b, nbr);
	index_a = ft_find_index(a, nbr);
	i = 0;
	if (place_b != 0)
		i = ft_lstsize(b) - place_b;
	if ((i < (ft_lstsize(a) - index_a)) && index_a)
		i = ft_lstsize(a) - index_a;
	return (i);
}

int	ft_rotate(t_list *a, t_list *b, int nbr)
{
	int	i;
	int	index;

	i = ft_find_place_b(b, nbr);
	index = ft_find_index(a, nbr);
	if (i < index)
		i = index;
	return (i);
}

int	ft_ra_rrb(t_list *a, t_list *b, int nbr)
{
	int	i;
	int	place_b;

	i = 0;
	place_b = ft_find_place_b(b, nbr);
	if (place_b != 0)
		i = ft_lstsize(b) - place_b;
	i = ft_find_index(a, nbr) + i;
	return (i);
}

int	ft_rra_rb(t_list *a, t_list *b, int nbr)
{
	int	i;
	int	index;

	i = 0;
	index = ft_find_index(a, nbr);
	if (index != 0)
		i = ft_lstsize(a) - index;
	i = ft_find_place_b(b, nbr) + i;
	return (i);
}
