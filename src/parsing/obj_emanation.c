/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_emanation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egauthey <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 18:51:04 by egauthey          #+#    #+#             */
/*   Updated: 2022/11/21 18:51:06 by egauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	add_ambiant(t_data *d, t_tok *lst)
{
	t_object	*new;
	t_ambiant	inst;
	int			nb;

	nb = calc_nb_prop(lst);
	if (nb != 4)
		exit_error(ERR_PROPERTIES, 1);
	only_one_zero_type(lst);
	lst = lst->next;
	inst.light_ratio = ft_atof(lst->s);
	lst = lst->next;
	inst.colors.x = ft_atof(lst->s);
	lst = lst->next;
	inst.colors.y = ft_atof(lst->s);
	lst = lst->next;
	inst.colors.z = ft_atof(lst->s);
	new = create_object(AMBIANT, &inst);
	add_object_to_list(&d->chaos, new);
	free_tok(d);
}

void	set_camera_prop(t_tok **lst, t_cam *inst)
{
	*lst = (*lst)->next;
	inst->pos.x = ft_atof((*lst)->s);
	*lst = (*lst)->next;
	inst->pos.y = ft_atof((*lst)->s);
	*lst = (*lst)->next;
	inst->pos.z = ft_atof((*lst)->s);
	*lst = (*lst)->next;
	inst->orient.x = ft_atof((*lst)->s);
	*lst = (*lst)->next;
	inst->orient.y = ft_atof((*lst)->s);
	*lst = (*lst)->next;
	inst->orient.z = ft_atof((*lst)->s);
	*lst = (*lst)->next;
	inst->fov = ft_atof((*lst)->s);
	inst->orient = vec_unit(inst->orient);
	if (!inst->orient.x && !inst->orient.z)
		inst->up = vec_cross(inst->orient, (t_vec){0, 0, 1});
	else
		inst->up = (t_vec){0, 1, 0};
	inst->up = vec_unit(inst->up);
	inst->right = vec_cross(inst->orient, inst->up);
	inst->right = vec_unit(inst->right);
}

void	add_camera(t_data *d, t_tok *lst)
{
	t_object	*new;
	t_cam		inst;
	int			nb;

	nb = calc_nb_prop(lst);
	if (nb != 7)
		exit_error(ERR_PROPERTIES, 1);
	only_one_zero_type(lst);
	set_camera_prop(&lst, &inst);
	new = create_object(CAMERA, &inst);
	add_object_to_list(&d->chaos, new);
	free_tok(d);
}

void	what_obj(t_data *d, char *obj)
{
	if (!ft_strncmp(obj, "A", 1) && obj[1] == 0)
		add_ambiant(d, d->lst);
	else if (!ft_strncmp(obj, "C", 1) && obj[1] == 0)
		add_camera(d, d->lst);
	else if (!ft_strncmp(obj, "L", 1) && obj[1] == 0)
		d->count.l_count += add_light(d, d->lst);
	else if (!ft_strncmp(obj, "sp", 2) && obj[2] == 0)
		d->count.sp_count += add_sphere(d, d->lst);
	else if (!ft_strncmp(obj, "pl", 2) && obj[2] == 0)
		d->count.pl_count += add_plane(d, d->lst);
	else if (!ft_strncmp(obj, "cy", 2) && obj[2] == 0)
		d->count.cy_count += add_cylinder(d, d->lst);
	else if (!ft_strncmp(obj, "hy", 2) && obj[2] == 0)
		d->count.hy_count += add_hyperboloid(d, d->lst);
	else
		exit_error(ERR_OBJ, 1);
}

void	obj_eman(t_data *d)
{
	t_tok	*tmp;

	tmp = d->lst;
	while (tmp)
	{
		if (tmp->type == 0)
		{
			what_obj(d, tmp->s);
			break ;
		}
		tmp = tmp->next;
	}
}
