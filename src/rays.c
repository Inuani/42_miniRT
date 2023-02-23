
#include "../includes/minirt.h"

t_ray	create_ray(t_cam *cam, t_viewport *vp, float u, float v)
{
	t_ray	ray;

	ray.origin.x = cam->coords.x;
	ray.origin.y = cam->coords.y;
	ray.origin.z = cam->coords.z;

	t_vec a = vec_add(vp->llc, vec_scale(u, vp->vp_x));
	t_vec b = vec_add(a, vec_scale(v, vp->vp_y));
	t_vec d = vec_subs(vec_add(a, b), ray.origin);

	ray.direction = d;
	return (ray);
}

int ray_color(t_ray *ray)
{
	t_vec u_vec = vec_unit(ray->direction);
	float h = 0.5*(u_vec.y) + 1.0;
	return (1.0 - h) * create_trgb(0, 255, 255, 255) + h * create_trgb(0, 125, 178, 255);
}