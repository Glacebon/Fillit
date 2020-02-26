/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillitpiecefits.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoskela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 19:42:59 by hkoskela          #+#    #+#             */
/*   Updated: 2020/01/05 19:47:26 by hkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Function smallerthanside
** Goes through all coordinates saved in the link
** and compares them to the side that works as the max
** row length and row amount.
** Returns 0 is a coordinate is out of bounds.
** Returns 1 otherwise.
*/

int		smallerthanside(t_etris *tc, int side)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (tc->x[i] >= side || tc->y[i] >= side)
			return (0);
		i++;
	}
	return (1);
}

int		aredots(char **map, t_etris *tc)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (map[tc->y[i]][tc->x[i]] != '.')
			return (0);
		i++;
	}
	return (1);
}

/*
** Functions piecefits & aredots
** Checks if the given coordinates have space (only dots)
** in the map and if so, puts the piece in them.
*/

int		piecefits(char **map, t_etris *tc, int side)
{
	while (smallerthanside(tc, side) == 1)
	{
		if (aredots(map, tc) == 1)
			return (1);
		else if (aredots(map, tc) == 0)
			moveforward(tc, side);
	}
	movetozero(tc);
	return (0);
}
