/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoskela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 17:07:43 by hkoskela          #+#    #+#             */
/*   Updated: 2020/01/08 14:12:06 by hkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	t_etris	*tetris;
	t_map	*result;

	tetris = NULL;
	result = malloc(sizeof(t_map));
	if (argc != 2 ||
(tetris = read_tetris(open(argv[1], O_RDONLY), result)) == NULL ||
(result->map = solve(tetris, result)) == NULL)
	{
		if (argc != 2)
			ft_putendl("usage: file_name");
		else
			ft_putendl("error");
		return (0);
	}
	ft_print2d(result->map);
	return (0);
}
