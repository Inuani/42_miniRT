/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lskraber <lskraber@student.42lausan>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:13:13 by egauthey          #+#    #+#             */
/*   Updated: 2023/02/22 20:47:19 by lskraber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../libs/libft/libft.h"
# include "../libs/mlx/mlx.h"


# include <fcntl.h> // functions for working with file descriptors, opening and manipulating file
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

typedef struct s_cam
{
	t_vec	coords;
	t_vec	orientation;
	int	fov;
}				t_cam;

typedef struct s_ray {
	t_vec	origin;
	t_vec	direction;
}				t_ray;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	t_img	img;
	void	**objs;
}				t_data;


//init objs
void	initialise_objs(t_data *data, int num);

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
t_ray	create_ray(t_cam *cam);

//vector utils
t_vec	vec_add(t_vec *vec1, t_vec *vec2);
t_vec	vec_subs(t_vec *vec1, t_vec *vec2);
t_vec	vec_mult(t_vec *vec1, t_vec *vec2);
t_vec	vec_scale(float nbr, t_vec *vec2);
float	vec_dot(t_vec vec1, t_vec vec2);
t_vec	vec_cross(t_vec vec1, t_vec vec2);
float	vec_norm(t_vec vec);
t_vec	vec_unit(t_vec vec);



// void		close_win(void);
int		close_win(void);

//handle keys
// void	event_handler(int key, t_data *data);
int	event_handler(int key, t_data *data);


#endif