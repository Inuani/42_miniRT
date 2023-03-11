#include "../../includes/minirt.h"

void	light_deep_copy(t_object *new_node, const t_object *list)
{
	new_node->u_data.light.pos.x = list->u_data.light.pos.x;
	new_node->u_data.light.pos.y = list->u_data.light.pos.y;
	new_node->u_data.light.pos.z = list->u_data.light.pos.z;
	new_node->u_data.light.colors.x = list->u_data.light.colors.x;
	new_node->u_data.light.colors.y = list->u_data.light.colors.y;
	new_node->u_data.light.colors.z = list->u_data.light.colors.z;
	new_node->u_data.light.light_ratio = list->u_data.light.light_ratio;
}

void	plane_deep_copy(t_object *new_node, const t_object *list)
{
	new_node->u_data.plane.point.x = list->u_data.plane.point.x;
	new_node->u_data.plane.point.y = list->u_data.plane.point.y;
	new_node->u_data.plane.point.z = list->u_data.plane.point.z;
	new_node->u_data.plane.orient.x = list->u_data.plane.orient.x;
	new_node->u_data.plane.orient.y = list->u_data.plane.orient.y;
	new_node->u_data.plane.orient.z = list->u_data.plane.orient.z;
	new_node->u_data.plane.colors.x = list->u_data.plane.colors.x;
	new_node->u_data.plane.colors.y = list->u_data.plane.colors.y;
	new_node->u_data.plane.colors.z = list->u_data.plane.colors.z;
	new_node->u_data.plane.xpm.img = list->u_data.plane.xpm.img;
	new_node->u_data.plane.xpm.addr = list->u_data.plane.xpm.addr;
	new_node->u_data.plane.xpm.bits_per_pixel = list->u_data.plane.xpm.bits_per_pixel;
	new_node->u_data.plane.xpm.line_length = list->u_data.plane.xpm.line_length;
	new_node->u_data.plane.xpm.endian = list->u_data.plane.xpm.endian;
	new_node->u_data.plane.xpm.wdth = list->u_data.plane.xpm.wdth;
	new_node->u_data.plane.xpm.hgt = list->u_data.plane.xpm.hgt;
	new_node->u_data.plane.flg = list->u_data.plane.flg;
}

void	cylinder_deep_copy(t_object *new_node, const t_object *list)
{
	new_node->u_data.cylinder.center.x = list->u_data.cylinder.center.x;
	new_node->u_data.cylinder.center.y = list->u_data.cylinder.center.y;
	new_node->u_data.cylinder.center.z = list->u_data.cylinder.center.z;
	new_node->u_data.cylinder.orient.x = list->u_data.cylinder.orient.x;
	new_node->u_data.cylinder.orient.y = list->u_data.cylinder.orient.y;
	new_node->u_data.cylinder.orient.z = list->u_data.cylinder.orient.z;
	new_node->u_data.cylinder.colors.x = list->u_data.cylinder.colors.x;
	new_node->u_data.cylinder.colors.y = list->u_data.cylinder.colors.y;
	new_node->u_data.cylinder.colors.z = list->u_data.cylinder.colors.z;
	new_node->u_data.cylinder.radius = list->u_data.cylinder.radius;
	new_node->u_data.cylinder.hgt = list->u_data.cylinder.hgt;
	new_node->u_data.cylinder.xpm.img = list->u_data.cylinder.xpm.img;
	new_node->u_data.cylinder.xpm.addr = list->u_data.cylinder.xpm.addr;
	new_node->u_data.cylinder.xpm.bits_per_pixel = list->u_data.cylinder.xpm.bits_per_pixel;
	new_node->u_data.cylinder.xpm.line_length = list->u_data.cylinder.xpm.line_length;
	new_node->u_data.cylinder.xpm.endian = list->u_data.cylinder.xpm.endian;
	new_node->u_data.cylinder.xpm.wdth = list->u_data.cylinder.xpm.wdth;
	new_node->u_data.cylinder.xpm.hgt = list->u_data.cylinder.xpm.hgt;
	new_node->u_data.cylinder.flg = list->u_data.cylinder.flg;
}

