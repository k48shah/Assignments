//Kathan Shah 20713485
//Harim Park 20744108
#include "patient_record.hpp"

using namespace std;

PatientRecord::PatientRecord()
{
	categoryID = 0;
	patientID = 0;
	name;
	address;
	birthDate;
}

PatientRecord::PatientRecord(unsigned int newCatID, unsigned int newPatID, 
							 string newName, string newAddress, string newDOB)
{
	categoryID = newCatID;
	patientID = newPatID;
	name = newName;
	address = newAddress;
	birthDate = newDOB;
}

unsigned int PatientRecord::getCatID()
{
	return categoryID;
}

unsigned int PatientRecord::getPatID()
{
	return patientID;
}

string PatientRecord::getName()
{
	return name;
}

string PatientRecord::getAddress()
{
	return address;
}

string PatientRecord::getDOB()
{
	return birthDate;
}
