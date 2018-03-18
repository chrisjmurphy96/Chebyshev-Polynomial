//Name: Chris Murphy
//Date:2/20/18
//Assignment: Parameterized Array Class(es) and Polynomial Interpolation
//File name: newton.h

#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#include "array.h"

using namespace std;

#ifndef NEWTON_H
#define NEWTON_H

///
/// \Class: Newton
/// Encapsulates all the necessary functionality of a a Newtonian
/// Divided Differences table. Necessary being table generation,
/// getting function values, and relative and absolute errors.
///

template<typename T>
class Newton
{
	private:
		Array<T> m_xVals;
		Array<Array<T> > m_fVals;

	public:
		///
		/// Default constructor when 0 arguments are provided
		/// pre{ None }
		/// \post{ A Newton is generated with an empty m_xVals and an
		///		   empty m_fVals }
		///
		Newton() {}

		///
		/// Copy constructor for the Newton class
		/// \pre{A const Newton reference n is passed}
		/// \post{ The current Newton copies n's m_xVals and m_fVals
		////	   effectively making this Newton n's copy }
		///
		Newton(const Newton& n);

		///
		/// Destructor for Newton class
		/// \pre{ None }
		/// \post{ The Newton is deallocated }
		///
		~Newton() {}

		///
		/// Initializes the x values and y values of the Newtonigan table
		/// \pre{ Takes a const Array<T> xVals by reference and a
		///		  const Array<T> yVals by reference }
		/// \post{ Sets m_xVals = xVals and m_fVals[0] = yVals }
		///
		void addPairs(const Array<T>& xVals, const Array<T>& yVals);

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
		T divDiff(const T& x1, const T& x0, const T& y1, const T& y0);

		///
		///	Prints out the coefficients of the formula generated in a
		/// Newtonian divided differences table.
		/// \pre{A generated m_fVals and non-empty m_xVals}
		/// \post{Prints out the coefficients that will be used
		///		   to generate f(x)}
		///
		void printCoeff();

		///
		/// Returns the Newtonian function value at x
		/// \pre{ Takes a const T reference which denotes the x to evaluate
		///		  f(x) at }
		/// \pre{ Requires a non-empty m_xVals and m_fVals }
		/// \post{ Returns a T which is the estimated function value at x } 
		///
		T getF(const T& x);

		///
		/// Returns the actual value of f at x
		/// \pre{ Takes a const T reference x which is the x value to be evaluated }
		/// \post{ Returns a T which is the actual value of f at x. The formula
		///		   is: 1 / (1 + 12 * (x^2) ) }
		///
		T getRealF(const T& x) {return ( 1 / (1 + 12 * pow(x, 2) ) );}

		///
		/// Returns the absolute error at the x value passed
		/// \pre{ Takes a const T reference x which denotes the current x value }
		/// \pre{ Requires that m_fVals be filled out from tableGen() }
		/// \post{ Returns a T which is the absolute error at x. The formula
		///		   is: |(actual value at x) - (estimated value at x)| }
		///
		T absErr(const T& x) {return abs( getRealF(x) - getF(x) );}

		///
		/// Returns the relative error at the x value passed
		/// \pre{ Takes a const T reference x which denotes the current x value }
		/// \pre{ Requires that m_fVals be filled out from tableGen() }
		/// \post{ Returns a T which is the relative error at x. The formula
		///		   is: (100 * absoluteError(x) / (actual value at x)) }
		///
		T relErr(const T& x) {return (100 * ( absErr(x) / getRealF(x) ) );}

		///
		/// Prints the current m_fVals table
		/// \pre{ None }
		/// \post{ Displays the current m_fVals which is the Newtonan table }
		///
		void printTable();

};

#include "newton.hpp"

#endif