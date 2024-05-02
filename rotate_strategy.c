/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_strategy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vodebunm <vodebunm@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 21:25:21 by vodebunm          #+#    #+#             */
/*   Updated: 2024/05/03 21:25:37 by vodebunm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_choose_rotate_ab(t_list *a, t_list *b)
{
	int		i;
	t_list	*temp;

	temp = a;
	i = ft_rev_rot(a, b, get_content(a));
	while (temp != 0)
	{
		if (i > ft_rotate(a, b, get_content(temp)))
			i = ft_rotate(a, b, get_content(temp));
		if (i > ft_rev_rot(a, b, get_content(temp)))
			i = ft_rev_rot(a, b, get_content(temp));
		if (i > ft_ra_rrb(a, b, get_content(temp)))
			i = ft_ra_rrb(a, b, get_content(temp));
		if (i > ft_rra_rb(a, b, get_content(temp)))
			i = ft_rra_rb(a, b, get_content(temp));
		temp = temp->next;
	}
	return (i);
}

int	ft_choose_rotate_ba(t_list *a, t_list *b)
{
	int		i;
	t_list	*temp;

	temp = b;
	i = ft_rev_rot_a(a, b, get_content(b));
	while (temp != 0)
	{
		if (i > ft_rotate_a(a, b, get_content(temp)))
			i = ft_rotate_a(a, b, get_content(temp));
		if (i > ft_rev_rot_a(a, b, get_content(temp)))
			i = ft_rev_rot_a(a, b, get_content(temp));
		if (i > ft_ra_rrb_a(a, b, get_content(temp)))
			i = ft_ra_rrb_a(a, b, get_content(temp));
		if (i > ft_rra_rb_a(a, b, get_content(temp)))
			i = ft_rra_rb_a(a, b, get_content(temp));
		temp = temp->next;
	}
	return (i);
}
