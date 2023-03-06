# include "../includes/minirt.h"


float	hit_cylinder(t_ray *ray, t_cylinder cyl, t_vec origin)
{
	// t_vec	h;
	// t_vec	top_cyl;
	float	a;
	float	b;
	float	c;
	float	t1;
	float	t2;
	float	delta;
	(void)origin;
	t_vec	point_at;

	// printf("---------\n");
	// printf_vec(cyl.orient);
	// cyl.orient = vec_unit(cyl.orient);
	// printf("cyl orient:\n");
	// printf_vec(cyl.orient);

	// top_cyl = vec_add(cyl.center, vec_scale(cyl.hgt, cyl.orient));
	// printf("top cyl:\n");
	// printf_vec(top_cyl);
	// h = vec_div_float(vec_subs(top_cyl, cyl.center), vec_len(vec_subs(top_cyl, cyl.center)));

	// h = vec_unit(vec_subs(top_cyl, cyl.center));
	// printf("vec h:\n");
	// printf_vec(h);
	// printf("---------\n");
	a = vec_dot(ray->direction, ray->direction) - powf(vec_dot(ray->direction, cyl.h_unit), 2);
	b = 2.0 * ((vec_dot(ray->direction, cyl.cam2cyl)) - (vec_dot(ray->direction, cyl.h_unit) * vec_dot(cyl.cam2cyl, cyl.h_unit)));
	c = vec_dot(cyl.cam2cyl, cyl.cam2cyl) - powf(vec_dot(cyl.cam2cyl, cyl.h_unit), 2) - powf(cyl.radius, 2.0);
	delta = (b * b) - (4 * a * c);
	
	// printf("%f, %f, %f, %f\n", a, b, c, delta);

	
	if (delta == 0.0)
	{
		if (fabs(vec_dot(vec_unit(ray->direction), cyl.h_unit)) != 1)
			return(-(b / (2.0 * a)));
		// else if (fabs(vec_dot(vec_unit(ray->direction), cyl.h_unit)) == 1)
		// {
		// 		t1 = (-b - sqrt(delta)) / (2.0 * a);
		// 		t2 = (-b + sqrt(delta)) / (2.0 * a);

		// 	if (t1 > 0.0 && (t2 < 0.0 || t1 < t2))
		// 		return (t1);
		// 	return (t2);
		// }
	}
	else if (delta > 0)
	{
		t1 = (-b - sqrt(delta)) / (2.0 * a);
		t2 = (-b + sqrt(delta)) / (2.0 * a);
		// verifier si t sont bien positif, sinon ils sont derriere la camera

		float	t;
		if (t2 < 0)
			return (-1);
		t = (t1 > 0 ? t1 : t2);
		float max = sqrtf(powf(cyl.hgt / 2, 2) + powf(cyl.radius, 2));
		point_at = vec_add(origin, vec_scale(t, ray->direction));
		t_vec len = vec_subs(point_at, cyl.center);
		len = vec_subs(point_at, cyl.center);
		// len = vec_subs(ray->point_at, vec_add(cyl.center, vec_scale(cyl.hgt / 2, cyl.orient)));
		if (vec_len(len) > max)
			t = t2;
		point_at = vec_add(origin, vec_scale(t, ray->direction));
		len = vec_subs(point_at, cyl.center);
		// len = vec_subs(ray->point_at, vec_add(cyl.center, vec_scale(cyl.hgt / 2, cyl.orient)));
		if (vec_len(len) > max)
			return (-1);
		return (t);

	
		// if (t1 > 0.0 && (t2 < 0.0 || t1 < t2))
		// {
		// 	ray->point_at = vec_add(origin, vec_scale(t1, ray->direction));
		// 	if (vec_dot(vec_subs(ray->point_at, cyl.center), cyl.h) < 0)
		// 		return -1;
		// 	if (vec_dot(vec_subs(ray->point_at, cyl.center), cyl.h) > vec_dot(cyl.h, cyl.h))
		// 		return -1;
		// 	return (t1);
		// }
		// printf("ici\n");
		// ray->point_at = vec_add(origin, vec_scale(t2, ray->direction));
		// // if (vec_dot(vec_subs(ray->point_at, cyl.center), cyl.h) < 0)
		// // 	return (-1);
		// // if (vec_dot(vec_subs(ray->point_at, cyl.center), cyl.h) > vec_dot(cyl.h, cyl.h))
		// // 	return (-1);
		// return (t2);
	}
	return (-1.0);
}

