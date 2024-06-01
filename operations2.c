/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:26:39 by wouter            #+#    #+#             */
/*   Updated: 2024/06/01 17:19:49 by wpepping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_rb(t_stack *stack_b, int n)
{
	while (n-- > 0)
	{
		ft_stackrotate(&stack_b->top);
		ft_putendl_fd("rb", 1);
	}
}

void	op_rr(t_stack	*stack_a, t_stack *stack_b, int n)
{
	while (n-- > 0)
	{
		ft_stackrotate(&stack_a->top);
		ft_stackrotate(&stack_b->top);
		ft_putendl_fd("rr", 1);
	}
}

void	op_rra(t_stack	*stack_a, int n)
{
	while (n-- > 0)
	{
		ft_stackrev_rotate(&stack_a->top);
		ft_putendl_fd("rra", 1);
	}
}

void	op_rrb(t_stack *stack_b, int n)
{
	while (n-- > 0)
	{
		ft_stackrev_rotate(&stack_b->top);
		ft_putendl_fd("rrb", 1);
	}
}

void	op_rrr(t_stack	*stack_a, t_stack *stack_b, int n)
{
	while (n-- > 0)
	{
		ft_stackrev_rotate(&stack_a->top);
		ft_stackrev_rotate(&stack_b->top);
		ft_putendl_fd("rrr", 1);
	}
}
