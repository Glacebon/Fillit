/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoskela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 17:42:45 by hkoskela          #+#    #+#             */
/*   Updated: 2019/11/06 17:37:25 by hkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*fresh;
	int		len;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(fresh = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (*s1)
	{
		fresh[i++] = *s1;
		s1++;
	}
	while (*s2)
	{
		fresh[i++] = *s2;
		s2++;
	}
	fresh[i] = '\0';
	i = 0;
	return (fresh);
}
