/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tok_list_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egauthey <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 18:51:04 by egauthey          #+#    #+#             */
/*   Updated: 2022/11/21 18:51:06 by egauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_tok	*tok_lstnew(char *s, int t)
{
	t_tok	*new;

	new = malloc(sizeof(t_tok));
	new->type = t;
	new->s = s;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	tok_add_back(t_tok **lst, t_tok *new)
{
	t_tok	*tmp;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	tmp = tok_last(*lst);
	tmp->next = new;
	new->prev = tmp;
}

t_tok	*tok_last(t_tok *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

int	tok_lst_size(t_tok *lst)
{
	t_tok	*tmp;
	int		i;

	tmp = lst;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

// t_tok	*remove_tok(t_tok **lst, t_tok *tok_to_remove)
// {
// 	if (!(*lst) || !tok_to_remove)
// 		return (NULL);
// 	if (*lst == tok_to_remove)
// 		*lst = tok_to_remove->next;
// 	if (tok_to_remove->next != NULL)
// 		tok_to_remove->next->prev = tok_to_remove->prev;
// 	if (tok_to_remove->prev != NULL)
// 		tok_to_remove->prev->next = tok_to_remove->next;
// 	if (tok_to_remove->s != NULL)
// 		free(tok_to_remove->s);
// 	free(tok_to_remove);
// 	if (*lst == NULL)
// 		return (NULL);
// 	return (*lst);
// }