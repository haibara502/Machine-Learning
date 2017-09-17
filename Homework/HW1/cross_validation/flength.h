#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

#include "basicfeature.h"

#ifndef FLENGTH
#define FLENGTH

class fLength: public BasicFeature
{
	double subEntro(People people, int left, int right);
	public:
	double informationGain(People people);
	vector<People> getDivide(People people);
	int findLocate(string name);
};
#endif