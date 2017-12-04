#ifndef WEIGHT
#define WEIGHT

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

class Weight
{
	vector<double> w;

public:
	Weight(int n);
	void update(double, double, double, vector<pair<int, double> >, int);
	double multiply(vector<pair<int, double> >);
	void copy(vector<double>);
	void output();
};

#endif
