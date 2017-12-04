#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

#include "logistic_regression.h"

using namespace std;

int main()
{
	LogisticRegression *lr = new LogisticRegression();
	lr -> train();
	lr -> test();
}
