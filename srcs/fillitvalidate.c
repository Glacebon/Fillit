/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillitvalidate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoskela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 17:24:35 by hkoskela          #+#    #+#             */
/*   Updated: 2020/01/08 13:39:32 by hkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		validtetri(char *piece)
{
	int		count;
	int		i;

	i = 0;
	count = 0;
	while (piece[i])
	{
		if ((i + 1 < 20) && piece[i] == '#' && piece[i + 1] == '#')
			count++;
		if ((i - 1 > -1) && piece[i] == '#' && piece[i - 1] == '#')
			count++;
		if ((i - 5 > -1) && piece[i] == '#' && piece[i - 5] == '#')
			count++;
		if ((i + 5 < 20) && piece[i] == '#' && piece[i + 5] == '#')
			count++;
		i++;
	}
	if (count == 6 || count == 8)
		return (1);
	return (0);
}

int		validarea(char *piece)
{
	int i;
	int hasht;
	int dot;

	i = 0;
	hasht = 0;
	dot = 0;
	while (piece[i])
	{
		if (piece[i] == '.')
			dot++;
		else if (piece[i] == '#')
			hasht++;
		else if (piece[i] != '\n')
			return (0);
		if ((i + 1) % 5 == 0 && piece[i] != '\n')
			return (0);
		i++;
	}
	if (hasht == 4 && dot == 12)
		return (1);
	return (0);
}
