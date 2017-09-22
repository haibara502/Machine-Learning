#ifndef PERCEPTRON
#define PERCEPTRON

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>

#include "url.h"

using namespace std;

class Perceptron
{
	vector<double> w;
	double b;
	double learningRate;
	static const int dimension;
	double getRandom();
	public:
		void init();
		void setLearningRate(double);
		void train(Urls);
		double cv(Urls);
		double test(Urls);
};

#endif
