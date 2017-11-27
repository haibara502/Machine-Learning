#ifndef SVM
#define SVM

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

class SVM
{
	int epoch;
	Dataset train_dataset, cv_dataset, test_dataset;
	Weight w;
	LearningRate r;
	double c;

	void read_weight();
	void output_weight();

	void cross_validate();
	void get_accuracy(Dataset);

public:
	void train();
	void test();

	SVM();
}
#endif
