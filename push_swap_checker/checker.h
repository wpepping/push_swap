/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 16:28:06 by wpepping          #+#    #+#             */
/*   Updated: 2024/06/04 15:50:29 by wpepping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libpush_swap/libpush_swap.h"

int	ft_strcmp(char *s1, char *s2);
int	do_op(char result[4], t_list **stack_a, t_list **stack_b);
int	do_rotations(char result[4], t_list **stack_a, t_list **stack_b);
int	read_op(char result[4], int fd);
int	checker_is_sorted(t_list *stack);

#endif
