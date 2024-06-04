/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:26:39 by wouter            #+#    #+#             */
/*   Updated: 2024/06/04 16:49:31 by wpepping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpush_swap.h"

void	op_rb(t_stack *stack_b, int n)
{
	while (n-- > 0)
	{
		ft_stackrotate(&stack_b->top);
		ft_putendl_fd("rb", STDOUT_FILENO);
	}
}

void	op_rr(t_stack	*stack_a, t_stack *stack_b, int n)
{
	while (n-- > 0)
	{
		ft_stackrotate(&stack_a->top);
		ft_stackrotate(&stack_b->top);
		ft_putendl_fd("rr", STDOUT_FILENO);
	}
}

void	op_rra(t_stack	*stack_a, int n)
{
	while (n-- > 0)
	{
		ft_stackrev_rotate(&stack_a->top);
		ft_putendl_fd("rra", STDOUT_FILENO);
	}
}

void	op_rrb(t_stack *stack_b, int n)
{
	while (n-- > 0)
	{
		ft_stackrev_rotate(&stack_b->top);
		ft_putendl_fd("rrb", STDOUT_FILENO);
	}
}

void	op_rrr(t_stack	*stack_a, t_stack *stack_b, int n)
{
	while (n-- > 0)
	{
		ft_stackrev_rotate(&stack_a->top);
		ft_stackrev_rotate(&stack_b->top);
		ft_putendl_fd("rrr", STDOUT_FILENO);
	}
}
