/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoskela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 18:10:57 by hkoskela          #+#    #+#             */
/*   Updated: 2019/11/06 17:37:55 by hkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
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
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	if (s[i])
	{
		while (s[len - 1] == ' ' || s[len - 1] == '\n' || s[len - 1] == '\t')
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
