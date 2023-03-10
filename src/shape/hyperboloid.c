
#include "../../includes/minirt.h"

int is_inside_hyp(t_ray *ray, t_hyperboloid hyp)
{
	t_vec	h_point = vec_add(hyp.center, vec_scale(hyp.hgt, hyp.orient));

	float cone_dist = vec_dot(vec_subs(ray->point_at, h_point), hyp.orient);
	float cone_radius = (cone_dist / hyp.hgt) * hyp.radius;
	float orth_distance = vec_len(vec_subs(vec_subs(ray->point_at, h_point), vec_scale(cone_dist, hyp.orient)));

	return (orth_distance <= cone_radius);
}

void	hyp_light_hit(t_ray *ray, t_data *data, t_hyperboloid hyp, t_light light)
{
	if (!light_hit_objs(data, ray->point_at, light))
		return ;
//	if (!is_inside_hyp(ray, hyp))
//		return ;

	float slant_height = sqrt(hyp.radius * hyp.radius + hyp.hgt * hyp.hgt);
	ray->normal.x = ray->point_at.x / slant_height;
	ray->normal.y = ray->point_at.y / slant_height;
	ray->normal.z = hyp.hgt / slant_height;
	ray->normal = vec_unit(ray->normal);
	ray->shiny = 100;
	phong(data, ray, light, hyp.colors);
}

void	init_hy(t_hyperboloid *hyp, t_vec v, t_vec origin)
{
	(void)v;
	(void)origin;

	hyp->h_point = vec_add(hyp->center, vec_scale(hyp->hgt, hyp->orient));
	hyp->h = vec_subs(hyp->center, hyp->h_point);
	hyp->w = vec_subs(origin, hyp->h_point);
	hyp->m = (hyp->radius * hyp->radius) / (vec_len(hyp->h) * vec_len(hyp->h));
	hyp->v_h = vec_dot(v, vec_unit(hyp->h));
	hyp->w_h = vec_dot(hyp->w, vec_unit(hyp->h));
}

float	hit_hyperboloid(t_vec v, t_hyperboloid hyp, t_vec origin)
{
	(void)v;
	(void)hyp;
	(void)origin;
	
	t_vec	point_at1;
	t_vec	point_at2;
	float	a;
	float	b;
	float	c;

	init_hy(&hyp, v, origin);
	/*hyp.h_point = vec_add(hyp.center, vec_scale(hyp.hgt, hyp.orient));
	hyp.h = vec_subs(hyp.center, hyp.h_point);
	hyp.w = vec_subs(origin, hyp.h_point);
	hyp.m = (hyp.radius * hyp.radius) / (vec_len(hyp.h) * vec_len(hyp.h));
	hyp.v_h = vec_dot(v, vec_unit(hyp.h));
	hyp.w_h = vec_dot(hyp.w, vec_unit(hyp.h));*/
	a = vec_dot(v, v) - hyp.m * hyp.v_h * hyp.v_h - hyp.v_h * hyp.v_h;
	b = 2 * (vec_dot(v, hyp.w) - hyp.m * hyp.v_h * hyp.w_h - hyp.v_h * hyp.w_h);
	c = vec_dot(hyp.w, hyp.w) - hyp.m * hyp.w_h * hyp.w_h - hyp.w_h * hyp.w_h;
	point_at1 = vec_add(origin, vec_scale((-b - sqrt(b * b - 4 * a * c)) / (2.0 * a), v));
	point_at2 = vec_add(origin, vec_scale((-b + sqrt(b * b - 4 * a * c)) / (2.0 * a), v));
	if (vec_dot(vec_subs(point_at1, hyp.h_point), vec_unit(hyp.h)) >= 0
			&& vec_dot(vec_subs(point_at1, hyp.h_point), vec_unit(hyp.h)) <= vec_len(hyp.h))
		return ((-b - sqrt(b * b - 4 * a * c)) / (2.0 * a));
	else if (vec_dot(vec_subs(point_at2, hyp.h_point), vec_unit(hyp.h)) >= 0
			&& vec_dot(vec_subs(point_at2, hyp.h_point), vec_unit(hyp.h)) <= vec_len(hyp.h))
		return ((-b + sqrt(b * b - 4 * a * c)) / (2.0 * a));
	return (-1);
}

float it_hit_hy(t_data *data, t_ray *ray, t_hyperboloid hp)
{
	int		i;
	float	ret;

	ret = 0;
	i = 0;
	(void)ray;
	//ray->normal = vec_scale(1/sphere.radius, vec_subs(ray->point_at, sphere.center));
	while (i < data->count.l_count)
		hyp_light_hit(ray, data, hp, data->objs[2 + i++]->u_data.light);
	t_vec ambient_color = add_color(vec_scale(K, hp.colors), vec_scale(1 - K, data->objs[0]->u_data.ambiant.colors));
	data->final_color = add_colors(data->final_color, ambient_color, data->objs[0]->u_data.ambiant.light_ratio);
	return (1);
}