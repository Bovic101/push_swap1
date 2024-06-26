/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_strategy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vodebunm <vodebunm@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 21:25:21 by vodebunm          #+#    #+#             */
/*   Updated: 2024/05/22 01:29:36 by vodebunm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_src/push_swap.h"

int	opt_rotate_ab(t_list *a, t_list *b)
{
	int		i;
	t_list	*temp;

	temp = a;
	i = rev_rotb(a, b, obtain_value(a));
	while (temp != 0)
	{
		if (i > rot_ab(a, b, obtain_value(temp)))
			i = rot_ab(a, b, obtain_value(temp));
		if (i > rev_rotb(a, b, obtain_value(temp)))
			i = rev_rotb(a, b, obtain_value(temp));
		if (i > move_ra_rrb(a, b, obtain_value(temp)))
			i = move_ra_rrb(a, b, obtain_value(temp));
		if (i > move_rra_rb(a, b, obtain_value(temp)))
			i = move_rra_rb(a, b, obtain_value(temp));
		temp = temp->next;
	}
	return (i);
}

int	opt_rotate_ba(t_list *a, t_list *b)
{
	int		i;
	t_list	*temp;

	temp = b;
	i = rev_rotb_a(a, b, obtain_value(b));
	while (temp != 0)
	{
		if (i > rot_ab_a(a, b, obtain_value(temp)))
			i = rot_ab_a(a, b, obtain_value(temp));
		if (i > rev_rotb_a(a, b, obtain_value(temp)))
			i = rev_rotb_a(a, b, obtain_value(temp));
		if (i > move_ra_rrb_a(a, b, obtain_value(temp)))
			i = move_ra_rrb_a(a, b, obtain_value(temp));
		if (i > move_rra_rb_a(a, b, obtain_value(temp)))
			i = move_rra_rb_a(a, b, obtain_value(temp));
		temp = temp->next;
	}
	return (i);
}
