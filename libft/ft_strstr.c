/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoskela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 14:36:25 by hkoskela          #+#    #+#             */
/*   Updated: 2019/10/28 15:41:28 by hkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[j])
	{
		while (haystack[j + i] == needle[i] && haystack[j + i])
			i++;
		if (needle[i] == '\0')
			return ((char *)haystack + j);
		i = 0;
		j++;
	}
	return (NULL);
}
