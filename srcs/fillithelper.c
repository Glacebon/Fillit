/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillithelper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoskela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 19:32:06 by hkoskela          #+#    #+#             */
/*   Updated: 2020/01/08 13:57:17 by hkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_etris	*delinvalid(t_etris *head, t_etris *piece)
{
	t_etris *next;
	t_etris *this;

	piece->next = NULL;
	this = head;
	while (this)
	{
		next = this->next;
		ft_memdel((void **)&this);
		this = next;
	}
	head = NULL;
	return (NULL);
}

void	delmap(char **map)
{
	int j;

	j = 0;
	while (map[j])
	{
		free(map[j]);
		j++;
	}
	free(map);
}

int		smallestroot(int nbr)
{
	int i;

	i = 2;
	while (i * i < nbr)
		i++;
	return (i);
}

void	ft_print2d(char **map)
{
	int i;

	i = 0;
	while (map[i])
	{
		ft_putendl(map[i]);
		i++;
	}
}
