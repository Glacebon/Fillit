/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoskela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 17:43:24 by hkoskela          #+#    #+#             */
/*   Updated: 2019/11/06 16:54:56 by hkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*fresh;
	t_list	*old;

	if (!lst || !f)
		return (NULL);
	old = f(lst);
	if (!(new = ft_lstnew(old->content, old->content_size)))
		return (NULL);
	lst = lst->next;
	fresh = new;
	while (lst)
	{
		old = f(lst);
		if (!(new->next = ft_lstnew(old->content, old->content_size)))
			return (NULL);
		new = new->next;
		lst = lst->next;
	}
	return (fresh);
}
