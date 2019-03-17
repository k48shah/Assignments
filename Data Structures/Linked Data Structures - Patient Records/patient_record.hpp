//Kathan Shah 20713485
//Harim Park 20744108
#ifndef PATIENTRECORD_HPP
#define PATIENTRECORD_HPP

#include <iostream>
#include <string>

using namespace std;

class PatientRecord
{
		unsigned int categoryID;
		unsigned int patientID;
		string name;
		string address;
		string birthDate;
	public:
		PatientRecord();
		PatientRecord(unsigned int newCatID, unsigned int newPatID, 
					  string newName, string newAddress, string newDOB);
		unsigned int getCatID();
		unsigned int getPatID();
		string getName();
		string getAddress();
		string getDOB();
};

#endif
