#ifndef URL
#define URL

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <sstream>
#include <vector>
#include <fstream>

using namespace std;

class Url
{
	int label;
	vector<double> feature;
	public:
	Url();
	Url(int, vector<double>);
	int getLabel();
	double getFeature(int);
	vector<double> getWholeFeature();
};

class Urls
{
	vector<Url> trainSamples;
	vector<Url> testSamples;
	static const int dimension;
	void handleString(string, int &, vector<double>&);
	public:
	vector<double> getOneTrainSample(int);
	Urls();
	void readTrain(string);
	void readTest(string);
	int getTrainingSize();
	double getTrainSample(int, int);
	int getTrainLabel(int);
	int getTestSize();
	double getTestSample(int, int);
	int getTestLabel(int);
};

#endif
