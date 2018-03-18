//Name: Chris Murphy
//Date:2/20/18
//Assignment: Parameterized Array Class(es) and Polynomial Interpolation
//File name: array.hpp

#include <iostream>
#include "OOB.h"
#include "sizeErr.h"

using namespace std;

template<typename T>
Array<T>::Array(const Array& a): m_size(0), m_data(NULL)
{
	setSize(a.m_size);
	arrayCopy(a);
}

template<typename T>
T& Array<T>::operator[](const int i)
{
	//string s;
	if( (i < 0) || (i >= m_size) )
	{
		OOB o(i);
		//s = "Error!! Index should be between 0 and the size of the array.";
		throw o;
	}
	return m_data[i];

}

template<typename T>
void Array<T>::arrayCopy(const Array<T>& a)
{
	for(int i = 0; i < m_size; i++)
	{
		m_data[i] = a.m_data[i];
	}

	return;
}

template<typename T>
void Array<T>::setSize(const int size)
{
	//string s;
	if(size < 0)
	{
		SizeErr sErr(size);
		//s = "Error!! The size of an array must be 0 or positive";
		throw sErr;
	}

	if(m_size != size)
	{
		//Only delete if we actually have an array
		if(m_data != NULL)
			delete []m_data;
		
		m_data = new T[size];
		m_size = size;
	}
	

	return;
}

template<typename T>
Array<T>& Array<T>::operator=(Array<T> rhs)
{
	/*
	if(m_data != rhs.m_data)
	{
		setSize(rhs.m_size);
		arrayCopy(rhs);
	}
	*/
	
	swap(*this, rhs);

	return *this;
}

template<typename T>
void Array<T>::shiftR()
{
	for(int i = m_size - 1; i > 0; i--)
	{
		m_data[i] = m_data[i-1];
	}
	m_data[0] = 0;
	
}