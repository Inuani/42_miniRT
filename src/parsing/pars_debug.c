#include "../../includes/minirt.h"

void	print_token(t_tok **lst)
{
	t_tok	*token;

	token = *lst;
	while (token)
	{
		printf("type: %d - str: %s\n", token->type, token->s);
		token = token->next;
	}
}

void	print_object(t_object obj)
{
	printf("Object type: %d\n", obj.type);
	if (obj.type == CAMERA)
	{
		printf("Camera position: (%.1f, %.1f, %.1f)\n", obj.u_data.camera.pos.x,
			obj.u_data.camera.pos.y, obj.u_data.camera.pos.z);
		printf("Camera orientation: (%.1f, %.1f, %.1f)\n", obj.u_data.camera.orient.x,
			obj.u_data.camera.orient.y, obj.u_data.camera.orient.z);
		printf("Camera up vector: (%.1f, %.1f, %.1f)\n", obj.u_data.camera.up.x,
			obj.u_data.camera.up.y, obj.u_data.camera.up.z);
		printf("Camera right vector: (%.1f, %.1f, %.1f)\n", obj.u_data.camera.right.x,
			obj.u_data.camera.right.y, obj.u_data.camera.right.z);
		printf("Camera field of view: %.1f\n", obj.u_data.camera.fov);
	}
	else if (obj.type == AMBIANT)
	{
		printf("Ambient light ratio: %.2f\n", obj.u_data.ambiant.light_ratio);
		printf("Ambient light color: (%.1f, %.1f, %.1f)\n", obj.u_data.ambiant.colors.x,
			obj.u_data.ambiant.colors.y, obj.u_data.ambiant.colors.z);
	}
	else if (obj.type == LIGHT)
	{
		printf("Light position: (%.1f, %.1f, %.1f)\n", obj.u_data.light.pos.x,
			obj.u_data.light.pos.y, obj.u_data.light.pos.z);
		printf("Light ratio: %.2f\n", obj.u_data.light.light_ratio);
		printf("Light color: (%.1f, %.1f, %.1f)\n", obj.u_data.light.colors.x,
			obj.u_data.light.colors.y, obj.u_data.light.colors.z);
	}
	else if (obj.type == SPHERE)
	{
		printf("Sphere center: (%.1f, %.1f, %.1f)\n", obj.u_data.sphere.center.x,
			obj.u_data.sphere.center.y, obj.u_data.sphere.center.z);
		printf("Sphere radius: %.2f\n", obj.u_data.sphere.radius);
		printf("Sphere color: (%.1f, %.1f, %.1f)\n", obj.u_data.sphere.colors.x,
			obj.u_data.sphere.colors.y, obj.u_data.sphere.colors.z);
	}
	else if (obj.type == PLANE)
	{
		printf("Plane point: (%.1f, %.1f, %.1f)\n", obj.u_data.plane.point.x,
			obj.u_data.plane.point.y, obj.u_data.plane.point.z);
		printf("Plane orientation: (%.1f, %.1f, %.1f)\n", obj.u_data.plane.orient.x,
			obj.u_data.plane.orient.y, obj.u_data.plane.orient.z);
		printf("Plane color: (%.1f, %.1f, %.1f)\n", obj.u_data.plane.colors.x,
			obj.u_data.plane.colors.y, obj.u_data.plane.colors.z);
	}
	else if (obj.type == CYLINDER)
	{
		printf("Cylinder center: (%.1f, %.1f, %.1f)\n", obj.u_data.cylinder.center.x,
			obj.u_data.cylinder.center.y, obj.u_data.cylinder.center.z);
	printf("Cylinder orientation: (%.1f, %.1f, %.1f)\n", obj.u_data.cylinder.orient.x,
		obj.u_data.cylinder.orient.y, obj.u_data.cylinder.orient.z);
	printf("Cylinder radius: %.3f\n", obj.u_data.cylinder.radius);
	printf("Cylinder height: %.3f\n", obj.u_data.cylinder.hgt);
	printf("Cylinder color: (%.1f, %.1f, %.1f)\n", obj.u_data.cylinder.colors.x,
		obj.u_data.cylinder.colors.y, obj.u_data.cylinder.colors.z);
	}
	else if (obj.type == HYPERBOLOID)
	{
		printf("Cone center: (%.1f, %.1f, %.1f)\n", obj.u_data.hyperboloid.center.x,
			obj.u_data.hyperboloid.center.y, obj.u_data.hyperboloid.center.z);
	printf("Cone orientation: (%.1f, %.1f, %.1f)\n", obj.u_data.hyperboloid.orient.x,
		obj.u_data.hyperboloid.orient.y, obj.u_data.hyperboloid.orient.z);
	printf("Cone radius: %.3f\n", obj.u_data.hyperboloid.radius);
	printf("Cone height: %.3f\n", obj.u_data.hyperboloid.hgt);
	printf("Cone color: (%.1f, %.1f, %.1f)\n", obj.u_data.hyperboloid.colors.x,
		obj.u_data.hyperboloid.colors.y, obj.u_data.hyperboloid.colors.z);
	}
	printf("\n");
}


