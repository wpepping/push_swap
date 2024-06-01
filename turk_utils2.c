/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 13:46:08 by wpepping          #+#    #+#             */
/*   Updated: 2024/05/31 17:36:48 by wpepping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_pos(t_list **curr, int *i)
{
	*curr = (*curr)->next;
	(*i)++;
}

void	set_direction(t_move *mv, int dir_a, int dir_b, int moves)
{
	mv->direction_a = dir_a;
	mv->direction_b = dir_b;
	mv->moves = moves;
}

void	max_to_top(t_stack *stack)
{
	t_list	*curr;
	int		pos;

	if (stack->top != NULL && stack->top->next != NULL)
	{
		pos = 0;
		curr = stack->top;
		while (*(int *)curr->content != stack->max)
		{
			curr = curr->next;
			pos++;
		}
		if (pos < (stack->size + 1) / 2)
			op_rb(stack, pos);
		else if (pos != 0)
			op_rrb(stack, stack->size - pos);
	}
}

void	min_to_top(t_stack *stack)
{
	t_list	*curr;
	int		pos;

	if (stack->top != NULL && stack->top->next != NULL)
	{
		pos = 0;
		curr = stack->top;
		while (*(int *)curr->content != stack->max)
		{
			curr = curr->next;
			pos++;
		}
		if (pos == stack->size - 1)
			return ;
		if (pos > stack->size / 2)
			op_rra(stack, stack->size - pos - 1);
		else
			op_ra(stack, pos + 1);
	}
}
