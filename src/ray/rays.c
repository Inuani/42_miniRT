
#include "../../includes/minirt.h"

// used to calculate the intensity of lighting on an object
// based on the angle between the normal vector
// of the object and the direction of the light source.
//what if negatif?
float	map(float x)
{
	float	y;

	y = fabs(90 - x);
	return (0.0 + ((1.0 - 0.0) / (float)(90.0 - 0)) * (y - 0));
}

// used to adjust the intensity of lighting based on
// the minimum intensity and the minimum value of the range.
float	map2(float x, float min, float input_min)
{
	return (((1 - min) / (2 - input_min)) * (x - input_min) + min);
}

t_ray	create_ray(t_cam *cam, t_viewport *vp, float u, float v)
{
	t_ray	ray;

	ray.point_at = (t_vec){0, 0, 0};
	ray.direction = (t_vec)
	{
		-1 *(u - 0.5) * vp->viewp_wdt,
		-1 * (v - 0.5) * vp->viewp_hgt,
		vp->focal_len
	};
	ray.direction = vec_unit(ray.direction);
	ray.ray = (t_vec)
	{
		ray.direction.x * cam->right.x + ray.direction.y
		* cam->up.x + ray.direction.z * cam->orient.x,
		ray.direction.x * cam->right.y + ray.direction.y
		* cam->up.y + ray.direction.z * cam->orient.y,
		ray.direction.x * cam->right.z + ray.direction.y
		* cam->up.z + ray.direction.z * cam->orient.z
	};
	ray.ray = vec_unit(ray.ray);
	ray.direction = ray.ray;
	return (ray);
}

int	ray_color(t_ray *ray, t_data *data)
{
	t_vec	color;

	color = (t_vec){0, 0, 0};
	data->final_color = (t_vec){0, 0, 0};
	hit_objs(data, ray);
	if (data->final_color.x > 255 || data->final_color.x < 0)
		data->final_color.x = 255;
	if (data->final_color.y > 255 || data->final_color.y < 0)
		data->final_color.y = 255;
	if (data->final_color.z > 255 || data->final_color.z < 0)
		data->final_color.z = 255;
	color = data->final_color;
	return (create_trgb(0, color.x, color.y, color.z));
}

void	phong(t_data *data, t_ray *ray, t_light light, t_vec obj_color)
{
	float	i_d;
	float	i_s;
	t_vec	r;
	t_vec	vector;
	t_vec	diffuse_color;

	vector = vec_subs(ray->point_at, light.pos);
	vector = vec_unit(vector);
	r = vec_subs(vec_scale(2 * vec_dot(vector, ray->normal),
				ray->normal), vector);
	i_d = vec_dot(vector, ray->normal) * light.light_ratio;
	i_s = powf(vec_dot(r, vec_scale(-1, ray->direction)), ray->shiny)
		* light.light_ratio;
	if (i_d < 0)
		i_d = -i_d;
	diffuse_color = add_color(vec_scale(K_LIGHT, obj_color),
			vec_scale(1 - K_LIGHT, light.colors));
	data->final_color = add_colors(data->final_color, diffuse_color, i_d);
	data->final_color = add_colors(data->final_color, light.colors, i_s);
}
