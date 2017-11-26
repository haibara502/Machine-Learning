#include "data.h"

Data::Data()
{
	x.clear();
	y = 0;
}

double Data::calc(weight w)
{
	int weight_x = w.multiply(x);
	return y * weight_x;
}

void Dataset::read_data(string file)
{
	examples.clear();
	freopen(file, "r", stdin);
	string line;
	while (cin.getline(line))
	{
		istringstream is(line);
		int label;
		is >> label;
		string indices;
		vector<pair<int, double> > x;
		while (is >> indices)
		{
			int maohao = indices.find(':');
			istringstream find_index(indices.substr(0, maohao));
			int index;
			find_index >> index;
			istringstream find_value(indices.substr(maohao + 1));
			double value;
			find_value >> value;
			x.push_back(make_pair(index, value));
		}
		examples.push_back(Data(x, label);
	}
}

Data Dataset::pick_random()
{
	int index = round(random() / (double)RAND_MAX * (examples.size() - 1));
	return examples[index];
}
