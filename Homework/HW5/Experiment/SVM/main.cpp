#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

#include "svm.h"

using namespace std;

int main()
{
	SVM *svm = new SVM();
	svm -> train();
	svm -> test();
	//delete svm;
}
