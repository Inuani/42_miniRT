
#include "../includes/minirt.h"

void	new_cam(t_data *data, t_vec coords, t_vec orientation, int fov)
{
	t_cam	*cam = malloc(sizeof(t_cam));

	cam->pos.x = coords.x;
	cam->pos.y = coords.y;
	cam->pos.z = coords.z;


	cam->orient.x = orientation.x;
	cam->orient.y = orientation.y;
	cam->orient.z = orientation.z;

	if (!orientation.x && !orientation.z)
		cam->up = vec_cross(cam->orient, (t_vec) {0, 0, 1});
	else
		cam->up = (t_vec) {0, 1, 0}; //camera's up vector is perpendicular to the camera's orientation vector. This will ensure that the camera is oriented correctly.
	
	cam->right = vec_cross(orientation, cam->up);
	cam->right = vec_unit(cam->right);

	cam->fov = fov;

	data->objss[1] = cam;
}

void	initialise_viewport(t_data *data) // will have to normalise cam->orientation
{
	t_cam *cam;

	cam = (t_cam*)data->objs[1];

	data->vp = malloc(sizeof(t_viewport) + 1);

	data->vp->aspect_ratio = 16.0 / 9.0;
	data->vp->viewp_wdt = tan(cam->fov / 2 * M_PI / 180.0) * 2;
	data->vp->viewp_hgt = data->vp->viewp_wdt / (data->vp->aspect_ratio);

	data->vp->focal_len = 1;

	data->vp->samplespp = 100;

	/*t_vec a = vec_subs(cam->coords, vec_scale(0.5, d->vp->vp_x));
	t_vec b = vec_subs(a, vec_scale(0.5, d->vp->vp_x));
	t_vec c = vec_subs(b, cam->orientation);*/
	//data->vp->llc = c;
}

void	initialise_objs(t_data *data, int num)
{
	t_vec temp_coords = {.x = 0, .y = 0, .z = 0};
	t_vec temp_direction = {.x = 0.25, .y = 0.5, .z = 0.25};
	temp_direction = vec_unit(temp_direction);

	t_vec temp_center = {5, 10, 5};
	float diameter = 5;
	t_vec s_colors = {255, 102, 102};

	data->objss = malloc((num + 1) * sizeof(void *));

	new_cam(data, temp_coords, temp_direction, 90);
	data->objss[2] = create_sphere(temp_center, diameter, s_colors);
	data->objss[num] = NULL;
	initialise_viewport(data);

}

