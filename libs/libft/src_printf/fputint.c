/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fputint.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egauthey <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 11:44:23 by egauthey          #+#    #+#             */
/*   Updated: 2022/10/23 12:18:48 by egauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
//#define DEC "0123456789"
//#include "unistd.h"
//#include <string.h>
//#include <stdio.h>

static int	nbrlen(int nb, int base)
{
	int	x;

	x = 0;
	if (nb == 0)
		x = 1;
	while (nb)
	{
		x++;
		nb /= base;
	}
	return (x);
}

void	f_writeint(int base, char *strbase, int nb)
{
	if (nb > base - 1)
		f_writeint(base, strbase, (nb / base));
	write(1, &strbase[nb % base], 1);
}

int	fputint(int nb, char *strbase)
{
	int	len;
	int	base;

	len = 0;
	if (nb < 0)
	{
		write (1, "-", 1);
		len++;
		if (nb == -2147483648)
		{
			write (1, "2", 1);
			nb = 147483648;
			len++;
		}
		else
			nb = -nb;
	}
	base = fstrlen(strbase);
	len += nbrlen(nb, base);
	f_writeint(base, strbase, nb);
	return (len);
}
/*
int	main()
{
	int	n;

	char	*base10;

	base10 = DEC;

	n = 2147483647;
//	printf("%d\n", nbrlen(n, base10));
	printf("\n%d", fputint(n, base10));
}*/
