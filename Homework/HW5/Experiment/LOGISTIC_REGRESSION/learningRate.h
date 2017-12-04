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

public:
	double getLearningRate(int t);
	double getLearningRate(int t, double c);
	LearningRate(double r = 0):r0(r){};
};

#endif
