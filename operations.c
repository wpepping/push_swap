/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:00:01 by wouter            #+#    #+#             */
/*   Updated: 2024/06/01 17:19:28 by wpepping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_sa(t_stack *stack_a)
{
	ft_stackswap(&stack_a->top);
	ft_putendl_fd("sa", 1);
}

void	op_push(t_stack *stack_a, t_stack *stack_b)
{
	t_list	*curr;

	ft_stackpush(&stack_b->top, &stack_a->top);
	if (stack_a->top != NULL && *(int *)stack_a->top->content > stack_a->max)
		stack_a->max = *(int *)stack_a->top->content;
	if (stack_b->top == NULL)
		stack_b->max = -2147483648;
	else
	{
		curr = stack_b->top;
		stack_b->max = *(int *)curr->content;
		while (curr != NULL)
		{
			if (*(int *)curr->content > stack_b->max)
				stack_b->max = *(int *)curr->content;
			curr = curr->next;
		}
	}
	stack_a->size++;
	stack_b->size--;
}

void	op_pa(t_stack *stack_a, t_stack *stack_b)
{
	op_push(stack_a, stack_b);
	ft_putendl_fd("pa", 1);
}

void	op_pb(t_stack *stack_a, t_stack *stack_b)
{
	op_push(stack_b, stack_a);
	ft_putendl_fd("pb", 1);
}

void	op_ra(t_stack *stack_a, int n)
{
	while (n-- > 0)
	{
		ft_stackrotate(&stack_a->top);
		ft_putendl_fd("ra", 1);
	}
}
