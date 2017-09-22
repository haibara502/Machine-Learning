#include "url.h"

Url::Url(int label, vector<double> feature):label(label), feature(feature){};

const int Urls::dimension = 70;

Url::Url():label(0)
{
	feature.clear();
}

int Url::getLabel()
{
	return label;
}

double Url::getFeature(int i)
{
	return feature[i];
}

Urls::Urls()
{
	trainSamples.clear();
	testSamples.clear();
}

void Urls::handleString(string input, int &label, vector<double> &featureVector)
{
	istringstream iss(input);

	iss >> label;

	string feature;
	while (iss >> feature)
	{
		int pos;
		double number;
		sscanf(feature.c_str(), "%d:%lf", &pos, &number);
		featureVector[pos] = number;
	}
}

void Urls::readTrain(string file)
{
	ifstream fin(file.c_str());

	string line;
	while (getline(fin, line))
	{
		//cerr << "This line is " << line << endl;
		int label = 0;
		vector<double> featureVector(dimension, 0);
		handleString(line, label, featureVector);

		trainSamples.push_back(Url(label, featureVector));
	}

	fin.close();
}

void Urls::readTest(string file)
{
	ifstream fin(file.c_str());

	string line;
	while (getline(fin, line))
	{
		int label = 0;
		vector<double> featureVector(dimension, 0);
		handleString(line, label, featureVector);

		testSamples.push_back(Url(label, featureVector));
	}

	fin.close();
}

int Urls::getTrainingSize()
{
	return trainSamples.size();
}

int Urls::getTrainLabel(int i)
{
	return trainSamples[i].getLabel();
}

double Urls::getTrainSample(int i, int j)
{
	return trainSamples[i].getFeature(j);
}

int Urls::getTestLabel(int i)
{
	return testSamples[i].getLabel();
}

double Urls::getTestSample(int i, int j)
{
	return testSamples[i].getFeature(j);
}

int Urls::getTestSize()
{
	return testSamples.size();
}
