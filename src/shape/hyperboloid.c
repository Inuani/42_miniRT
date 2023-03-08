
#include "../../includes/minirt.h"


float	hit_hyperboloid(t_vec vector, t_hyperboloid hyp, t_vec origin)
{
	float		det;
	//t_vec orient = hyperboloid.orient;
	//(void)orient;

	/*cy.a = vec_dot(vector, vector) - powf(vec_dot(vector, hyperboloid.orient), 2);
	cy.b = 2.0 * ((vec_dot(ray_dir, ori2cy)) - (vec_dot(ray_dir, cy.orient) * vec_dot(ori2cy, cy.orient)));
	cy.c = vec_dot(ori2cy, ori2cy) - powf(vec_dot(ori2cy, cy.orient), 2) - powf(cy.radius, 2.0);*/

//float a = vec_dot(vector, vector) -

	//float a = (vector.x * vector.x) / hyp.radius
	//			+ (vector.y * vector.y) / hyp.radius
	//			- (vector.z * vector.z) / 1;
	float a = vec_dot(vector, vector) - powf(vec_dot(vector, hyp.orient), 2);
	//a = a * -1;
	printf("%f\n", a);

	float b = 2 * ((origin.x * vector.x / hyp.radius)
					+ (origin.y * vector.y / hyp.radius)
					- (origin.z * vector.z / 1));
	//float b = 2.0 * ((vec_dot(vector, origin)) - (vec_dot(vector, hyp.orient) * vec_dot(origin, hyp.orient)));
	//printf("%f\n", b);

	float c = (origin.x * origin.x) / hyp.radius
				+ (origin.y * origin.y) / hyp.radius
				- (origin.z * origin.z) / 1 - 1;

	det = b * b - 4 * a * c;
	//printf("%f\n", det);
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