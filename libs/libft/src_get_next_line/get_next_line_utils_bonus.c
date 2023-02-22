/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egauthey <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 13:27:29 by egauthey          #+#    #+#             */
/*   Updated: 2022/10/23 13:27:31 by egauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdio.h>
#include <unistd.h>

int	fstrlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*fstrjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*scat;

	if (!s1 || !s2)
		return (NULL);
	scat = malloc((fstrlen(s1) + fstrlen(s2) + 1) * sizeof(char));
	if (!scat)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		scat[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		scat[i] = s2[j];
		i++;
		j++;
	}
	scat[i] = 0;
	free(s1);
	return (scat);
}

int	fstrchrn(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*fstrdup(char *s1)
{
	char	*str;
	int		i;

	str = malloc((fstrlen(s1) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = 0;
	return (str);
}
