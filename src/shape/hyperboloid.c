
#include "../../includes/minirt.h"

t_vec calculate_x_y_hcb(t_ray *ray, t_hyperboloid *cyl)
{
	float	u;
	float	v;
	u = get_angle_0_to_1(vec_unit(ray->point_at), (t_vec){1,0,0});
	v = fmod(ray->point_at.y, 1);

	if (!((u + v) < 0.5 || ((u + v) > 1 && (u + v) < 1.5)))
		return ((t_vec) {255, 255, 255});
	return ((t_vec) cyl->colors);
}

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
	//if (!is_inside_hyp(ray, hyp))
	//	return ;

	t_vec dist = vec_subs(ray->point_at, hyp.center);
	t_vec proj = vec_subs(dist, vec_scale(vec_dot(dist, hyp.orient), hyp.orient));
	ray->normal = vec_unit(proj);
	ray->shiny = 100;
	phong(data, ray, light, hyp.colors);
}

void	init_hy(t_hyperboloid *hyp, t_vec v, t_vec origin)
{
	hyp->h_point = vec_add(hyp->center, vec_scale(hyp->hgt, hyp->orient));
	hyp->h = vec_subs(hyp->center, hyp->h_point);
	hyp->w = vec_subs(origin, hyp->h_point);
	hyp->m = (hyp->radius * hyp->radius) / (vec_len(hyp->h) * vec_len(hyp->h));
	hyp->v_h = vec_dot(v, vec_unit(hyp->h));
	hyp->w_h = vec_dot(hyp->w, vec_unit(hyp->h));
}

float	hit_hyperboloid(t_vec v, t_hyperboloid hyp, t_vec origin)
{
	t_vec	point_at1;
	t_vec	point_at2;
	float	a;
	float	b;
	float	c;

	init_hy(&hyp, v, origin);
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

void get_u_v_hy(t_hyperboloid *hy, t_ray *ray, float *u, float *v)
{
	t_vec	hit_vec;
	float	theta;
	
	hit_vec = vec_subs(ray->point_at, hy->center);
	theta = atan2(hit_vec.x, hit_vec.z);
	if (theta < 0)
		theta += 2 * M_PI;
	*u = theta / (2 * M_PI);
	*v = (hit_vec.y + hy->hgt / 2) / hy->hgt;
}

t_vec get_x_y_color_hy(t_data *d, t_hyperboloid *hy, float u, float v)
{
	int	x;
	int	y;

	x = u * hy->xpm.wdth;
	y = (1 - v) * hy->xpm.hgt;
	return (decimalToRGB(get_color_pixel(d, x, y, &hy->xpm)));
}

t_vec	set_hy_xpm_color(t_data *d, t_ray *ray, t_hyperboloid *hy)
{
	t_vec	pixel_color;
	float	u;
	float	v;

	get_u_v_hy(hy, ray, &u, &v);
	pixel_color = get_x_y_color_hy(d, hy, u, v);
	return (pixel_color);
}

float it_hit_hy(t_data *data, t_ray *ray, t_hyperboloid hy)
{
	int		i;
	float	ret;
	t_vec	ambient_color;

	ret = 0;
	i = 0;
	if (hy.flg == 2)
		hy.colors = set_hy_xpm_color(data, ray, &hy);
	else if (hy.flg == 1)
		hy.colors = calculate_x_y_hcb(ray, &hy);
	while (i < data->count.l_count)
		hyp_light_hit(ray, data, hy, data->objs[2 + i++]->u_data.light);
	ambient_color = add_color(vec_scale(K_LIGHT, hy.colors), vec_scale(1 - K_LIGHT, data->objs[0]->u_data.ambiant.colors));
	data->final_color = add_colors(data->final_color, ambient_color, data->objs[0]->u_data.ambiant.light_ratio);
	return (1);
}