/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egauthey <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:26:59 by egauthey          #+#    #+#             */
/*   Updated: 2022/10/19 16:18:11 by egauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*clear;

	if (*lst)
	{
		while (*lst)
		{
			clear = (**lst).next;
			ft_lstdelone(*lst, del);
			*lst = clear;
		}
	}
}
