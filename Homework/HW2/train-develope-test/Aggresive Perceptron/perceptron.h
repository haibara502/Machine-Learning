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
	double learningRate;
	double marginPerception;
	static const int dimension;
	double getRandom();
	double calcLearningRate(vector<double>, double);
	int totalUpdate;
	public:
		void init();
		void train(Urls);
		double cv(Urls);
		double test(Urls);
		void setMarginPerception(double);
};

#endif