void	hyperboloid_deep_copy(t_object *new_node, const t_object *list)
{
	new_node->u_data.hyperboloid.center.x = list->u_data.hyperboloid.center.x;
	new_node->u_data.hyperboloid.center.y = list->u_data.hyperboloid.center.y;
	new_node->u_data.hyperboloid.center.z = list->u_data.hyperboloid.center.z;
	new_node->u_data.hyperboloid.orient.x = list->u_data.hyperboloid.orient.x;
	new_node->u_data.hyperboloid.orient.y = list->u_data.hyperboloid.orient.y;
	new_node->u_data.hyperboloid.orient.z = list->u_data.hyperboloid.orient.z;
	new_node->u_data.hyperboloid.colors.x = list->u_data.hyperboloid.colors.x;
	new_node->u_data.hyperboloid.colors.y = list->u_data.hyperboloid.colors.y;
	new_node->u_data.hyperboloid.colors.z = list->u_data.hyperboloid.colors.z;
	new_node->u_data.hyperboloid.radius = list->u_data.hyperboloid.radius;
	new_node->u_data.hyperboloid.hgt = list->u_data.hyperboloid.hgt;
	new_node->u_data.hyperboloid.xpm.img = list->u_data.hyperboloid.xpm.img;
	new_node->u_data.hyperboloid.xpm.addr = list->u_data.hyperboloid.xpm.addr;
	new_node->u_data.hyperboloid.xpm.bits_per_pixel = list->u_data.hyperboloid.xpm.bits_per_pixel;
	new_node->u_data.hyperboloid.xpm.line_length = list->u_data.hyperboloid.xpm.line_length;
	new_node->u_data.hyperboloid.xpm.endian = list->u_data.hyperboloid.xpm.endian;
	new_node->u_data.hyperboloid.xpm.wdth = list->u_data.hyperboloid.xpm.wdth;
	new_node->u_data.hyperboloid.xpm.hgt = list->u_data.hyperboloid.xpm.hgt;
	new_node->u_data.hyperboloid.flg = list->u_data.hyperboloid.flg;
}

void	sphere_deep_copy(t_object *new_node, const t_object *list)
{
	new_node->u_data.sphere.center.x = list->u_data.sphere.center.x;
	new_node->u_data.sphere.center.y = list->u_data.sphere.center.y;
	new_node->u_data.sphere.center.z = list->u_data.sphere.center.z;
	new_node->u_data.sphere.radius = list->u_data.sphere.radius;
	new_node->u_data.sphere.colors.x = list->u_data.sphere.colors.x;
	new_node->u_data.sphere.colors.y = list->u_data.sphere.colors.y;
	new_node->u_data.sphere.colors.z = list->u_data.sphere.colors.z;		
	new_node->u_data.sphere.xpm.img = list->u_data.sphere.xpm.img;
	new_node->u_data.sphere.xpm.addr = list->u_data.sphere.xpm.addr;
	new_node->u_data.sphere.xpm.bits_per_pixel = list->u_data.sphere.xpm.bits_per_pixel;
	new_node->u_data.sphere.xpm.line_length = list->u_data.sphere.xpm.line_length;
	new_node->u_data.sphere.xpm.endian = list->u_data.sphere.xpm.endian;
	new_node->u_data.sphere.xpm.wdth = list->u_data.sphere.xpm.wdth;
	new_node->u_data.sphere.xpm.hgt = list->u_data.sphere.xpm.hgt;
	new_node->u_data.sphere.n_map.img = list->u_data.sphere.n_map.img;
	new_node->u_data.sphere.n_map.addr = list->u_data.sphere.n_map.addr;
	new_node->u_data.sphere.n_map.bits_per_pixel = list->u_data.sphere.n_map.bits_per_pixel;
	new_node->u_data.sphere.n_map.line_length = list->u_data.sphere.n_map.line_length;
	new_node->u_data.sphere.n_map.endian = list->u_data.sphere.n_map.endian;
	new_node->u_data.sphere.n_map.wdth = list->u_data.sphere.n_map.wdth;
	new_node->u_data.sphere.n_map.hgt = list->u_data.sphere.n_map.hgt;
	new_node->u_data.sphere.flg = list->u_data.sphere.flg;
}