
#include "../includes/minirt.h"

t_light	*create_light(t_vec center, float lights, t_vec colors)
{
	t_light	*light;
	
	light = malloc(sizeof(t_light) + 1); 

	light->point.x = center.x;
	light->point.y = center.y;
	light->point.z = center.z;

	light->light_ratio = lights;

	light->colors.x = colors.x;
	light->colors.y = colors.y;
	light->colors.z = colors.z;

	return (light);
}

int	get_angle(t_vec normal, t_vec ray_l)
{
	float dot = vec_dot(normal, ray_l);
	float magnitude_n = vec_len(normal);
	float magnitude_l = vec_len(ray_l);
	float angle = acos(dot / (magnitude_n * magnitude_l));
	return (angle * 180.0 / M_PI);
}

float	is_blocked_s(t_ray *ray, t_light *light, void **objs)
{
	float		det;
	t_vec		v;

	t_sphere *sphere = (t_sphere*)objs[2];

	v = vec_subs(light->point, sphere->center);

	t_vec vector = vec_subs(ray->point_at, light->point);

	vector = vec_unit(vector);

	float a = vec_dot(vector, vector); //can simplify
	float half_b = vec_dot(v, vector);
	float c = vec_dot(v, v) - (sphere->radius * sphere->radius); //can simplify
	det = half_b*half_b - a*c;

	float t1 = (-half_b - sqrt(det)) / a;
	float t2 = (-half_b + sqrt(det)) / a;

	if (t1 > 0.0 && (t2 < 0.0 || t1 < t2)) //change in function of camera
		return (t1);
	return (t2);

}

int	light_hit(t_ray *ray, t_data *data)
{
	float root2;
	t_vec tmp_center = {0, 20, 10};
	float tmp_light = 0.5;
	t_vec tmp_colors = {100, 100, 100};
	t_sphere	*sphere;
	t_cam	*cam;

	cam = (t_cam*)data->objs[1];
	sphere = (t_sphere*)data->objs[2];

	t_light *light = create_light(tmp_center, tmp_light, tmp_colors);

	root2 = (float)is_blocked_s(ray, light, data->objs);
	
	/*printf("-------\n");
	printf("root2: %f\n", root2);
	printf("ray t: %f\n", ray->t);*/

	t_vec light_dir = vec_subs(ray->point_at, light->point);
	light_dir = vec_unit(light_dir);

	t_vec root_at = vec_add(light->point, vec_scale(root2, light_dir));
	t_vec vector_l = vec_subs(root_at, light->point);

	t_vec vector = vec_subs(ray->point_at, light->point);
	
	//vmaybe vec unit vector_l;

	if (vec_len(vector) - 0.01 <= vec_len(vector_l))
		return (get_angle(ray->normal, vector_l));
	return (0);
}