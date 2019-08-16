/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skiessli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 13:03:27 by skiessli          #+#    #+#             */
/*   Updated: 2018/11/09 13:11:24 by skiessli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*n_lst;
	t_list	*cur;

	if (!lst || !f)
		return (NULL);
	if (!(n_lst = ft_lstnew(f(lst)->content, f(lst)->content_size)))
		return (NULL);
	cur = n_lst;
	while (lst->next)
	{
		lst = lst->next;
		if (!(cur->next = ft_lstnew(f(lst)->content, f(lst)->content_size)))
			return (NULL);
		cur = cur->next;
	}
	return (n_lst);
}
