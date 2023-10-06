#include "ray.h"
#include "vec3.h"
#include <math.h>

#include <stdio.h>

double	hit_sphere(t_ray ray, t_vec3 center, double radius)
{
	t_vec3	oc;
	double		a;
	double		b;
	double		c;
	double		discriminant;

	oc = sub_vec3(ray.origin, center);
	a = dot_vec3(ray.direction, ray.direction);
	b = dot_vec3(oc, ray.direction);
	c = dot_vec3(oc, oc) - radius * radius;
	discriminant = b * b - a * c;
	if (discriminant < 0)
		return (-1);
	else
		return ((-b - sqrt(discriminant)) / a);
}
