# include "../../includes/minirt.h"


t_vec calculate_x_y_ccb(t_ray *ray, t_cylinder *cyl)
{
	float	u;
	float	v;
	u = get_angle_0_to_1(vec_unit(ray->point_at), (t_vec){1,0,0});
	v = fmod(ray->point_at.y, 1);

	if (!((u + v) < 0.5 || ((u + v) > 1 && (u + v) < 1.5)))
		return ((t_vec) {255, 255, 255});
	return ((t_vec) cyl->colors);
}


void	cyl_light_hit(t_ray *ray, t_data *data, t_cylinder cyl, t_light light)
{
	if (!light_hit_objs(data, ray->point_at, light))
		return ;
	// if (is_inside(cyl, data->objs[1]->u_data.camera, light))
	// 	return ;

	ray->shiny = 100;
	phong(data, ray, light, cyl.colors);
}

float	cylinder_eman(t_data *data, t_ray *ray, t_cylinder cyl)
{
	int	i;
	t_vec	normal_map_color;

	normal_map_color = get_sp_xpm_color(data, ray, &cyl.n_map);
	cyl.colors = vec_add(get_sp_xpm_color(data, ray, &cyl.xpm), vec_unit(normal_map_color));
	i = 0;

	t_vec dist = vec_subs(ray->point_at, cyl.center);
	t_vec proj = vec_subs(dist, vec_scale(vec_dot(dist, cyl.orient), cyl.orient));
	ray->normal = vec_unit(proj);

	cyl.colors = calculate_x_y_ccb(ray, &cyl);
	while (i < data->count.l_count)
		cyl_light_hit(ray, data, cyl, data->objs[2 + i++]->u_data.light);
	t_vec ambient_color = add_color(vec_scale(K_LIGHT, cyl.colors), vec_scale(1 - K_LIGHT, data->objs[0]->u_data.ambiant.colors));
	data->final_color = add_colors(data->final_color, ambient_color, data->objs[0]->u_data.ambiant.light_ratio);
	return(0);
}

float	hit_cylinder(t_vec ray_dir, t_cylinder cy, t_vec origin, t_vec ori2cy)
{
	float	t1;
	float	t2;
	float	t;
	float	max;
	t_vec	len;
	t_vec	point_at;

	cy.a = vec_dot(ray_dir, ray_dir) - powf(vec_dot(ray_dir, cy.orient), 2);
	cy.b = 2.0 * ((vec_dot(ray_dir, ori2cy)) - (vec_dot(ray_dir, cy.orient) * vec_dot(ori2cy, cy.orient)));
	cy.c = vec_dot(ori2cy, ori2cy) - powf(vec_dot(ori2cy, cy.orient), 2) - powf(cy.radius, 2.0);
	cy.delta = (cy.b * cy.b) - (4 * cy.a * cy.c);
	if (cy.delta == 0.0)
	{
		if (fabs(vec_dot(vec_unit(ray_dir), cy.orient)) != 1)
			return(-(cy.b / (2.0 * cy.a)));
		else if (fabs(vec_dot(vec_unit(ray_dir), cy.orient)) == 1)
		{
				t1 = (-cy.b - sqrt(cy.delta)) / (2.0 * cy.a);
				t2 = (-cy.b + sqrt(cy.delta)) / (2.0 * cy.a);

			if (t1 > 0.0 && (t2 < 0.0 || t1 < t2))
				return (t1);
			return (t2);
		}
	}
	else if (cy.delta > 0)
	{
		t1 = (-cy.b - sqrt(cy.delta)) / (2.0 * cy.a);
		t2 = (-cy.b + sqrt(cy.delta)) / (2.0 * cy.a);
		if (t2 < 0)
			return (-1);
		t = (t1 > 0 ? t1 : t2);
		max = sqrtf(powf(cy.hgt / 2, 2) + powf(cy.radius, 2));
		point_at = vec_add(origin, vec_scale(t, ray_dir));
		len = vec_subs(point_at, cy.center);
		if (vec_len(len) > max)
			t = t2;
		point_at = vec_add(origin, vec_scale(t, ray_dir));
		len = vec_subs(point_at, cy.center);
		if (vec_len(len) > max)
			return (-1);
		return (t);
	}
	return (-1.0);
}

