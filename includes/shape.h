#ifndef OBJECTS_H
# define OBJECTS_H


// hyperboloid
float	it_hit_hy(t_data *data, t_ray *ray, t_hyperboloid hp);
float	hit_hyperboloid(t_vec vector, t_hyperboloid hyperboloid, t_vec origin);


// cylinder
float	cylinder_eman(t_data *data, t_ray *ray, t_cylinder cyl);
// float	hit_cylinder(t_vec ray_dir, t_cylinder cyl, t_vec origin);
float	hit_cylinder(t_vec ray_dir, t_cylinder cyl, t_vec origin, t_vec ori2cy);
void	cylinder_init(t_data *d, t_cylinder *cyl);

// plane
void	plane_life(t_data *data, t_ray *ray, t_plane plane);
float	plane_hit(t_plane *plane, t_vec ray_origine, t_vec ray_direction);

// sphere
float		it_hit_sphere(t_data *data, t_ray *ray, t_sphere sphere);
float		sphere_hits(t_vec vector, t_vec v, t_sphere sphere);

// viewport
void	initialise_viewport(t_data *data);

#endif