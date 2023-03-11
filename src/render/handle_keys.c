/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lskraber <lskraber@student.42lausan>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:05:42 by lskraber          #+#    #+#             */
/*   Updated: 2023/03/11 14:51:21 by lskraber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include "../../includes/keys.h"


	// inst.orient = vec_unit(inst.orient);
	// if (!inst.orient.x && !inst.orient.z)
	// 	inst.up = vec_cross(inst.orient, (t_vec) {0, 0, 1});
	// else
	// 	inst.up = (t_vec) {0, 1, 0};
	// inst.up = vec_unit(inst.up);
	// inst.right = vec_cross(inst.orient, inst.up);
	// inst.right = vec_unit(inst.right);

void	handle_hyperboloids(int key, t_data *data)
{
	t_hyperboloid	*obj;

	obj = &data->objs[data->current]->u_data.hyperboloid;
	if (key == Q)
		obj->center.x += 1.0;
	else if (key == W)
		obj->center.y += 1.0;
	else if (key == E)
		obj->center.z += 1.0;
	else if (key == A)
		obj->center.x -= 1.0;
	else if (key == S)
		obj->center.y -= 1.0;
	else if (key == D)
		obj->center.z -= 1.0;
	else if (key == U && obj->orient.x <= 0.9)
		obj->orient.x += 0.1;
	else if (key == I && obj->orient.y <= 0.9)
		obj->orient.y += 0.1;
	else if (key == O && obj->orient.z <= 0.9)
		obj->orient.z += 0.1;
	else if (key == J && obj->orient.x >= -0.9)
		obj->orient.x -= 0.1;
	else if (key == K && obj->orient.y >= -0.9)
		obj->orient.y -= 0.1;
	else if (key == L && obj->orient.z >= -0.9)
		obj->orient.z -= 0.1;
	else if (key == N_SEVEN && obj->colors.x < 246)
		obj->colors.x += 10;
	else if (key == N_EIGHT &&obj->colors.y < 246)
		obj->colors.y += 10;
	else if (key == N_NINE && obj->colors.z < 246)
		obj->colors.z += 10;
	else if (key == N_FOUR && obj->colors.x > 9)
		obj->colors.x -= 10;
	else if (key == N_FIVE && obj->colors.y > 9)
		obj->colors.y -= 10;
	else if (key == N_SIX && obj->colors.z > 9)
		obj->colors.z -= 10;
}

void	handle_cylinders(int key, t_data *data)
{
	t_cylinder	*obj;

	obj = &data->objs[data->current]->u_data.cylinder;
	if (key == Q)
		obj->center.x += 1.0;
	else if (key == W)
		obj->center.y += 1.0;
	else if (key == E)
		obj->center.z += 1.0;
	else if (key == A)
		obj->center.x -= 1.0;
	else if (key == S)
		obj->center.y -= 1.0;
	else if (key == D)
		obj->center.z -= 1.0;
	else if (key == U && obj->orient.x <= 0.9)
		obj->orient.x += 0.1;
	else if (key == I && obj->orient.y <= 0.9)
		obj->orient.y += 0.1;
	else if (key == O && obj->orient.z <= 0.9)
		obj->orient.z += 0.1;
	else if (key == J && obj->orient.x >= -0.9)
		obj->orient.x -= 0.1;
	else if (key == K && obj->orient.y >= -0.9)
		obj->orient.y -= 0.1;
	else if (key == L && obj->orient.z >= -0.9)
		obj->orient.z -= 0.1;
	else if (key == N_SEVEN && obj->colors.x < 246)
		obj->colors.x += 10;
	else if (key == N_EIGHT &&obj->colors.y < 246)
		obj->colors.y += 10;
	else if (key == N_NINE && obj->colors.z < 246)
		obj->colors.z += 10;
	else if (key == N_FOUR && obj->colors.x > 9)
		obj->colors.x -= 10;
	else if (key == N_FIVE && obj->colors.y > 9)
		obj->colors.y -= 10;
	else if (key == N_SIX && obj->colors.z > 9)
		obj->colors.z -= 10;

	obj->orient = vec_unit(obj->orient);
}

void	handle_planes(int key, t_data *data)
{
	t_plane	*obj;

	obj = &data->objs[data->current]->u_data.plane;
	if (key == Q)
		obj->point.x += 1.0;
	else if (key == W)
		obj->point.y += 1.0;
	else if (key == E)
		obj->point.z += 1.0;
	else if (key == A)
		obj->point.x -= 1.0;
	else if (key == S)
		obj->point.y -= 1.0;
	else if (key == D)
		obj->point.z -= 1.0;
	else if (key == U && obj->orient.x <= 0.9)
		obj->orient.x += 0.1;
	else if (key == I && obj->orient.y <= 0.9)
		obj->orient.y += 0.1;
	else if (key == O && obj->orient.z <= 0.9)
		obj->orient.z += 0.1;
	else if (key == J && obj->orient.x >= -0.9)
		obj->orient.x -= 0.1;
	else if (key == K && obj->orient.y >= -0.9)
		obj->orient.y -= 0.1;
	else if (key == L && obj->orient.z >= -0.9)
		obj->orient.z -= 0.1;
	else if (key == N_SEVEN && obj->colors.x < 246)
		obj->colors.x += 10;
	else if (key == N_EIGHT &&obj->colors.y < 246)
		obj->colors.y += 10;
	else if (key == N_NINE && obj->colors.z < 246)
		obj->colors.z += 10;
	else if (key == N_FOUR && obj->colors.x > 9)
		obj->colors.x -= 10;
	else if (key == N_FIVE && obj->colors.y > 9)
		obj->colors.y -= 10;
	else if (key == N_SIX && obj->colors.z > 9)
		obj->colors.z -= 10;
}

void	handle_spheres(int key, t_data *data)
{
	t_sphere	*sphere;

	sphere = &data->objs[data->current]->u_data.sphere;
	if (key == Q)
		sphere->center.x += 5.0;
	else if (key == W)
		sphere->center.y += 5.0;
	else if (key == E)
		sphere->center.z += 5.0;
	else if (key == A)
		sphere->center.x -= 5.0;
	else if (key == S)
		sphere->center.y -= 5.0;
	else if (key == D)
		sphere->center.z -= 5.0;
	if (key == I)
		sphere->radius += 1.0;
	else if (key == K && sphere->radius >= 1.0)
		sphere->radius -= 1.0;
	else if (key == N_SEVEN && sphere->colors.x < 246)
		sphere->colors.x += 10;
	else if (key == N_EIGHT && sphere->colors.y < 246)
		sphere->colors.y += 10;
	else if (key == N_NINE && sphere->colors.z < 246)
		sphere->colors.z += 10;
	else if (key == N_FOUR && sphere->colors.x > 9)
		sphere->colors.x -= 10;
	else if (key == N_FIVE && sphere->colors.y > 9)
		sphere->colors.y -= 10;
	else if (key == N_SIX && sphere->colors.z > 9)
		sphere->colors.z -= 10;
}

void	handle_lights(int key, t_data *data)
{
	t_light *light;

	light = &data->objs[data->current]->u_data.light;
	if (key == Q)
		light->pos.x += 5.0;
	else if (key == W)
		light->pos.y += 5.0;
	else if (key == E)
		light->pos.z += 5.0;
	else if (key == A)
		light->pos.x -= 5.0;
	else if (key == S)
		light->pos.y -= 5.0;
	else if (key == D)
		light->pos.z -= 5.0;
	if (key == I && light->light_ratio <= 0.9)
		light->light_ratio += 0.1;
	else if (key == K && light->light_ratio >= 0.1)
		light->light_ratio -= 0.1;
	else if (key == N_SEVEN && light->colors.x < 246)
		light->colors.x += 10;
	else if (key == N_EIGHT && light->colors.y < 246)
		light->colors.y += 10;
	else if (key == N_NINE && light->colors.z < 246)
		light->colors.z += 10;
	else if (key == N_FOUR && light->colors.x > 9)
		light->colors.x -= 10;
	else if (key == N_FIVE && light->colors.y > 9)
		light->colors.y -= 10;
	else if (key == N_SIX && light->colors.z > 9)
		light->colors.z -= 10;
}

void	handle_camera(int key, t_data *data)
{
	//print txt;
	t_cam *cam;

	cam = &data->objs[1]->u_data.camera;
	if (key == Q)
		cam->pos.x += 1.0;
	else if (key == W)
		cam->pos.y += 1.0;
	else if (key == E)
		cam->pos.z += 1.0;
	else if (key == A)
		cam->pos.x -= 1.0;
	else if (key == S)
		cam->pos.y -= 1.0;
	else if (key == D)
		cam->pos.z -= 1.0;
	else if (key == U && cam->orient.x <= 0.9)
		cam->orient.x += 0.1;
	else if (key == I && cam->orient.y <= 0.9)
		cam->orient.y += 0.1;
	else if (key == O && cam->orient.z <= 0.9)
		cam->orient.z += 0.1;
	else if (key == J && cam->orient.x >= -0.9)
		cam->orient.x -= 0.1;
	else if (key == K && cam->orient.y >= -0.9)
		cam->orient.y -= 0.1;
	else if (key == L && cam->orient.z >= -0.9)
		cam->orient.z -= 0.1;
	else if (key == P && cam->fov <= 170)
		cam->fov += 10;
	else if (key == POINT_COMMA && cam->fov >= 10)
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
	if (key == I && ambient->light_ratio <= 0.9)
		ambient->light_ratio += 0.1;
	else if (key == K && ambient->light_ratio >= 0.1)
		ambient->light_ratio -= 0.1;
	else if (key == N_SEVEN && ambient->colors.x < 246)
		ambient->colors.x += 10;
	else if (key == N_EIGHT && ambient->colors.y < 246)
		ambient->colors.y += 10;
	else if (key == N_NINE && ambient->colors.z < 246)
		ambient->colors.z += 10;
	else if (key == N_FOUR && ambient->colors.x > 9)
		ambient->colors.x -= 10;
	else if (key == N_FIVE && ambient->colors.y > 9)
		ambient->colors.y -= 10;
	else if (key == N_SIX && ambient->colors.z > 9)
		ambient->colors.z -= 10;
}


int	event_handler(int key, t_data *data)
{
	(void) data;
	if (key == 53)
	{
		free (data->objs);
		free_obj_list(data->chaos);
		free(data->vp);
		exit(0);
	}
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
	else if (data->current < 2 + data->count.l_count + data->count.sp_count + data->count.pl_count + data->count.cy_count)
		handle_cylinders(key, data);
	else if (data->current < 2 + data->count.l_count + data->count.sp_count + data->count.pl_count + data->count.cy_count + data->count.hy_count)
		handle_hyperboloids(key, data);
	//render(data);
	create_thread(data);
	return (0);
}
