/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoskela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 16:30:15 by hkoskela          #+#    #+#             */
/*   Updated: 2019/11/06 17:39:23 by hkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_wordcount(char const *s, char c)
{
	int		count;

	count = 0;
	if (!s)
		return (0);
	while (*s)
	{
		if (*s != c)
		{
			count++;
			while (*s != c && *s)
				s++;
		}
		if (*s)
			s++;
	}
	return (count);
}

static int		ft_nextc(char const *s, int start, char c)
{
	while (s[start] != c && s[start])
		start++;
	return (start);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**str_arr;
	int		wordc;
	int		i;
	int		j;

	wordc = ft_wordcount(s, c);
	i = 0;
	j = 0;
	if (!s || !(str_arr = (char **)malloc(sizeof(char *) * wordc + 1)))
		return (NULL);
	while (s[i] && wordc > 0)
	{
		if (s[i] != c && s[i])
		{
			str_arr[j] = ft_strsub(s, i, (ft_nextc(s, i, c) - i));
			j++;
			while (s[i] != c && s[i])
				i++;
		}
		if (s[i])
			i++;
	}
	str_arr[j] = NULL;
	return (str_arr);
}
