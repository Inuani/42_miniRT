
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

	/*t_vec a = vec_subs(cam->coords, vec_scale(0.5, d->vp->vp_x));
	t_vec b = vec_subs(a, vec_scale(0.5, d->vp->vp_x));
	t_vec c = vec_subs(b, cam->orientation);*/
	//data->vp->llc = c;
}

void	cylinder_init(t_data *d, t_cylinder *cyl)
{
	cyl->h = vec_subs(vec_add(cyl->center, vec_scale(cyl->hgt, cyl->orient)), cyl->center);
	cyl->cam2cyl = vec_subs(d->objs[1]->u_data.camera.pos, cyl->center);
	cyl->orient = vec_unit(cyl->orient);
	cyl->top_cyl = vec_add(cyl->center, vec_scale(cyl->hgt, cyl->orient));
	cyl->h_unit = vec_div_float(vec_subs(cyl->top_cyl, cyl->center), vec_len(vec_subs(cyl->top_cyl, cyl->center)));
	(void)d;
	(void)cyl;
}
