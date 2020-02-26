/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_modifycoor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoskela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 20:04:22 by hkoskela          #+#    #+#             */
/*   Updated: 2020/01/05 19:42:39 by hkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Functions movetozero && movealltozero
** Moves all the given tetriminos' coordinates
** as close to 0, 0 as possible without any of
** them going under 0.
*/

t_etris	*movetozero(t_etris *current)
{
	int		i;

	while (current->x[0] > 0 && current->x[1] > 0 &&
current->x[2] > 0 && current->x[3] > 0)
	{
		i = 0;
		while (i < 4)
		{
			current->x[i]--;
			i++;
		}
	}
	while (current->y[0] > 0 && current->y[1] > 0 &&
current->y[2] > 0 && current->y[3] > 0)
	{
		i = 0;
		while (i < 4)
		{
			current->y[i]--;
			i++;
		}
	}
	return (current);
}

void	movealltozero(t_etris *tetricoor)
{
	while (tetricoor->next)
	{
		movetozero(tetricoor);
		tetricoor = tetricoor->next;
	}
}

/*
** Functions moveforward, movex and movey
** Takes in coordinates and moves them one step forward
** first on x axis and then on y axis if movex returns 0.
** In movey moves all the x coordinates as close to 0 as
** possible.
*/

int		movex(t_etris *tc, int side)
{
	int		i;

	i = 0;
	if ((tc->x[0] + 1 < side) && (tc->x[1] + 1 < side) &&
		(tc->x[2] + 1 < side) && (tc->x[3] + 1 < side))
	{
		while (i < 4)
		{
			tc->x[i]++;
			i++;
		}
		return (1);
	}
	return (0);
}

int		movey(t_etris *tc, int side)
{
	int		i;

	if ((tc->y[0] < side) && (tc->y[1] < side) &&
		(tc->y[2] < side) && (tc->y[3] < side))
	{
		i = 0;
		while (i < 4)
		{
			tc->y[i]++;
			i++;
		}
		while (tc->x[0] > 0 && tc->x[1] > 0 && tc->x[2] > 0 && tc->x[3] > 0)
		{
			i = 0;
			while (i < 4)
			{
				tc->x[i]--;
				i++;
			}
		}
		return (1);
	}
	return (0);
}

int		moveforward(t_etris *tc, int side)
{
	if (!(movex(tc, side)))
		return (movey(tc, side));
	return (1);
}
