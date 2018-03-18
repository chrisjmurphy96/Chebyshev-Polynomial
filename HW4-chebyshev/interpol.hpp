//Name: Chris Murphy
//Date: 3/1/18
//Assignment: Chess
//File: interpol.hpp

#include <iostream>

using namespace std;

template<typename T>
InterPol<T>::InterPol(const Array<T>& xVals, const Array<T>& yVals): m_xVals(xVals)
{
	m_fVals.setSize(yVals.getSize());
	m_fVals[0] = yVals;
}

template<typename T>
void InterPol<T>::genTable()
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

template<typename T>
T InterPol<T>::divDiff(const T& x1, const T& x0, const T& f1, const T& f0)
{
	//T result = ( (f1 - f0) / (x1 - x0) );
	return ( (f1 - f0) / (x1 - x0) );
}

template<typename T>
void InterPol<T>::printTable()
{
	string s;
	//int column = 0;
	cout << fixed;

	int lcv = m_fVals.getSize() - 1;
	//int size = 0;
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

template<typename T>
Array<T> InterPol<T>::genCoeff()
{
	//T c = m_fVals[m_fVals.getSize() - 1][0];
	Array<T> shifter(m_xVals);
	Array<T> a(m_fVals.getSize());
	for(int i = 0; i < m_fVals.getSize(); i++)
	{
		a[i] = m_fVals[i][0];
	}

	for(int j = 0; j < a.getSize(); j++)
	{
		for(int i = a.getSize() - 2; i >= 0; i--)
		{
			a[i] = a[i] + (0 - shifter[i]) * a[i + 1];
		}
		shifter.shiftR();
	}
	return a;
}