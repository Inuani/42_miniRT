#include "../../includes/minirt.h"

//check for potential double A or double C that gives back error

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
	get_hyperboloid(d);
	d->objs[d->count.total] = NULL;
}

