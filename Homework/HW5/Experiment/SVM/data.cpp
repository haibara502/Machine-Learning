#include "data.h"

Data::Data()
{
	y = 0;
	x.clear();
}

double Data::calc(Weight w)
{
	double weight_x = w.multiply(x);
	return y * weight_x;
}

int Data::get_label()
{
	return y;
}

vector<pair<int, double> > Data::get_vector()
{
	return x;
}

void Dataset::read_data(string file)
{
	freopen(file.c_str(), "r", stdin);
	string line;
	while (getline(cin, line))
	{
		istringstream is(line.c_str());
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
		examples.push_back(Data(x, label));
	}
}

Dataset::Dataset()
{
	examples.clear();
}

Data Dataset::pick_random()
{
	int index = round(random() / (double)RAND_MAX * (examples.size() - 1));
	return examples[index];
}

int Dataset::size()
{
	return examples.size();
}

Data Dataset::pick(int index)
{
	return examples[index];
}
