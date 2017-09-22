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
	b = getRandom();
	marginPerception = 1;
	learningRate = 1; //Set default learning rate as 1.
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

		if (urls.getTrainLabel(i) * sum < marginPerception)
		{
			for (int j = 0; j < dimension; ++j)
				w[j] += learningRate * urls.getTrainSample(i, j) * urls.getTrainLabel(i);
			b += learningRate * urls.getTrainLabel(i);
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
