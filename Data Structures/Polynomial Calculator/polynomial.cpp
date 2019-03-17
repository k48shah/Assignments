#include "polynomial.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>


using namespace std;

Polynomial::Polynomial(int a[], int size)
{
	data = new int[size];
	dataSize = size;
	data = a;
	delete [] a;
}

Polynomial::Polynomial()
{
	dataSize = rand() % 10 + 1;
	data = new int[dataSize];
	
	for (int index = 0; index < dataSize; index++)
	{
		int sign = rand() % 2;
		if (sign == 0)
		{
			data[index] = -(rand() % 10);
		}
		else
		{
			data[index] = rand() % 10;
		}
	}
}

Polynomial::Polynomial(string fileName) {
	ifstream fin(fileName.c_str());
	fin >> dataSize;
	data = new int[dataSize];
	for (int index = 0; index < dataSize; index++)
	{
		fin >> data[index];
	}
}

int* Polynomial::GetData()
{
	return data;
}

int Polynomial::GetSize()
{
	return dataSize;
}

void Polynomial::add(const Polynomial& second)
{
	int* sum = NULL;
	if (second.dataSize > dataSize)
	{
		sum = new int[second.dataSize];
		for (int index = 0; index < dataSize; index++)
		{
			sum[index] = second.data[index] + data[index];
		//data[index] += second.data[index];
		}
		for (int index = dataSize; index < second.dataSize; index++)
		{
			sum[index] = second.data[index];
		}
		dataSize = second.dataSize;\
	}
	else
	{
		sum = new int[dataSize];
		for (int index = 0; index < second.dataSize; index++)
		{
			sum[index] = second.data[index] + data[index];
		}
		for (int index = second.dataSize; index < dataSize; index++)
		{
			sum[index] = data[index];
		}\
	}
	delete [] data;
	data = sum;
}

void Polynomial::subtract(const Polynomial& second)
{
	int* difference = NULL;
	if (second.dataSize > dataSize)
	{
		difference = new int[second.dataSize];
		for (int index = 0; index < dataSize; index++)
		{
			difference[index] = data[index] - second.data[index];
		//data[index] += second.data[index];
		}
		for (int index = dataSize; index < second.dataSize; index++)
		{
			difference[index] = -(second.data[index]);
		}
		dataSize = second.dataSize;
	}
	else
	{
		difference = new int[dataSize];
		for (int index = 0; index < second.dataSize; index++)
		{
			difference[index] = data[index] - second.data[index];
		}
		for (int index = second.dataSize; index < dataSize; index++)
		{
			difference[index] = data[index];
		}
	}
	delete [] data;
	data = difference;
}

void Polynomial::multiply(const Polynomial& second)
{
	int multiplySize = dataSize + second.dataSize;
	int* product = new int[multiplySize];
	for (int indexMultiply = 0; indexMultiply < dataSize; indexMultiply++)
	{
		for (int indexMultiplied = 0; indexMultiplied < second.dataSize; 
			 indexMultiplied++)
		{
			product[indexMultiply + indexMultiplied] += data[indexMultiply] * 
				second.data[indexMultiplied];
		}
	}
	
	dataSize = multiplySize;
	delete [] data;
	data = product;
}

Polynomial::~Polynomial()
{
	if (data)
	{
		delete [] data;
	}
}
