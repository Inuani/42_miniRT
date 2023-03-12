/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cyl_eman.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egauthey <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 18:51:04 by egauthey          #+#    #+#             */
/*   Updated: 2022/11/21 18:51:06 by egauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	get_cylindre(t_data *d)
{
	t_object	*tmp;
	int			i;

	tmp = d->chaos;
	i = 2 + d->count.l_count + d->count.sp_count + d->count.pl_count;
	while (tmp)
	{
		if (tmp->type == CYLINDER)
		{
			d->objs[i] = tmp;
			i++;
		}
		tmp = tmp->next;
	}
}

int	*set_pixel_color_array(t_data *d, t_img *xpm, int hgt, int wdt)
{
	int	*pix_arr;
	int	x;
	int	y;
	int	pixel_offset;

	y = 0;
	pix_arr = malloc(sizeof(int) * hgt * wdt);
	while (y < hgt)
	{
		x = 0;
		while (x < wdt)
		{
			pixel_offset = (y * xpm->line_length) + (x * (xpm->bits_per_pixel / 8));
			pix_arr[y * wdt + x] = mlx_get_color_value(d->mlx, *(int *)(xpm->addr + pixel_offset));
			x++;
		}
		y++;
	}
	return(pix_arr);
}

void	cy_img_init(t_data *d, t_tok **lst, t_cylinder *cur)
{
	char	*xpm;

	xpm = NULL;
	cur->flg = 2;
	*lst = (*lst)->next;
	set_xpm_path(&xpm, &(*lst)->s);
	cur->xpm.img = mlx_xpm_file_to_image(d->mlx,
			xpm, &cur->xpm.wdth, &cur->xpm.hgt);
	cur->xpm.addr = mlx_get_data_addr(cur->xpm.img,
			&cur->xpm.bits_per_pixel, &cur->xpm.line_length, &cur->xpm.endian);
	cur->pix_arr = set_pixel_color_array(d, &cur->xpm, cur->xpm.hgt, cur->xpm.wdth);
	free(xpm);
}

void	set_cyl_prop(t_tok **lst, t_cylinder *inst)
{
	inst->flg = 0;
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
}

int	add_cylinder(t_data *d, t_tok *lst)
{
	t_object	*new;
	t_cylinder	inst;
	int			nb;

	nb = calc_nb_prop(lst);
	if (nb != 11 && nb != 12)
		exit_error(ERR_PROPERTIES, 1);
	set_cyl_prop(&lst, &inst);
	if (nb == 12)
	{
		if (!ft_strncmp(lst->next->s, "damier", 6))
			inst.flg = 1;
		else if (ft_strncmp(lst->next->s, "hyper", 5))
			cy_img_init(d, &lst, &inst);
	}
	if (lst->next && !ft_strncmp(lst->next->s, "hyper", 5))
		inst.flg = 3;
	else
		inst.orient = vec_unit(inst.orient);
	new = create_object(CYLINDER, &inst);
	add_object_to_list(&d->chaos, new);
	free_tok(d);
	return (1);
}
