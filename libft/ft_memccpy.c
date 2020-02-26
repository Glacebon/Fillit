/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoskela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 18:22:43 by hkoskela          #+#    #+#             */
/*   Updated: 2019/10/28 17:56:24 by hkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*undst;
	unsigned char	*unsrc;

	undst = (unsigned char *)dst;
	unsrc = (unsigned char *)src;
	while (n > 0)
	{
		if (*unsrc == (unsigned char)c)
		{
			*undst = *unsrc;
			undst++;
			return (undst);
		}
		*undst = *unsrc;
		undst++;
		unsrc++;
		n--;
	}
	return (NULL);
}
