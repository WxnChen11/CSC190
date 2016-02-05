#include "lab1.h"

float S(float a, float b)
{
	float res;
	res = ((b-a)/6)*(f(a) + 4*f((a+b)/2) + f(b));
	return (res);
}
