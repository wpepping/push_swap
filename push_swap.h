/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 12:35:05 by wpepping          #+#    #+#             */
/*   Updated: 2024/06/01 17:10:47 by wpepping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_move
{
	int		moves;
	int		pos_a;
	int		pos_b;
	int		direction_a;
	int		direction_b;
	t_list	*node;
}	t_move;

typedef struct s_stack
{
	t_list	*top;
	int		size;
	int		max;
}	t_stack;

int		min(int a, int b);
int		intcmp(int *a, int *b);
int		isint(char *str);
long	ft_atol(const char *nptr);
void	ft_stackrotate(t_list **lst);
void	ft_stackrev_rotate(t_list **lst);
void	ft_stackpush(t_list **lst1, t_list **lst2);
void	ft_stackswap(t_list **lst);
t_move	*find_next_move(t_stack *stack_a, t_stack *stack_b, t_move *result);
void	do_move(t_stack *stack_a, t_stack *stack_b, t_move *mv);
void	new_stack(t_stack *result, t_list *list, int *max);
void	merge(t_stack *stack_a, t_stack *stack_b);
void	new_move(t_move *result, t_stack *stack);
void	copy_move(t_move *result, t_move *move);
void	set_direction(t_move *mv, int dir_a, int dir_b, int moves);
void	move_pos(t_list **curr, int *i);
void	op_sa(t_stack *stack_a);
void	op_pa(t_stack *stack_a, t_stack *stack_b);
void	op_pb(t_stack *stack_a, t_stack *stack_b);
void	op_ra(t_stack *stack_a, int n);
void	op_rb(t_stack *stack_b, int n);
void	op_rr(t_stack	*stack_a, t_stack *stack_b, int n);
void	op_rra(t_stack	*stack_a, int n);
void	op_rrb(t_stack *stack_b, int n);
void	op_rrr(t_stack	*stack_a, t_stack *stack_b, int n);
int		is_sorted(t_stack *stack);
void	sort_3(t_stack *s);
void	max_to_top(t_stack *stack);
void	min_to_top(t_stack *stack);

#endif
