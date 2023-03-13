/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egauthey <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 18:51:04 by egauthey          #+#    #+#             */
/*   Updated: 2022/11/21 18:51:06 by egauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	create_thread(t_data *data)
{
	int	i;

	pthread_mutex_init(&data->lock, 0);
	data->fin = 0;
	data->thread_id = malloc(sizeof(pthread_t) * THREADS);
	i = 0;
	while (i < THREADS)
	{
		data->thread_i = i;
		pthread_create(&data->thread_id[i], NULL, render_thr, data);
		usleep(500);
		i++;
	}
	pthread_mutex_destroy(&data->lock);
	while (data->fin != 12)
	{
	}
	while (--i >= 0)
		pthread_join(data->thread_id[i], NULL);
	render_text(data);
	free(data->thread_id);
}

void	ambient_deep_copy(t_object *new_node, const t_object *list)
{
	new_node->u_data.ambiant.light_ratio = list->u_data.ambiant.light_ratio;
	new_node->u_data.ambiant.colors.x = list->u_data.ambiant.colors.x;
	new_node->u_data.ambiant.colors.y = list->u_data.ambiant.colors.y;
	new_node->u_data.ambiant.colors.z = list->u_data.ambiant.colors.z;
}

void	camera_deep_copy(t_object *new_node, const t_object *list)
{
	new_node->u_data.camera.pos.x = list->u_data.camera.pos.x;
	new_node->u_data.camera.pos.y = list->u_data.camera.pos.y;
	new_node->u_data.camera.pos.z = list->u_data.camera.pos.z;
	new_node->u_data.camera.orient.x = list->u_data.camera.orient.x;
	new_node->u_data.camera.orient.y = list->u_data.camera.orient.y;
	new_node->u_data.camera.orient.z = list->u_data.camera.orient.z;
	new_node->u_data.camera.up.x = list->u_data.camera.up.x;
	new_node->u_data.camera.up.y = list->u_data.camera.up.y;
	new_node->u_data.camera.up.z = list->u_data.camera.up.z;
	new_node->u_data.camera.right.x = list->u_data.camera.right.x;
	new_node->u_data.camera.right.y = list->u_data.camera.right.y;
	new_node->u_data.camera.right.z = list->u_data.camera.right.z;
	new_node->u_data.camera.fov = list->u_data.camera.fov;
}

t_object	*copy_obj_list_deep(const t_object *list)
{
	t_object	*new_node;

	new_node = malloc(sizeof(t_object));
	if (!new_node)
		return (NULL);
	new_node->type = list->type;
	new_node->next = NULL;
	if (list->next != NULL)
		new_node->next = copy_obj_list_deep(list->next);
	if (new_node->type == AMBIANT)
		ambient_deep_copy(new_node, list);
	else if (new_node->type == CAMERA)
		camera_deep_copy(new_node, list);
	else if (new_node->type == LIGHT)
		light_deep_copy(new_node, list);
	else if (new_node->type == SPHERE)
		sphere_deep_copy(new_node, list);
	else if (new_node->type == PLANE)
		plane_deep_copy(new_node, list);
	else if (new_node->type == CYLINDER)
		cylinder_deep_copy(new_node, list);
	else if (new_node->type == HYPERBOLOID)
		hyperboloid_deep_copy(new_node, list);
	return (new_node);
}

void	init_thread_data(t_data *th_d, t_data *d)
{
	init_minirt_data(th_d);
	th_d->chaos = copy_obj_list_deep(d->chaos);
	th_d->count.sp_count = d->count.sp_count;
	th_d->count.pl_count = d->count.pl_count;
	th_d->count.cy_count = d->count.cy_count;
	th_d->count.l_count = d->count.l_count;
	th_d->count.hy_count = d->count.hy_count;
	obj_array_create(th_d);
	initialise_viewport(th_d);
}

// if (list == NULL)
// 		return (NULL);
