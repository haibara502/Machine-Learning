#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cstdlib>
#include <algorithm>

#include "perceptron.h"
#include "url.h"

using namespace std;

int main()
{
	Perceptron perceptron;

	double learningRate;
	cout << "Please enter the learning rate: " ;
	cin >> learningRate;

	double margin;
	cout << "Please enter the margin: ";
	cin >> margin;

	double finalAnswer = 0;
	for (int i = 0; i < 5; ++i)
	{
		Urls urls;

		for (int j = 0; j < 5; ++j) 
			if (i != j)
				urls.readTrain(string("training0") + char(j + '0') + string(".data"));
		
		urls.readTest(string("training0") + char(i + '0') + string(".data"));

		perceptron.init();
		perceptron.setLearningRate(learningRate);
		perceptron.setMarginPerception(margin);
		double answer;
		for (int epoch = 0; epoch < 10; ++epoch)
			answer = perceptron.accuracy(urls);
		finalAnswer += answer;
	}
	cout << "The final accuracy of margin perceptron is " << finalAnswer / 5.0 << endl;
}
