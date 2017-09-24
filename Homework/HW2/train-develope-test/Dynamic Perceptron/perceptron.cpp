#include "perceptron.h"

const int Perceptron::dimension = 70;

double Perceptron::getRandom()
{
	return 2 * random() / double(RAND_MAX) - 1;
}

void Perceptron::init()
{
	totalUpdate = 0;
	w.clear();
	for (int i = 0; i < dimension; ++i)
		w.push_back(getRandom());
	b = getRandom();
	learningRate = 0.1; //Set default learning rate as 0.1.
}

void Perceptron::setLearningRate(double expectLearningRate) //Set the learning rate.
{
	learningRate = expectLearningRate;
}

void Perceptron::train(Urls urls)
{
	for (int i = 0; i < urls.getTrainingSize(); ++i)
	{
		double sum = 0;
		for (int j = 0; j < dimension; ++j)
			 sum += w[j] * urls.getTrainSample(i, j);
		sum += b;

		if (urls.getTrainLabel(i) * sum < -1e-10)
		{
			for (int j = 0; j < dimension; ++j)
				w[j] += learningRate * urls.getTrainSample(i, j) * urls.getTrainLabel(i);
			b += learningRate * urls.getTrainLabel(i);
			++totalUpdate;
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
		sum += b;

		if (sum * urls.getTestLabel(i) < -1e-10)
			continue;
		++numCorrect;
	}
	cout << "Total update : " << totalUpdate << endl;
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
		sum += b;

		if (sum * urls.getCvLabel(i) < -1e-10)
			continue;
		++numCorrect;
	}
	return double(numCorrect) / urls.getCvSize();
}

void Perceptron::divideLearningRate(double ratio)
{
	learningRate /= ratio;
}
