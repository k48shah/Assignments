#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

void readCurrentFile (ifstream & fin, string title[], bool status[], const int SPACES) // bool function is true for staff, false for students
{
	int staff = 0, parkingSpace = 0;
	string name = "";
	
	for (int index = 0; index < SPACES; index++)
	{
		fin >> staff >> name >> parkingSpace; //read in data
		title[parkingSpace - 1] = name;		//assign the name to parking spot
		status[parkingSpace - 1] = staff;	//assign job status to parking spot
	}
}

int readAddOrRemove(ifstream & readIn, bool status[], string name[])
{
	int numberOfPeople = 0;
	while (readIn >> status[numberOfPeople] >> name[numberOfPeople])
	{
		numberOfPeople++;
	}
	return numberOfPeople;
	
}

void freeSpaces(string ownerRemove, string currentOwner[])
{
	
	for (int index = 0; index < 50; index++)
		if (ownerRemove == currentOwner[index])
			currentOwner = "Available";
			
	
}

bool assignSpaces(bool status, string newOwner)
{
		if (/*function E*/ == true && status == 1)
		{
		
			//Do not know how to configure this function
		
		}
			
	
}

int main()
{
	
	const int TOTALSPACES = 50;
	int parking[TOTALSPACES] = {0};
	
	ifstream fremove("parking_remove.txt");
	ifstream fadd("parking_add.txt");
	ifstream fcurrent("parking_current.txt");
	
	if (!fremove || !fadd)
		cout << "A file is missing";
		
	bool parkingStatus[TOTALSPACES] = {0};
	string parkingOwner[TOTALSPACES] = " ";
	readCurrentFile (fcurrent, parkingOwner, parkingStatus, TOTALSPACES);
	string parkingOwnerCurrent[TOTALSPACES] = parkingOwner[TOTALSPACES];
	bool parkingStatusCurrent[TOTALSPACES] = parkingStatus[TOTALSPACES];
	
	for (int index = 0; index < addOrRemove(fremove, parkingStatus, parkingOwner); index++)
	{
		string removeOwner = parkingStatus[index]
		freeSpaces(parkingOwner, parkingOwnerCurrent);
		
	}
	
	for (int index = 0; index < addOrRemove(fadd, parkingStatus, parkingOwner); index++)
	{
		string assignOwner = parkingOwner[index]
		bool assignStatus = parkingStatus[index]
		assignSpaces(parkingStatus, parkingOwner);
		
	}
	
}
