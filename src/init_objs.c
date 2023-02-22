
#include "../includes/minirt.h"

void	new_cam(t_data *data, t_vec *coords, t_vec *orientation, int fov)
{
	t_cam cam;

	cam.coords.x = coords->x;
	cam.coords.y = coords->y;
	cam.coords.z = coords->z;

	cam.orientation.x = orientation->x;
	cam.orientation.y = orientation->y;
	cam.orientation.z = orientation->z;

	cam.fov = fov;

	data->objs[1] = &cam;
}

void	initialise_objs(t_data *data, int num)
{
	//temp until parsing;
	t_vec temp = {.x = -50.0, .y = 0, .z = 20};
	t_vec temp1 = {.x = 0, .y = 0, .z = 1};

	data->objs = malloc((num + 1) * sizeof(void *));

	new_cam(data, &temp, &temp1, 180);
	data->objs[num] = NULL;
}