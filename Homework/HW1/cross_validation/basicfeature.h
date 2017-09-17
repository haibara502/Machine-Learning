#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>

#include "people.h"

using namespace std;

#ifndef BASICFEATURE  
#define BASICFEATURE

class BasicFeature
{
	public:
	virtual int findLocate(string) = 0;
	virtual double informationGain(People) = 0;
	virtual vector<People> getDivide(People) = 0;
};

#endif