/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wouter <wouter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:15:23 by wpepping          #+#    #+#             */
/*   Updated: 2024/06/05 19:35:06 by wouter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static const char	*read_sign(const char *str, int *sign)
{
	while (*str == ' ' || *str == '\f' || *str == '\n'
		|| *str == '\r' || *str == '\t' || *str == '\v')
		str++;
	if (*str == '-')
	{
		*sign = -1;
		return (str + 1);
	}
	*sign = 1;
	if (*str == '+')
		str++;
	return (str);
}

static long	read_numbers(const char *str)
{
	long	result;

	result = 0;
	while (*str >= '0' && *str <= '9')
	{
		result *= 10;
		result += *str - '0';
		str++;
	}
	return (result);
}

long	ft_atol(const char *nptr)
{
	int	sign;

	nptr = read_sign(nptr, &sign);
	return (read_numbers(nptr) * sign);
}
