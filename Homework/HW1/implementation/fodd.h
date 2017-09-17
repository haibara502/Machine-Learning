#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

#include "basicfeature.h"

class fOdd: public BasicFeature
{
	double subEntro(People, int);
	public:
	double informationGain(People);
	vector<People> getDivide(People);
	int findLocate(string);
};