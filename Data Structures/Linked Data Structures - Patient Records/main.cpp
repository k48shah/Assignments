//Kathan Shah 20713485
//Harim Park 20744108
#include <iostream>
#include "records_manager.hpp"
#include "patient_record.hpp"
#include "records_manager_test.hpp"
#include <iomanip>

using namespace std;

int main()
{
	RecordsManager patRec = RecordsManager();
	RecordsManagerTest recTest;
	//Add random patients to fill blank array
	patRec.insertRecord(1000, 300, "J.A.R.V.I.S", "Tony Stark's Apt.", "Y2K");
	patRec.insertRecord(1001, 256, "Harim Park", "954 Westview Crescent", 
						"25/09/99");
	patRec.insertRecord(1004, 212, "Igor Ivkovic", "RCH 301", "01/05/74");
	patRec.insertRecord(1001, 213, "Sonic the Hedgehog", "Green Hills", 
						"23/06/91");
	patRec.insertRecord(1003, 212, "Tim Horton", "Everywhere", "01/01/01");
	string testNum;
	cout << "Which test would you like to run (1-10)" << endl;
	cin >> testNum;
	RecordsManager* patRecPointer = &patRec;
	bool testsuccess = false;
	if (testNum == "1")
	{
		testsuccess = recTest.test1(patRecPointer);
	}
	else if (testNum == "2")
	{
		testsuccess = recTest.test2(patRecPointer);
	}
	else if (testNum == "3")
	{
		testsuccess = !(recTest.test3(patRecPointer));
	}
	else if (testNum == "4")
	{
		testsuccess = recTest.test4(patRecPointer);
	}
	else if (testNum == "5")
	{
		testsuccess = recTest.test5(patRecPointer);
	}
	else if (testNum == "6")
	{
		testsuccess = !(recTest.test6(patRecPointer));
	}
	else if (testNum == "7")
	{
		testsuccess = !(recTest.test7(patRecPointer));
	}
	else if (testNum == "8")
	{
		testsuccess = recTest.test8(patRecPointer);
	}
	else if (testNum == "9")
	{
		testsuccess = recTest.test9(patRecPointer);
	}
	else { }
	cout << "Category ID:" << setw(20) 
			 << "Patient ID:" << setw(25) << "Name:" 
			 << setw(27) << "Address:" << setw(20)
			 << "DOB:" << endl << "------------------------------------------------------------------------------------------------------------------------" << endl;
	patRec.print();
	if (testsuccess)
	{
		cout << endl << "success" << endl;
	}
	else
	{
		cout << endl << "fail" << endl;
	}
	if (patRec.getSize() > 0)
	{
		patRec.~RecordsManager();
	}
	return 0;
}

