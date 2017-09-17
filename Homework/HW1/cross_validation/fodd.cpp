#include "fodd.h"

double fOdd::subEntro(People people, int std)
{
	vector<pair<string, bool> > subPeople;
	for (int i = 0; i < people.people.size(); ++i)
	{
		int sum = 0;
		for (int j = 0; j < people.people[i].first.size(); ++j)
		{
			if (!isalpha(people.people[i].first[j]))
				break;
			sum += people.people[i].first[j];
		}
		sum &= 1;
		if (sum == std)
			subPeople.push_back(people.people[i]);
	}
	People subp(subPeople);
	return subp.calcEntropy() * subPeople.size();
}

double fOdd::informationGain(People people)
{
	double inforGain = 0;
	inforGain += subEntro(people, 0);
	inforGain += subEntro(people, 1);
	inforGain /= people.people.size();
	return inforGain;
}

vector<People> fOdd::getDivide(People people)
{
	vector<pair<string, bool> > p[2];
	for (int i = 0; i < people.people.size(); ++i)
	{
		int sum = 0;
		for (int j = 0; j < people.people[i].first.size(); ++j)
		{
			if (!isalpha(people.people[i].first[j]))
				break;
			sum += people.people[i].first[j];
		}
		p[sum & 1].push_back(people.people[i]);
	}
	vector<People> subPeople;
	subPeople.push_back(People(p[0]));
	subPeople.push_back(People(p[1]));
	return subPeople;
}

int fOdd::findLocate(string name)
{
	int sum = 0;
	for (int i = 0; i < name.size(); ++i)
	{
		if (!isalpha(name[i]))
			break;
		sum += name[i];
	}
	return sum & 1;
}