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
		printf("Camera position: (%f, %f, %f)\n", obj.u_data.camera.pos.x,
			obj.u_data.camera.pos.y, obj.u_data.camera.pos.z);
		printf("Camera orientation: (%f, %f, %f)\n", obj.u_data.camera.orient.x,
			obj.u_data.camera.orient.y, obj.u_data.camera.orient.z);
		printf("Camera up vector: (%f, %f, %f)\n", obj.u_data.camera.up.x,
			obj.u_data.camera.up.y, obj.u_data.camera.up.z);
		printf("Camera right vector: (%f, %f, %f)\n", obj.u_data.camera.right.x,
			obj.u_data.camera.right.y, obj.u_data.camera.right.z);
		printf("Camera field of view: %f\n", obj.u_data.camera.fov);
	}
	else if (obj.type == AMBIANT)
	{
		printf("Ambient light ratio: %f\n", obj.u_data.ambiant.light_ratio);
		printf("Ambient light color: (%f, %f, %f)\n", obj.u_data.ambiant.colors.x,
			obj.u_data.ambiant.colors.y, obj.u_data.ambiant.colors.z);
	}
	else if (obj.type == LIGHT)
	{
		printf("Light position: (%f, %f, %f)\n", obj.u_data.light.pos.x,
			obj.u_data.light.pos.y, obj.u_data.light.pos.z);
		printf("Light ratio: %f\n", obj.u_data.light.light_ratio);
		printf("Light color: (%f, %f, %f)\n", obj.u_data.light.colors.x,
			obj.u_data.light.colors.y, obj.u_data.light.colors.z);
	}
	else if (obj.type == SPHERE)
	{
		printf("Sphere center: (%f, %f, %f)\n", obj.u_data.sphere.center.x,
			obj.u_data.sphere.center.y, obj.u_data.sphere.center.z);
		printf("Sphere radius: %f\n", obj.u_data.sphere.radius);
		printf("Sphere color: (%f, %f, %f)\n", obj.u_data.sphere.colors.x,
			obj.u_data.sphere.colors.y, obj.u_data.sphere.colors.z);
	}
	else if (obj.type == PLANE)
	{
		printf("Plane point: (%f, %f, %f)\n", obj.u_data.plane.point.x,
			obj.u_data.plane.point.y, obj.u_data.plane.point.z);
		printf("Plane orientation: (%f, %f, %f)\n", obj.u_data.plane.orient.x,
			obj.u_data.plane.orient.y, obj.u_data.plane.orient.z);
		printf("Plane color: (%f, %f, %f)\n", obj.u_data.plane.colors.x,
			obj.u_data.plane.colors.y, obj.u_data.plane.colors.z);
	}
	else if (obj.type == CYLINDER)
	{
		printf("Cylinder base: (%f, %f, %f)\n", obj.u_data.cylinder.base.x,
			obj.u_data.cylinder.base.y, obj.u_data.cylinder.base.z);
	printf("Cylinder orientation: (%f, %f, %f)\n", obj.u_data.cylinder.orient.x,
		obj.u_data.cylinder.orient.y, obj.u_data.cylinder.orient.z);
	printf("Cylinder diameter: %f\n", obj.u_data.cylinder.diameter);
	printf("Cylinder height: %f\n", obj.u_data.cylinder.hgt);
	printf("Cylinder color: (%f, %f, %f)\n", obj.u_data.cylinder.colors.x,
		obj.u_data.cylinder.colors.y, obj.u_data.cylinder.colors.z);
	}
	printf("\n");
}


