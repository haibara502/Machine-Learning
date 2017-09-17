#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

#include "flength.h"
#include "fsum.h"
#include "fthirdchar.h"
#include "fodd.h"

#ifndef ALLFEATURE
#define ALLFEATURE

class AllFeature
{
	vector<BasicFeature*> features;
	
	public:
	AllFeature();
	double calc(int feature, People people);
	vector<People> getDivide(int feature, People people);
	int findLocate(int feature, string name);
};
#endif