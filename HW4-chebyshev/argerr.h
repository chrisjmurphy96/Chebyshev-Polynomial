//Name: Chris Murphy
//Date: 3/1/18
//Assignment: Chebyshev
//File: 

#ifndef ARGERR_H
#define ARGERR_H

#include <iostream>

using namespace std;

///
/// ArgErr is used to indicate when an incorrect number of arguments is provided to the command line
///

class ArgErr
{
	private:
		int numArgs;
	public:
		///
		/// Default constructor for ArgErr
		/// \pre{ takes an int num }
		/// \post{ constructs an ArgErr with numArgs = num }
		///
		ArgErr(int num): numArgs(num) {}

		///
		/// Default destructor for ArgErr
		/// \pre{ None }
		/// \post{ The ArgErr is deallocated }
		///
		~ArgErr() {}

		///
		/// Returns a stream outputting the number of arguments provided to the command line.
		/// \pre{ ostream available, ArgErr aErr }
		/// \post{ retuns a stream variable containing number of args provided }
		///
		friend ostream& operator<<(ostream& stream, const ArgErr& aErr) {stream << aErr.numArgs; return stream;}
};

#endif