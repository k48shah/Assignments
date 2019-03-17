//Kathan Shah & Ronny Paredes
#include <iostream>
#include <cmath>

using namespace std;

bool sort_three_numbers(float & num_1, float & num_2, float & num_3)
{
	
	int swapVariation = 0;
	while (num_1 <= num_2 || num_2 <= num_3)
	{
		float temp = num_1;
		
		if (swapVariation % 2 == 0)
		{
			num_1 = num_3;
			num_3 = temp;
		}
		else
		{
			num_1 = num_2;
			num_2 = temp; 
		}
		swapVariation++;
	}
	if (swapVariation == 0)
		return true;
	else
		return false;
}

int main()
{
	
	float value1 = 0, value2 = 0, value3 = 0;
	do
	{
	cout << "Enter three numbers to be sorted:" << endl;
	cin >> value1 >> value2 >> value3;
	} while (value1 == value2 || value2 == value3 || value1 == value3);
	if (sort_three_numbers(value1, value2, value3) == true)
		cout << "These numbers were already given in descending order" << endl;
	cout << value1 << " " << value2 << " " << value3;
	
	return 0;
}

/*
Outputs:

Enter three numbers to be sorted:
13
12
14
14 13 12
--------------------------------
Process exited after 4.929 seconds with return value 0
Press any key to continue . . .

Enter three numbers to be sorted:
12
13
14
14 13 12
--------------------------------
Process exited after 69.66 seconds with return value 0
Press any key to continue . . .

Enter three numbers to be sorted:
12 14 13
14 13 12
--------------------------------
Process exited after 14.64 seconds with return value 0
Press any key to continue . . .

Enter three numbers to be sorted:
13 14 12
14 13 12
--------------------------------
Process exited after 5.121 seconds with return value 0
Press any key to continue . . .

Enter three numbers to be sorted:
14 12 13
14 13 12
--------------------------------
Process exited after 6.332 seconds with return value 0
Press any key to continue . . .

Enter three numbers to be sorted:
14 13 12
These numbers were already given in descending order
14 13 12
--------------------------------
Process exited after 35.25 seconds with return value 0
Press any key to continue . . .

Enter three numbers to be sorted:
14 14 12
Enter three numbers to be sorted:
12 13 14
14 13 12
--------------------------------
Process exited after 7.764 seconds with return value 0
Press any key to continue . . .


*/
