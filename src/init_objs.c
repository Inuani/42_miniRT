
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

void	initialise_viewport(t_data *d)
{
	t_cam *cam = (t_cam*)d->objs[1];
	t_viewport vp;

	vp.viewp_wdt = tan(cam->fov / 2) * 2;
	vp.viewp_hgt = vp.viewp_wdt * (HEIGHT / WIDTH);

	vp.vp_x.x = vp.viewp_wdt;
	vp.vp_x.y = 0;
	vp.vp_x.z = 0;

	vp.vp_y.y = vp.viewp_hgt;
	vp.vp_y.x = 0;
	vp.vp_y.z = 0;

	t_vec C = vec_add(cam->coords, cam->orientation); // will have to normalise
	t_vec left = vec_subs(vec_add(cam->coords, cam->orientation), vec_scale(0.5,vp.vp_x));

	vp.llc = vec_subs(left, vec_scale(0.5, vp.vp_y));

	d->vp = vp;
}

void	initialise_objs(t_data *data, int num)
{
	//temp until parsing;
	t_vec temp = {.x = -50.0, .y = 0, .z = 20};
	t_vec temp1 = {.x = 0, .y = 1, .z = 0};

	data->objs = malloc((num + 1) * sizeof(void *));

	new_cam(data, &temp, &temp1, 180);
	data->objs[num] = NULL;
	initialise_viewport(data);
}

