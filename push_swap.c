/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 12:35:01 by wpepping          #+#    #+#             */
/*   Updated: 2024/06/04 16:50:08 by wpepping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	isint(char *str)
{
	if (*str == '-')
		str++;
	if (ft_strlen(str) > 10)
		return (0);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

static int	read_error(t_list *list, char **arr, int *n)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	ft_lstclear(&list, free);
	if (arr != NULL)
		free_arr((void **)arr);
	if (n != NULL)
		free(n);
	return (0);
}

static int	add_numbers(char *str, t_list **list, int *max)
{
	char	**nrs;
	int		n;
	int		*new;
	long	l;

	nrs = ft_split(str, ' ');
	if (nrs == NULL)
		return (read_error(*list, NULL, NULL));
	n = arrlen((void **)nrs) - 1;
	while (n >= 0)
	{
		new = malloc(sizeof(int));
		if (!isint(nrs[n]) || new == NULL)
			return (read_error(*list, nrs, NULL));
		l = ft_atol(nrs[n--]);
		if (l > 2147483647 || l < -2147483648 || ft_lstfind(*list, &l, *intcmp))
			return (read_error(*list, nrs, new));
		*new = l;
		if (*new > *max)
			*max = *new;
		ft_lstadd_front(list, ft_lstnew(new));
	}
	free_arr((void **)nrs);
	return (1);
}

static int	read_input(int argc, char **argv, t_stack *stack)
{
	int		max;
	t_list	*list;

	max = -2147483648;
	list = NULL;
	while (--argc > 0)
	{
		if (!add_numbers(argv[argc], &list, &max))
			return (0);
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
		return (1);
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
