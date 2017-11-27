#ifndef LAERNINGRATE
#define LEARNINGRATE

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

class learningRate
{
	double r0;

	double learningRate(int t);
	double learningRate(int t, double c);
	learningRate(double r):r0(r){};
};

#endif
