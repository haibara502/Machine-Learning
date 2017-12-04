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
#include <fstream>

using namespace std;

class Data
{
	int y; //The label of this example
	vector<pair<int, double> > x; //The x vector, the pair stores for which index the value of it

public:
	Data(); //Function for initialization
	Data(vector<pair<int, double> > _x, int _y):y(_y),x(_x){}
	double calc(Weight w);
	int get_label();
	vector<pair<int, double> > get_vector();
};

class Dataset
{
	vector<Data> examples; //Stores all the examples
public:
	Data pick_random(); //Randomlly pick subset of the whole examples
	void read_data(string); //Read all the examples from the file
	Dataset();
	int size();
	Data pick(int);
};

#endif