void	cylinder_init(t_data *d, t_cylinder *cy)
{
	cy->h = vec_subs(vec_add(cy->center, vec_scale(cy->hgt, cy->orient)), cy->center);
	cy->cam2cyl = vec_subs(d->objs[1]->u_data.camera.pos, cy->center);
	// cyl->orient = vec_unit(cyl->orient);
	cy->top_cyl = vec_add(cy->center, vec_scale(cy->hgt, cy->orient));

}


// OLD CYLINDER FUNCTION
// float	hit_cylinder(t_vec ray_dir, t_cylinder cyl, t_vec origin)
// {
// 	float	a;
// 	float	b;
// 	float	c;
// 	float	t1;
// 	float	t2;
// 	float	delta;
// 	t_vec	point_at;

// 	a = vec_dot(ray_dir, ray_dir) - powf(vec_dot(ray_dir, cyl.orient), 2);
// 	b = 2.0 * ((vec_dot(ray_dir, cyl.cam2cyl)) - (vec_dot(ray_dir, cyl.orient) * vec_dot(cyl.cam2cyl, cyl.orient)));
// 	c = vec_dot(cyl.cam2cyl, cyl.cam2cyl) - powf(vec_dot(cyl.cam2cyl, cyl.orient), 2) - powf(cyl.radius, 2.0);
// 	delta = (b * b) - (4 * a * c);
// 	if (delta == 0.0)
// 	{
// 		if (fabs(vec_dot(vec_unit(ray_dir), cyl.orient)) != 1)
// 			return(-(b / (2.0 * a)));
// 		else if (fabs(vec_dot(vec_unit(ray_dir), cyl.orient)) == 1)
// 		{
// 				t1 = (-b - sqrt(delta)) / (2.0 * a);
// 				t2 = (-b + sqrt(delta)) / (2.0 * a);

// 			if (t1 > 0.0 && (t2 < 0.0 || t1 < t2))
// 				return (t1);
// 			return (t2);
// 		}
// 	}
// 	else if (delta > 0)
// 	{
// 		t1 = (-b - sqrt(delta)) / (2.0 * a);
// 		t2 = (-b + sqrt(delta)) / (2.0 * a);
// 		// verifier si t sont bien positif, sinon ils sont derriere la camera

// 		float	t;
// 		if (t2 < 0)
// 			return (-1);
// 		t = (t1 > 0 ? t1 : t2);
// 		float max = sqrtf(powf(cyl.hgt / 2, 2) + powf(cyl.radius, 2));
// 		point_at = vec_add(origin, vec_scale(t, ray_dir));
// 		t_vec len = vec_subs(point_at, cyl.center);
// 		// len = vec_subs(point_at, cyl.center);
// 		// len = vec_subs(ray->point_at, vec_add(cyl.center, vec_scale(cyl.hgt / 2, cyl.orient)));
// 		if (vec_len(len) > max)
// 			t = t2;
// 		point_at = vec_add(origin, vec_scale(t, ray_dir));
// 		len = vec_subs(point_at, cyl.center);
// 		// len = vec_subs(ray->point_at, vec_add(cyl.center, vec_scale(cyl.hgt / 2, cyl.orient)));
// 		if (vec_len(len) > max)
// 			return (-1);
// 		return (t);

	
// 		// if (t1 > 0.0 && (t2 < 0.0 || t1 < t2))
// 		// {
// 		// 	ray->point_at = vec_add(origin, vec_scale(t1, ray->direction));
// 		// 	if (vec_dot(vec_subs(ray->point_at, cyl.center), cyl.h) < 0)
// 		// 		return -1;
// 		// 	if (vec_dot(vec_subs(ray->point_at, cyl.center), cyl.h) > vec_dot(cyl.h, cyl.h))
// 		// 		return -1;
// 		// 	return (t1);
// 		// }
// 		// printf("ici\n");
// 		// ray->point_at = vec_add(origin, vec_scale(t2, ray->direction));
// 		// // if (vec_dot(vec_subs(ray->point_at, cyl.center), cyl.h) < 0)
// 		// // 	return (-1);
// 		// // if (vec_dot(vec_subs(ray->point_at, cyl.center), cyl.h) > vec_dot(cyl.h, cyl.h))
// 		// // 	return (-1);
// 		// return (t2);
// 	}
// 	return (-1.0);
// }
