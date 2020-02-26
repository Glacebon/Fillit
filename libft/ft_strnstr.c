/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoskela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 14:50:57 by hkoskela          #+#    #+#             */
/*   Updated: 2019/11/02 17:27:23 by hkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		i;
	size_t	j;

	i = 0;
	j = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[j] && j < len && len != 0)
	{
		while (haystack[j + i] == needle[i] && (j + i) < len &&
haystack[j + i] && needle[i])
			i++;
		if (needle[i] == '\0')
			return ((char *)haystack + j);
		i = 0;
		j++;
	}
	return (NULL);
}
