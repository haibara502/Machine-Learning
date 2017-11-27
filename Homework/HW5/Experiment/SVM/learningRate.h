#ifndef LAERNINGRATE
#define LEARNINGRATE

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

class LearningRate
{
	double r0;

	double getLearningRate(int t);
	double getLearningRate(int t, double c);
	LearningRate(double r):r0(r){};
};

#endif
