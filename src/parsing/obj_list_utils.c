/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_list_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egauthey <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 18:51:04 by egauthey          #+#    #+#             */
/*   Updated: 2022/11/21 18:51:06 by egauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_object	*create_object(t_type type, void *data)
{
	t_object	*new;

	new = malloc(sizeof(t_object));
	if (!new)
		return (NULL);
	new->type = type;
	if (type == AMBIANT)
		new->u_data.ambiant = *(t_ambiant *)data;
	else if (type == CAMERA)
		new->u_data.camera = *(t_cam *)data;
	else if (type == LIGHT)
		new->u_data.light = *(t_light *)data;
	else if (type == SPHERE)
		new->u_data.sphere = *(t_sphere *)data;
	else if (type == PLANE)
		new->u_data.plane = *(t_plane *)data;
	else if (type == CYLINDER)
		new->u_data.cylinder = *(t_cylinder *)data;
	else if (type == HYPERBOLOID)
		new->u_data.hyperboloid = *(t_hyperboloid *)data;
	new->next = NULL;
	return (new);
}

void	add_object_to_list(t_object **lst, t_object *new)
{
	t_object	*last;

	last = get_last_object(*lst);
	if (last == NULL)
		*lst = new;
	else
		last->next = new;
}

t_object	*get_last_object(t_object *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	free_obj_list(t_object *chaos)
{
	t_object	*tmp;

	while (chaos)
	{
		if (chaos->next != NULL)
			tmp = chaos->next;
		else
			tmp = NULL;
		free(chaos);
		chaos = NULL;
		if (tmp != NULL)
			chaos = tmp;
	}
}

void	free_array_xpm(t_object *chaos)
{
	t_object	*tmp;

	tmp = chaos;
	while (tmp)
	{
		if (tmp->type == SPHERE && tmp->u_data.sphere.pix_arr != NULL)
			free(tmp->u_data.sphere.pix_arr);
		else if (tmp->type == PLANE && tmp->u_data.plane.pix_arr != NULL)
			free(tmp->u_data.plane.pix_arr);
		else if (tmp->type == CYLINDER && tmp->u_data.cylinder.pix_arr != NULL)
			free(tmp->u_data.cylinder.pix_arr);
		else if (tmp->type == HYPERBOLOID
			&& tmp->u_data.hyperboloid.pix_arr != NULL)
			free(tmp->u_data.hyperboloid.pix_arr);
		tmp = tmp->next;
	}
}
