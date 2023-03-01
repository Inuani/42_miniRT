/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lskraber <lskraber@student.42lausan>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:13:13 by egauthey          #+#    #+#             */
/*   Updated: 2023/03/01 13:12:29 by lskraber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../libs/libft/libft.h"
# include "../libs/mlx/mlx.h"

# include "struct.h"
# include "parsing.h"
# include "object_type.h"

# include <stdio.h> //temporarily
# include <fcntl.h> // functions for working with file descriptors, opening and manipulating files
# include <math.h>
# include <pthread.h>
# include <sys/errno.h>

//nbr of threads, 24?


# define HEIGHT 1080
# define WIDTH 1920

float	light_hit_objs(t_data *data, t_ray *ray, t_vec point_at);
int	get_angle(t_vec normal, t_vec ray_l);
int	light_hit(t_ray *ray, t_data *data, t_sphere sphere);
float	hit_objs(t_data *data, t_ray *ray, t_vec *colors);

void	printf_vec(t_vec vec);

//rand
int		fast_rand(int seed);
float	rand_double(int seed);

//init objs
void	initialise_viewport(t_data *data);

//plane
int	plane_life(t_data *data, t_ray *ray, t_plane plane);
int	plane_hit(t_plane *plane, t_vec ray_origine, t_vec ray_direction);

//sphere
float		it_hit_sphere(t_data *data, t_ray *ray, t_sphere sphere);
float		sphere_hits(t_vec vector, t_vec v, t_sphere sphere);

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


/*TODO LIST:

	BUG: CHANGER LA CAMERA DE DIRECTION; - kinda fixed

	PARSING :D
	FUNC HP PLUS PROCHE DE CAMERA / LUMIERES;
	AUTRES OBJETS : PLAN / CYLINDRE;
	LIGHTS :D

	DEPLACEMENTS;

	(threads, antialising, reflection etc...)
*/