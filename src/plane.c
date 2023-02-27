
#include "../includes/minirt.h"

int	plane_hit(t_data *data, t_ray *ray, t_plane *plane)
{
	float	t;
	float	numer;
	float	denom;
	t_cam	cam;

	cam = data->objs[1]->u_data.camera;
	numer = vec_dot(vec_subs(plane->point, cam.pos), plane->orient);
	denom = vec_dot(ray->direction, plane->orient);

	t = (float)numer / (float)denom;

	if (t < 0)
		return -1;
	else
		return 1;
}

int	plane_life(t_data *data, t_ray *ray, t_plane plane)
{
	float	root;

	plane.orient = vec_unit(plane.orient);
	root = plane_hit(data, ray, &plane);
	ray->point_at = (t_vec){999, 999, 999};
	if (root < 0)
		return -1;
	ray->point_at = vec_add(data->objs[1]->u_data.camera.pos, vec_scale(root, ray->direction));

	return 0;
}
