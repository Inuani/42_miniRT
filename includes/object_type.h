#ifndef OBJECT_TYPE_H
# define OBJECT_TYPE_H

typedef enum {
	LIGHT,
	SPHERE,
	PLANE,
	CYLINDER
}		Type;

typedef struct s_objects {
	Type type;
	union {
		t_light		light;
		t_sphere	sphere;
		t_cylinder	cylinder;
		t_plane		plane;
	} data;
	struct s_objects *next;
}		t_objects;

#endif