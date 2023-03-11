
#include "../../includes/minirt.h"
#include "../../includes/keys.h"

void	handle_hyperboloids_p2(int key, t_hyperboloid *obj)
{
	if (key == O && obj->orient.z <= 0.9)
		obj->orient.z += 0.1;
	else if (key == J && obj->orient.x >= -0.9)
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

void	handle_hyperboloids(int key, t_data *data)
{
	t_hyperboloid	*obj;

	obj = &data->objs[data->current]->u_data.hyperboloid;
	if (key == Q)
		obj->center.x += 1.0;
	else if (key == W)
		obj->center.y += 1.0;
	else if (key == E)
		obj->center.z += 1.0;
	else if (key == A)
		obj->center.x -= 1.0;
	else if (key == S)
		obj->center.y -= 1.0;
	else if (key == D)
		obj->center.z -= 1.0;
	else if (key == U && obj->orient.x <= 0.9)
		obj->orient.x += 0.1;
	else if (key == I && obj->orient.y <= 0.9)
		obj->orient.y += 0.1;
	else
		handle_hyperboloids_p2(key, obj);
}


void	handle_cylinders_p2(int key, t_cylinder *obj)
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

void	handle_cylinders(int key, t_data *data)
{
	t_cylinder	*obj;

	obj = &data->objs[data->current]->u_data.cylinder;
	if (key == Q)
		obj->center.x += 1.0;
	else if (key == W)
		obj->center.y += 1.0;
	else if (key == E)
		obj->center.z += 1.0;
	else if (key == A)
		obj->center.x -= 1.0;
	else if (key == S)
		obj->center.y -= 1.0;
	else if (key == D)
		obj->center.z -= 1.0;
	else if (key == U && obj->orient.x <= 0.9)
		obj->orient.x += 0.1;
	else if (key == I && obj->orient.y <= 0.9)
		obj->orient.y += 0.1;
	else if (key == O && obj->orient.z <= 0.9)
		obj->orient.z += 0.1;
	else
		handle_cylinders_p2(key, obj);

	//obj->orient = vec_unit(obj->orient);
}

void handle_stuff(int key, t_data *data)
{
	if (data->current == 0)
		handle_ambient(key, data);
	else if (data->current == 1)
		handle_camera(key, data);
	else if (data->current < 2 + data->count.l_count)
		handle_lights(key, data);
	else if (data->current < 2 + data->count.l_count + data->count.sp_count)
		handle_spheres(key, data);
	else if (data->current < 2 + data->count.l_count + data->count.sp_count
			 + data->count.pl_count)
		handle_planes(key, data);
	else if (data->current < 2 + data->count.l_count + data->count.sp_count
			 + data->count.pl_count + data->count.cy_count)
		handle_cylinders(key, data);
	else if (data->current < 2 + data->count.l_count + data->count.sp_count
			 + data->count.pl_count + data->count.cy_count + data->count.hy_count)
		handle_hyperboloids(key, data);
}