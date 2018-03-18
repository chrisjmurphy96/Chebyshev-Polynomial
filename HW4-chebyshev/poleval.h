//Name: Chris Murphy
//Date: 3/1/18
//Assignment: Chebyshev
//File: poleval.h

#ifndef POLEVAL_H
#define POLEVAL_H

#include <iostream>
#include <iomanip>
#include "array.h"

using namespace std;

///
/// Evaluates the Chebyshev polynomal at point x
///

template<typename T>
class PolEval
{
	private:
		Array<T> coeff;

	public:
		///
		/// Constructor for PolEval
		/// \pre{ Array class defined }
		/// \pre{ Takes an Array<T> c which is the coefficients }
		/// \post{ PolEval initialized with coeff = c }
		///
		PolEval(Array<T> c): coeff(c) {}

		///
		/// Default destructor for PolEval
		/// \pre{ None }
		/// \post{ PolEval deallocated }
		///
		~PolEval() {}

		///
		/// Operator overload for ()
		/// \pre{ Array class defined }
		/// \pre{ takes a const int by reference x }
		/// \post{ Returns the Chebyshev polynomial value evaluated at x }
		///
		const T operator()(const T& x);

};

#include "poleval.hpp"

#endif