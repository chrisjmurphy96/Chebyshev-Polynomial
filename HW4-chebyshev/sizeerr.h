//Name: Chris Murphy
//Date: 3/1/18
//Assignment: Chebyshev
//File: sizeErr.h

#ifndef SIZE_ERR
#define SIZE_ERR

#include <iostream>

using namespace std;

///
/// SizeErr is used to indicate when an Array attempts to be set to an invalid size (size < 0).
///

class SizeErr
{
	private:
		int size;
	public:
		///
		/// Default constructor for SizeErr
		/// \pre{ takes an int s }
		/// \post{ constructs a SizeErr with size = s }
		///
		SizeErr(int s): size(s) {}

		///
		/// Default destructor for SizeErr
		/// \pre{ None }
		/// \post{ The SizeErr is deallocated }
		///
		~SizeErr() {}

		///
		/// Returns a stream outputting the size the Array tried to set itself to.
		/// \pre{ ostream available, SizeErr class sErr}
		/// \post{ returns a stream variable containing size }
		///
		friend ostream& operator<<(ostream& stream, const SizeErr& sErr) {stream << sErr.size; return stream;}
};

#endif