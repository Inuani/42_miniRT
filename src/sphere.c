
#include "../includes/minirt.h"

float	sphere_hits(t_object **objs, t_ray *ray)
{
	t_sphere	sphere;
	t_cam		cam;
	t_vec		v;
	float		det;

	sphere = objs[3]->u_data.sphere;
	cam = objs[1]->u_data.camera;

	//printf("%f\n", sphere.radius);
	//printf_vec(sphere.center);

	v = vec_subs(cam.pos, sphere.center);

	float a = vec_dot(ray->direction, ray->direction); //can simplify
	float half_b = vec_dot(v, ray->direction);
	float c = vec_dot(v, v) - (sphere.radius * sphere.radius); //can simplify
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

float it_hit_sphere(t_data *data, t_ray *ray, t_sphere sphere)
{
	t_cam	cam;

	cam = data->objs[1]->u_data.camera;
	float root = sphere_hits(data->objs, ray);
	//printf("%f\n", root);
	ray->point_at = (t_vec){999, 999, 999};
	if (root < 0)
		return -1;
	//ray->depth *= 0.5;
	//if (ray->depth < )
	ray->point_at = vec_add(cam.pos, vec_scale(root, ray->direction));
	ray->normal = vec_scale(1/sphere.radius, vec_subs(ray->point_at, sphere.center));
	ray->normal = front(ray);

	//vec_unit(ray->normal); //useless?

	if (light_hit(ray, data))
		return (light_hit(ray, data));


	return (0);
}
