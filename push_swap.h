/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vodebunm <vodebunm@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 01:04:31 by vodebunm          #+#    #+#             */
/*   Updated: 2024/05/19 06:45:31 by vodebunm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"

void	swap_a(t_list **a);
void	swap_b(t_list **b);
void	swap_ss(t_list **a, t_list **b);
int		sorted_checker(t_list *stack_a);
t_list	*my_ft_lstnew(char *content);
int		ft_check_error(char *argv, t_list *temp);
void	ft_error(void);
int		ft_duplicate(t_list *lst, int n);
void	push_a(t_list **a, t_list **b);
void	push_b(t_list **b, t_list **a);
void	rotate_a(t_list **a);
void	rotate_b(t_list **b);
void	rotate_rr(t_list **a, t_list **b);
void	rev_rot_b(t_list **b);
void	rev_rot_a(t_list **a);
int		obtain_value(t_list *elem);
void	rev_rot_ab(t_list **a, t_list **b);
t_list	*ft_remove_back(t_list **list);
t_list	*ft_remove_front(t_list **list);
void	print_list(t_list *a);
void	ft_sort_list(t_list **a);
t_list	*ft_sort_b(t_list **lst_a);
void	ft_sort_b_3(t_list **lst_a, t_list **lst_b);
int		ft_choose_rotate_ab(t_list *a, t_list *b);
int		search_position_b(t_list *b, int nbr);
int		ft_find_bigger(t_list *lst);
int		ft_find_smaller(t_list *lst);
int		ft_find_index(t_list *lst, int nbr);
int		ft_rev_rot(t_list *a, t_list *b, int nbr);
int		ft_rra_rb(t_list *a, t_list *b, int nbr);
int		ft_ra_rrb(t_list *a, t_list *b, int nbr);
int		ft_rotate(t_list *a, t_list *b, int nbr);
void	partsorted_stack_a(t_list **a);
int		ft_do_rotate(t_list **a, t_list **b, int nbr, char s);
int		ft_do_rev_rot(t_list **a, t_list **b, int nbr, char s);
int		ft_do_rra_rb(t_list **a, t_list **b, int nbr, char s);
int		ft_do_ra_rrb(t_list **a, t_list **b, int nbr, char s);
t_list	**ft_sort_a(t_list **lst_a, t_list **lst_b);
int		ft_choose_rotate_ba(t_list *a, t_list *b);
int		ft_ra_rrb_a(t_list *a, t_list *b, int nbr);
int		ft_rra_rb_a(t_list *a, t_list *b, int nbr);
int		ft_rotate_a(t_list *a, t_list *b, int nbr);
int		ft_rev_rot_a(t_list *a, t_list *b, int nbr);

int		search_position_a(t_list *a, int nbr);

#endif