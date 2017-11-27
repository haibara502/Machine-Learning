#include "weight.h"

Weight::Weight(int n)
{
	w.clear();
	for (int i = 0; i < n; ++i)
		w.push_back(0);
}

void Weight::update(double r, double c, Data x)
{
	for (int i = 0; i < w.size(); ++i)
		w[i] *= (1 - r.learning_rate());

	for (int i = 0; i < w.size(); ++i)
		w[i] += r.learning_rate() * c * x.x[i] * x.y;
}

double Weight::multiply(vector<pair<int, double> > x)
{
	double ans = 0;
	int pos = 0;
	for (int i = 0; i < w.size(); ++i)
		if ((pos < x.size()) && (x[pos].first == i))
		{
			ans += w[i] * x[pos].second;
			++pos;
		}
	return ans;
}

void Weight::copy(vector<double> _w)
{
	w = _w;
}
