/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lskraber <lskraber@student.42lausan>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:05:42 by lskraber          #+#    #+#             */
/*   Updated: 2023/03/12 14:08:22 by lskraber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	calculate_x_y_sp(t_img *xpm, t_ray *ray, int *x, int *y)
{
	float	u;
	float	v;

	u = get_angle_0_to_1(vec_unit(ray->normal), (t_vec){1, 0, 0});
	v = get_angle_0_to_1(vec_unit(ray->normal), (t_vec){0, 1, 0});
	*x = u * (xpm->wdth - 1);
	*y = (1 - v) * (xpm->hgt - 1);
}

t_vec	get_sp_xpm_color(t_ray *ray, t_sphere *sp)
{
	t_vec	pixel_color;
	int		x;
	int		y;

	calculate_x_y_sp(&sp->xpm, ray, &x, &y);
	pixel_color = decimal_to_rgb(sp->pix_arr[y * sp->xpm.wdth + x]);
	return (pixel_color);
}

t_vec	calculate_x_y_scb(t_ray *ray, t_sphere *sphere)
{
	float	u;
	float	v;

	u = get_angle_0_to_1(vec_unit(ray->normal), (t_vec){1, 0, 0});
	v = get_angle_0_to_1(vec_unit(ray->normal), (t_vec){0, 1, 0});
	u = u * CB_W;
	v = v * CB_H;
	if (((int)u + (int)v) % 2 == 0)
		return ((t_vec){255, 255, 255});
	return (sphere->colors);
}
