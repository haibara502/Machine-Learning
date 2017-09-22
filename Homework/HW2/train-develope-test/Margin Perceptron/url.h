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
};

class Urls
{
	vector<Url> trainSamples;
	vector<Url> cvSamples;
	vector<Url> testSamples;
	static const int dimension;
	void handleString(string, int &, vector<double>&);
	public:
	Urls();
	void readTrain(string);
	void readCv(string);
	void readTest(string);
	int getTrainingSize();
	int getCvSize();
	int getTestSize();
	double getTrainSample(int, int);
	double getTestSample(int, int);
	double getCvSample(int, int);
	int getTrainLabel(int);
	int getTestLabel(int);
	int getCvLabel(int);
};

#endif
