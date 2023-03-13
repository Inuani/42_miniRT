/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hyp_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lskraber <lskraber@student.42lausan>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:05:42 by lskraber          #+#    #+#             */
/*   Updated: 2023/03/13 18:18:53 by lskraber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	get_u_v_hy(t_hyperboloid *hy, t_ray *ray, float *u, float *v)
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

int	get_color_pixel(t_data *d, int x, int y, t_img *xpm)
{
	int	pixel_color;
	int	pixel_offset;

	(void)d;
	pixel_offset = (y * xpm->line_length) + (x * (xpm->bits_per_pixel / 8));
	pixel_color = mlx_get_color_value(d->mlx,
			*(int *)(xpm->addr + pixel_offset));
	return (pixel_color);
}

// t_vec get_x_y_color_hy(t_data *d, t_hyperboloid *hy, float u, float v)
// {
// 	int	x;
// 	int	y;

// 	x = u * hy->xpm.wdth;
// 	y = (1 - v) * hy->xpm.hgt;
// 	return (decimal_to_rgb(get_color_pixel(d, x, y, &hy->xpm)));
// }

t_vec	get_x_y_color_hy(t_data *d, t_hyperboloid *hy, float u, float v)
{
	int	x;
	int	y;

	(void)d;
	x = u * hy->xpm.wdth;
	y = (1 - v) * hy->xpm.hgt;
	if ((y * hy->xpm.wdth + x) > hy->xpm.wdth * hy->xpm.hgt)
	{
		x = hy->xpm.wdth - 1;
		y = hy->xpm.hgt - 1;
	}
	return (decimal_to_rgb(hy->pix_arr[y * hy->xpm.wdth + x]));
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

t_vec	calculate_x_y_hcb(t_ray *ray, t_hyperboloid *cyl)
{
	float	u;
	float	v;

	u = get_angle_0_to_1(vec_unit(ray->point_at), (t_vec){1, 0, 0});
	if (ray->point_at.y < 0)
		ray->point_at.y *= -1;
	v = fmod(ray->point_at.y, 1);
	if (!((u + v) < 0.5 || ((u + v) > 1 && (u + v) < 1.5)))
		return ((t_vec){255, 255, 255});
	return ((t_vec) cyl->colors);
}
