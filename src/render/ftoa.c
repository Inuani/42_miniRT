/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lskraber <lskraber@student.42lausan>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:05:42 by lskraber          #+#    #+#             */
/*   Updated: 2023/03/12 14:08:22 by lskraber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	reverse(char *str, int len)
{
	int	i;
	int	j;
	int	temp;

	temp = 0;
	i = 0;
	j = len - 1;
	while (i < j)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}
}

void	putneg(char *str)
{
	int		i;
	char	c;
	char	temp;

	i = 0;
	c = str[i];
	str[i] = '-';
	while (str[++i])
	{
		temp = str[i];
		str[i] = c;
		c = temp;
	}
	str[++i] = '0';
	str[i] = '\0';
}

int	int_to_str(int x, char str[], int d)
{
	int	i;

	i = 0;
	if (x < 0)
		x = -x;
	while (x)
	{
		str[i++] = (x % 10) + '0';
		x = x / 10;
	}
	while (i < d)
		str[i++] = '0';
	reverse(str, i);
	str[i] = '\0';
	return (i);
}

char	*fts(float n, char *res)
{
	int		ipart;
	float	fpart;
	int		i;

	ipart = (int)n;
	fpart = n - (float)ipart;
	i = int_to_str(ipart, res, 0);
	res[i] = '.';
	fpart = fpart * pow(10, 1);
	int_to_str((int)fpart, res + i + 1, 1);
	if (n < 0)
		putneg(res);
	return (res);
}
