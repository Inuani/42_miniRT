
#include "../includes/minirt.h"

// used to calculate the intensity of lighting on an object
// based on the angle between the normal vector
// of the object and the direction of the light source.

//what if negatif?
float map(float x) //changed to float
{
	float	y;
	y = fabs(90 - x);
	return (0.0 +  ((1.0 - 0.0) / (float)(90.0 - 0)) * (y - 0));
}

float inverse_map(float x)
{
	float	y;
	y = fabs(1 - x);
	return (0.0 +  ((1.0 - 0.0) / (float)(90.0 - 0)) * (y - 0));
}

// used to adjust the intensity of lighting based on
// the minimum intensity and the minimum value of the range.
float map2(float x, float min, float input_min)
{
	return (((1 - min) / (2 - input_min)) * (x - input_min) + min);
}

 // Create a ray of light that can be used to calculate the color of a pixel.
 // u and v that represent the x and y coordinates of the pixel being sampled.
 // The function computes the direction of the ray by taking the difference between the normalized
 // viewport coordinates (u-0.5) and (v-0.5) and multiplying them by the viewport width and height.
t_ray	create_ray(t_cam *cam, t_viewport *vp, float u, float v)
{
	t_ray	ray;

	ray.point_at = (t_vec){0, 0, 0};

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

// Calculate the color of a pixel based on the intersection of a ray with the objects in a scene.
// Hit_objs function is called to determine if the ray
// intersects with any of the objects in the scene.
int ray_color(t_ray *ray, t_data *data)
{
	t_vec		color = {0, 0, 0};
	//float		li;
	//float		ai;

	data->final_color = (t_vec){0, 0, 0};
	//ai = data->objs[0]->u_data.ambiant.light_ratio;
	//li = data->objs[2]->u_data.light.light_ratio;

	//if (plane_life(data, ray))
	//	return create_trgb(0, 0, 30, 150);

	hit_objs(data, ray);

	//printf("%f\n", ai);
	//data->final_color = add_colors(data->final_color, data->objs[0]->u_data.ambiant.colors, ai);
	if (data->final_color.x > 255 || data->final_color.x < 0)
		data->final_color.x = 255;
	if (data->final_color.y > 255 || data->final_color.y < 0)
		data->final_color.y = 255;
	if (data->final_color.z > 255 || data->final_color.z < 0)
		data->final_color.z = 255;
	color = data->final_color;
	return create_trgb(0, color.x, color.y, color.z);
}

/*
	if (it_hit_sphere(data, ray, sphere) == 0)
		color = vec_scale(0.2, sphere.colors); //0.5 correspond a la lumiere ambiante
	else if (it_hit_sphere(data, ray, sphere) == -1)
		return create_trgb(0, color.x, color.y, color.z);
	else
	{
		float scale = map2(0.9 + map(it_hit_sphere(data, ray, sphere)), 0.2, 0.9);
		color = vec_scale(scale, sphere.colors);
	}
	return create_trgb(0, color.x,  color.y,  color.z);
}*/