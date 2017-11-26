#include "learningRate.h"

double learningRate::learningRate(int t)
{
	return r0 / (1 + t);
}

double learningRate::learningRate(int t, double c)
{
	return r0 / (1 + r0 * t / c);
}

