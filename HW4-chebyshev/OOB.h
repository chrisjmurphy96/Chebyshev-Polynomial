//Name: Chris Murphy
//Date: 3/1/18
//Assignment: Chebyshev
//File: OOB.h

#ifndef OOB_H
#define OOH_H

#include <iostream>

using namespace std;

//
// OOB = Out of Bounds. A class to be thrown when a user attempts to access outside of Array's bounds.
//

class OOB
{
	private:
		int m_ind;

	public:
		///
		/// Default constructor for OOB
		/// \pre{ takes an int ind }
		/// \post{ constructs an OOB with m_ind = ind }
		///
		OOB(const int ind): m_ind(ind) {}

		///
		/// Default destructor for OOB
		/// \pre{ None }
		/// \post{ The OOB is deallocated }
		///
		~OOB() {}

		///
		/// Returns a stream outputting the index the Array tried to access.
		/// \pre{ ostream available, OOB class o}
		/// \post{ retuns a stream variable containing m_ind }
		///
		friend ostream& operator<<(ostream& stream, const OOB& o) {stream << o.m_ind; return stream;}
};

#endif