//Program to illustrate the perceptron training rule
#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <fstream>
using namespace std;

int testsigmoid()
{
	float w[3]; //array to hold perceptron weights

	float t, o;
	const double eta = .1;
	int i;

	int count = 0;

	bool correct = 0;

	//define and initialize training data
	//and function
	/*int train [4] [3] = {0, 0, 0,
	0, 1, 0,
	1, 0, 0,
	1, 1, 1 };*/

	//or function
	int train[4][3] = { 0, 0, 0,
		0, 1, 1,
		1, 0, 1,
		1, 1, 1 };

	//xor function
	/*int train [4] [3] = {0, 0, 0,
	0, 1, 1,
	1, 0, 1,
	1, 1, 0 };*/

	int x0, x1, x2; //will hold the inputs

	float weightsum, deltaw0, deltaw1, deltaw2;

	ofstream outfile;
	outfile.open("sigout.txt");

	if (outfile.fail())
	{
		cout << "file failed to open";
		abort();
	}



	//initialize random number generator
	srand((unsigned)(time(0)));

	rand();

	//initialize threshold
	x0 = 1;


	w[0] = (float)(rand()) / (32767 / 2) - 1;


	for (i = 1; i < 3; ++i)
		w[i] = (float)(rand()) / (32767 / 2) - 1;

	cout << "INITIAL WEIGHTS" << endl
		<< "---------------" << endl;

	cout << "w0 = " << w[0] << endl;
	cout << "w1 = " << w[1] << endl;
	cout << "w2 = " << w[2] << endl;

	//implement perceptron training rule as long as training examples are
	//classified incorrectly
	//while(!correct)
	for (int j = 0; j < 1000; j++)
	{
		correct = 1;

		count++;

		for (i = 0; i < 4; ++i)
		{

			x1 = train[i][0]; //input for x1
			x2 = train[i][1]; //input for x2

			//find weighted sum of inputs and threshold values
			weightsum = x0 * w[0] + x1 * w[1] + x2 * w[2];


			//determine output of sigmoid
			o = (float)(1 / (1 + exp(-weightsum)));

			//determine true ouput
			t = train[i][2];

			//deltaw0 = eta * (t - o) * x0;
			w[0] = w[0] + eta * (t - o)*o*(1 - o)*x0;

			//deltaw1 = eta * (t - o) * x1;
			w[1] = w[1] + eta * (t - o)*o*(1 - o)*x1;

			//deltaw2 = eta * (t - o) * x2;
			w[2] = w[2] + eta * (t - o)*o*(1 - o)*x2;

			correct = 0;



		}
	}


	//OUTPUT
	cout << endl << endl;
	cout << "FINAL WEIGHTS" << endl
		<< "-------------" << endl;
	cout << "w0 = " << w[0] << endl;
	cout << "w1 = " << w[1] << endl;
	cout << "w2 = " << w[2] << endl;

	cout << "The delta rules were invoked " << count << " times" << endl;


	//output to file

	outfile << w[0] << endl;
	outfile << w[1] << endl;
	outfile << w[2] << endl;

	outfile.close();


	return 0;
}