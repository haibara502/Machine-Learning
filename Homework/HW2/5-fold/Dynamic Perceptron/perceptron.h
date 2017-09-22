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
	void train(Urls);
	double test(Urls);
	public:
		void init();
		void setLearningRate(double);
		double accuracy(Urls);
		void divideLearningRate(double);
};

#endif
