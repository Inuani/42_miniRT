/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angle_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egauthey <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 18:51:04 by egauthey          #+#    #+#             */
/*   Updated: 2022/11/21 18:51:06 by egauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

float	get_angle_0_to_1(t_vec normal, t_vec obj)
{
	float	dot;
	float	angle;

	dot = vec_dot(normal, obj);
	angle = acos(dot);
	return (angle / (M_PI));
}

int	get_angle_degree(t_vec normal, t_vec ray_l)
{
	float	dot;
	float	magnitude_n;
	float	magnitude_l;
	float	angle;

	dot = vec_dot(normal, ray_l);
	magnitude_n = vec_len(normal);
	magnitude_l = vec_len(ray_l);
	angle = acos(dot / (magnitude_n * magnitude_l));
	return (angle * 180.0 / M_PI);
}
