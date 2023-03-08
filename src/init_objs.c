
#include "../includes/minirt.h"

void	initialise_viewport(t_data *data) // will have to normalise cam->orientation
{
	t_cam cam;

	cam = data->objs[1]->u_data.camera;

	data->vp = malloc(sizeof(t_viewport) + 1);

	data->vp->aspect_ratio = 16.0 / 9.0;
	data->vp->viewp_wdt = tan(cam.fov / 2 * M_PI / 180.0) * 2;
	data->vp->viewp_hgt = data->vp->viewp_wdt / (data->vp->aspect_ratio);

	data->vp->focal_len = 1;

	data->vp->samplespp = 100;
}

