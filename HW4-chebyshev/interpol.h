//Name: Chris Murphy
//Date: 3/1/18
//Assignment: Chess
//File: interpol.h

#ifndef INTERPOL_H
#define INTERPOL_H

#include <iostream>
#include "array.h"

using namespace std;

///
/// Generates the interpolating polynomal based on the xVals and yVals given at initialization
///

template<typename T>
class InterPol
{
	private:
		Array<T> m_xVals;
		Array<Array<T> > m_fVals;

	public:
		///
		/// Default constructor for Interpol
		/// \pre{ Array class defined }
		/// \post{ InterPol initialized }
		///
		InterPol() {}

		///
		/// Full constructor for InterPol
		/// \pre{ Array class defined }
		/// \pre{ 2 const Array<T> passed by reference, xVals and yVals }
		/// \post{ InterPol initialized with m_xVals = xVals, m_fVals[0] = yVals }
		///
		InterPol(const Array<T>& xVals, const Array<T>& yVals);

		///
		/// Default destructor for InterPol
		/// \pre{ None }
		/// \post{ InterPol deallocated }
		///
		~InterPol() {}

		///
		/// Generates the Newtonian table based on the initial x and y
		/// values.
		/// \pre{ Have non-empty m_xVals and m_fVals }
		/// \post{ m_fVals empty columns are newly generated divided
		///		   difference vales }
		///
		void genTable();

		///
		/// Generates a single entry to be placed in the m_fVals table
		/// based on the divided differences formula.
		/// \pre{ Takes 2 const type T x values by reference and two
		///		  type T const y values by reference. }
		///	\pre{ T should be of a standard numerical type
		///		  (e.g. int, float, double) }
		/// \post{ Returns A T value which is generated according to the
		///		   formula: (f1 - f0) / (x1 - x0) }
		///
		T divDiff(const T& x1, const T& x0, const T& f1, const T& f0);

		///
		/// Prints the current m_fVals table
		/// \pre{ None }
		/// \post{ Displays the current m_fVals which is the Newtonan table }
		///
		void printTable();

		///
		/// Generates the Chebyshev coefficients based on a nested multiplication algorithm
		/// \pre{ Array class defined }
		/// \pre{ Newtonian table(fVals) fully constructed }
		/// \post{ retuns and Array<T> contating the coefficients }
		///
		Array<T> genCoeff();
};

#include "interpol.hpp"

#endif