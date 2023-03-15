/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tutorial2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lskraber <lskraber@student.42lausan>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:05:42 by lskraber          #+#    #+#             */
/*   Updated: 2023/03/12 14:08:22 by lskraber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	sphere_text(t_data *data)
{
	char	str[32];

	if (data->changed)
	{
		printf("\nYou are on a sphere.\nUse I to increase radius,");
		printf(" K to decrease.\n Q W E to increase coords components");
		printf("\nA S D to decrease them\n7 8 9 to");
		printf(" increase colors components\n4 5 6 to decrease them\n\n");
	}
	mlx_string_put(data->mlx, data->win, WIDTH / 2 - WIDTH / 30,
		HEIGHT - HEIGHT / 19, 0xFFFFFF, "You are on a sphere");
	mlx_string_put(data->mlx, data->win, WIDTH / 2 + 20 - WIDTH / 20 - 80,
		HEIGHT - HEIGHT / 30, 0xFFFFFF, "sphere center coords : ");
	mlx_string_put(data->mlx, data->win, WIDTH / 2 + 10, HEIGHT - HEIGHT / 30,
		0xFFFFFF, fts(data->objs[data->current]->u_data.sphere.center.x, str));
	mlx_string_put(data->mlx, data->win, WIDTH / 2 + 60, HEIGHT - HEIGHT / 30,
		0xFFFFFF, fts(data->objs[data->current]->u_data.sphere.center.y, str));
	mlx_string_put(data->mlx, data->win, WIDTH / 2 + 110, HEIGHT - HEIGHT / 30,
		0xFFFFFF, fts(data->objs[data->current]->u_data.sphere.center.z, str));
	mlx_string_put(data->mlx, data->win, WIDTH / 2 - 70, HEIGHT - HEIGHT / 55,
		0xFFFFFF, "sphere radius : ");
	mlx_string_put(data->mlx, data->win, WIDTH / 2 + 50, HEIGHT - HEIGHT / 55,
		0xFFFFFF, fts(data->objs[data->current]->u_data.sphere.radius, str));
}

void	plane_text_p2(t_data *data, char *str)
{
	mlx_string_put(data->mlx, data->win, WIDTH / 2 + 60, HEIGHT - HEIGHT / 30,
		0xFFFFFF, fts(data->objs[data->current]->u_data.plane.point.y, str));
	mlx_string_put(data->mlx, data->win, WIDTH / 2 + 110, HEIGHT - HEIGHT / 30,
		0xFFFFFF, fts(data->objs[data->current]->u_data.plane.point.z, str));
	mlx_string_put(data->mlx, data->win, WIDTH / 2 - 140, HEIGHT - HEIGHT / 55,
		0xFFFFFF, "plane orientation : ");
	mlx_string_put(data->mlx, data->win, WIDTH / 2, HEIGHT - HEIGHT / 55,
		0xFFFFFF, fts(data->objs[data->current]->u_data.plane.orient.x, str));
	mlx_string_put(data->mlx, data->win, WIDTH / 2 + 50, HEIGHT - HEIGHT / 55,
		0xFFFFFF, fts(data->objs[data->current]->u_data.plane.orient.y, str));
	mlx_string_put(data->mlx, data->win, WIDTH / 2 + 100, HEIGHT - HEIGHT / 55,
		0xFFFFFF, fts(data->objs[data->current]->u_data.plane.orient.z, str));
}

void	plane_text(t_data *data)
{
	char	str[32];

	if (data->changed)
	{
		printf("\nYou are on a plane.\nUse W E to increase coords components\n");
		printf("A S D to decrease them.\n");
		printf("U I O and J K L to change the orientation");
		printf("\n7 8 9 to increase colors components\n4 5 6 to decrease them\n\n");
	}
	mlx_string_put(data->mlx, data->win, WIDTH / 2 - WIDTH / 30,
		HEIGHT - HEIGHT / 19, 0xFFFFFF, "You are on a plane");
	mlx_string_put(data->mlx, data->win, WIDTH / 2 + 20 - WIDTH / 20 - 80,
		HEIGHT - HEIGHT / 30, 0xFFFFFF, "plane center coords : ");
	mlx_string_put(data->mlx, data->win, WIDTH / 2 + 10, HEIGHT - HEIGHT / 30,
		0xFFFFFF, fts(data->objs[data->current]->u_data.plane.point.x, str));
	plane_text_p2(data, str);
}

void	hyperboloid_text_p2(t_data *data, char *str)
{
	mlx_string_put(data->mlx, data->win, WIDTH / 2 + 110, HEIGHT - HEIGHT / 30,
		0xFFFFFF, fts(data->objs[data->current]->u_data.plane.point.z, str));
	mlx_string_put(data->mlx, data->win, WIDTH / 2 - 140, HEIGHT - HEIGHT / 55,
		0xFFFFFF, "cone orientation : ");
	mlx_string_put(data->mlx, data->win, WIDTH / 2, HEIGHT - HEIGHT / 55,
		0xFFFFFF, fts(data->objs[data->current]->u_data.plane.orient.x, str));
	mlx_string_put(data->mlx, data->win, WIDTH / 2 + 50, HEIGHT - HEIGHT / 55,
		0xFFFFFF, fts(data->objs[data->current]->u_data.plane.orient.y, str));
	mlx_string_put(data->mlx, data->win, WIDTH / 2 + 100, HEIGHT - HEIGHT / 55,
		0xFFFFFF, fts(data->objs[data->current]->u_data.plane.orient.z, str));
	mlx_string_put(data->mlx, data->win, WIDTH / 2 - WIDTH / 30,
		HEIGHT - HEIGHT / 19, 0xFFFFFF, "You are on a cone");
}

void	hyperboloid_text(t_data *data)
{
	char	str[32];

	if (data->changed)
	{
		printf("\nYou are on a cone.\nUse W E to increase coords components\n");
		printf("A S D to decrease them.\n");
		printf("U I O and J K L to change the orientation\n");
		printf("7 8 9 to increase colors components\n4 5 6 to decrease them\n\n");
	}
	mlx_string_put(data->mlx, data->win, WIDTH / 2 - WIDTH / 30,
		HEIGHT - HEIGHT / 19, 0xFFFFFF, "You are on a cone");
	mlx_string_put(data->mlx, data->win, WIDTH / 2 + 20 - WIDTH / 20 - 80,
		HEIGHT - HEIGHT / 30, 0xFFFFFF, "cone center coords : ");
	mlx_string_put(data->mlx, data->win, WIDTH / 2 + 10, HEIGHT - HEIGHT / 30,
		0xFFFFFF, fts(data->objs[data->current]->u_data.plane.point.x, str));
	mlx_string_put(data->mlx, data->win, WIDTH / 2 + 60, HEIGHT - HEIGHT / 30,
		0xFFFFFF, fts(data->objs[data->current]->u_data.plane.point.y, str));
	hyperboloid_text_p2(data, str);
}
