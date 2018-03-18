//Name: Chris Murphy
//Date:2/20/18
//Assignment: Parameterized Array Class(es) and Polynomial Interpolation
//File name: array.h

#include <iostream>

using namespace std;

#ifndef ARRAY_H
#define ARRAY_H

///
/// \Class: Array
/// \Functions as a standard array with the addition of a setSize() and
/// \getSize() function. Like a standard array it will work with any
///	\basic data type or class.
///

template<typename T>
class Array
{
	private:
		int m_size;
		T* m_data;
		void arrayCopy(const Array& a);

	public:

		///
		/// Empty constructor for the array class. Generates an array
		/// of size 0 and with no elements.
		/// \pre{None}
		/// \post{Initializes an array of size 0 with no elements}
		///
		Array(): m_size(0), m_data(NULL) {}

		///
		/// Constructor for the array class that takes a single int
		/// as an arg and makes an array of that size.
		/// \pre{Takes a const 0 or positive integer which denotes
		///	     the size of the array to be generated.}
		/// \post{Generates an array the size of the passed integer}
		///
		Array(const int size): m_size(size), m_data(new T[size]) {}

		///
		/// Copy constructor for the Array class
		/// \pre{Takes a const Array by reference}
		/// \post{Generates an Array identical to the passed Array}
		///
		Array(const Array& a);

		///
		/// Move constructor for Array
		/// \pre{ Takes an Array a by rvalue reference }
		/// \post{ This Array has identical values to the passed array a }
		///
		Array(Array&& a) {swap(*this, a);}

		///
		/// Destructor for the Array class. Deletes the dynamic array
		/// member variable.
		/// \pre{None}
		/// \post{Deletes the dynamic array member m_data}
		///
		~Array() {delete []m_data;}

		///
		/// Overloads the [] operator to return a reference to a cell
		/// in the Array just as in a normal C++ array.
		/// \pre{Takes a const int i which is the element to be returned}
		/// \post{Returns a T reference to the element at i}
		/// \post{OOB class included}
		/// \post{throws an OOB object when an invalid index is called}
		///
		T& operator[](const int i);

		///
		/// Overloads the standard swap to work for Array
		/// \pre{ namespace std established }
		/// \pre{ takes 2 Arrays by reference (lhs and rhs) }
		/// \post{ lhs takes on the same values as rhs }
		///
		friend void swap(Array<T>& lhs, Array<T>& rhs)
		{
			swap(lhs.m_data, rhs.m_data);
			swap(lhs.m_size, rhs.m_size);

			return;
		}

		///
		/// operator=
		/// Overloads the = operator so that when an Array = Array
		/// occurs the left side Array copies the right side Array.
		/// \pre{Takes a const Array reference which is the variable
		///		  on the right side of the = sign}
		///	\post{Returns a reference to an array which is identical
		/// 	   to the right side Array}
		///
		Array& operator=(Array rhs);

		friend ostream& operator<<(ostream& stream, const Array& a)
		{
			for(int i = 0; i < a.m_size; i++)
			{
				stream << a.m_data[i] << " " << endl;
			}

			return stream;
		}		

		///
		/// setSize
		/// Deletes m_data (the current array) and then changes
		/// the size of the array and changes m_data to the new size
		/// (but now with all cells with a value of 0).
		/// Throws an error message if the new size is < 0
		/// \pre{Takes a const int size >= 0 which will be the new size of m_data}
		/// \pre{SizeErr class included}
		/// \post{m_data is cleared and newly generated with a size
		/// 	   equal to the passed integer. m_size is set to be equal
		/// 	   to the passed integer. If the passed size was < 0 a SizeErr object
		///		   is thrown instead.}
		///
		void setSize(const int size);

		///
		/// getSize
		/// Returns the current size of the Array
		/// \pre{None}
		/// \post{Returns an int which is the value of m_size}
		///
		int getSize() const {return m_size;}

		///
		/// shiftR
		/// Shifts the entire array right by one element, leaving a 0 where the leftmost entry from the
		/// the passed value was
		///
		void shiftR();

};

#include "array.hpp"

#endif