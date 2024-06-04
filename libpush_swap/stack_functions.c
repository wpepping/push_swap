/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:30:17 by wpepping          #+#    #+#             */
/*   Updated: 2024/06/03 16:00:48 by wpepping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpush_swap.h"

void	ft_stackrotate(t_list **lst)
{
	t_list	*temp;

	if (*lst && (*lst)->next)
	{
		ft_lstlast(*lst)->next = *lst;
		temp = (*lst)->next;
		(*lst)->next = NULL;
		*lst = temp;
	}
}

void	ft_stackrev_rotate(t_list **lst)
{
	t_list	*last;
	t_list	*before_last;

	if (*lst && (*lst)->next)
	{
		last = *lst;
		while (last->next != NULL)
		{
			before_last = last;
			last = last->next;
		}
		last->next = *lst;
		*lst = last;
		before_last->next = NULL;
	}
}

void	ft_stackpush(t_list **lst1, t_list **lst2)
{
	t_list	*temp;

	if (*lst1)
	{
		temp = *lst1;
		if ((*lst1)->next)
			*lst1 = (*lst1)->next;
		else
			*lst1 = NULL;
		ft_lstadd_front(lst2, temp);
	}
}

void	ft_stackswap(t_list **lst)
{
	t_list	*temp;

	if (*lst && (*lst)->next)
	{
		temp = (*lst)->next;
		(*lst)->next = temp->next;
		temp->next = *lst;
		*lst = temp;
	}
}
