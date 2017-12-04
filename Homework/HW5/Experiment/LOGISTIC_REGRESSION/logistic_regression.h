#ifndef LOGISTICREGRESSION
#define LOGISTICREGRESSION

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <sstream>
#include <string>

#include "data.h"
#include "weight.h"
#include "learningRate.h"

using namespace std;

class LogisticRegression
{
	int epoch;
	Dataset train_dataset, cv_dataset, test_dataset;
	Weight *w;
	LearningRate *r;
	double sigma;

	void read_weight();
	void output_weight();

	double sigmoid(double);

	void cross_validate();
	double get_accuracy(Dataset);

	void read_dataset(int);

public:
	void train();
	void test();

	LogisticRegression();
};
#endif
