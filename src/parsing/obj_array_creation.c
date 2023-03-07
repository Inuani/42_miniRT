#include "../../includes/minirt.h"

//check for potential double A or double C that gives back error

int	calc_nb_obj(t_object *chaos)
{
	t_object	*tmp;
	int			nb;

	nb = 0;
	tmp = chaos;
	while(tmp)
	{
		nb++;
		tmp = tmp->next;
	}
	return (nb);
}

void	get_camera(t_data *d)
{
	t_object	*tmp;

	tmp = d->chaos;
	while(tmp)
	{
		if (tmp->type == CAMERA)
		{
			d->objs[1] = tmp;
		}
		tmp = tmp->next;
	}
}

void	get_ambiant(t_data *d)
{
	t_object	*tmp;

	tmp = d->chaos;
	while(tmp)
	{
		if (tmp->type == AMBIANT)
		{
			d->objs[0] = tmp;
		}
		tmp = tmp->next;
	}
}

void	get_light(t_data *d)
{
	t_object	*tmp;
	int	i;

	tmp = d->chaos;
	i = 2;
	while(tmp)
	{
		if (tmp->type == LIGHT)
		{
			d->objs[i] = tmp;
			i++;
		}
		tmp = tmp->next;
	}
}

void	get_sphere(t_data *d)
{
	t_object	*tmp;
	int	i;

	i = 2 + d->count.l_count;
	tmp = d->chaos;
	while(tmp)
	{
		if (tmp->type == SPHERE)
		{
			d->objs[i] = tmp;
			i++;
		}
		tmp = tmp->next;
	}
}

void	get_plane(t_data *d)
{
	t_object	*tmp;
	int	i;

	i = 2 + d->count.l_count + d->count.sp_count;
	tmp = d->chaos;
	while(tmp)
	{
		if (tmp->type == PLANE)
		{
			d->objs[i] = tmp;
			i++;
		}
		tmp = tmp->next;
	}
}

void	get_cylindre(t_data *d)
{
	t_object	*tmp;
	int	i;

	tmp = d->chaos;
	i = 2 + d->count.l_count + d->count.sp_count + d->count.pl_count;
	while(tmp)
	{
		if (tmp->type == CYLINDER)
		{
			d->objs[i] = tmp;
			i++;
		}
		tmp = tmp->next;
	}
}

void	obj_array_create(t_data *d)
{
	int	i;

	i = 0;
	d->count.total = calc_nb_obj(d->chaos);
	d->objs = malloc(sizeof(t_object*) * (d->count.total + 1));
	get_ambiant(d);
	get_camera(d);
	get_light(d);
	get_sphere(d);
	get_plane(d);
	get_cylindre(d);
	d->objs[d->count.total] = NULL;

	/*printf_vec(d->objs[4]->u_data.plane.orient);

	t_plane plane;
	plane = d->objs[4]->u_data.plane;
	printf_vec(plane.orient);*/
	// get_camera(d);
	// get_ambiant(d);
	// get_light(d);
}