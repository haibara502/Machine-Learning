#include "flength.h"

double fLength::subEntro(People people, int left, int right)
{
	vector<pair<string, bool> > subPeople;
	for (int i = 0; i < people.people.size(); ++i)
		if (people.people[i].first.length() >= left && people.people[i].first.length() < right)
			subPeople.push_back(people.people[i]);
	People subp(subPeople);
	return subp.calcEntropy() * subPeople.size();
}
double fLength::informationGain(People people)
{
	double inforGain = 0;
	
	inforGain += subEntro(people, 0, 4);
	inforGain += subEntro(people, 4, 8) ;
	inforGain += subEntro(people, 8, 100);
	inforGain /= people.people.size();
	return inforGain;
}

vector<People> fLength::getDivide(People people)
{
	vector<pair<string, bool> > p1, p2, p3;
	for (int i = 0; i < people.people.size(); ++i)
	{
		int l = people.people[i].first.length();
		if (l < 4)
			p1.push_back(people.people[i]);
		else if (l < 8)
			p2.push_back(people.people[i]);
		else
			p3.push_back(people.people[i]);
	}
	vector<People> subp;
	subp.push_back(People(p1));
	subp.push_back(People(p2));
	subp.push_back(People(p3));
	return subp;
}
int fLength::findLocate(string name)
{
	if (name.length() < 4)
		return 0;
	else if (name.length() < 8)
		return 1;
	else
		return 2;
}