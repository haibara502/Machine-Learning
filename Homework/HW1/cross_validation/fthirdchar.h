#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

#include "basicfeature.h"

class fThirdChar: public BasicFeature
{
	double subEntro(People, int);
	double otherEntro(People);
	public:
	double informationGain(People);
	vector<People> getDivide(People);
	int findLocate(string);
};