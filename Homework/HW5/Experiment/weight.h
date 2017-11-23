#ifndef WEIGHT
#define WEIGHT

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

class Weight
{
	vector<double> w;

	Weight(int n);
	void update(double r, Data x);
	double multiply(vector<pair<int, double> > x);
};

#endif
