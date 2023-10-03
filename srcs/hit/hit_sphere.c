#include "ray.h"
#include "vector3.h"
#include <math.h>

double	hit_sphere(t_ray ray, t_vector3 center, double radius)
{
	t_vector3	oc;
	double		a;
	double		b;
	double		c;
	double		discriminant;

	oc = subtract_vector3(ray.origin, center);
	a = dot_product_vector3(ray.direction, ray.direction);
	b = dot_product_vector3(oc, ray.direction);
	c = dot_product_vector3(oc, oc) - radius * radius;
	discriminant = b * b - a * c;
	if (discriminant < 0)
		return (-1);
	else
		return ((-b - sqrt(discriminant)) / a);
}
