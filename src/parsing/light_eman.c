/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_eman.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egauthey <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 18:51:04 by egauthey          #+#    #+#             */
/*   Updated: 2022/11/21 18:51:06 by egauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	get_light(t_data *d)
{
	t_object	*tmp;
	int			i;

	tmp = d->chaos;
	i = 2;
	while (tmp)
	{
		if (tmp->type == LIGHT)
		{
			d->objs[i] = tmp;
			i++;
		}
		tmp = tmp->next;
	}
}

void	set_light_prop(t_tok **lst, t_light *inst)
{
	*lst = (*lst)->next;
	inst->pos.x = ft_atof((*lst)->s);
	*lst = (*lst)->next;
	inst->pos.y = ft_atof((*lst)->s);
	*lst = (*lst)->next;
	inst->pos.z = ft_atof((*lst)->s);
	*lst = (*lst)->next;
	inst->light_ratio = ft_atof((*lst)->s);
	*lst = (*lst)->next;
	inst->colors.x = ft_atof((*lst)->s);
	*lst = (*lst)->next;
	inst->colors.y = ft_atof((*lst)->s);
	*lst = (*lst)->next;
	inst->colors.z = ft_atof((*lst)->s);
}

int	add_light(t_data *d, t_tok *lst)
{
	t_object	*new;
	t_light		inst;
	int			nb;

	nb = calc_nb_prop(lst);
	if (nb != 7)
		exit_error(ERR_PROPERTIES, 1);
	set_light_prop(&lst, &inst);
	new = create_object(LIGHT, &inst);
	add_object_to_list(&d->chaos, new);
	free_tok(d);
	return (1);
}
