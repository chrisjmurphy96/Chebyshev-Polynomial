//Name: Chris Murphy
//Date: 3/1/18
//Assignment: Chebyshev
//File: 

#ifndef CHEBERR_H
#define CHEBERR_H

#include <iostream>
#include <cmath>
#include "array.h"

using namespace std;

///
/// ChebErr is used to generate the absolute and relative errors of the Chebyshev polynomial, as
/// well as the relative change from the Newton polynomial to the Chebyshev polynomial.
///

template<typename T>
class ChebErr
{
	private:
		Array<T> chebVals;
		Array<T> realVals;
		Array<T> newtVals;

	public:
		///
		/// Constructor for ChebErr
		/// \pre{ Array class defined }
		/// \pre{ 3 const Array<T> passed by reference, one for Chebyshev values, one for
		/// 	  real function values, and one for Newton values }
		/// \post{ ChebErr initialized }
		///
		ChebErr(const Array<T>& c, const Array<T>& r, const Array<T>& n): 
				chebVals(c), realVals(r), newtVals(n)	{}

		///
		/// Default destructor for ChebErr
		/// \pre{ None }
		/// \post{ ChebErr deallocated }
		///
		~ChebErr() {}

		///
		/// Generates absolute error values for Chebyshev
		/// \pre{ Array class defined }
		/// \pre{ Array<T> passed by reference xVals }
		/// \post{ generates and returns an Array<T> which is the absolute error for Chebyshev }
		///
		Array<T> absErr(Array<T>& xVals);

		///
		/// Generates relative error values for Chebyshev
		/// \pre{ Array class defined }
		/// \pre{ Array<T> passed by reference xVals }
		/// \post{ generates and returns an Array<T> which is the relative error for Chebyshev }
		///
		Array<T> relErr(Array<T>& xVals);

		///
		/// Generates the relative change for Chebyshev from Newton
		/// \pre{ Array class defined }
		/// \post{ generates and returns an Array<T> which is the relative change for Chebyshev from Newton }
		///
		Array<T> relChange();
};

#include "cheberr.hpp"

#endif