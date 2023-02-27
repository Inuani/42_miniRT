
#include "../includes/minirt.h"

t_sphere	*create_sphere(t_vec center, float diameter, t_vec colors)
{
	t_sphere	*sphere;
	
	sphere = malloc(sizeof(t_sphere) + 1);

	sphere->center.x = center.x;
	sphere->center.y = center.y;
	sphere->center.z = center.z;

	sphere->radius = diameter / 2.0;

	sphere->colors.x = colors.x;
	sphere->colors.y = colors.y;
	sphere->colors.z = colors.z;

	return (sphere);
}

float	sphere_hits(void **objs, t_ray *ray)
{
	t_sphere	*sphere;
	t_cam		*cam;
	t_vec		v;
	float		det;

	sphere = (t_sphere*)objs[2];
	cam = (t_cam*)objs[1];

	v = vec_subs(cam->pos, sphere->center);

	float a = vec_dot(ray->direction, ray->direction); //can simplify
	float half_b = vec_dot(v, ray->direction);
	float c = vec_dot(v, v) - (sphere->radius * sphere->radius); //can simplify
	det = half_b*half_b - a*c;

	if (det < 0)
		return (-1.0);
	float t1 = (-half_b - sqrt(det)) / a;
	float t2 = (-half_b + sqrt(det)) / a;

	if (t1 > 0.0 && (t2 < 0.0 || t1 < t2)) //change in function of camera
		return (t1);
	return (t2);
}

t_vec front(t_ray *ray) //useless?
{
	int	front;
	front = vec_dot(ray->direction, ray->normal) < 0;
	return (front ? ray->normal : vec_scale(-1, ray->normal));
}

float it_hit_sphere(t_data *data, t_ray *ray, t_sphere *sphere)
{
	t_cam	*cam;

	cam = (t_cam*)data->objs[1];
	float root = sphere_hits(data->objss, ray);
	if (root < 0)
		return 0;
	//ray->depth *= 0.5;
	//if (ray->depth < )
	ray->point_at = vec_add(cam->pos, vec_scale(root, ray->direction));
	ray->normal = vec_scale(1/sphere->radius, vec_subs(ray->point_at, sphere->center));
	ray->normal = front(ray);

	//vec_unit(ray->normal); //useless?

	if (light_hit(ray, data))
		return (light_hit(ray, data));


	return (0);
}