/* Output::

First test: Inserting into list (different category)

Which test would you like to run (1-8)
1
Category ID:         Patient ID:                    Name:                   Address:                DOB:
------------------------------------------------------------------------------------------------------------------------
1000                 300                      J.A.R.V.I.S          Tony Stark's Apt.                 Y2K
1001                 213               Sonic the Hedgehog                Green Hills            23/06/91
1001                 256                       Harim Park      954 Westview Crescent            25/09/99
1002                 315                Inserted Identity              Random Street            31/10/96
1003                 212                       Tim Horton                 Everywhere            01/01/01
1004                 212                     Igor Ivkovic                    RCH 301            01/05/74

success

--------------------------------
Process exited after 0.8165 seconds with return value 0
Press any key to continue . . .


Second Test: Inserting into list (same category, different patient ID)

Which test would you like to run (1-8)
2
Category ID:         Patient ID:                    Name:                   Address:                DOB:
------------------------------------------------------------------------------------------------------------------------
1000                 300                      J.A.R.V.I.S          Tony Stark's Apt.                 Y2K
1000                 500                       Same CatID              Sesame Street            32/13/19
1001                 213               Sonic the Hedgehog                Green Hills            23/06/91
1001                 256                       Harim Park      954 Westview Crescent            25/09/99
1003                 212                       Tim Horton                 Everywhere            01/01/01
1004                 212                     Igor Ivkovic                    RCH 301            01/05/74

success

--------------------------------
Process exited after 2.012 seconds with return value 0
Press any key to continue . . .


Third test: Inserting same CatID and PatID into list

Which test would you like to run (1-8)
3
Category ID:         Patient ID:                    Name:                   Address:                DOB:
------------------------------------------------------------------------------------------------------------------------
1000                 300                      J.A.R.V.I.S          Tony Stark's Apt.                 Y2K
1001                 213               Sonic the Hedgehog                Green Hills            23/06/91
1001                 256                       Harim Park      954 Westview Crescent            25/09/99
1003                 212                       Tim Horton                 Everywhere            01/01/01
1004                 212                     Igor Ivkovic                    RCH 301            01/05/74

success

--------------------------------
Process exited after 1.071 seconds with return value 0
Press any key to continue . . .

//We successfully eradicated The HackerMan from changing data of an already instantiated patient

Fourth test: Remove from list

Which test would you like to run (1-8)
4
Category ID:         Patient ID:                    Name:                   Address:                DOB:
------------------------------------------------------------------------------------------------------------------------
1000                 300                      J.A.R.V.I.S          Tony Stark's Apt.                 Y2K
1001                 213               Sonic the Hedgehog                Green Hills            23/06/91
1001                 256                       Harim Park      954 Westview Crescent            25/09/99
1004                 212                     Igor Ivkovic                    RCH 301            01/05/74

success

--------------------------------
Process exited after 1.396 seconds with return value 0
Press any key to continue . . .


Fifth Test: Surpass capacity (Insert into full list) (test capacity = 7)

Which test would you like to run (1-8)
5
Category ID:         Patient ID:                    Name:                   Address:                DOB:
------------------------------------------------------------------------------------------------------------------------
1000                 300                      J.A.R.V.I.S          Tony Stark's Apt.                 Y2K
1001                 213               Sonic the Hedgehog                Green Hills            23/06/91
1001                 256                       Harim Park      954 Westview Crescent            25/09/99
1003                 212                       Tim Horton                 Everywhere            01/01/01
1004                 212                     Igor Ivkovic                    RCH 301            01/05/74
1011                 323                   Test Subject 2                Test Street            24/12/99
1024                 276                    Over Capacity                    Unknown            25/12/95
1030                  65                   Test Subject 1                Test Street            24/12/99

success

--------------------------------
Process exited after 1.545 seconds with return value 0
Press any key to continue . . .


Sixth Test: Remove from empty list (Commented out additional patients)

Which test would you like to run (1-8)
6
Category ID:         Patient ID:                    Name:                   Address:                DOB:
------------------------------------------------------------------------------------------------------------------------

success

--------------------------------
Process exited after 1.823 seconds with return value 0
Press any key to continue . . .


Seventh Test: Remove non-existing record from list

Which test would you like to run (1-8)
7
Category ID:         Patient ID:                    Name:                   Address:                DOB:
------------------------------------------------------------------------------------------------------------------------
1000                 300                      J.A.R.V.I.S          Tony Stark's Apt.                 Y2K
1001                 213               Sonic the Hedgehog                Green Hills            23/06/91
1001                 256                       Harim Park      954 Westview Crescent            25/09/99
1003                 212                       Tim Horton                 Everywhere            01/01/01
1004                 212                     Igor Ivkovic                    RCH 301            01/05/74

success

--------------------------------
Process exited after 1.686 seconds with return value 0
Press any key to continue . . .


Eighth Test: Insert into start and end of list

Which test would you like to run (1-8)
8
Category ID:         Patient ID:                    Name:                   Address:                DOB:
------------------------------------------------------------------------------------------------------------------------
1000                 299                   Test Subject 2                Test Street            24/12/99
1000                 300                      J.A.R.V.I.S          Tony Stark's Apt.                 Y2K
1001                 213               Sonic the Hedgehog                Green Hills            23/06/91
1001                 256                       Harim Park      954 Westview Crescent            25/09/99
1003                 212                       Tim Horton                 Everywhere            01/01/01
1004                 212                     Igor Ivkovic                    RCH 301            01/05/74
2030                  65                   Test Subject 1                Test Street            24/12/99

success

--------------------------------
Process exited after 1.634 seconds with return value 0
Press any key to continue . . .

Nineth Test: Remove from start and end of list

Which test would you like to run (1-10)
9
Category ID:         Patient ID:                    Name:                   Address:                DOB:
------------------------------------------------------------------------------------------------------------------------
1001                 213               Sonic the Hedgehog                Green Hills            23/06/91
1001                 256                       Harim Park      954 Westview Crescent            25/09/99
1003                 212                       Tim Horton                 Everywhere            01/01/01

success

--------------------------------
Process exited after 1.789 seconds with return value 0
Press any key to continue . . .

(lol)

*/
