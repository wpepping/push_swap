/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 19:32:02 by wpepping          #+#    #+#             */
/*   Updated: 2024/05/31 17:36:06 by wpepping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	new_stack(t_stack *result, t_list *list, int *max)
{
	result->top = list;
	result->size = ft_lstsize(list);
	if (max == NULL)
		result->max = -2147483648;
	else
		result->max = *max;
}

void	new_move(t_move *result, t_stack *stack)
{
	result->node = stack->top;
	result->pos_a = 0;
	result->pos_b = 0;
	result->moves = 0;
	result->direction_a = 1;
	result->direction_b = 1;
}

void	copy_move(t_move *result, t_move *move)
{
	result->pos_a = move->pos_a;
	result->pos_b = move->pos_b;
	result->moves = move->moves;
	result->direction_a = move->direction_a;
	result->direction_b = move->direction_b;
}

int	is_sorted(t_stack *stack)
{
	t_list	*lst;

	if (!stack->top)
		return (1);
	lst = stack->top;
	while (lst->next)
	{
		if (*(int *)lst->next->content < *(int *)lst->content
			&& *(int *)lst->content != stack->max)
			return (0);
		lst = lst->next;
	}
	if (*(int *)stack->top->content < *(int *)lst->content
		&& *(int *)lst->content != stack->max)
		return (0);
	return (1);
}

void	sort_3(t_stack *s)
{
	int	a;
	int	b;
	int	c;

	a = *(int *)s->top->content;
	b = *(int *)s->top->next->content;
	c = *(int *)s->top->next->next->content;
	if (a > b && b > c)
	{
		op_sa(s);
		op_rra(s, 1);
	}
	else if (b > c && c > a)
	{
		op_sa(s);
		op_ra(s, 1);
	}
	else if (c > a && a > b)
		op_sa(s);
	else if (a > c && c > b)
		op_ra(s, 1);
	else if (b > a && a > c)
		op_rra(s, 1);
}
