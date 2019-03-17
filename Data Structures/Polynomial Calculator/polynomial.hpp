#ifndef POLYNOMIAL_HPP
#define POLYNOMIAL_HPP
#include <iostream>
#include <string>

class Polynomial {
		int dataSize = 0;
		int* data = NULL;
	public:
		Polynomial();
		Polynomial(int a[], int size);
		Polynomial(std::string fileName);
		~Polynomial();
		void add(const Polynomial& second);
		void subtract(const Polynomial& second);
		void multiply(const Polynomial& second);
		int* GetData();
		int GetSize();
};

#endif
