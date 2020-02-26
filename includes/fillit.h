/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmerilai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 14:09:51 by jmerilai          #+#    #+#             */
/*   Updated: 2020/01/08 13:57:36 by hkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUFF_SIZE 4096

# include "../libft/includes/libft.h"
# include <stdlib.h>
# include <fcntl.h>

typedef struct		s_tetris
{
	char			c;
	int				x[4];
	int				y[4];
	int				strlen;
	struct s_tetris *next;
}					t_etris;

typedef struct		s_map
{
	char			**map;
	int				side;
}					t_map;

char				**solve(t_etris *head, t_map *result);

int					moveforward(t_etris *tc, int side);
int					validarea(char *piece);
int					validtetri(char *piece);
int					piecefits(char **map, t_etris *tc, int side);
int					smallestroot(int nbr);

t_etris				*delinvalid(t_etris *head, t_etris *piece);
t_etris				*movetozero(t_etris *current);
t_etris				*read_tetris(int fd, t_map *result);

void				delmap(char **map);
void				movealltozero(t_etris *tetricoor);
void				ft_print2d(char **map);
void				ft_printcoor(t_etris *current);
void				ft_printallcoor(t_etris *current);

#endif
