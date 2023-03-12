/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tok_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egauthey <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 18:51:04 by egauthey          #+#    #+#             */
/*   Updated: 2022/11/21 18:51:06 by egauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	create_obj_tok(t_data *d, char *line, int *i)
{
	char	*obj;
	int		j;
	t_tok	*new;

	j = *i;
	while (line[*i] && ft_isalpha(line[*i]))
		*i += 1;
	obj = ft_substr(line, j, *i - j);
	if (!obj)
		exit_error(ERR_MALLOC, 260);
	new = tok_lstnew(obj, 0);
	if (!new)
		exit_error(ERR_MALLOC, 260);
	tok_add_back(&d->lst, new);
}

void	create_prop_tok(t_data *d, char *line, int *i)
{
	char	*prop;
	int		j;
	t_tok	*new;

	j = *i;
	while (line[*i] && (ft_isdigit(line[*i])
			|| line[*i] == '.' || line[*i] == '-'))
		*i += 1;
	prop = ft_substr(line, j, *i - j);
	if (!prop)
		exit_error(ERR_MALLOC, 260);
	new = tok_lstnew(prop, 1);
	if (!new)
		exit_error(ERR_MALLOC, 260);
	tok_add_back(&d->lst, new);
}

void	create_xpm_tok(t_data *d, char *line, int *i)
{
	char	*xpm;
	int		j;
	t_tok	*new;

	j = *i;
	while (line[*i] && (ft_isalpha(line[*i]) || line[*i] == '.'))
		*i += 1;
	xpm = ft_substr(line, j, *i - j);
	if (!xpm)
		exit_error(ERR_MALLOC, 260);
	new = tok_lstnew(xpm, 2);
	if (!new)
		exit_error(ERR_MALLOC, 260);
	tok_add_back(&d->lst, new);
}

void	free_tok(t_data *d)
{
	t_tok	*tmp;

	while (d->lst)
	{
		if (d->lst->next != NULL)
			tmp = d->lst->next;
		else
			tmp = NULL;
		free(d->lst->s);
		d->lst->s = NULL;
		free(d->lst);
		d->lst = NULL;
		d->lst = tmp;
	}
	d->lst = NULL;
}
