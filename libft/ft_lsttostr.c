/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsttostr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoskela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 19:15:12 by hkoskela          #+#    #+#             */
/*   Updated: 2019/11/06 19:37:23 by hkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_lsttostr(t_list *begin)
{
	t_list	*node;
	char	*nodesdata;
	char	*str;
	int		length;
	int		i;

	if (!begin)
		return (NULL);
	node = begin;
	length = ft_lstcontentlen(begin);
	i = 0;
	if (!(str = (char *)malloc(sizeof(char) * length)))
		return (NULL);
	while (node != NULL)
	{
		nodesdata = node->content;
		str = ft_strcat(str, nodesdata);
		node = node->next;
		i++;
	}
	return (str);
}
