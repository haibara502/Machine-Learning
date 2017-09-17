#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>

#include "people.h"
#include "node.h"
#include "allfeatures.h"

using namespace std;

AllFeature *allFeatures;
People wholePeople;
int depth = 0, maxDepth = 3;

void build(Node *root, People people)
{
	++depth;
	if (depth == maxDepth)
		root -> avlFeature = 0;
	
	if (root -> avlFeature == 0)
	{
		--depth;
		root -> lastLabel = wholePeople.mostLabel();
		return;
	}
	if (people.calcEntropy() < 1e-10)
	{
		--depth;
		root -> lastLabel = people.mostLabel();
		return;
	}
	
	double minEntropy = 1e10;
	int bstFeature = -1;
	
	for (int i = 0; i < 4; ++i)
		if ((root -> avlFeature & (1 << i)) != 0)
		{
			double theEntropy = allFeatures -> calc(i, people);
			if (theEntropy < minEntropy)
			{
				minEntropy = theEntropy;
				bstFeature = i;
			}
		}
		
	root -> thisFeature = bstFeature;
	
	vector<People> subPeople = allFeatures -> getDivide(bstFeature, people);
	for (int i = 0; i < subPeople.size(); ++i)
	{
		Node *subNode = new Node();
		root -> subtrees.push_back(subNode);
		
		subNode -> avlFeature = root -> avlFeature;
		subNode -> avlFeature ^= (1 << bstFeature);
		build(subNode, subPeople[i]);
	}
	--depth;
}

bool test(Node *root, string name)
{
	if (root -> subtrees.size() == 0)
		return root -> lastLabel;
	
	int pos = allFeatures -> findLocate(root -> thisFeature, name);
	return test(root -> subtrees[pos], name);
}

int main()
{
	allFeatures = new AllFeature();
	
	wholePeople.read("train.txt");
	
	Node *root = new Node();
	root -> avlFeature = (1 << 4) - 1;
	
	build(root, wholePeople);
	
	
	People testPeople;
	testPeople.read("train.txt");
	int correct = 0;
	for (int i = 0; i < testPeople.people.size(); ++i)
	{
		bool ans = test(root, testPeople.people[i].first);
		if (ans == testPeople.people[i].second)
			++correct;
	}
	cout << "The accuracy of the dependency tree on training data is " << (double)correct / testPeople.people.size() << endl;
	
	testPeople = People();
	testPeople.read("test.txt");
	correct = 0;
	for (int i = 0; i < testPeople.people.size(); ++i)
	{
		bool ans = test(root, testPeople.people[i].first);
		if (ans == testPeople.people[i].second)
			++correct;
	}
	cout << "The accuracy of the dependency tree on test data is " << (double)correct / testPeople.people.size() << endl;
}