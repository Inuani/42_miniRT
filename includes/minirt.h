/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lskraber <lskraber@student.42lausan>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:13:13 by egauthey          #+#    #+#             */
/*   Updated: 2023/03/08 20:43:27 by lskraber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../libs/libft/libft.h"
# include "../libs/mlx/mlx.h"

# include "struct.h"
# include "parsing.h"
# include "shape.h"

# include <stdio.h>
# include <fcntl.h> // functions for working with file descriptors, opening and manipulating files
# include <math.h>
# include <pthread.h>
# include <sys/errno.h>

//nbr of threads, 24?

# define THREADS 12
# define HEIGHT 1080
# define WIDTH 1920
# define K 0.8


//light
void	phong(t_data *data, t_ray *ray, t_light light, t_vec obj_color);
float	light_hit_objs(t_data *data, t_ray *ray, t_vec point_at, t_light light);
void	light_hit(t_ray *ray, t_data *data, t_sphere sphere, t_light light);

//color
t_vec	decimalToRGB(int color);
int		create_trgb(int t, int r, int g, int b);
t_vec	add_color(t_vec c1, t_vec c2);
t_vec	add_colors(t_vec c1, t_vec c2, float intensity);

//utility
float	map2(float x, float min, float input_min);
float	map(float x);
int		get_angle(t_vec normal, t_vec ray_l);

//render text-tutorial
void render_text(t_data *data);

// rand
// int		fast_rand(int seed);
// float	rand_double(int seed);


// handle window && image
void	render(t_data *data);
void	init_window(t_data *data);
int		close_win(void);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
void	init_image(t_data *data, int width, int height, t_img *img);
int		close_win(void);

// handle keys
int		event_handler(int key, t_data *data);

// ray
int		ray_color(t_ray *ray, t_data *data);
void	hit_objs(t_data *data, t_ray *ray);
t_ray	create_ray(t_cam *cam, t_viewport *vp, float u, float v);
int		is_first(t_vec r_point_at, t_cam cam, t_vec *point_at, int *first);
//shape
void	is_sphere(t_data *data, t_ray *ray, t_vec *point_at, int i);
void	is_plane(t_data *data, t_ray *ray, t_vec *point_at, int i);
void	is_cylinder(t_data *data, t_ray *ray, t_vec *point_at, int i);
//shadow
int shadow_sphere(t_data *data, int i, t_vec point_at, t_light light);
int shadow_plane(t_data *data, int i, t_light light);
int	shadow_cylinder(t_data *data, int i, t_vec point_at, t_light light);
int	is_first_light(t_light light, t_vec point_at, t_vec root_at);
int	is_light_plane(t_light light, t_data *data, t_plane plane);

// vector utils
t_vec	vec_add(t_vec vec1, t_vec vec2);
t_vec	vec_subs(t_vec vec1, t_vec vec2);
t_vec	vec_mult(t_vec vec1, t_vec vec2);
t_vec	vec_scale(float nbr, t_vec vec2);
float	vec_dot(t_vec vec1, t_vec vec2);
t_vec	vec_cross(t_vec vec1, t_vec vec2);
float	vec_len(t_vec vec);
t_vec	vec_unit(t_vec vec);
t_vec	vec_div_float(t_vec vec, float nb);
void	vec_equal(t_vec *vec1, t_vec *vec2);


//threads
t_object	*copy_obj_list_deep(const t_object *list);
void		init_thread_data(t_data *th_d, t_data *d);
void		create_thread(t_data *data);
void		*render_thr(void *data);

//debug
int		print_key(int key, t_data *data);
void	printf_vec(t_vec vec);
void	print_new_list(t_data *d);

#endif