/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fputptr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egauthey <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 18:29:39 by egauthey          #+#    #+#             */
/*   Updated: 2022/10/21 20:38:59 by egauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
/*#include <unistd.h>
#include <string.h>
#include <stdio.h>
#define HEXMIN "0123456789abcdef"*/

static int	nbrlen(unsigned long long nb, unsigned long long base)
{
	int	x;

	x = 0;
	if (nb == 0)
		x = 1;
	while (nb > 0)
	{
		x++;
		nb /= base;
	}
	return (x);
}

void	f_writeptr(unsigned long long base,
			char *strbase, unsigned long long nb)
{
	if (nb > base - 1)
		f_writeptr(base, strbase, (nb / base));
	write(1, &strbase[nb % base], 1);
}

int	fputnbrbaseptr(unsigned long long nb, char *strbase)
{
	int					len;
	unsigned long long	base;

	base = fstrlen(strbase);
	len = nbrlen(nb, base);
	f_writeptr(base, strbase, nb);
	return (len);
}

int	fputptr(unsigned long long ptr, char *strbase)
{
	int	len;

	len = write(1, "0x", 2);
	if (!ptr)
		len += write(1, "0", 1);
	else
		len += fputnbrbaseptr(ptr, strbase);
	return (len);
}

/*
int	main()
{
//	char	ptr[] = "Hey";

	printf("%d", fputptr("hey", HEXMIN));
int	l;

	l = 0;
	l = write(1, "x", 1);
	printf("\n%d", l);
	return (0);
}*/