#include "train.h"

void SVM::Train()
{
	for (int i = 0; i < epoch; ++i)
	{
		Data example = dataset.pick_random();
		double value = dataset.calc(w);
		if (value <= 1)
			w.update(r.learning_rate(i), c, example);
		else
			w.update(r.learning_rate(i), 0, example);
	}
}

void SVM::read_weight(string file)
{
	freopen(file, "r", stdin);
	vector<double> weights;
	string line;
	cin >> line;
	istringstream is(line);
	double value;
	while (is >> value)
		weights.push_back(value);
	w.copy(weights);	
}

void SVM::output_weight(string file)
{
	freopen(file, "w", stdout);
	w.output();
}

SVM::SVM()
{

}
