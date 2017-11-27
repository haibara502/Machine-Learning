#include "svm.h"

void SVM::read_dataset(int index)
{
	for (int i = 0; i < 5; ++i) if (i != index)
	{
		string file = string("training0") + char(i + '0') + string(".data");
		train_dataset.read_data(file);
	}
	string cv_file = string("training0") + char(index + '0') + string(".data");
	cv_dataset.read_data(cv_file);

	string test_file = "speeches.test.liblinear";
	test_dataset.read_data(test_file);
}

SVM::SVM()
{
	cout << "Please input epoch: ";
	cin >> epoch;

	double _r;
	cout << "Please input initial learning rate: ";
	cin >> _r;
	r = LearningRate(_r);
	cout << "Please input initial parameter C: ";
	cin >> c;
	cout << "Please input the number of cv set(from 0 to 4): ";
	int cv_index; 
	cin >> cv_index;
	read_dataset(cv_index);	
	cout << "All data read done." << endl;
	int dimension;
	cout << "Please input the dimension of feature: ";
	cin >> dimension;

	w = Weight(dimension);
	cout << "Weight initialization done." << endl;
}

double SVM::get_accuracy(Dataset dataset)
{
	double all = dataset.size();
	int correct = 0;
	for (int i = 0; i < dataset.size(); ++i)
	{
		double value = dataset.pick(i).calc(w);
		int label = 1;
		if (value < 0)
			label = -1;
		if (label == dataset.pick(i).get_label())
			correct ++;
	}
	all = correct / all;
	return all;
}

void SVM::cross_validate()
{
	double accuracy = get_accuracy(cv_dataset);
	cout << "The cross-validation accuracy is: " << accuracy << endl;
}

void SVM::train()
{
	cout << "Start the training process." << endl;
	for (int i = 0; i < SVM::epoch; ++i)
	{
		cout << "This is epoch " << i << endl;
		double current_accuracy = get_accuracy(train_dataset);
		cout << "The training accuracy is: " << current_accuracy << endl;

		Data example = train_dataset.pick_random();
		double value = example.calc_error(w);
		if (value <= 1)
			w.update(r.getLearningRate(i), c, example.get_vector(), example.get_label());
		else
			w.update(r.getLearningRate(i), 0, example.get_vector(), example.get_label());
		cross_validate();
	}
	cout << "Do you want to store current weight vector?(y/n)" << endl;
	string answer;
	cin >> answer;
	if (answer == "y")
		output_weight();
}

void SVM::test()
{
	cout << "Do you want to read existed weight vector?(y/n)" << endl;
	string answer;
	cin >> answer;
	if (answer == "y")
		read_weight();

	double accuracy = get_accuracy(test_dataset);
	cout << "The test accuracy is: " << accuracy << endl;
}

void SVM::read_weight()
{
	cout << "Please input the file name to read from: ";
	string file;
	cin >> file;
	freopen(file.c_str(), "r", stdin);

	vector<double> weights;
	string line;
	cin >> line;
	istringstream is(line);
	double value;
	while (is >> value)
		weights.push_back(value);
	w.copy(weights);	
	cout << "Read done." << endl;
}

void SVM::output_weight()
{
	cout << "Please input the file name to output to: ";
	string file;
	cin >> file;
	freopen(file.c_str(), "w", stdout);
	w.output();
	cout << "Write done." << endl;
}
