
#include "../includes/minirt.h"

t_ray	create_ray(t_cam *cam, t_viewport *vp, float u, float v)
{
	t_ray	ray;

	ray.depth = 0.5;

	ray.direction = (t_vec) {
		-1 *(u - 0.5) * vp->viewp_wdt,
		-1 * (v - 0.5) * vp->viewp_hgt,
		vp->focal_len// * (-1)
	};

	(void)cam;

	ray.direction = vec_unit(ray.direction);

	ray.ray = (t_vec) {
		ray.direction.x * cam->right.x + ray.direction.y * cam->up.x + ray.direction.z * cam->orientation.x,
		ray.direction.x * cam->right.y + ray.direction.y * cam->up.y + ray.direction.z * cam->orientation.y,
		ray.direction.x * cam->right.z + ray.direction.y * cam->up.z + ray.direction.z * cam->orientation.z
	};

	ray.ray = vec_unit(ray.ray);

	ray.direction = ray.ray;

	return (ray);
}

int ray_color(t_ray *ray, t_data *data)
{
	t_sphere	*sphere;
	t_vec		tmp_color = {0, 0, 0};

	sphere = (t_sphere*)data->objs[2];
	if (it_hit_sphere(data, ray, sphere))
		tmp_color = vec_scale(0.5, vec_add(ray->normal, sphere->colors)); //0.5 correspond a la lumiere ambiante
	return create_trgb(0, tmp_color.x,  tmp_color.y,  tmp_color.z);
}