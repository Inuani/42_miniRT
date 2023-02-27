#ifndef OBJECT_TYPE_H
# define OBJECT_TYPE_H

/*
typedef enum object_type {
	CAMERA,
	AMBIANT,
	LIGHT,
	SPHERE,
	PLANE,
	CYLINDER
}	t_type;

typedef struct s_object {
	t_type			type;
	union {
		struct s_cam		camera;
		struct s_ambiant	ambiant;
		struct s_light		light;
		struct s_sphere		sphere;
		struct s_plane		plane;
		struct s_cylinder	cylinder;
	}	u_data;
	struct s_object	*next;
}				t_object;

----------------------------------------------
object_list_utils.c
----------------------------------------------*/

t_object	*create_object(t_type type, void *data);
void		add_object_to_list(t_object **lst, t_object *new);
t_object	*get_last_object(t_object *lst);
int			nb_objects(t_object *lst);

#endif