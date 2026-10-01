/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor-odebunmi <victor-odebunmi@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 01:04:31 by vodebunm          #+#    #+#             */
/*   Updated: 2026/10/01 17:15:27 by victor-odeb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"
# include <stdbool.h>
# include <limits.h>

typedef struct s_push_swap_stack
{
	int							data;
	int							count;
	int							nearval_cal;
	bool						nearval;
	bool						push_midval;
	struct s_push_swap_stack	*next;
	struct s_push_swap_stack	*prevnode;
	struct s_push_swap_stack	*desired_node;
}	t_push_swap_stack;

/* Initialization and sorting */
void					stack_a_init(t_push_swap_stack **a, char **argv);
bool					sorted_stack(t_push_swap_stack *stack);
void					alt_sorter(t_push_swap_stack **a);
void					turks_sorter(t_push_swap_stack **a,
							t_push_swap_stack **b);
void					data_value(t_push_swap_stack **a);

/* List operations */
void					join_lstnode(t_push_swap_stack **list, int val);
void					push_activate(t_push_swap_stack **stack,
							t_push_swap_stack *last_datanode,
							char stack_variable);

/* Basic operations */
void					swap_func(t_push_swap_stack **stack);
void					rot_func(t_push_swap_stack **stack);
void					rev_rot_ab(t_push_swap_stack **stack);
void					activate_push(t_push_swap_stack **stack1,
							t_push_swap_stack **stack2);

/* Push_swap operations */
void					sa(t_push_swap_stack **a, bool value);
void					sb(t_push_swap_stack **b, bool value);
void					ss(t_push_swap_stack **a, t_push_swap_stack **b,
							bool value);
void					pa(t_push_swap_stack **a, t_push_swap_stack **b,
							bool value);
void					pb(t_push_swap_stack **b, t_push_swap_stack **a,
							bool value);
void					ra(t_push_swap_stack **a, bool value);
void					rb(t_push_swap_stack **b, bool value);
void					rr(t_push_swap_stack **a, t_push_swap_stack **b,
							bool value);
void					rra(t_push_swap_stack **a, bool value);
void					rrb(t_push_swap_stack **b, bool value);
void					rrr(t_push_swap_stack **a, t_push_swap_stack **b,
							bool value);

/* Turk algorithm */
void					index_position(t_push_swap_stack *stack);
void					assign_t4a(t_push_swap_stack *a,
							t_push_swap_stack *b);
void					assign_t4b(t_push_swap_stack *a,
							t_push_swap_stack *b);
void					push_cost4a(t_push_swap_stack *a,
							t_push_swap_stack *b);
void					chose_closest_val(t_push_swap_stack *stack);
void					turk_implement(t_push_swap_stack *a,
							t_push_swap_stack *b);
void					turk_implement_b(t_push_swap_stack *a,
							t_push_swap_stack *b);

/* Turk movement */
void					a_b(t_push_swap_stack **a,
							t_push_swap_stack **b);
void					b_a(t_push_swap_stack **a,
							t_push_swap_stack **b);
void					rot_ab(t_push_swap_stack **a,
							t_push_swap_stack **b,
							t_push_swap_stack *closest_node);
void					rrot_both(t_push_swap_stack **a,
							t_push_swap_stack **b,
							t_push_swap_stack *closest_node);

/* Utilities */
int						format_check(const char *str);
int						rm_copy(t_push_swap_stack *a, int num);
void					free_mystack(t_push_swap_stack **stack);
void					free_memory(t_push_swap_stack **a);
void					free_split(char **split);
t_push_swap_stack		*max_stackval(t_push_swap_stack *stack);
t_push_swap_stack		*min_stackval(t_push_swap_stack *stack);
t_push_swap_stack		*obtain_closest_v(t_push_swap_stack *stack);
int						get_stack_len(t_push_swap_stack *stack);

#endif