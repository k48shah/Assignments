#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <cmath>

class Polynomial
{
		int dataSize = 0;
		int* data = NULL;
	public:
		Polynomial(int a[], int size)
		Polynomial();
		Polynomial(string fileName);
		void add(const Polynomial& second);
		void subtract(const Polynomial& second);
		//void multiply(const Polynomial& second);
};
