/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lskraber <lskraber@student.42lausan>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:13:13 by egauthey          #+#    #+#             */
/*   Updated: 2023/02/24 17:11:51 by lskraber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../libs/libft/libft.h"
# include "../libs/mlx/mlx.h"

# include "stdio.h" //temporarily
# include <fcntl.h> // functions for working with file descriptors, opening and manipulating files
# include <math.h>

# define HEIGHT 1080
# define WIDTH 1920

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_vec
{
	float	x;
	float	y;
	float	z;
}				t_vec;

typedef struct s_sphere {
	t_vec	center;
	float	radius;
	t_vec	colors;
}				t_sphere;

typedef struct s_viewport
{
	float	viewp_hgt;
	float	viewp_wdt;
	float	focal_len;
	float	aspect_ratio;
}				t_viewport;

typedef struct s_cam
{
	t_vec	coords;
	t_vec	orientation;
	t_vec	up;
	t_vec	right;
	float	fov;
}				t_cam;

typedef struct s_ray {
	t_vec	direction;
	t_vec	ray;
}				t_ray;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	t_img		img;
	t_viewport	*vp;
	void	**objs;
}				t_data;

void	printf_vec(t_vec vec);

//init objs
void	initialise_objs(t_data *data, int num);

//sphere
float		sphere_hits(void **objs, t_ray *ray);
t_sphere	*create_sphere(t_vec center, float diameter, t_vec colors);

//render frames
void	render(t_data *data);

//handle window && image
void	init_window(t_data *data);
int		close_win(void);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);

//handle keys
int		event_handler(int key, t_data *data);

//return trgb color
int		create_trgb(int t, int r, int g, int b);

//ray
int		ray_color();
t_ray	create_ray(t_cam *cam, t_viewport *vp, float u, float v);

//vector utils
t_vec	vec_div(t_vec vec1, t_vec vec2);
t_vec	vec_add(t_vec vec1, t_vec vec2);
t_vec	vec_subs(t_vec vec1, t_vec vec2);
t_vec	vec_mult(t_vec vec1, t_vec vec2);
t_vec	vec_scale(float nbr, t_vec vec2);
float	vec_dot(t_vec vec1, t_vec vec2);
t_vec	vec_cross(t_vec vec1, t_vec vec2);
float	vec_len(t_vec vec);
t_vec	vec_unit(t_vec vec);

// void		close_win(void);
int		close_win(void);

//handle keys
int	event_handler(int key, t_data *data);


#endif

// //vector utils with pointeur
// t_vec	vec_div(t_vec *vec1, t_vec *vec2);
// t_vec	vec_add(t_vec *vec1, t_vec *vec2);
// t_vec	vec_subs(t_vec *vec1, t_vec *vec2);
// t_vec	vec_mult(t_vec *vec1, t_vec *vec2);
// t_vec	vec_scale(float nbr, t_vec *vec2);
// float	vec_dot(t_vec *vec1, t_vec *vec2);
// t_vec	vec_cross(t_vec *vec1, t_vec *vec2);
// float	vec_len(t_vec *vec);
// t_vec	vec_unit(t_vec *vec);
