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
	double lr;
	cout << "Please input the learning rate: ";
	cin >> lr;

	Urls urls;
	urls.readTrain("phishing.train");
	urls.readCv("phishing.dev");	
	urls.readTest("phishing.test");
	
	Perceptron perceptron;
	perceptron.init();
	perceptron.setLearningRate(lr);

	for (int epoch = 0; epoch < 20; ++epoch)
	{
		perceptron.train(urls);
		cout << "This is epoch : " << epoch << endl;
		cout << "The accuracy of development set is " << perceptron.cv(urls) << endl;
		perceptron.divideLearningRate(epoch + 1);
	}
	cout << "The final accuracy of simple perceptron is " << perceptron.test(urls) << endl;
}
