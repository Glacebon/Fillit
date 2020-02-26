/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoskela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 14:59:33 by hkoskela          #+#    #+#             */
/*   Updated: 2019/10/21 16:12:22 by hkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *pt1;
	unsigned char *pt2;

	pt1 = (unsigned char *)s1;
	pt2 = (unsigned char *)s2;
	while (n > 0)
	{
		if (*pt1 != *pt2)
			return (*pt1 - *pt2);
		else
		{
			n--;
			pt1++;
			pt2++;
		}
	}
	return (0);
}
