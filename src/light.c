
#include "../includes/minirt.h"

int	get_angle(t_vec normal, t_vec ray_l)
{
	float dot = vec_dot(normal, ray_l);
	float magnitude_n = vec_len(normal);
	float magnitude_l = vec_len(ray_l);
	float angle = acos(dot / (magnitude_n * magnitude_l));
	return (angle * 180.0 / M_PI);
}

float	is_blocked_s(t_ray *ray, t_light *light, t_object **objs)
{
	float		det;
	t_vec		v;

	t_sphere sphere = objs[3]->u_data.sphere;

	v = vec_subs(light->pos, sphere.center);

	t_vec vector = vec_subs(ray->point_at, light->pos);

	vector = vec_unit(vector);

	float a = vec_dot(vector, vector); //can simplify
	float half_b = vec_dot(v, vector);
	float c = vec_dot(v, v) - (sphere.radius * sphere.radius); //can simplify
	det = half_b*half_b - a*c;

	float t1 = (-half_b - sqrt(det)) / a;
	float t2 = (-half_b + sqrt(det)) / a;

	if (t1 > 0.0 && (t2 < 0.0 || t1 < t2)) //change in function of camera
		return (t1);
	return (t2);

}

int	light_hit(t_ray *ray, t_data *data)
{
	float		root2;
	t_sphere	sphere;
	t_cam		cam;
	t_light		light;

	cam = data->objs[1]->u_data.camera;
	sphere = data->objs[2]->u_data.sphere;
	light = data->objs[2]->u_data.light;

	root2 = (float)is_blocked_s(ray, &light, data->objs);
	
	/*printf("-------\n");
	printf("root2: %f\n", root2);
	printf("ray t: %f\n", ray->t);*/

	t_vec light_dir = vec_subs(ray->point_at, light.pos);
	light_dir = vec_unit(light_dir);

	t_vec root_at = vec_add(light.pos, vec_scale(root2, light_dir));
	t_vec vector_l = vec_subs(root_at, light.pos);

	t_vec vector = vec_subs(ray->point_at, light.pos);
	
	//vmaybe vec unit vector_l;

	if (vec_len(vector) - 0.01 <= vec_len(vector_l))
		return (get_angle(ray->normal, vector_l));
	return (0);
}