//Name: Chris Murphy
//Date: 3/1/18
//Assignment: Chess
//File: HCfunc.hpp

#include <iostream>
#include <cmath>

template<typename T>
const Array<T> HCfunc<T>::operator()(Array<T>& nodes)
{
	Array<T> yVals(nodes.getSize());

	for(int i = 0; i < nodes.getSize(); i++)
	{
		yVals[i] = ( 1 / (1 + 12 * pow(nodes[i], 2) ) );
	}

	return yVals;
}