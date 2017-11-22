#include "data.h"

Data::Data()
{
	x.clear();
	y = 0;
}

void Dataset::read_data(string file)
{
	freopen(file, "r", stdin);
	string line;
	while (cin.getline(line))
	{
		istringstream is(line);
		int label;
		is >> label;
	}
}
