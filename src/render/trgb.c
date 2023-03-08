
#include "../../includes/minirt.h"

t_vec	add_colors(t_vec c1, t_vec c2, float intensity) {
	t_vec c_res;
	c_res.x = c1.x + c2.x * intensity;
	c_res.y = c1.y + c2.y * intensity;
	c_res.z = c1.z + c2.z * intensity;
	return c_res;
}

t_vec	add_color(t_vec c1, t_vec c2) {
	t_vec c_res;
	c_res.x = c1.x + c2.x;
	c_res.y = c1.y + c2.y;
	c_res.z = c1.z + c2.z;
	return c_res;
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}