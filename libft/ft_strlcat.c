/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoskela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 17:59:55 by hkoskela          #+#    #+#             */
/*   Updated: 2019/11/03 19:42:40 by hkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t		i;
	size_t		j;
	size_t		len;

	i = ft_strlen(dst);
	j = 0;
	len = ft_strlen(src);
	if (i > dstsize)
		len = len + dstsize;
	else
		len = len + i;
	if (dstsize > 0 && i <= dstsize)
	{
		while (src[j] && i < dstsize - 1)
		{
			dst[i] = src[j];
			i++;
			j++;
		}
		dst[i] = '\0';
	}
	return (len);
}
