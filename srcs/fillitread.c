/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillitread.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoskela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 17:32:33 by hkoskela          #+#    #+#             */
/*   Updated: 2020/01/08 14:07:29 by hkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_etris		*addtetri(t_etris *piece, char *buf, char c, int ret)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (buf[i])
	{
		if (buf[i] == '#')
		{
			piece->x[j] = (i - (i / 5)) % 4;
			piece->y[j] = i / 5;
			j++;
		}
		i++;
	}
	piece->strlen = ret;
	piece->c = c;
	movetozero(piece);
	if (ret == 21)
	{
		if (!(piece->next = malloc(sizeof(t_etris))))
			return (NULL);
		piece = piece->next;
	}
	return (piece);
}

t_etris		*read_tetris(int fd, t_map *result)
{
	int		ret;
	int		c;
	char	*buf;
	t_etris	*piece;
	t_etris	*head;

	c = 0;
	buf = ft_strnew(21);
	if (!(head = malloc(sizeof(t_etris))))
		return (NULL);
	piece = head;
	while ((ret = read(fd, buf, 21)) >= 20)
	{
		if (!(validarea(buf)) || !(validtetri(buf)) ||
(piece = addtetri(piece, buf, 'A' + c++, ret)) == NULL)
			break ;
	}
	free(buf);
	if (piece->strlen != 20 || ret != 0 || c > 26 || !piece)
		return (delinvalid(head, piece));
	piece->next = NULL;
	result->side = smallestroot(c * 4);
	return (head);
}
