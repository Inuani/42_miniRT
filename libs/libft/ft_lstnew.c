/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egauthey <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 09:49:51 by egauthey          #+#    #+#             */
/*   Updated: 2022/10/19 11:06:55 by egauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	(*new).content = content;
	(*new).next = NULL;
	return (new);
}
/*
int main()
{
	char	c;
	t_list	*x;

	c = 'c';
	x = ft_lstnew((void *)&c);
	printf("%p\n", (*x).next);

	char	*data;
	data = (char *)(*x).content;
	printf("%c", *data);
}*/
