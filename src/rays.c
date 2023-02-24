
#include "../includes/minirt.h"

t_ray	create_ray(t_cam *cam, t_viewport *vp, float u, float v)
{
	t_ray	ray;// = malloc(sizeof(t_ray) + 1); //necessary??

	//printf("vp wdt : %f\n", (u - 0.5) * vp->viewp_wdt);

	ray.direction = (t_vec) {
		(u - 0.5) * vp->viewp_wdt,
		(v - 0.5) * vp->viewp_hgt,
		vp->focal_len * (-1)
	};


	
	ray.direction = vec_unit(ray.direction);

	//printf_vec(cam->orientation);
	//printf("what interests me: %f\n", ray.direction.z * cam->orientation.z);

	ray.ray = (t_vec) {
		ray.direction.x * cam->right.x + ray.direction.y * cam->up.x + ray.direction.z * cam->orientation.x,
		ray.direction.x * cam->right.y + ray.direction.y * cam->up.y + ray.direction.z * cam->orientation.y,
		ray.direction.x * cam->right.z + ray.direction.y * cam->up.z + ray.direction.z * cam->orientation.z
	};

	ray.ray = vec_unit(ray.ray);

	//printf_vec(ray.ray);

	return (ray);
}

int ray_color(t_ray *ray, t_data *data)
{
	float t = sphere_hits(data->objs, ray);
	if (t > 0.0)
		return (create_trgb(0, 255, 255, 255));
	return (create_trgb(0, 0, 0, 0));
}