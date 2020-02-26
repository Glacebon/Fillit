/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrimc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoskela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 19:44:36 by hkoskela          #+#    #+#             */
/*   Updated: 2019/11/06 19:47:42 by hkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrimc(char const *s, char c)
{
	char	*trim;
	int		len;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	i = 0;
	j = 0;
	while (s[i] == c)
		i++;
	if (s[i])
	{
		while (s[len - 1] == c)
			len--;
	}
	if (!(trim = (char *)malloc(sizeof(char) * (len - i) + 1)))
		return (NULL);
	while (i < len)
		trim[j++] = s[i++];
	trim[j] = '\0';
	j = 0;
	return (trim);
}
