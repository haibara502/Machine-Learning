#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

#ifndef PEOPLE
#define PEOPLE

class People
{
	public:
	vector<pair<string, bool> > people;
	double entropy;
	People():entropy(-1){};
	People(vector<pair<string, bool> > people):people(people), entropy(-1){}
	void read(string fileName);
	double calcEntropy();
	bool mostLabel();
};

#endif