
#include "../includes/minirt.h"


float	hit_hyperboloid(t_vec vector, t_hyperboloid hyperboloid, t_vec origin)
{
	float		det;
	t_vec orient = hyperboloid.orient;


	float a = (vector.x * vector.x) / (orient.x * orient.x)
				+ (vector.y * vector.y) / (orient.y * orient.y)
				+ (vector.z * vector.z) / (orient.z * orient.z);

	float b = 2 * (origin.x * vector.x / (orient.x * orient.x))
					+ (origin.y * vector.y / (orient.y * orient.y))
					- (origin.z * vector.z / (orient.z * orient.z));

	float c = (origin.x * origin.x) / (orient.x * orient.x)
				+ (origin.y * origin.y) / (orient.y * orient.y)
				- (origin.z * origin.z) / (orient.z * orient.z) - 1;

	det = b * b - 4 * a * c;

	if (det < 0)
		return (-1.0);
	float t1 = (-b - sqrt(det)) / (2 * a);
	float t2 = (-b + sqrt(det)) / (2 * a);

	if (t1 > 0.0 && (t2 < 0.0 || t1 < t2)) //change in function of camera
		return (t1);
	return (t2);
}


float it_hit_hy(t_data *data, t_ray *ray, t_hyperboloid hp)
{
	int		i;
	float	ret;

	ret = 0;
	i = 0;
	(void)ray;
	//ray->normal = vec_scale(1/sphere.radius, vec_subs(ray->point_at, sphere.center));
	//while (i < data->count.l_count)
	//	light_hit(ray, data, hp, data->objs[2 + i++]->u_data.light);
	t_vec ambient_color = add_color(vec_scale(K, hp.colors), vec_scale(1 - K, data->objs[0]->u_data.ambiant.colors));
	data->final_color = add_colors(data->final_color, ambient_color, data->objs[0]->u_data.ambiant.light_ratio);
	return (1);
}