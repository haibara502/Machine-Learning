#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
	SVM svm = new SVM();
	svm -> train();
	svm -> test();
	delete svm;
}
