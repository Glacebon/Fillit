/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoskela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 15:03:03 by hkoskela          #+#    #+#             */
/*   Updated: 2019/11/06 18:49:00 by hkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list		*this;
	t_list		*next;

	this = *alst;
	while (this)
	{
		next = this->next;
		del(this->content, this->content_size);
		free(this);
		this = next;
	}
	*alst = NULL;
}
