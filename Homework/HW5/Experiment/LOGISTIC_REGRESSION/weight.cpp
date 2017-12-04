#include "weight.h"

Weight::Weight(int n)
{
	w.clear();
	for (int i = 0; i < n; ++i)
		w.push_back(0);
}

void Weight::update(double r, double value, double sigma, vector<pair<int, double> > x, int y)
{
	for (int i = 0; i < w.size(); ++i)
		w[i] += -r * 2 / sigma * w[i];

	for (int i = 0; i < x.size(); ++i)
		w[x[i].first] += -r * value * x[i].second;
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

void Weight::output()
{
	for (int i = 0; i < w.size(); ++i)
		cout << w[i] << ' ';
	cout << endl;
}
