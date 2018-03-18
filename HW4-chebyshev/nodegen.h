//Name: Chris Murphy
//Date: 3/1/18
//Assignment: Chess
//File: nodegen.h

#ifndef NODEGEN_H
#define NODEGEN_H

#include <iostream>
#include <cmath>
#include "array.h"

using namespace std;

//
// Class for generating the nodes to be used by Chebyshev
//

template<typename T>
class NodeGen
{
	public:
		///
		/// Generates the nodes for a Chebyshev polynomial of nth degree
		/// \pre{ Array class defined }
		/// \pre{ Returns an Array<T> which contains the x values which are the Chebyshev nodes }
		///
		const Array<T> operator()(const int N) const;
};

#include "nodegen.hpp"

#endif