// t_vec	cyl_surface_normal_vec()
// {
// 	t_vec	center2point;

// }

void	cyl_light_hit(t_ray *ray, t_data *data, t_cylinder cyl, t_light light)
{
	//if (!light_hit_objs(data, ray, ray->point_at, light))
	//	return ;
	// if (is_inside(cyl, data->objs[1]->u_data.camera, light))
	// 	return ;

	t_vec dist = vec_subs(ray->point_at, cyl.center);
	t_vec proj = vec_subs(dist, vec_scale(vec_dot(dist, cyl.orient), cyl.orient));
	float dot_prod = vec_dot(proj, ray->direction);
	float sign = dot_prod >= 0 ? 1 : -1;
	ray->normal = vec_scale(sign, vec_unit(proj));

	// ray->normal = vec_unit(proj);
	// if (vec_dot(vec_subs(ray->point_at, cyl.center), cyl.orient) < 0)
	// 	ray->normal = vec_scale(-1, ray->normal);
	// printf_vec(ray->normal);

	// float dist_from_center = vec_len(vec_subs(ray->point_at, cyl.center));
	// float half_height = cyl.hgt / 2.0;
	// if (dist_from_center > half_height)
	// 	ray->normal = vec_scale(-1, ray->normal);

	// float dot = vec_dot(dist, cyl.orient);
	// if (dot < 0)
	// ray->normal = vec_scale(-1, ray->normal);
		(void)data;
		(void)ray;
		(void)cyl;
		(void)light;
	ray->shiny = 100;
	phong(data, ray, light, cyl.colors);
}


float	cylinder_eman(t_data *data, t_ray *ray, t_cylinder cyl)
{
	int	i;

	i = 0;

	while (i < data->count.l_count)
		cyl_light_hit(ray, data, cyl, data->objs[2 + i++]->u_data.light);
	t_vec ambient_color = add_color(vec_scale(K, cyl.colors), vec_scale(1 - K, data->objs[0]->u_data.ambiant.colors));
	data->final_color = add_colors(data->final_color, ambient_color, data->objs[0]->u_data.ambiant.light_ratio);
	return(0);

	// t_cam	cam;
	// float	hot_or_not;

	// cam = data->objs[1]->u_data.camera;
	// hot_or_not = hit_cylinder(ray, cyl, cam.pos);
	// // printf("hot or not : %f\n", hot_or_not);
	
	// if (hot_or_not < 0)
	// 	return (-1);
	// // cyl.h = vec_subs(vec_add(cyl.center, vec_scale(cyl.hgt, cyl.orient)), cyl.center);

	// // printf("---------\n");
	// // printf("ray point at\n");
	// // printf_vec(ray->point_at);
	// // printf("vec len: %f\n\n", vec_len(cyl.h));
	// // printf("vec cyl.h :\n");
	// // printf_vec(cyl.h);

	// // ray->point_at = vec_add(cam.pos, vec_scale(hot_or_not, ray->direction));
	// // if (vec_dot(vec_subs(ray->point_at, cyl.center), cyl.h) < 0)
	// // 	return -1;
	// // // if (vec_dot(vec_subs(ray->point_at, cyl.center), cyl.h) > vec_len(cyl.h))
	// // if (vec_dot(vec_subs(ray->point_at, cyl.center), cyl.h) > vec_dot(cyl.h, cyl.h))
	// // 	return -1;
	// return(0);
}
