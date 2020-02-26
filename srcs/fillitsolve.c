/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillitsolve.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmerilai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 17:35:40 by jmerilai          #+#    #+#             */
/*   Updated: 2020/01/08 13:56:17 by hkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**makemap(int side)
{
	int		i;
	char	**map;

	if (!(map = (char **)malloc(sizeof(char *) * side + 1)))
		return (NULL);
	i = 0;
	while (i < side)
	{
		map[i] = ft_strnew(side);
		map[i] = ft_memset(map[i], '.', side);
		i++;
	}
	map[i] = NULL;
	return (map);
}

char	**setpiece(char **map, t_etris *piece, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (c != '.' && i < 4)
	{
		map[piece->y[i]][piece->x[i]] = c;
		i++;
	}
	while (c == '.' && map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == piece->c)
				map[j][i] = '.';
			i++;
		}
		j++;
	}
	return (map);
}

t_etris	*movetoprevious(t_etris *tetricoor, t_etris *head)
{
	t_etris *tmp;

	tmp = tetricoor;
	tetricoor = head;
	while (tetricoor->next != tmp)
		tetricoor = tetricoor->next;
	return (tetricoor);
}

char	**start(char **map, t_etris *tetricoor, t_etris *head, int side)
{
	while (tetricoor)
	{
		while (!(piecefits(map, tetricoor, side)))
		{
			if (tetricoor != head)
			{
				movetozero(tetricoor);
				tetricoor = movetoprevious(tetricoor, head);
				moveforward(tetricoor, side);
				map = setpiece(map, tetricoor, '.');
			}
			else
			{
				movealltozero(tetricoor);
				tetricoor = head;
				side++;
				delmap(map);
				map = makemap(side);
			}
		}
		setpiece(map, tetricoor, tetricoor->c);
		tetricoor = tetricoor->next;
	}
	return (map);
}

char	**solve(t_etris *head, t_map *result)
{
	char	**map;
	t_etris *piece;

	piece = head;
	map = makemap(result->side);
	map = start(map, piece, head, result->side);
	return (map);
}
