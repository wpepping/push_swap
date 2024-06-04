/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 16:07:09 by wpepping          #+#    #+#             */
/*   Updated: 2024/06/04 16:40:04 by wpepping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpush_swap.h"

int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	intcmp(int *a, int *b)
{
	return (*a - *b);
}

int	arrlen(void **arr)
{
	int	result;

	result = 0;
	while (arr[result] != NULL)
		result++;
	return (result);
}

void	free_arr(void **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}
