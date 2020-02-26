/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoskela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 11:12:18 by hkoskela          #+#    #+#             */
/*   Updated: 2019/11/06 17:50:54 by hkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_intlen(int n)
{
	int		len;

	len = 1;
	if (n == -2147483648)
		return (11);
	else if (n < 0)
	{
		n = n * -1;
		len++;
	}
	while ((n / 10) >= 1)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static	void	ft_putnbr_str(char *str, int n, size_t len)
{
	int		i;

	i = len;
	if (n == -2147483648)
	{
		ft_putnbr_str(str, -214748364, len - 1);
		str[len] = '8';
	}
	else if (n < 0)
	{
		str[0] = '-';
		ft_putnbr_str(str, (n * -1), len);
	}
	else if (n > 9)
	{
		ft_putnbr_str(str, (n / 10), len - 1);
		str[len] = (n % 10) + '0';
	}
	else if (n <= 9)
		str[len] = n + '0';
}

char			*ft_itoa(int n)
{
	int		len;
	char	*nbr;

	len = ft_intlen(n);
	if (!(nbr = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	else
	{
		ft_putnbr_str(nbr, n, len - 1);
		nbr[len] = '\0';
	}
	return (nbr);
}
