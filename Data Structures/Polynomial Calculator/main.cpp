//Kathan Shah 20713485
//Harim Park 20744108
#include "polynomial.hpp"

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

void displayPolynomial(Polynomial displayed, int* arrayLoc)
{
	for (int index = 0; index < displayed.GetSize(); index++)
	{
		if (index == displayed.GetSize() - 1)
		{
			cout << *(arrayLoc+index) << "x^" << index << endl;
		}
		else
		{
			cout << *(arrayLoc+index) << "x^" << index << " + ";
		}
	}
}

int main() 
{
	srand((unsigned)time(0)); //A seed used to make rand() work properly and
							  //not produce the same numbers on multiple
							  //executions.
	Polynomial first;
	cout << "Choose a method to create a polynomial(create/random/file)" << 
			endl;
	string method;
	cin >> method;
	if (method == "create")
	{
		cout << "Enter degree of the polynomial (max 9)" << endl;
		int degree = 0;
		cin >> degree;
		cout << "Enter coefficients for each degree (x^0 -> x^n)" << endl;
		int* coeff = new int[degree + 1];
		for (int index = 0; index <= degree; index++)
		{
			cin >> coeff[index];
		}
		first = Polynomial(coeff, degree + 1);
		delete [] coeff;
	}
	else if (method == "random")
	{
		first = Polynomial();
	}
	else if (method == "file")
	{
		cout << "Enter file name" << endl;
		string fileName;
		cin >> fileName;
		first = Polynomial(fileName);
	}
	int* p_firstData = first.GetData();
	displayPolynomial(first, p_firstData);
	
	
	srand((unsigned)time(0) + 1);
	
	Polynomial second;
	cout << "Choose a method to create a polynomial(create/random/file)" << 
			endl;
	cin >> method;
	if (method == "create")
	{
		cout << "Enter degree of the polynomial (max 9)" << endl;
		int degree = 0;
		cin >> degree;
		cout << "Enter coefficients for each degree (x^0 -> x^n)" << endl;
		int coeff[10] = {0};
		for (int index = 0; index <= degree; index++)
		{
			cin >> coeff[index];
		}
		second = Polynomial(coeff, degree + 1);
	}
	else if (method == "random")
	{
		second = Polynomial();
	}
	else if (method == "file")
	{
		cout << "Enter file name" << endl;
		string fileName;
		cin >> fileName;
		second = Polynomial(fileName);
	}
	int* p_secondData = second.GetData();
	displayPolynomial(second, p_secondData);
	
	
	cout << "Choose an operation(add/subtract/multiply)"<< endl;
	string operation;
	cin >> operation;
	if (operation == "add")
	{
		first.add(second);
		p_firstData = first.GetData();
		displayPolynomial(first, p_firstData);
	}
	if (operation == "subtract")
	{
		first.subtract(second);
		p_firstData = first.GetData();
		displayPolynomial(first, p_firstData);
	}
	if (operation == "multiply")
	{
		first.multiply(second);
		p_firstData = first.GetData();
		displayPolynomial(first, p_firstData);
	}
	first.~Polynomial();
	second.~Polynomial();
	return 0;
}

/*
Output 1 (Create Polynomials through array and add):
Choose a method to create a polynomial(create/random/file)
create
Enter degree of the polynomial (max 9)
2
Enter coefficients for each degree (x^0 -> x^n)
1
2
3
1x^0 + 2x^1 + 3x^2
Choose a method to create a polynomial(create/random/file)
create
Enter degree of the polynomial (max 9)
5
Enter coefficients for each degree (x^0 -> x^n)
6
5
4
3
2
1
6x^0 + 5x^1 + 4x^2 + 3x^3 + 2x^4 + 1x^5
Choose an operation(add/subtract/multiply)
add
7x^0 + 7x^1 + 7x^2 + 3x^3 + 2x^4 + 1x^5

--------------------------------
Process exited after 22.18 seconds with return value 0
Press any key to continue . . .


Output 2 (Random Polynomial Creation and Subtract):
Choose a method to create a polynomial(create/random/file)
random
1x^0 + -2x^1 + 0x^2 + -1x^3
Choose a method to create a polynomial(create/random/file)
random
-9x^0 + -7x^1 + -3x^2 + 6x^3 + -7x^4
Choose an operation(add/subtract/multiply)
subtract
10x^0 + 5x^1 + 3x^2 + -7x^3 + 7x^4

--------------------------------
Process exited after 18.9 seconds with return value 0
Press any key to continue . . .


Output 3 (File Polynomials and multiply):
FILES:
first.txt:
2
1
2

second.txt:
7
1
7
2
6
3
5
4

Choose a method to create a polynomial(create/random/file)
file
Enter file name
first.txt
1x^0 + 2x^1
Choose a method to create a polynomial(create/random/file)
file
Enter file name
second.txt
1x^0 + 7x^1 + 2x^2 + 6x^3 + 3x^4 + 5x^5 + 4x^6
Choose an operation(add/subtract/multiply)
multiply
1x^0 + 9x^1 + 16x^2 + 10x^3 + 15x^4 + 11x^5 + 14x^6 + 8x^7 + 0x^8

--------------------------------
Process exited after 16.96 seconds with return value 0
Press any key to continue . . .

Empty Polynomial:
Choose a method to create a polynomial(create/random/file)
create
Enter degree of the polynomial (max 9)
0
Enter coefficients for each degree (x^0 -> x^n)

0
0x^0
Choose a method to create a polynomial(create/random/file)
create
Enter degree of the polynomial (max 9)
0
Enter coefficients for each degree (x^0 -> x^n)
0
0x^0
Choose an operation(add/subtract/multiply)
add
0x^0

--------------------------------
Process exited after 29.2 seconds with return value 0
Press any key to continue . . .

Empty file:
Choose a method to create a polynomial(create/random/file)
file
Enter file name
first.txt
Choose a method to create a polynomial(create/random/file)
file
Enter file name
second.txt
Choose an operation(add/subtract/multiply)
subtract

--------------------------------
Process exited after 18.72 seconds with return value 0
Press any key to continue . . .

//DOES NOT GIVE A RESULT
*/

