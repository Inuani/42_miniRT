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

typedef struct s_tok {
	int				type;
	char			*s;
	struct s_tok	*next;
	struct s_tok	*prev;
}				t_tok;

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
	t_vec	up;
	t_vec	right;
	t_vec	colors;
}				t_sphere;

typedef struct s_hyperboloid {
	t_vec	orient;
	t_vec	center;
	float	radius;
	float	hgt;
	t_vec	colors;
	t_vec	h;
	t_vec	h_point;
	t_vec	w;
	float	m;
	float	v_h;
	float	w_h;
}				t_hyperboloid;

typedef struct s_cylinder {
	t_vec	center;
	t_vec	orient;
	t_vec	h;
	t_vec	top_cyl;
	t_vec	cam2cyl;
	float	a;
	float	b;
	float	c;
	float	delta;
	float	radius;
	float	hgt;
	t_vec	colors;
}				t_cylinder;

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
	float	shiny;
	int		obj_n;
	int		first;
}				t_ray;

typedef enum object_type {
	AMBIANT,
	CAMERA,
	LIGHT,
	SPHERE,
	PLANE,
	CYLINDER,
	HYPERBOLOID
}	t_type;

typedef struct s_object {
	t_type			type;
	union {
		struct s_ambiant		ambiant;
		struct s_cam			camera;
		struct s_light			light;
		struct s_sphere			sphere;
		struct s_plane			plane;
		struct s_cylinder		cylinder;
		struct s_hyperboloid	hyperboloid;
	}	u_data;
	struct s_object	*next;
}				t_object;

typedef struct s_count {
	int	total;
	int	sp_count;
	int	pl_count;
	int	cy_count;
	int	l_count;
	int	hy_count;
}				t_count;

typedef struct s_data
{
	pthread_t	*thread_id;
	pthread_mutex_t	lock;
	int			thread_i;
	void		*mlx;
	void		*win;
	t_img		img;
	t_viewport	*vp;
	t_tok		*lst;
	t_count		count;
	t_object	*chaos;
	t_object	**objs;
	int			current;
	int			changed;
	t_vec		final_color;
	t_vec		point_at;
	int			fin;
}				t_data;

#endif