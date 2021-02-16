/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 16:30:34 by rlozano           #+#    #+#             */
/*   Updated: 2019/12/04 16:33:16 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *begin;

	begin = *lst;
	if (begin == NULL)
		*lst = new;
	else
	{
		while (begin->next)
			begin = begin->next;
		begin->next = new;
	}
}
