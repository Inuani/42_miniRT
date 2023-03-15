/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egauthey <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 18:51:04 by egauthey          #+#    #+#             */
/*   Updated: 2022/11/21 18:51:06 by egauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPE_H
# define SHAPE_H

// ----------------------------------------------
// hyperboloid
// ----------------------------------------------

float		it_hit_hy(t_data *data, t_ray *ray, t_hyperboloid hp);
float		hit_hyperboloid(t_vec vector,
				t_hyperboloid hyperboloid, t_vec origin);
t_vec		calculate_x_y_hcb(t_ray *ray, t_hyperboloid *cyl);
t_vec		set_hy_xpm_color(t_ray *ray, t_hyperboloid *hy);
int			is_inside_hyp(t_ray *ray, t_hyperboloid hyp);

// ----------------------------------------------
// cylinder
// ----------------------------------------------

float		cylinder_eman(t_data *data, t_ray *ray, t_cylinder cyl);
float		hit_cylinder(t_vec ray_dir, t_cylinder *cyl,
				t_vec origin, t_vec ori2cy);
void		cylinder_init(t_data *d, t_cylinder *cyl);
t_vec		set_cy_xpm_color(t_ray *ray, t_cylinder *cy);
t_vec		calculate_x_y_ccb(t_ray *ray, t_cylinder *cyl);

// ----------------------------------------------
// plane
// ----------------------------------------------

void		plane_life(t_data *data, t_ray *ray, t_plane plane);
float		plane_hit(t_plane *plane, t_vec ray_origine, t_vec ray_direction);
void		phong_plane(t_data *data, t_ray *ray,
				t_light light, t_vec obj_color);
t_vec		get_texture(t_data *data, t_ray ray, t_plane *pl);
t_vec		calculate_x_y_pcb(t_ray ray, t_plane *plane);

// ----------------------------------------------
// sphere
// ----------------------------------------------

float		it_hit_sphere(t_data *data, t_ray *ray, t_sphere sphere);
float		sphere_hits(t_vec vector, t_vec v, t_sphere sphere);
int			is_inside(t_sphere sphere, t_cam camera, t_light light);
t_vec		get_sp_xpm_color(t_ray *ray, t_sphere *sp);
t_vec		calculate_x_y_scb(t_ray *ray, t_sphere *sphere);

// ----------------------------------------------
// viewport
// ----------------------------------------------

void		initialise_viewport(t_data *data);

// ----------------------------------------------
// texture
// ----------------------------------------------

t_vec		get_sp_xpm_color(t_ray *ray, t_sphere *sp);
int			get_color_pixel(t_data *d, int x, int y, t_img *xpm);
void		calculate_x_y_sp(t_img *xpm, t_ray *ray, int *x, int *y);

#endif