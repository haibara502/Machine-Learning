#ifndef TRAIN
#define TRAIN

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

class SVM
{
	int epoch;
	Dataset dataset;
	Weight w;
	LearningRate r;
	double c;

	Run(int epoch, Dataset dataset, double r, double c, int dimension, string file):epoch(epoch), r(r), c(c)
	{	
		w = Weight(dimension);	
		dataset.read_data(file);
	};

	Run();

	void Train();
	void Test();

	void read_weight(string);
	void output_weight(string);

#endif
