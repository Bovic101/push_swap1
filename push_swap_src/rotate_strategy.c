/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_strategy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vodebunm <vodebunm@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 21:25:21 by vodebunm          #+#    #+#             */
/*   Updated: 2024/05/19 18:45:27 by vodebunm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_src/push_swap.h"

int	ft_choose_rotate_ab(t_list *a, t_list *b)
{
	int		i;
	t_list	*temp;

	temp = a;
	i = ft_rev_rot(a, b, obtain_value(a));
	while (temp != 0)
	{
		if (i > ft_rotate(a, b, obtain_value(temp)))
			i = ft_rotate(a, b, obtain_value(temp));
		if (i > ft_rev_rot(a, b, obtain_value(temp)))
			i = ft_rev_rot(a, b, obtain_value(temp));
		if (i > ft_ra_rrb(a, b, obtain_value(temp)))
			i = ft_ra_rrb(a, b, obtain_value(temp));
		if (i > ft_rra_rb(a, b, obtain_value(temp)))
			i = ft_rra_rb(a, b, obtain_value(temp));
		temp = temp->next;
	}
	return (i);
}

int	ft_choose_rotate_ba(t_list *a, t_list *b)
{
	int		i;
	t_list	*temp;

	temp = b;
	i = ft_rev_rot_a(a, b, obtain_value(b));
	while (temp != 0)
	{
		if (i > ft_rotate_a(a, b, obtain_value(temp)))
			i = ft_rotate_a(a, b, obtain_value(temp));
		if (i > ft_rev_rot_a(a, b, obtain_value(temp)))
			i = ft_rev_rot_a(a, b, obtain_value(temp));
		if (i > ft_ra_rrb_a(a, b, obtain_value(temp)))
			i = ft_ra_rrb_a(a, b, obtain_value(temp));
		if (i > ft_rra_rb_a(a, b, obtain_value(temp)))
			i = ft_rra_rb_a(a, b, obtain_value(temp));
		temp = temp->next;
	}
	return (i);
}
