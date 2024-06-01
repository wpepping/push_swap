/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 18:40:16 by wpepping          #+#    #+#             */
/*   Updated: 2024/05/31 17:35:21 by wpepping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_pos(t_stack *stack, int nr)
{
	int		curr_i;
	t_list	*curr;

	curr = stack->top;
	curr_i = 0;
	if (!curr || !curr->next)
		return (0);
	while (*(int *)curr->content != stack->max)
		move_pos(&curr, &curr_i);
	while (curr->next && *(int *)curr->content > nr)
		move_pos(&curr, &curr_i);
	if (*(int *)curr->content > nr)
	{
		curr = stack->top;
		curr_i = 0;
		while (*(int *)curr->content > nr
			&& *(int *)curr->content != stack->max)
			move_pos(&curr, &curr_i);
	}
	return (curr_i);
}

static void	check_directions(t_stack *stck_a, t_stack *stck_b, t_move *mv)
{
	int	a_down;
	int	b_down;

	a_down = 0;
	b_down = 0;
	if (mv->pos_a != 0)
		a_down = stck_a->size - mv->pos_a;
	if (mv->pos_b != 0)
		b_down = stck_b->size - mv->pos_b;
	set_direction(mv, 1, 1, mv->pos_a + mv->pos_b - min(mv->pos_a, mv->pos_b));
	if (mv->pos_a + b_down < mv->moves)
		set_direction(mv, 1, -1, mv->pos_a + (stck_b->size - mv->pos_b));
	if (a_down + b_down - min(a_down, b_down) < mv->moves)
		set_direction(mv, -1, -1, a_down + b_down - min(a_down, b_down));
	if (a_down + mv->pos_b < mv->moves)
		set_direction(mv, -1, 1, (stck_a->size - mv->pos_a) + mv->pos_b);
}

t_move	*find_next_move(t_stack *stack_a, t_stack *stack_b, t_move *result)
{
	int		min_moves;
	t_move	curr;

	new_move(&curr, stack_a);
	min_moves = 2147483647;
	while (curr.pos_a < stack_a->size)
	{
		if (curr.pos_a < min_moves || stack_a->size - curr.pos_a < min_moves)
		{
			curr.pos_b = find_pos(stack_b, *(int *)curr.node->content);
			check_directions(stack_a, stack_b, &curr);
			if (curr.moves < min_moves)
			{
				min_moves = curr.moves;
				copy_move(result, &curr);
			}
		}
		curr.node = curr.node->next;
		curr.pos_a++;
	}
	return (result);
}

void	do_move(t_stack *stack_a, t_stack *stack_b, t_move *mv)
{
	int	both;

	both = 0;
	if (mv->direction_a == 1 && mv->direction_b == 1)
	{
		both = min(mv->pos_a, mv->pos_b);
		op_rr(stack_a, stack_b, both);
	}
	else if (mv->pos_a != 0 && mv->pos_b != 0
		&& mv->direction_a == mv->direction_b)
	{
		both = min(stack_a->size - mv->pos_a, stack_b->size - mv->pos_b) - 1;
		op_rrr(stack_a, stack_b, both);
	}
	if (mv->direction_a == 1)
		op_ra(stack_a, mv->pos_a - both);
	else if (mv->pos_a != 0)
		op_rra(stack_a, stack_a->size - mv->pos_a - both);
	if (mv->direction_b == 1)
		op_rb(stack_b, mv->pos_b - both);
	else if (mv->pos_b != 0)
		op_rrb(stack_b, stack_b->size - mv->pos_b - both);
	op_pb(stack_a, stack_b);
}

void	merge(t_stack *stack_a, t_stack *stack_b)
{
	int	rotates;
	int	max_a;

	max_a = stack_a->max;
	max_to_top(stack_b);
	rotates = stack_a->size;
	while (stack_b->top != NULL)
	{
		if (stack_a->top != NULL)
		{
			while (max_a > *(int *)stack_b->top->content
				&& rotates > 0)
			{
				op_rra(stack_a, 1);
				max_a = *(int *)ft_lstlast(stack_a->top)->content;
				rotates--;
			}
		}
		op_pa(stack_a, stack_b);
	}
}
