/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcontentlen.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoskela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 19:20:05 by hkoskela          #+#    #+#             */
/*   Updated: 2019/11/06 19:23:30 by hkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_lstcontentlen(t_list *begin)
{
	size_t	len;
	t_list	*link;

	len = 0;
	if (!begin)
		return (0);
	link = begin;
	while (link)
	{
		len = len + (link->content_size);
		link = link->next;
	}
	return (len);
}
