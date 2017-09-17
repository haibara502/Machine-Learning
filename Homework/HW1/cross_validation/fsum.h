#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

#include "basicfeature.h"

class fSum: public BasicFeature
{
	double subEntro(People people, int std);
	public:
	double informationGain(People people);
	vector<People> getDivide(People people);
	int findLocate(string name);
};