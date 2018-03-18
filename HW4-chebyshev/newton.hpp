//Name: Chris Murphy
//Date:2/20/18
//Assignment: Parameterized Array Class(es) and Polynomial Interpolation
//File name: newton.hpp

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;


template<typename T>
void Newton<T>::addPairs(const Array<T>& xVals, const Array<T>& yVals)
{
	m_xVals = xVals;
	m_fVals.setSize(m_xVals.getSize());
	m_fVals[0] = yVals;
}


template<typename T>
void Newton<T>::genTable()
{
	int offset = 1;
	Array<T> a;
	for(int i = 0; i < m_fVals.getSize()-1; i++)
	{
		//resize to only the size necessary for the current iteration
		a.setSize(m_xVals.getSize() - i - 1);
		for(int j = 0; j < m_fVals[i].getSize()-1; j++)
		{
			a[j] = divDiff(m_xVals[j+offset], m_xVals[j], m_fVals[i][j+1],
						   m_fVals[i][j]);
		}
		m_fVals[i+1] = a;
		offset++;
	}
	return;

}

//Divided difference
template<typename T>
T Newton<T>::divDiff(const T& x1, const T& x0, const T& f1, const T& f0)
{
	T result = ( (f1 - f0) / (x1 - x0) );
	return result;
}

template<typename T>
void Newton<T>::printCoeff()
{
	for(int i = 0; i < m_fVals.getSize(); i++)
	{
		cout << m_fVals[i][0] << endl;
	}
}

template<typename T>
T Newton<T>::getF(const T& x)
{
	T c = 1;
	T f = m_fVals[0][0];	//the calculated f(x) value
	for(int i = 1; i < m_xVals.getSize(); i++)
	{
		//f += (x - m_xVals[i]) * m_fVals[i][0];
		c *= (x - m_xVals[i-1]);
		f += c * m_fVals[i][0];
	}
	return f;
}

template<typename T>
void Newton<T>::printTable()
{
	string s;
	int column = 0;
	cout << fixed;

	int lcv = m_fVals.getSize() - 1;
	int size = 0;
	for(int i = m_xVals.getSize() - 1; i >= 0; i--)
	{
		for(int j = 0; j <= i; j++)
		{
			cout << setw(8) << setprecision(4) << m_fVals[j][lcv - i] << " ";
		}
		cout << endl;
	}

	return;
}