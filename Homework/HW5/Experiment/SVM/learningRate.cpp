#include "learningRate.h"

double LearningRate::getLearningRate(int t)
{
	return r0 / (1 + t);
}

double LearningRate::getLearningRate(int t, double c)
{
	return r0 / (1 + r0 * t / c);
}
