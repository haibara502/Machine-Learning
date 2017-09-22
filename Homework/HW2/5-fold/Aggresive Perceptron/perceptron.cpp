#include "perceptron.h"

const int Perceptron::dimension = 70;

double Perceptron::getRandom()
{
	return 2 * random() / double(RAND_MAX) - 1;
}

void Perceptron::init()
{
	w.clear();
	for (int i = 0; i < dimension; ++i)
		w.push_back(getRandom());
	marginPerception = 0;
	learningRate = 1; //Set default learning rate as 1.
}

void Perceptron::setLearningRate(double expectLearningRate) //Set the learning rate.
{
	learningRate = expectLearningRate;
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

void Perceptron::train(Urls urls)
{
	for (int i = 0; i < urls.getTrainingSize(); ++i)
	{
		double sum = 0;
		for (int j = 0; j < dimension; ++j)
			 sum += w[j] * urls.getTrainSample(i, j);

		if (urls.getTrainLabel(i) * sum < marginPerception)
		{
			learningRate = calcLearningRate(urls.getOneTrainSample(i), urls.getTrainLabel(i));
			for (int j = 0; j < dimension; ++j)
				w[j] += learningRate * urls.getTrainSample(i, j) * urls.getTrainLabel(i);
		}
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

		if (sum * urls.getTestLabel(i) < 0)
			continue;
		++numCorrect;
	}
	return double(numCorrect) / urls.getTestSize();
}

double Perceptron::accuracy(Urls urls) //Return the test accuracy after the training.
{
	train(urls);
	return test(urls);
}

void Perceptron::divideLearningRate(double ratio)
{
	learningRate /= ratio;
}

void Perceptron::setMarginPerception(double std)
{
	marginPerception = std;
}
