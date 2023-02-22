/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fputnbribase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egauthey <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 14:08:15 by egauthey          #+#    #+#             */
/*   Updated: 2022/10/21 18:14:32 by egauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	fstrlen(char *s)
{
	int	cpt;

	cpt = 0;
	while (s[cpt])
		cpt++;
	return (cpt);
}

static int	nbrlen(unsigned int nb, unsigned int base)
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

void	f_write(unsigned int base, char *strbase, unsigned int nb)
{
	if (nb > base - 1)
		f_write(base, strbase, (nb / base));
	write(1, &strbase[nb % base], 1);
}

int	fputnbrbase(unsigned int nb, char *strbase)
{
	int					len;
	unsigned int		base;

	base = fstrlen(strbase);
	len = nbrlen(nb, base);
	f_write(base, strbase, nb);
	return (len);
}
/*
int	main()
{
	unsigned int	n;

	char	*base10;

	base10 = DEC;

	n = 123;
//	printf("%d\n", nbrlen(n, base16));
	printf("\n%d", fputnbrbase(n, base10));
}*/
