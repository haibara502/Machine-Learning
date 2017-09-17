#include "fthirdchar.h"

double fThirdChar::subEntro(People people, int std)
{
	vector<pair<string, bool> > subPeople;
	for (int i = 0; i < people.people.size(); ++i)
		if (people.people[i].first[3] == std + 'a' || people.people[i].first[3] == std + 'A')
			subPeople.push_back(people.people[i]);
	People subp(subPeople);
	return subp.calcEntropy() * subPeople.size();
}
double fThirdChar::otherEntro(People people)
{
	vector<pair<string, bool> > subPeople;
	for (int i = 0; i < people.people.size(); ++i)
	{
		if (people.people[i].first.size() < 4)
			subPeople.push_back(people.people[i]);
		else if (!isalpha(people.people[i].first[3]))
			subPeople.push_back(people.people[i]);
	}
	People subp(subPeople);
	return subp.calcEntropy() * subPeople.size();
}
double fThirdChar::informationGain(People people)
{
	double inforGain = 0;
	for (int i = 0; i < 26; ++i)
		inforGain += subEntro(people, i) / people.people.size();
	inforGain += otherEntro(people);
	return inforGain;
}
vector<People> fThirdChar::getDivide(People people)
{
	vector<pair<string, bool> > p[27];
	for (int i = 0; i < people.people.size(); ++i)
	{
		if (people.people[i].first.size() < 4)
		{
			p[26].push_back(people.people[i]);
			continue;
		}
		char w = people.people[i].first[3];
		if ((w >= 'A') && (w <= 'Z'))
			w -= 'A';
		else if ((w >= 'a') && (w <= 'z'))
			w -= 'a';
		else 
			w = 26;
		p[w].push_back(people.people[i]);
	}
	vector<People> pp;
	for (int i = 0; i < 27; ++i)
		pp.push_back(People(p[i]));
	return pp;
}
int fThirdChar::findLocate(string name)
{
	int w = name[3];
	if ((w >= 'a') && (w <= 'z'))
		return w - 'a';
	else if ((w >= 'A') && (w <= 'Z'))
		return w - 'A';
	else
		return 26;
}