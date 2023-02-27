
#include "../includes/minirt.h"


//what if negatif?
float map(int x)
{
	float	y;
	y = abs(90 - x);
	return (0.0 +  ((1.0 - 0.0) / (float)(90.0 - 0)) * (y - 0));
}

float map2(float x, float min, float input_min)
{
	return (((1 - min) / (2 - input_min)) * (x - input_min) + min);
}


t_ray	create_ray(t_cam *cam, t_viewport *vp, float u, float v)
{
	t_ray	ray;

	ray.point_at = (t_vec){0, 0, 0};
	ray.depth = 0.5;

	ray.direction = (t_vec) {
		-1 *(u - 0.5) * vp->viewp_wdt,
		-1 * (v - 0.5) * vp->viewp_hgt,
		vp->focal_len// * (-1)
	};

	ray.direction = vec_unit(ray.direction);

	ray.ray = (t_vec) {
		ray.direction.x * cam->right.x + ray.direction.y * cam->up.x + ray.direction.z * cam->orient.x,
		ray.direction.x * cam->right.y + ray.direction.y * cam->up.y + ray.direction.z * cam->orient.y,
		ray.direction.x * cam->right.z + ray.direction.y * cam->up.z + ray.direction.z * cam->orient.z
	};

	ray.ray = vec_unit(ray.ray);

	ray.direction = ray.ray;

	return (ray);
}

int ray_color(t_ray *ray, t_data *data)
{
	t_vec		color = {0, 0, 0};

	//if (plane_life(data, ray))
	//	return create_trgb(0, 0, 30, 150);
	
	if (hit_objs(data, ray, &color) >= 0)
		return create_trgb(0, color.x, color.y, color.z);
/*
	if (it_hit_sphere(data, ray, sphere) == 0)
		color = vec_scale(0.2, sphere.colors); //0.5 correspond a la lumiere ambiante
	else if (it_hit_sphere(data, ray, sphere) == -1)
		return create_trgb(0, color.x,  color.y,  color.z);
	else
	{
		float scale = map2(0.9 + map(it_hit_sphere(data, ray, sphere)), 0.2, 0.9);
		color = vec_scale(scale, sphere.colors);
	}*/
	return create_trgb(0, color.x,  color.y,  color.z);
}