
#include "../includes/minirt.h"

int	get_angle(t_vec normal, t_vec ray_l)
{
	float dot = vec_dot(normal, ray_l);
	float magnitude_n = vec_len(normal);
	float magnitude_l = vec_len(ray_l);
	float angle = acos(dot / (magnitude_n * magnitude_l));
	return (angle * 180.0 / M_PI);
}

void	light_hit(t_ray *ray, t_data *data, t_sphere sphere, t_light light)
{
	float	root2;
	t_cam	cam;
	float	ln2;
	t_vec	R;
	float	i_d;
	float	i_s;

	cam = data->objs[1]->u_data.camera;

	t_vec vector = vec_subs(ray->point_at, light.pos);
	t_vec v = vec_subs(light.pos, sphere.center);
	root2 = sphere_hits(vector, v, sphere);
	t_vec root_at = vec_add(light.pos, vec_scale(root2, vector));
	t_vec vector_l = vec_subs(root_at, light.pos);

	//if (!is_first(ray, data->objs[1]->u_data.camera, &data->point_at))
	//	return ;
	t_vec ambient_color = add_color(vec_scale(K, sphere.colors), vec_scale(1 - K, data->objs[0]->u_data.ambiant.colors));
	data->final_color = add_colors(data->final_color, ambient_color, data->objs[0]->u_data.ambiant.light_ratio);
	if (!(vec_len(vec_subs(ray->point_at, light.pos)) - 0.01 <= vec_len(vector_l)))
		return ;


	vector = vec_unit(vector);
	ln2 = 2 * vec_dot(vector, ray->normal);
	R = vec_subs(vec_scale(ln2, ray->normal), vector);
	t_vec pos = vec_subs(ray->point_at, data->objs[1]->u_data.camera.pos);		
	pos = vec_unit(pos);
	i_d = vec_dot(vector, ray->normal) * light.light_ratio;
	i_s = fmax(powf(vec_dot(R, pos), 100) * light.light_ratio, 0.0);
	
	t_vec diffuse_color = add_color(vec_scale(K, sphere.colors), vec_scale(1 - K, light.colors));
	data->final_color = add_colors(data->final_color, diffuse_color, -i_d);
	data->final_color = add_colors(data->final_color, light.colors, i_s);
}

float	sphere_hits(t_vec vector, t_vec v, t_sphere sphere)
{
	float		det;

	float a = vec_dot(vector, vector); //can simplify
	float half_b = vec_dot(v, vector);
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
	int		i;
	float	ret;

	ret = 0;
	i = 0;
	ray->normal = vec_scale(1/sphere.radius, vec_subs(ray->point_at, sphere.center));
	//ray->normal = vec_unit(ray->normal); //useless?
	while (i < data->count.l_count)
		light_hit(ray, data, sphere, data->objs[2 + i++]->u_data.light);
	
	return (1);
}
