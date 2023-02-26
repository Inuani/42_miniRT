#ifndef OBJECT_TYPE_H
# define OBJECT_TYPE_H

typedef enum object_type {
	LIGHT,
	SPHERE,
	PLANE,
	CYLINDER
}	t_type;

typedef struct s_object {
	t_type				type;
	union {
		struct s_light		light;
		struct s_sphere		sphere;
		struct s_plane		plane;
		struct s_cylinder	cylinder;
	}	u_data;
	struct s_objects	*next;
}				t_object;

#endif