/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egauthey <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 14:59:39 by egauthey          #+#    #+#             */
/*   Updated: 2022/10/21 12:42:58 by egauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	f_special(va_list argu, const char type)
{
	int	lentype;

	lentype = 0;
	if (type == '%')
		lentype = write(1, "%", 1);
	else if (type == 's')
		lentype = fputstr(va_arg(argu, char *));
	else if (type == 'c')
		lentype = fputchar(va_arg(argu, int));
	else if (type == 'd' || type == 'i')
		lentype = fputint(va_arg(argu, int), DEC);
	else if (type == 'u')
		lentype = fputnbrbase(va_arg(argu, unsigned int), DEC);
	else if (type == 'X')
		lentype = fputnbrbase(va_arg(argu, unsigned int), HEXMAJ);
	else if (type == 'x')
		lentype = fputnbrbase(va_arg(argu, unsigned int), HEXMIN);
	else if (type == 'p')
		lentype = fputptr(va_arg(argu, unsigned long long), HEXMIN);
	return (lentype);
}

static int	printlen(va_list argu, const char *s)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			len = len + f_special(argu, s[i + 1]);
			i++;
		}
		else
		{
			write (1, &s[i], 1);
			len++;
		}
		i++;
	}
	return (len);
}

int	ft_printf(const char *s, ...)
{
	int		len_s;
	va_list	argu;

	if (!s)
		return (0);
	len_s = 0;
	va_start(argu, s);
	len_s = printlen(argu, s);
	va_end(argu);
	return (len_s);
}
