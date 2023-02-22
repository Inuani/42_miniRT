
#include "../includes/minirt.h"

t_ray	create_ray(t_cam *cam)
{
	t_ray	ray;

	ray.origin.x = cam->coords.x;
	ray.origin.y = cam->coords.y;
	ray.origin.z = cam->coords.z;

	ray.direction.x = cam->orientation.x;
	ray.direction.y = cam->orientation.y;
	ray.direction.z = cam->orientation.z;
	return (ray);
}

int ray_color(t_ray *ray)
{
	t_vec u_vec = vec_unit(ray->direction);
	float h = 0.5*(u_vec.y) + 1.0;
	return (1.0 - h) * create_trgb(0, 255, 255, 255) + h * create_trgb(0, 125, 178, 255);
}