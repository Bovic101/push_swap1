/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vodebunm <vodebunm@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 01:04:31 by vodebunm          #+#    #+#             */
/*   Updated: 2024/05/21 13:09:31 by vodebunm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"

void	swap_a(t_list **a);
void	swap_b(t_list **b);
void	swap_ss(t_list **a, t_list **b);
int		sorted_checker(t_list *stack_a);
t_list	*string_covert_int(char *content);
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
t_list	*ft_remove_front(t_list **list);
void	print_list(t_list *a);
void	sort_linklist(t_list **a);
t_list	*ft_sort_b(t_list **lst_a);
void	sort_lsta_b(t_list **lst_a, t_list **lst_b);
int		ft_choose_rotate_ab(t_list *a, t_list *b);
int		search_position_b(t_list *b, int nbr);
int		search_bigger_value(t_list *lst);
int		search_smaller_value(t_list *lst);
int		search_index_node(t_list *lst, int nbr);
int		rev_rotb(t_list *a, t_list *b, int nbr);
int		move_rra_rb(t_list *a, t_list *b, int nbr);
int		move_ra_rrb(t_list *a, t_list *b, int nbr);
int		rot_ab(t_list *a, t_list *b, int nbr);
void	partsorted_stack_a(t_list **a);
int		rotate_linked_list(t_list **a, t_list **b, int nbr, char s);
int		rev_rot_linklist(t_list **a, t_list **b, int nbr, char s);
int		rev_rot_a_rot_b(t_list **a, t_list **b, int nbr, char s);
int		rot_a_revrot_b(t_list **a, t_list **b, int nbr, char s);
t_list	**ft_sort_a(t_list **lst_a, t_list **lst_b);
t_list	*ft_remove_back(t_list **list);
int		ft_choose_rotate_ba(t_list *a, t_list *b);
int		move_ra_rrb_a(t_list *a, t_list *b, int nbr);
int		move_rra_rb_a(t_list *a, t_list *b, int nbr);
int		rot_ab_a(t_list *a, t_list *b, int nbr);
int		rev_rotb_a(t_list *a, t_list *b, int nbr);
int		search_position_a(t_list *a, int nbr);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*ft_lstnew(void *content);
int		ft_lstsize(t_list *lst);
#endif