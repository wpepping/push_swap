/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wouter <wouter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:50:18 by wpepping          #+#    #+#             */
/*   Updated: 2024/06/05 21:02:30 by wouter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	isint(char *str)
{
	if (*str == '-')
		str++;
	if (*str == '\0' || ft_strlen(str) > 10)
		return (0);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

static int	err_handler(t_list *list_a, t_list *list_b, char **arr, int *n)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	if (n != NULL)
		free(n);
	if (arr != NULL)
		free_arr((void **)arr);
	ft_lstclear(&list_a, free);
	ft_lstclear(&list_b, free);
	return (0);
}

static int	add_numbers(char *str, t_list **list, char **nrs)
{
	int		n;
	int		*new;
	long	l;

	nrs = ft_split(str, ' ');
	if (nrs == NULL)
		return (err_handler(*list, NULL, NULL, NULL));
	n = arrlen((void **)nrs) - 1;
	while (n >= 0)
	{
		new = malloc(sizeof(int));
		if (new == NULL)
			return (err_handler(*list, NULL, nrs, NULL));
		if (!isint(nrs[n]))
			return (err_handler(*list, NULL, nrs, NULL));
		l = ft_atol(nrs[n--]);
		if (l > 2147483647 || l < -2147483648)
			return (err_handler(*list, NULL, nrs, new));
		if (ft_lstfind(*list, &l, *intcmp))
			return (err_handler(*list, NULL, nrs, new));
		*new = l;
		ft_lstadd_front(list, ft_lstnew(new));
	}
	free_arr((void **)nrs);
	return (1);
}

static int	read_input(int argc, char **argv, t_list **list)
{
	char	**nrs;

	nrs = NULL;
	while (--argc > 0)
	{
		if (!add_numbers(argv[argc], list, nrs))
			return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_list	*stck_a;
	t_list	*stck_b;
	char	op[4];
	int		n;

	stck_a = NULL;
	stck_b = NULL;
	if (argc == 1 || !read_input(argc, argv, &stck_a))
		return (1);
	n = read_op(op, STDIN_FILENO);
	while (n == 0)
	{
		if (!do_op(op, &stck_a, &stck_b))
			return (err_handler(stck_a, stck_b, NULL, NULL));
		n = read_op(op, STDIN_FILENO);
	}
	if (n == -2)
		return (err_handler(stck_a, stck_b, NULL, NULL));
	else if (checker_is_sorted(stck_a) && stck_b == NULL)
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	ft_lstclear(&stck_a, *free);
	ft_lstclear(&stck_b, *free);
	return (0);
}
