
#include "../../includes/minirt.h"
#include "../../includes/keys.h"

void	handle_planes_p2(int key, t_plane *obj)
{
	if (key == J && obj->orient.x >= -0.9)
		obj->orient.x -= 0.1;
	else if (key == K && obj->orient.y >= -0.9)
		obj->orient.y -= 0.1;
	else if (key == L && obj->orient.z >= -0.9)
		obj->orient.z -= 0.1;
	else if (key == N_SEVEN && obj->colors.x < 246)
		obj->colors.x += 10;
	else if (key == N_EIGHT &&obj->colors.y < 246)
		obj->colors.y += 10;
	else if (key == N_NINE && obj->colors.z < 246)
		obj->colors.z += 10;
	else if (key == N_FOUR && obj->colors.x > 9)
		obj->colors.x -= 10;
	else if (key == N_FIVE && obj->colors.y > 9)
		obj->colors.y -= 10;
	else if (key == N_SIX && obj->colors.z > 9)
		obj->colors.z -= 10;
}

void	handle_planes(int key, t_data *data)
{
	t_plane	*obj;

	obj = &data->objs[data->current]->u_data.plane;
	if (key == Q)
		obj->point.x += 1.0;
	else if (key == W)
		obj->point.y += 1.0;
	else if (key == E)
		obj->point.z += 1.0;
	else if (key == A)
		obj->point.x -= 1.0;
	else if (key == S)
		obj->point.y -= 1.0;
	else if (key == D)
		obj->point.z -= 1.0;
	else if (key == U && obj->orient.x <= 0.9)
		obj->orient.x += 0.1;
	else if (key == I && obj->orient.y <= 0.9)
		obj->orient.y += 0.1;
	else if (key == O && obj->orient.z <= 0.9)
		obj->orient.z += 0.1;
	else
		handle_planes_p2(key, obj);

	obj->orient = vec_unit(obj->orient);
}

void	handle_spheres_p2(int key, t_sphere *sphere)
{
	if (key == K && sphere->radius >= 1.0)
		sphere->radius -= 1.0;
	else if (key == N_SEVEN && sphere->colors.x < 246)
		sphere->colors.x += 10;
	else if (key == N_EIGHT && sphere->colors.y < 246)
		sphere->colors.y += 10;
	else if (key == N_NINE && sphere->colors.z < 246)
		sphere->colors.z += 10;
	else if (key == N_FOUR && sphere->colors.x > 9)
		sphere->colors.x -= 10;
	else if (key == N_FIVE && sphere->colors.y > 9)
		sphere->colors.y -= 10;
	else if (key == N_SIX && sphere->colors.z > 9)
		sphere->colors.z -= 10;
}

void	handle_spheres(int key, t_data *data)
{
	t_sphere	*sphere;

	sphere = &data->objs[data->current]->u_data.sphere;
	if (key == Q)
		sphere->center.x += 5.0;
	else if (key == W)
		sphere->center.y += 5.0;
	else if (key == E)
		sphere->center.z += 5.0;
	else if (key == A)
		sphere->center.x -= 5.0;
	else if (key == S)
		sphere->center.y -= 5.0;
	else if (key == D)
		sphere->center.z -= 5.0;
	else if (key == I)
		sphere->radius += 1.0;
	else
		handle_spheres_p2(key, sphere);
}

int	event_handler(int key, t_data *data)
{
	(void) data;
	if (key == 53)
	{
		free (data->objs);
		free_obj_list(data->chaos);
		free(data->vp);
		exit(0);
	}
	else if (key == 123) //maybe wrong
	{
		if (data -> current == 0)
			data->current = data->count.total - 1;
		else
			data->current--;
		data->changed = 1;
	}
	else if (key == 124) //maybe wrong
	{
		if (data -> current == data->count.total - 1)
			data->current = 0;
		else
			data->current++;
		data->changed = 1;
	}
	handle_stuff(key, data);
	//render(data);
	create_thread(data);
	return (0);
}
