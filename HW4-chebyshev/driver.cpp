//Name: Chris Murphy
//Date: 3/1/18
//Assignment: Chess
//File: test.cpp

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include "array.h"
#include "nodegen.h"
#include "HCfunc.h"
#include "interpol.h"
#include "poleval.h"
#include "cheberr.h"
#include "newton.h"
#include "argerr.h"

int main(int argc, char* argv[])
{
	try{

	if(argc != 3)
	{
		ArgErr argument(argc);
		throw argument;
	}

	int N = atoi(argv[1]);
	Array<double> a(N);
	Array<double> y(N);
	NodeGen<double> n;
	HCfunc<double> h;

	a = n(N);
	y = h(a);

	cout << setprecision(8) << fixed;
	cout << "#Data points" << endl;
	for(int i = 0; i < N; i++)
	{
		cout << a[i] << " " << y[i] << endl;
	}
	
	InterPol<double> inter(a, y);

	inter.genTable();

	Array<double> coeff(inter.genCoeff());
	cout << "#Coefficients based on Chebyshev" << endl;
	cout << coeff;

	PolEval<double> p(coeff);

	Array<double> vals(5);
	vals[0] = p(0.1);
	vals[1] = p(0.3);
	vals[2] = p(0.5);
	vals[3] = p(0.7);
	vals[4] = p(0.9);
	cout << "#Chebyshev values" << endl;
	cout << vals;


	Array<double> realVals(5);
	realVals[0] = h(0.1);
	realVals[1] = h(0.3);
	realVals[2] = h(0.5);
	realVals[3] = h(0.7);
	realVals[4] = h(0.9);
	cout << "#Real values" << endl;
	cout << realVals;

	// Read in Newton file
	Newton<double> newt;
	ifstream input;
	int numPairs = 0;
	input.open(argv[2]);
	if(input.is_open())
	{
		input >> numPairs;
		Array<double> xVals(numPairs);
		Array<double> yVals(numPairs);

		for(int i = 0; i < numPairs; i++)
		{
			input >> xVals[i];
			input >> yVals[i];
		}

		newt.addPairs(xVals, yVals);
		newt.genTable();
	}

	Array<double> xVals(5);
	xVals[0] = 0.1;
	xVals[1] = 0.3;
	xVals[2] = 0.5;
	xVals[3] = 0.7;
	xVals[4] = 0.9;

	// Newton value generation
	Array<double> newtVals(5);
	for(int i = 0; i < 5; i++)
	{
		newtVals[i] = newt.getF(xVals[i]);
	}

	// Error generation
	ChebErr<double> c(vals, realVals, newtVals);
	Array<double> absErr(c.absErr(xVals));
	Array<double> relErr(c.relErr(absErr));
	Array<double> relChg(c.relChange());

	cout << "#Absolute error" << endl;
	cout << absErr;
	cout << "#Relative error" << endl;
	cout << relErr;
	cout << "#Relative change" << endl;
	cout << relChg;

	}// end of try
	catch(OOB o)
	{
		cout << "Error!! Tried to access array at " << o << ", which is out of bounds" << endl;
	}
	catch(SizeErr s)
	{
		cout << "Error!! Tried to set size of array to " << s << ". The size should be positive" << endl;
	}
	catch(ArgErr aErr)
	{
		cout << "Error!! You should be providing three arguments. The second should be the number of " << endl;
		cout << "nodes, and the third should be the .txt file" << endl;
		cout << "You tried to use only " << aErr << " arguments" << endl;
	}
	
	return 0;
}