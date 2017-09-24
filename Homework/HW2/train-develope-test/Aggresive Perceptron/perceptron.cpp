#include "perceptron.h"

const int Perceptron::dimension = 70;

double Perceptron::getRandom()
{
	return 2 * random() / double(RAND_MAX) - 1;
}

double Perceptron::calcLearningRate(vector<double> x, double y)
{
	double rate = marginPerception;
	double sum = 0;
	for (int i = 0; i < dimension; ++i)
		sum += w[i] * x[i];
	sum *= y;
	rate -= sum;

	sum = 0;
	for (int i = 0; i < dimension; ++i)
		sum += x[i] * x[i];
	sum += 1;
	rate /= sum;
	return rate;
}

void Perceptron::init()
{
	w.clear();
	for (int i = 0; i < dimension; ++i)
		w.push_back(getRandom());
	marginPerception = 1;
	learningRate = 0.1; //Set default learning rate as 0.1.
}

void Perceptron::train(Urls urls)
{
	for (int i = 0; i < urls.getTrainingSize(); ++i)
	{
		double sum = 0;
		for (int j = 0; j < dimension; ++j)
			 sum += w[j] * urls.getTrainSample(i, j);

		if (urls.getTrainLabel(i) * sum < marginPerception)
			for (int j = 0; j < dimension; ++j)
				w[j] += calcLearningRate(urls.getOneTrainSample(i), urls.getTrainLabel(i)) * urls.getTrainSample(i, j) * urls.getTrainLabel(i);
	}
}

double Perceptron::test(Urls urls)
{
	int numCorrect = 0;
	for (int i = 0; i < urls.getTestSize(); ++i)
	{
		double sum = 0;
		for (int j = 0; j < dimension; ++j)
			sum += w[j] * urls.getTestSample(i, j);

		if (sum * urls.getTestLabel(i) < -1e-10)
			continue;
		++numCorrect;
	}
	return double(numCorrect) / urls.getTestSize();
}

double Perceptron::cv(Urls urls) 
{
	int numCorrect = 0;
	for (int i = 0; i < urls.getCvSize(); ++i)
	{
		double sum = 0;
		for (int j = 0; j < dimension; ++j)
			sum += w[j] * urls.getCvSample(i, j);

		if (sum * urls.getCvLabel(i) < -1e-10)
			continue;
		++numCorrect;
	}
	return double(numCorrect) / urls.getCvSize();
}

void Perceptron::setMarginPerception(double std)
{
	marginPerception = std;
}
