/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lskraber <lskraber@student.42lausan>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:05:42 by lskraber          #+#    #+#             */
/*   Updated: 2023/03/06 13:34:23 by lskraber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"


int	print_key(int key, t_data *data)
{
	(void)data;
	printf("key : %i\n", key);
	return (0);
}

	// inst.orient = vec_unit(inst.orient);
	// if (!inst.orient.x && !inst.orient.z)
	// 	inst.up = vec_cross(inst.orient, (t_vec) {0, 0, 1});
	// else
	// 	inst.up = (t_vec) {0, 1, 0};
	// inst.up = vec_unit(inst.up);
	// inst.right = vec_cross(inst.orient, inst.up);
	// inst.right = vec_unit(inst.right);

void	handle_planes(int key, t_data *data)
{
	t_plane	*plane;

	plane = &data->objs[data->current]->u_data.plane;
	if (key == 12)
		plane->point.x += 1.0;
	else if (key == 13)
		plane->point.y += 1.0;
	else if (key == 14)
		plane->point.z += 1.0;
	else if (key == 0)
		plane->point.x -= 1.0;
	else if (key == 1)
		plane->point.y -= 1.0;
	else if (key == 2)
		plane->point.z -= 1.0;
	else if (key == 32 && plane->orient.x <= 0.9)
		plane->orient.x += 0.1;
	else if (key == 34 && plane->orient.y <= 0.9)
		plane->orient.y += 0.1;
	else if (key == 31 && plane->orient.z <= 0.9)
		plane->orient.z += 0.1;
	else if (key == 38 && plane->orient.x >= -0.9)
		plane->orient.x -= 0.1;
	else if (key == 40 && plane->orient.y >= -0.9)
		plane->orient.y -= 0.1;
	else if (key == 37 && plane->orient.z >= -0.9)
		plane->orient.z -= 0.1;
	else if (key == 89 && plane->colors.x < 246)
		plane->colors.x += 10;
	else if (key == 91 &&plane->colors.y < 246)
		plane->colors.y += 10;
	else if (key == 92 && plane->colors.z < 246)
		plane->colors.z += 10;
	else if (key == 86 && plane->colors.x > 9)
		plane->colors.x -= 10;
	else if (key == 87 && plane->colors.y > 9)
		plane->colors.y -= 10;
	else if (key == 88 && plane->colors.z > 9)
		plane->colors.z -= 10;
}

void	handle_spheres(int key, t_data *data)
{
	t_sphere	*sphere;

	sphere = &data->objs[data->current]->u_data.sphere;
	if (key == 12)
		sphere->center.x += 5.0;
	else if (key == 13)
		sphere->center.y += 5.0;
	else if (key == 14)
		sphere->center.z += 5.0;
	else if (key == 0)
		sphere->center.x -= 5.0;
	else if (key == 1)
		sphere->center.y -= 5.0;
	else if (key == 2)
		sphere->center.z -= 5.0;
	if (key == 34)
		sphere->radius += 1.0;
	else if (key == 40 && sphere->radius >= 1.0)
		sphere->radius -= 1.0;
	else if (key == 89 && sphere->colors.x < 246)
		sphere->colors.x += 10;
	else if (key == 91 && sphere->colors.y < 246)
		sphere->colors.y += 10;
	else if (key == 92 && sphere->colors.z < 246)
		sphere->colors.z += 10;
	else if (key == 86 && sphere->colors.x > 9)
		sphere->colors.x -= 10;
	else if (key == 87 && sphere->colors.y > 9)
		sphere->colors.y -= 10;
	else if (key == 88 && sphere->colors.z > 9)
		sphere->colors.z -= 10;
}

void	handle_lights(int key, t_data *data)
{
	t_light *light;

	light = &data->objs[data->current]->u_data.light;
	if (key == 12)
		light->pos.x += 5.0;
	else if (key == 13)
		light->pos.y += 5.0;
	else if (key == 14)
		light->pos.z += 5.0;
	else if (key == 0)
		light->pos.x -= 5.0;
	else if (key == 1)
		light->pos.y -= 5.0;
	else if (key == 2)
		light->pos.z -= 5.0;
	if (key == 34 && light->light_ratio <= 0.9)
		light->light_ratio += 0.1;
	else if (key == 40 && light->light_ratio >= 0.1)
		light->light_ratio -= 0.1;
	else if (key == 89 && light->colors.x < 246)
		light->colors.x += 10;
	else if (key == 91 && light->colors.y < 246)
		light->colors.y += 10;
	else if (key == 92 && light->colors.z < 246)
		light->colors.z += 10;
	else if (key == 86 && light->colors.x > 9)
		light->colors.x -= 10;
	else if (key == 87 && light->colors.y > 9)
		light->colors.y -= 10;
	else if (key == 88 && light->colors.z > 9)
		light->colors.z -= 10;
}

void	handle_camera(int key, t_data *data)
{
	//print txt;
	t_cam *cam;

	cam = &data->objs[1]->u_data.camera;
	if (key == 12)
		cam->pos.x += 1.0;
	else if (key == 13)
		cam->pos.y += 1.0;
	else if (key == 14)
		cam->pos.z += 1.0;
	else if (key == 0)
		cam->pos.x -= 1.0;
	else if (key == 1)
		cam->pos.y -= 1.0;
	else if (key == 2)
		cam->pos.z -= 1.0;
	else if (key == 32 && cam->orient.x <= 0.9)
		cam->orient.x += 0.1;
	else if (key == 34 && cam->orient.y <= 0.9)
		cam->orient.y += 0.1;
	else if (key == 31 && cam->orient.z <= 0.9)
		cam->orient.z += 0.1;
	else if (key == 38 && cam->orient.x >= -0.9)
		cam->orient.x -= 0.1;
	else if (key == 40 && cam->orient.y >= -0.9)
		cam->orient.y -= 0.1;
	else if (key == 37 && cam->orient.z >= -0.9)
		cam->orient.z -= 0.1;
	else if (key == 35 && cam->fov <= 170)
		cam->fov += 10;
	else if (key == 41 && cam->fov >= 10)
		cam->fov -= 10;

	cam->orient = vec_unit(cam->orient);
	if (!cam->orient.x && !cam->orient.z)	//problem here
		cam->up = vec_cross(cam->orient, (t_vec) {0, 0, 1});
	else
		cam->up = (t_vec) {0, 1, 0};
	cam->up = vec_unit(cam->up);
	cam->right = vec_cross(cam->orient, cam->up);
	cam->right = vec_unit(cam->right);

	data->vp->viewp_wdt = tan(cam->fov / 2 * M_PI / 180.0) * 2;
	data->vp->viewp_hgt = data->vp->viewp_wdt / (data->vp->aspect_ratio);

}

void	handle_ambient(int key, t_data *data)
{

	t_ambiant *ambient;

	ambient = &data->objs[0]->u_data.ambiant;
	if (key == 34 && ambient->light_ratio <= 0.9)
		ambient->light_ratio += 0.1;
	else if (key == 40 && ambient->light_ratio >= 0.1)
		ambient->light_ratio -= 0.1;
	else if (key == 89 && ambient->colors.x < 246)
		ambient->colors.x += 10;
	else if (key == 91 && ambient->colors.y < 246)
		ambient->colors.y += 10;
	else if (key == 92 && ambient->colors.z < 246)
		ambient->colors.z += 10;
	else if (key == 86 && ambient->colors.x > 9)
		ambient->colors.x -= 10;
	else if (key == 87 && ambient->colors.y > 9)
		ambient->colors.y -= 10;
	else if (key == 88 && ambient->colors.z > 9)
		ambient->colors.z -= 10;
}


int	event_handler(int key, t_data *data)
{
	(void) data;
	if (key == 53)
		exit(0);
	else if (key == 123) //maybe wrong
	{
		if (data -> current == 0)
			data->current = data->count.total - 1;
		else
			data->current--;
		data->changed = 1;
	}
	else if (key == 124) //maybe wrong
	{
		if (data -> current == data->count.total - 1)
			data->current = 0;
		else
			data->current++;
		data->changed = 1;
	}
	if (data->current == 0)
		handle_ambient(key, data);
	else if (data->current == 1)
		handle_camera(key, data);
	else if (data->current < 2 + data->count.l_count)
		handle_lights(key, data);
	else if (data->current < 2 + data->count.l_count + data->count.sp_count)
		handle_spheres(key, data);
	else if (data->current < 2 + data->count.l_count + data->count.sp_count + data->count.pl_count)
		handle_planes(key, data);
	/*else
		handle_cylinder(key, data);*/
	//render(data);
	render_thr(data);
	return (0);
}
