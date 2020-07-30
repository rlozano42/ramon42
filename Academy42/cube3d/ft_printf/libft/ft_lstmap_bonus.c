/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 16:34:25 by rlozano           #+#    #+#             */
/*   Updated: 2019/12/04 16:34:28 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*temp;
	t_list	*new;

	if (lst)
	{
		if (!(temp = ft_lstnew(f(lst->content))))
			return (NULL);
		lst = lst->next;
		while (lst)
		{
			if (!(new = ft_lstnew(f(lst->content))))
			{
				ft_lstclear(&temp, del);
				return (NULL);
			}
			ft_lstadd_back(&temp, new);
			lst = lst->next;
		}
		return (temp);
	}
	return (0);
}
