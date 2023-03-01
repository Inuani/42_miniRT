
#include "../includes/minirt.h"

int	get_angle(t_vec normal, t_vec ray_l)
{
	float dot = vec_dot(normal, ray_l);
	float magnitude_n = vec_len(normal);
	float magnitude_l = vec_len(ray_l);
	float angle = acos(dot / (magnitude_n * magnitude_l));
	return (angle * 180.0 / M_PI);
}

int	light_hit(t_ray *ray, t_data *data, t_sphere sphere)
{
	float		root2;
	t_cam		cam;
	t_light		light;

	cam = data->objs[1]->u_data.camera;
	light = data->objs[2]->u_data.light; //will have to change for bonuses

	t_vec vector = vec_subs(ray->point_at, light.pos);
	t_vec v = vec_subs(light.pos, sphere.center);
	//vector = vec_unit(vector);
	root2 = sphere_hits(vector, v, sphere);
	//if (root2 == -1) return (-1); 

	t_vec root_at = vec_add(light.pos, vec_scale(root2, vector));
	t_vec vector_l = vec_subs(root_at, light.pos);

	if (vec_len(vector) - 0.01 <= vec_len(vector_l))
		return (get_angle(ray->normal, vector_l));
	return (0);
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

float it_hit_sphere(t_data *data, t_ray *ray, t_sphere sphere) //sphere_life
{
	t_cam	cam;
	float	root;

	cam = data->objs[1]->u_data.camera;

	t_vec vector = (t_vec) {ray->direction.x, ray->direction.y, ray->direction.z};
	t_vec v = vec_subs(cam.pos, sphere.center);

	root = sphere_hits(vector, v, sphere);
	ray->point_at = (t_vec){cam.pos.x, cam.pos.y, cam.pos.z}; //useless
	if (root < 0)
		return -1;
	//ray->depth *= 0.5;
	//if (ray->depth < )
	ray->point_at = vec_add(cam.pos, vec_scale(root, ray->direction));
	ray->normal = vec_scale(1/sphere.radius, vec_subs(ray->point_at, sphere.center));
	//ray->normal = front(ray); useless?

	vec_unit(ray->normal); //useless?
	if (!light_hit_objs(data, ray, ray->point_at))
		return (0);
	float value = light_hit(ray, data, sphere);
	if (value)
		return (value);//can optimize
	return (0);
}
