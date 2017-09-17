#include "allfeatures.h"

AllFeature::AllFeature()
{
	BasicFeature *node = new fLength();
	features.push_back(node);
	
	node = new fSum();
	features.push_back(node);
	
	node = new fThirdChar();
	features.push_back(node);
	
	node = new fOdd();
	features.push_back(node);
}
double AllFeature::calc(int feature, People people)
{
	return people.calcEntropy() - features[feature] -> informationGain(people);
}
vector<People> AllFeature::getDivide(int feature, People people)
{
	return features[feature] -> getDivide(people);
}
int AllFeature::findLocate(int feature, string name)
{
	return features[feature] -> findLocate(name);
}