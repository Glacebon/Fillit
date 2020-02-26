/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoskela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 16:14:29 by hkoskela          #+#    #+#             */
/*   Updated: 2019/11/06 16:58:35 by hkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		len;
	int		i;
	char	*fresh;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	i = 0;
	if (!(fresh = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (*s)
	{
		fresh[i] = f(*s);
		i++;
		s++;
	}
	fresh[i] = '\0';
	i = 0;
	return (fresh);
}
