/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_array_creation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egauthey <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 18:51:04 by egauthey          #+#    #+#             */
/*   Updated: 2022/11/21 18:51:06 by egauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

//check for potential double A or double C that gives back error

void	get_camera(t_data *d, int *flg)
{
	t_object	*tmp;

	tmp = d->chaos;
	while (tmp)
	{
		if (tmp->type == CAMERA)
		{
			d->objs[1] = tmp;
			(*flg)++;
		}
		tmp = tmp->next;
	}
}

void	get_ambiant(t_data *d, int *flg)
{
	t_object	*tmp;

	tmp = d->chaos;
	while (tmp)
	{
		if (tmp->type == AMBIANT)
		{
			d->objs[0] = tmp;
			(*flg)++;
		}
		tmp = tmp->next;
	}
}

int	calc_nb_obj(t_object *chaos)
{
	t_object	*tmp;
	int			nb;

	nb = 0;
	tmp = chaos;
	while (tmp)
	{
		nb++;
		tmp = tmp->next;
	}
	return (nb);
}

void	obj_array_create(t_data *d)
{
	int	i;
	int	flg_cam;
	int	flg_amb;

	i = 0;
	flg_cam = 0;
	flg_amb = 0;
	d->count.total = calc_nb_obj(d->chaos);
	d->objs = malloc(sizeof(t_object *) * (d->count.total + 1));
	get_ambiant(d, &flg_amb);
	get_camera(d, &flg_cam);
	get_light(d);
	get_sphere(d);
	get_plane(d);
	get_cylindre(d);
	get_hyperboloid(d);
	d->objs[d->count.total] = NULL;
	if (flg_cam != 1 || flg_amb != 1)
		exit_error(ERR_OBJ_CAM_AMB, 1);
}
