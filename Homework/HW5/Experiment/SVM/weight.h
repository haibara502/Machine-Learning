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
	void update(double r, double c, vector<pair<int, double> > x, int y);
	double multiply(vector<pair<int, double> > x);
	void copy(vector<double>);
	Weight(){w.clear();}
	void output();
};

#endif
