/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoskela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 18:31:04 by hkoskela          #+#    #+#             */
/*   Updated: 2019/11/01 17:57:11 by hkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*udst;
	const unsigned char	*usrc;

	udst = (unsigned char*)dst;
	usrc = (unsigned char*)src;
	i = 0;
	if (usrc == udst)
		return (dst);
	if (usrc < udst)
		while (++i <= len)
			udst[len - i] = usrc[len - i];
	else
	{
		while (len > 0)
		{
			*udst = *usrc;
			udst++;
			usrc++;
			len--;
		}
	}
	return (dst);
}
