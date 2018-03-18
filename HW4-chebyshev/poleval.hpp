//Name: Chris Murphy
//Date: 3/1/18
//Assignment: Chebyshev
//File: poleval.hpp

#include <iostream>
#include <iomanip>
#include <cmath>
#include "array.h"

using namespace std;

template<typename T>
const T PolEval<T>::operator()(const T& x)
{
	T result = 0;

	for(double i = 0; i < coeff.getSize(); i++)
	{
		result += coeff[i] * (pow(x, i));
	}

	return result;
}