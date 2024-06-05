/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wouter <wouter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:50:48 by wpepping          #+#    #+#             */
/*   Updated: 2024/06/05 10:52:54 by wouter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] - s2[i] != 0)
			return (s1[i] - s2[i]);
		i += 1;
	}
	return (s1[i] - s2[i]);
}

int	do_op(char result[4], t_list **stack_a, t_list **stack_b)
{
	if (ft_strcmp(result, "sa") == 0)
		ft_stackswap(stack_a);
	else if (ft_strcmp(result, "sb") == 0)
		ft_stackswap(stack_b);
	else if (ft_strcmp(result, "ss") == 0)
	{
		ft_stackswap(stack_a);
		ft_stackswap(stack_b);
	}
	else if (ft_strcmp(result, "pa") == 0)
		ft_stackpush(stack_b, stack_a);
	else if (ft_strcmp(result, "pb") == 0)
	{
		ft_stackpush(stack_a, stack_b);
	}
	else if (!do_rotations(result, stack_a, stack_b))
		return (0);
	return (1);
}

int	do_rotations(char result[4], t_list **stack_a, t_list **stack_b)
{
	if (ft_strcmp(result, "ra") == 0)
		ft_stackrotate(stack_a);
	else if (ft_strcmp(result, "rb") == 0)
		ft_stackrotate(stack_b);
	else if (ft_strcmp(result, "rr") == 0)
	{
		ft_stackrotate(stack_a);
		ft_stackrotate(stack_b);
	}
	else if (ft_strcmp(result, "rra") == 0)
		ft_stackrev_rotate(stack_a);
	else if (ft_strcmp(result, "rrb") == 0)
		ft_stackrev_rotate(stack_b);
	else if (ft_strcmp(result, "rrr") == 0)
	{
		ft_stackrev_rotate(stack_a);
		ft_stackrev_rotate(stack_b);
	}
	else
		return (0);
	return (1);
}

int	read_op(char result[4], int fd)
{
	char	c;
	int		bytes_read;

	bytes_read = read(fd, result, 2);
	if (bytes_read == 0)
		return (-1);
	else if (bytes_read == 1)
		return (-2);
	bytes_read = read(fd, &c, 1);
	if (c == '\n')
		result[2] = '\0';
	else
	{
		result[2] = c;
		bytes_read = read(fd, &c, 1);
		if (bytes_read == 0 || c != '\n')
			return (-2);
		result[3] = '\0';
	}
	return (0);
}

int	checker_is_sorted(t_list *stack)
{
	if (stack == NULL || stack->next == NULL)
		return (1);
	while (stack->next != NULL)
	{
		if (*(int *)stack->next->content <= *(int *)stack->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}
