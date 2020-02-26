/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoskela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 14:24:25 by hkoskela          #+#    #+#             */
/*   Updated: 2019/10/29 18:17:53 by hkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*undst;
	unsigned char	*unsrc;

	undst = (unsigned char*)dst;
	unsrc = (unsigned char*)src;
	if (n == 0 || (dst == src))
		return (dst);
	while (n > 0)
	{
		*undst = *unsrc;
		undst++;
		unsrc++;
		n--;
	}
	return (dst);
}
