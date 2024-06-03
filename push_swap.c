/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 12:35:01 by wpepping          #+#    #+#             */
/*   Updated: 2024/06/02 18:06:32 by wpepping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static int	read_error(t_list *list, int *n)
{
	ft_putendl_fd("Error", 2);
	if (n != NULL)
		free(n);
	ft_lstclear(&list, free);
	return (0);
}

static int	read_input(int argc, char **argv, t_stack *stack)
{
	int		i;
	long	l;
	int		*n;
	int		max;
	t_list	*list;

	i = 1;
	max = -2147483648;
	list = NULL;
	while (i < argc)
	{
		n = malloc(sizeof(int));
		if (!isint(argv[i]) || n == NULL)
			return (read_error(list, NULL));
		l = ft_atol(argv[i]);
		if (l > 2147483647 || l < -2147483648 || ft_lstfind(list, &l, *intcmp))
			return (read_error(list, n));
		*n = l;
		if (*n > max)
			max = *n;
		ft_lstadd_back(&list, ft_lstnew(n));
		i++;
	}
	new_stack(stack, list, &max);
	return (1);
}

int	main(int argc, char **argv)
{
	t_move	move;
	t_stack	stack_a;
	t_stack	stack_b;

	if (argc == 1 || !read_input(argc, argv, &stack_a))
		return (0);
	new_stack(&stack_b, NULL, NULL);
	while (stack_a.size > 3 && !is_sorted(&stack_a))
	{
		do_move(&stack_a, &stack_b, find_next_move(&stack_a, &stack_b, &move));
	}
	if (stack_a.size == 3)
		sort_3(&stack_a);
	else
		min_to_top(&stack_a);
	max_to_top(&stack_b);
	merge(&stack_a, &stack_b);
	min_to_top(&stack_a);
	ft_lstclear(&stack_a.top, *free);
	return (0);
}
