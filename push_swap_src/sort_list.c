/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vodebunm <vodebunm@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 16:21:40 by vodebunm          #+#    #+#             */
/*   Updated: 2024/05/21 13:09:31 by vodebunm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_src/push_swap.h"

void	partsorted_stack_a(t_list **a)
{
	if (obtain_value(*a) > obtain_value((*a)->next))
	{
		if (obtain_value(*a) < obtain_value((*a)->next->next))
			swap_a(a);
		else if (obtain_value(*a) > obtain_value((*a)->next->next)
			&& obtain_value((*a)->next) < obtain_value((*a)->next->next))
			rotate_a(a);
		else
		{
			rotate_a(a);
			swap_a(a);
		}
	}
	else if (obtain_value(*a) < obtain_value((*a)->next))
	{
		if (obtain_value(*a) > obtain_value((*a)->next->next))
			rev_rot_a(a);
		else if (obtain_value((*a)->next) > obtain_value((*a)->next->next))
		{
			swap_a(a);
			rotate_a(a);
		}
	}
}

void	sort_linklist(t_list **lst_a)
{
	t_list	*lst_b;
	int		i;

	lst_b = NULL;
	if (ft_lstsize(*lst_a) == 2)
		swap_a(lst_a);
	if (ft_lstsize(*lst_a) == 3)
		partsorted_stack_a(lst_a);
	else
	{
		lst_b = ft_sort_b(lst_a);
		lst_a = ft_sort_a(lst_a, &lst_b);
		i = search_index_node(*lst_a, search_smaller_value(*lst_a));
		if (i < ft_lstsize(*lst_a) - i)
		{
			while (obtain_value(*lst_a) != search_smaller_value(*lst_a))
				rotate_a(lst_a);
		}
		else
		{
			while (obtain_value(*lst_a) != search_smaller_value(*lst_a))
				rev_rot_a(lst_a);
		}
	}
}

t_list	*ft_sort_b(t_list **lst_a)
{
	t_list	*lst_b;
	int		sorted_a;

	lst_b = NULL;
	sorted_a = sorted_checker(*lst_a);
	if (ft_lstsize(*lst_a) > 3 && sorted_a == 0)
		push_b(&lst_b, lst_a);
	if (ft_lstsize(*lst_a) > 3 && sorted_a == 0)
		push_b(&lst_b, lst_a);
	if (ft_lstsize(*lst_a) > 3 && sorted_a == 0)
		sort_lsta_b(lst_a, &lst_b);
	if (sorted_a == 0)
		partsorted_stack_a(lst_a);
	return (lst_b);
}

t_list	**ft_sort_a(t_list **lst_a, t_list **lst_b)
{
	int		i;
	t_list	*temp;

	while (*lst_b != 0)
	{
		temp = *lst_b;
		i = ft_choose_rotate_ba(*lst_a, *lst_b);
		while (i >= 0)
		{
			if (i == rot_ab_a(*lst_a, *lst_b, obtain_value(temp)))
				i = rotate_linked_list(lst_a, lst_b, obtain_value(temp), 'b');
			else if (i == move_ra_rrb_a(*lst_a, *lst_b,
					obtain_value(temp)))
				i = rot_a_revrot_b(lst_a, lst_b, obtain_value(temp), 'b');
			else if (i == rev_rotb_a(*lst_a, *lst_b,
					obtain_value(temp)))
				i = rev_rot_linklist(lst_a, lst_b, obtain_value(temp), 'b');
			else if (i == move_rra_rb_a(*lst_a, *lst_b,
					obtain_value(temp)))
				i = rev_rot_a_rot_b(lst_a, lst_b, obtain_value(temp), 'b');
			else
				temp = temp->next;
		}
	}
	return (lst_a);
}

void	sort_lsta_b(t_list **lst_a, t_list **lst_b)
{
	int		i;
	int		sorted_a;
	t_list	*temp;

	sorted_a = sorted_checker(*lst_a);
	while (ft_lstsize(*lst_a) > 3 && sorted_a == 0)
	{
		temp = *lst_a;
		i = ft_choose_rotate_ab(*lst_a, *lst_b);
		while (i >= 0)
		{
			if (i == rot_ab(*lst_a, *lst_b, obtain_value(temp)))
				i = rotate_linked_list(lst_a, lst_b, obtain_value(temp), 'a');
			else if (i == rev_rotb(*lst_a, *lst_b, obtain_value(temp)))
				i = rev_rot_linklist(lst_a, lst_b, obtain_value(temp), 'a');
			else if (i == move_ra_rrb(*lst_a, *lst_b, obtain_value(temp)))
				i = rot_a_revrot_b(lst_a, lst_b, obtain_value(temp), 'a');
			else if (i == move_rra_rb(*lst_a, *lst_b, obtain_value(temp)))
				i = rev_rot_a_rot_b(lst_a, lst_b, obtain_value(temp), 'a');
			else
				temp = temp->next;
		}
	}
}
