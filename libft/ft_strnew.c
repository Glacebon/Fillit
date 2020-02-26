/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoskela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 17:22:07 by hkoskela          #+#    #+#             */
/*   Updated: 2019/11/02 17:05:13 by hkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*fresh;

	if (!(fresh = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	while (size > 0)
	{
		fresh[size] = '\0';
		size--;
	}
	fresh[size] = '\0';
	return (fresh);
}
