#ifndef STRUCT_H
# define STRUCT_H

// # include "object_type.h"

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

typedef struct s_ambiant
{
	float	light_ratio;
	t_vec	colors;
}			t_ambiant;

typedef struct s_light {
	t_vec	pos;
	float	light_ratio;
	t_vec	colors;
}				t_light;

typedef struct s_sphere {
	t_vec	center;
	float	radius;
	t_vec	colors;
}				t_sphere;

typedef struct s_cylinder {
	t_vec	base;
	t_vec	orient;
	float	diameter;
	float	hgt;
	t_vec	colors;
}			t_cylinder;

typedef struct s_plane {
	t_vec	point;
	t_vec	orient;
	t_vec	colors;
}				t_plane;

typedef struct s_viewport
{
	float	viewp_hgt;
	float	viewp_wdt;
	float	focal_len;
	float	aspect_ratio;
	float	samplespp;
}				t_viewport;

typedef struct s_cam
{
	t_vec	pos;
	t_vec	orient;
	t_vec	up;
	t_vec	right;
	float	fov;
}				t_cam;

typedef struct s_ray {
	t_vec	direction;
	t_vec	ray;
	t_vec	normal;
	t_vec	point_at;
	float	t;
	int		front;
	float	depth;
}				t_ray;

typedef enum object_type {
	AMBIANT,
	CAMERA,
	LIGHT,
	SPHERE,
	PLANE,
	CYLINDER
}	t_type;

typedef struct s_object {
	t_type			type;
	union {
		struct s_ambiant	ambiant;
		struct s_cam		camera;
		struct s_light		light;
		struct s_sphere		sphere;
		struct s_plane		plane;
		struct s_cylinder	cylinder;
	}	u_data;
	struct s_object	*next;
}				t_object;

typedef struct s_count {
	int total;
	int	sp_count;
	int	pl_count;
	int	cy_count;
	int	l_count;
}				t_count;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	t_img		img;
	t_viewport	*vp;
	void		**objss;
	t_object	*chaos;
	t_object	**objs;
	t_count		count;
}				t_data;

#endif