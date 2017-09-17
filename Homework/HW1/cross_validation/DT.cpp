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
int depth = 0, maxDepth = 4;

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
	cout << "Please input the desired maximum depth: " << endl;
	cin >> maxDepth;
	allFeatures = new AllFeature();
	vector<double> accuracies;
	for (int i = 0; i < 4; ++i)
	{
		wholePeople = People();
		for (int j = 0; j < 4; ++j)
			if (j != i)
			{
				string inputFile = "training";
				inputFile += j + '0';
				inputFile += ".txt";
				wholePeople.read(inputFile);
			}
			
		Node *root = new Node();
		root -> avlFeature = (1 << 4) - 1;
		
		build(root, wholePeople);
		
		People testPeople;
		string testFile = "training";
		testFile += i + '0';
		testFile += ".txt";
		testPeople.read(testFile);
		int correct = 0;
		for (int i = 0; i < testPeople.people.size(); ++i)
		{
			bool ans = test(root, testPeople.people[i].first);
			if (ans == testPeople.people[i].second)
				++correct;	
		}
		accuracies.push_back((double)correct / testPeople.people.size());
		
	}
	double sum = 0;
	cout << "The accuracies are: " << endl;
	for (int i = 0; i < accuracies.size(); ++i)
	{
		sum += accuracies[i];
		cout << i << ": " << accuracies[i] << endl;
	}
	cout << "The overall accuracy is: " << sum / accuracies.size() << endl;
}