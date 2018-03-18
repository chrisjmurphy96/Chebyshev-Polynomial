//Name: Chris Murphy
//Date: 3/1/18
//Assignment: Chebyshev
//File: HCfunc.h

#ifndef HCFUNC_H
#define HCFUNC_H

#include <iostream>
#include "array.h"

using namespace std;

//
// Class for returning the value of the actual function at x (HC = Hard Coded)
//

template<typename T>
class HCfunc
{
	public:
		const Array<T> operator()(Array<T>& nodes);

		const T operator()(const T& x) {return ( 1 / (1 + 12 * pow(x, 2) ) );}
};

#include "HCfunc.hpp"

#endif