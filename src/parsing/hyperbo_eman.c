/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hyperbo_eman.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egauthey <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 18:51:04 by egauthey          #+#    #+#             */
/*   Updated: 2022/11/21 18:51:06 by egauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	get_hyperboloid(t_data *d)
{
	t_object	*tmp;
	int			i;

	tmp = d->chaos;
	i = 2 + d->count.l_count + d->count.sp_count
		+ d->count.pl_count + d->count.cy_count;
	while (tmp)
	{
		if (tmp->type == HYPERBOLOID)
		{
			d->objs[i] = tmp;
			i++;
		}
		tmp = tmp->next;
	}
}

void	hyp_img_init(t_data *d, t_tok **lst, t_hyperboloid *cur)
{
	char	*xpm;

	xpm = NULL;
	*lst = (*lst)->next;
	set_xpm_path(&xpm, &(*lst)->s);
	cur->xpm.img = mlx_xpm_file_to_image(d->mlx, xpm,
			&cur->xpm.wdth, &cur->xpm.hgt);
	cur->xpm.addr = mlx_get_data_addr(cur->xpm.img,
			&cur->xpm.bits_per_pixel, &cur->xpm.line_length, &cur->xpm.endian);
	cur->pix_arr = set_pixel_color_array(d,
			&cur->xpm, cur->xpm.hgt, cur->xpm.wdth);
	free(xpm);
}

void	set_hp_prop(t_tok **lst, t_hyperboloid *inst)
{
	*lst = (*lst)->next;
	inst->center.x = ft_atof((*lst)->s);
	*lst = (*lst)->next;
	inst->center.y = ft_atof((*lst)->s);
	*lst = (*lst)->next;
	inst->center.z = ft_atof((*lst)->s);
	*lst = (*lst)->next;
	inst->orient.x = ft_atof((*lst)->s);
	*lst = (*lst)->next;
	inst->orient.y = ft_atof((*lst)->s);
	*lst = (*lst)->next;
	inst->orient.z = ft_atof((*lst)->s);
	*lst = (*lst)->next;
	inst->radius = (ft_atof((*lst)->s) / 2.0);
	*lst = (*lst)->next;
	inst->hgt = ft_atof((*lst)->s);
	*lst = (*lst)->next;
	inst->colors.x = ft_atof((*lst)->s);
	*lst = (*lst)->next;
	inst->colors.y = ft_atof((*lst)->s);
	*lst = (*lst)->next;
	inst->colors.z = ft_atof((*lst)->s);
	inst->orient = vec_unit(inst->orient);
	inst->pix_arr = NULL;
}

int	add_hyperboloid(t_data *d, t_tok *lst)
{
	t_object		*new;
	t_hyperboloid	inst;
	int				nb;

	nb = calc_nb_prop(lst);
	if (nb != 11 && nb != 12)
		exit_error(ERR_PROPERTIES, 1);
	inst.flg = 0;
	set_hp_prop(&lst, &inst);
	if (nb == 12)
	{
		if (!ft_strncmp(lst->next->s, "damier", 6))
			inst.flg = 1;
		else
		{
			hyp_img_init(d, &lst, &inst);
			inst.flg = 2;
		}
	}
	new = create_object(HYPERBOLOID, &inst);
	add_object_to_list(&d->chaos, new);
	free_tok(d);
	return (1);
}
