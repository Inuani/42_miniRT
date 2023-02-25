#include "../includes/minirt.h"

// Compute a pseudorandom integer.
// Output value in range [0, 32767]
int	fast_rand(int seed)
{
	int	r_seed;
	r_seed = (214013*seed+2531011);
	return (r_seed>>16)&0x7FFF;
}

float	rand_double(int seed)
{
	float	rand;
	rand = (float)fast_rand(seed) / (float)32767;
	return (rand);
}