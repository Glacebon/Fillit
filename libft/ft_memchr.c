/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoskela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 17:04:30 by hkoskela          #+#    #+#             */
/*   Updated: 2019/11/06 20:17:44 by hkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *pt;
	unsigned char src;

	pt = (unsigned char *)s;
	src = (unsigned char)c;
	while (n > 0)
	{
		if (*pt == src)
			return (pt);
		pt++;
		n--;
	}
	return (NULL);
}
