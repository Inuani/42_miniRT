/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lskraber <lskraber@student.42lausan>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:05:42 by lskraber          #+#    #+#             */
/*   Updated: 2023/03/11 18:34:27 by lskraber         ###   ########.fr       */
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

void	handle_lights_p2(int key, t_light *light)
{
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
	else
		handle_lights_p2(key, light);
}

void	handle_camera_p2(int key, t_data *data, t_cam *cam)
{
	if (key == O && cam->orient.z <= 0.9)
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

void	handle_camera(int key, t_data *data)
{
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
	else
		handle_camera_p2(key, data, cam);

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
