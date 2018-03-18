//Name: Chris Murphy
//Date: 3/1/18
//Assignment: Chebyshev
//File: cheberr.hpp

#include <iostream>
#include <cmath>

using namespace std;

template<typename T>
Array<T> ChebErr<T>::absErr(Array<T>& xVals)
{
	Array<T> absolute(xVals.getSize());

	for(int i = 0; i < absolute.getSize(); i++)
	{
		absolute[i] = abs(realVals[i] - chebVals[i]);
	}

	return absolute;
}

template<typename T>
Array<T> ChebErr<T>::relErr(Array<T>& errVals)
{
	Array<T> relative(errVals.getSize());

	for(int i = 0; i < relative.getSize(); i++)
	{
		relative[i] = (100 * ( errVals[i] / realVals[i] ) );
	}

	return relative;
}

template<typename T>
Array<T> ChebErr<T>::relChange()
{
	Array<T> relative(newtVals.getSize());

	for(int i = 0; i < relative.getSize(); i++)
	{
		relative[i] = (100 * ( abs( newtVals[i] - chebVals[i] ) / newtVals[i]) );
	}

	return relative;
}