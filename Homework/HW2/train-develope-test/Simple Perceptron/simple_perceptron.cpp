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

	Urls urls;
	urls.readTrain("phishing.train");
	urls.readCv("phishing.dev");
	urls.readTest("phishing.test");

	perceptron.init();
	double lr;
	cout << "Please input the learning rate: ";
	cin >> lr;
	perceptron.setLearningRate(lr);
	for (int epoch = 0; epoch < 20; ++epoch)
	{
		cout << "This is epoch : " << epoch << endl;
		perceptron.train(urls);
		cout << "The accuracy of development set is " << perceptron.cv(urls) << endl;
	}
	cout << "The final accuracy of simple perceptron is " << perceptron.test(urls) << endl;
}
