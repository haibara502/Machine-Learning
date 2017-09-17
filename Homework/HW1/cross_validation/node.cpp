#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

class Node
{
	public:
	vector<Node*> subtrees;
	int avlFeature, thisFeature;
	bool lastLabel;
};