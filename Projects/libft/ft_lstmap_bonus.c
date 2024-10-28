/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:24:40 by rraumain          #+#    #+#             */
/*   Updated: 2024/10/28 15:34:59 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	**new_lst;
	t_list	*element;
	size_t	len;

	len = ft_lstsize(lst);
	new_lst = malloc(len * sizeof(t_list *));
	if (!new_lst)
		return (NULL);
	while (lst)
	{
		ft_lstiter(lst, (void *)f);
		ft_lstdelone(lst, del);
		element = ft_lstnew(lst);
		if (!element)
		{
			ft_lstclear(new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(new_lst, element);
		lst = lst->next;
	}
	return (*new_lst);
}
