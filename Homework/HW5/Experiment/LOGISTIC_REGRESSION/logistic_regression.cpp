#include "logistic_regression.h"

void LogisticRegression::read_dataset(int index)
{
	cout << "Start to read the dataset" << endl;
	for (int i = 0; i < 5; ++i) if (i != index)
	{
		string file = string("training0") + char(i + '0') + string(".data");
		cout << file << endl;
		train_dataset.read_data(file);
	}
	cout << "Training data reading done." << endl;
	cout << "Training dataset size is: " << train_dataset.size() << endl;
	string cv_file = string("training0") + char(index + '0') + string(".data");
	cv_dataset.read_data(cv_file);
	cout << "CV data reading done." << endl;
	cout << "Size of CV dataset is: " << cv_dataset.size() << endl;

	string test_file = "speeches.test.liblinear";
	test_dataset.read_data(test_file);
	cout << test_dataset.size() << endl;
	cout << "Test data reading done." << endl;
}

LogisticRegression::LogisticRegression()
{
	cout << "Please input epoch: ";
	cin >> epoch;

	double _r;
	cout << "Please input initial learning rate: ";
	cin >> _r;
	r = new LearningRate(_r);
	cout << "Please input the square of the tradeoff parameter sigma: ";
	cin >> sigma;
	cout << "Please input the number of cv set(from 0 to 4): ";
	int cv_index; 
	cin >> cv_index;
	read_dataset(cv_index);	
	cout << "All data read done." << endl;

	int dimension;
	cout << "Please input the dimension of feature: ";
	cin >> dimension;

	w = new Weight(dimension);
	cout << "Weight initialization done." << endl;
}

double LogisticRegression::sigmoid(double v)
{
	return 1 / (1 + exp(-v));
}

double LogisticRegression::get_accuracy(Dataset dataset)
{
	double all = dataset.size();
	int correct = 0;
	for (int i = 0; i < dataset.size(); ++i)
	{
		double value = dataset.pick(i).calc(*w);
		double probability = sigmoid(-value);
		int label = bool(probability >= 0.5);
		if (label == dataset.pick(i).get_label())
			correct ++;
	}
	all = correct / all;
	return all;
}

void LogisticRegression::cross_validate()
{
	double accuracy = get_accuracy(cv_dataset);
	cout << "The cross-validation accuracy is: " << accuracy << endl;
}

void LogisticRegression::train()
{
	cout << "Start the training process." << endl;
	for (int i = 0; i < LogisticRegression::epoch; ++i)
	{
		cout << "This is epoch " << i << endl;
		double current_accuracy = get_accuracy(train_dataset);
		cout << "The training accuracy is: " << current_accuracy << endl;

		Data example = train_dataset.pick_random();
		double y_w_x = -example.calc(*w);
		double predict = sigmoid(y_w_x);

		double value = (1 - sigmoid(y_w_x)) * (-example.get_label());
		if (bool(predict >= 0.5) != example.get_label())
			w -> update(r -> getLearningRate(i), value, sigma, example.get_vector(), example.get_label());

		cross_validate();
	}
	cout << "Do you want to store current weight vector?(y/n)" << endl;
	string answer;
	cin >> answer;
	if (answer == "y")
		output_weight();
}

void LogisticRegression::test()
{
	cout << "Do you want to read existed weight vector?(y/n)" << endl;
	string answer;
	cin >> answer;
	if (answer == "y")
		read_weight();

	double accuracy = get_accuracy(test_dataset);
	cout << "The test accuracy is: " << accuracy << endl;
}

void LogisticRegression::read_weight()
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
	w -> copy(weights);	
	cout << "Read done." << endl;
}

void LogisticRegression::output_weight()
{
	cout << "Please input the file name to output to: ";
	string file;
	cin >> file;
	freopen(file.c_str(), "w", stdout);
	w -> output();
	cout << "Write done." << endl;
}
