/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lskraber <lskraber@student.42lausan>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:13:13 by egauthey          #+#    #+#             */
/*   Updated: 2023/03/07 15:44:28 by lskraber         ###   ########.fr       */
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

# define THREADS 12
# define HEIGHT 1080
# define WIDTH 1920
# define K 0.8

float	it_hit_hy(t_data *data, t_ray *ray, t_hyperboloid hp);
float	hit_hyperboloid(t_vec vector, t_hyperboloid hyperboloid, t_vec origin);
void	init_image(t_data *data, int width, int height, t_img *img);
int	is_inside(t_sphere sphere, t_cam camera, t_light light);
void	create_thread(t_data *data);
void	phong(t_data *data, t_ray *ray, t_light light, t_vec obj_color);
t_vec	add_color(t_vec c1, t_vec c2);
t_vec	add_colors(t_vec c1, t_vec c2, float intensity);
int		is_first(t_vec r_point_at, t_cam cam, t_vec *point_at, int *first);
float	map2(float x, float min, float input_min);
float	map(float x);
int		print_key(int key, t_data *data);
float	light_hit_objs(t_data *data, t_ray *ray, t_vec point_at, t_light light);
int		get_angle(t_vec normal, t_vec ray_l);
void	light_hit(t_ray *ray, t_data *data, t_sphere sphere, t_light light);
void	hit_objs(t_data *data, t_ray *ray);

void	printf_vec(t_vec vec);

//rand
int		fast_rand(int seed);
float	rand_double(int seed);

//init objs
void	initialise_viewport(t_data *data);
void	cylinder_init(t_data *d, t_cylinder *cyl);

//plane
void	plane_life(t_data *data, t_ray *ray, t_plane plane);
float	plane_hit(t_plane *plane, t_vec ray_origine, t_vec ray_direction);

//sphere
float		it_hit_sphere(t_data *data, t_ray *ray, t_sphere sphere);
float		sphere_hits(t_vec vector, t_vec v, t_sphere sphere);

//cylinder
float	cylinder_eman(t_data *data, t_ray *ray, t_cylinder cyl);
float	hit_cylinder(t_vec ray_dir, t_cylinder cyl, t_vec origin);
float	hit_cylinder_light(t_vec ray_dir, t_cylinder cyl, t_vec origin, t_vec l2cyl);

//render frames
void	render(t_data *data);
void	*render_thr(void *data);

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
t_vec	vec_div_float(t_vec vec, float nb);

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