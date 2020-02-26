/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoskela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 11:39:30 by hkoskela          #+#    #+#             */
/*   Updated: 2019/11/06 17:36:31 by hkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*fresh;
	size_t			j;

	if (!s)
		return (NULL);
	if (!(fresh = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	j = 0;
	while (j < len)
	{
		fresh[j] = s[start];
		j++;
		start++;
	}
	fresh[j] = '\0';
	return (fresh);
}
