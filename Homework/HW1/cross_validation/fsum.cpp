#include "fsum.h"

double fSum::subEntro(People people, int std)
{
	vector<pair<string, bool> > subPeople;
	for (int i = 0; i < people.people.size(); ++i)
	{
		int lengthSum = 0;
		for (int j = 0; j < people.people[i].first.size(); ++j)
			lengthSum += people.people[i].first[j];
		lengthSum %= 3;
		if (lengthSum == std)
			subPeople.push_back(people.people[i]);
	}
	People subP(subPeople);
	return subP.calcEntropy() * subPeople.size();
}
double fSum::informationGain(People people)
{
	double inforGain = 0;
	for (int i = 0; i < 3; ++i)
		inforGain += subEntro(people, i) / people.people.size();
	return inforGain;
}
vector<People> fSum::getDivide(People people)
{
	vector<pair<string, bool> > p[3];
	for (int i = 0; i < people.people.size(); ++i)
	{
		int sum = 0;
		for (int j = 0; j < people.people[i].first.size(); ++j)
			sum += people.people[i].first[j];
		p[sum % 3].push_back(people.people[i]);
	}
	vector<People> pp;
	for (int i = 0; i < 3; ++i)
		pp.push_back(p[i]);
	return pp;
}
int fSum::findLocate(string name)
{
	int sum = 0;
	for (int i = 0; i < name.size(); ++i)
		sum += name[i];
	return sum % 3;
}