/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlinkc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoskela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 16:30:26 by hkoskela          #+#    #+#             */
/*   Updated: 2019/11/06 17:45:00 by hkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstlinkc(t_list *begin)
{
	int		count;
	t_list	*link;

	if (!begin)
		return (0);
	link = begin;
	count = 0;
	while (link != NULL)
	{
		count++;
		link = link->next;
	}
	return (count);
}
