#ifndef DATA
#define DATA

#include "weight.h"

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <vector>
#include <sstream>
#include <cmath>

using namespace std;

class Data
{
	int y; //The label of this example
	vector<pair<int, double> > x; //The x vector, the pair stores for which index the value of it

public:
	Data(); //Function for initialization
	Data(vector<pair<int, double> > _x, int _y):x(_x), y(_y){}
	int calc_error(Weight w);
};

class Dataset
{
	vector<Data> examples; //Stores all the examples
	Data pick_random(); //Randomlly pick subset of the whole examples
	void read_data(string file); //Read all the examples from the file
	Dataset();
};

#endif
