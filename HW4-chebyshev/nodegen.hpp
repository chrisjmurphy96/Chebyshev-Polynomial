//Name: Chris Murphy
//Date: 3/1/18
//Assignment: Chess
//File: nodegen.hpp

#include <iostream>

using namespace std;

template<typename T>
const Array<T> NodeGen<T>::operator()(int N) const
{
	Array<T> nodes(N);
	N--;

	for(int K = 0; K <= N; K++)
	{
		nodes[K] = cos( ((2 * N) + 1 - (2 * K)) * (M_PI / ((2 * N) + 2)) );
	}

	return nodes;
}