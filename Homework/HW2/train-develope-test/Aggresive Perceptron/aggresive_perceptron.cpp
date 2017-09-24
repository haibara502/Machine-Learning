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
	Urls urls;
	urls.readTrain("phishing.train");
	urls.readCv("phishing.dev");
	urls.readTest("phishing.test");

	Perceptron perceptron;
	perceptron.init();

	double sp;
	cout << "Please input the value of margin Perceptron: ";
	cin >> sp;
	perceptron.setMarginPerception(sp);

	for (int epoch = 0; epoch < 20; ++epoch)
	{
		cout << "This is epoch: " << epoch + 1 << endl;
		perceptron.train(urls);
		cout << "The accuracy of dev is " << perceptron.cv(urls) << endl;
	}
	cout << "The final accuracy of Aggresive perceptron is " << perceptron.test(urls) << endl;
}
