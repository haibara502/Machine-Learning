#include "people.h"

void People::read(string fileName)
{
	char pos, name[100];
	freopen(fileName.c_str(), "r", stdin);
	
	while (scanf("%c ", &pos) != -1)
	{
		gets(name);
		people.push_back(make_pair(name, pos == '+'));
	}
}
double People::calcEntropy()
{
	if (entropy != -1)
		return entropy;
	int plusNum = 0;
	for (int i = 0; i < people.size(); ++i)
		plusNum += people[i].second;
	if ((plusNum == 0) || (plusNum == people.size()))
		return 0;
	double posPos = (double) plusNum / people.size();
	double posNeg = 1 - posPos;
	entropy = -posPos*log(posPos) - posNeg * log(posNeg);
	return (double)entropy / people.size();
}
bool People::mostLabel()
{
	int plusPeople = 0, negPeople = 0;
	for (int i = 0; i < people.size(); ++i)
		if (people[i].second)
			++plusPeople;
		else
			++negPeople;
	if (plusPeople >= negPeople)
		return true;
	else
		return false;
}