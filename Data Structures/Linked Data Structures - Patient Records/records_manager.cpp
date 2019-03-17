//Kathan Shah 20713485
//Harim Park 20744108
#include "records_manager.hpp"
#include <iomanip>

using namespace std;

RecordsManager::RecordsManager()
{
	capacity = 128;
	data = new PatientRecord*[capacity];
	size = 0;
}

RecordsManager::RecordsManager(int nCap)
{
	capacity = nCap;
	if (capacity < 128)
	{
		capacity = 128;
	}
	data = new PatientRecord*[capacity];
	size = 0;
}

RecordsManager::~RecordsManager()
{
	delete [] data;	
}

int RecordsManager::getSize()
{
	return size;
}

int RecordsManager::getCapacity()
{
	return capacity;
}

void RecordsManager::print()
{
	for (int index = 0; index < size; index++)
	{
		cout << data[index]->getCatID() << setw(20) 
			 << data[index]->getPatID() << setw(33) << data[index]->getName() 
			 << setw(27) << data[index]->getAddress() << setw(20)
			 << data[index]->getDOB() << endl;
	} 
}
bool RecordsManager::insertRecord(unsigned int newCatID, unsigned int newPatID, 
								  string newName, string newAddress, 
								  string newDOB)
{
	if (size == capacity)
	{
		capacity *= 2;
		PatientRecord** temp = new PatientRecord*[capacity];
		for (int index = 0; index < capacity/2; index++)
		{
			temp[index] = data[index];
		}
		delete [] data;
		data = temp;
	}
	
	bool foundID = false;
	int placeAt = 0;
	for (int index = 0; index < size; index++)
	{
		if (data[index]->getCatID() == newCatID)
		{
			if (newPatID == data[index]->getPatID())
			{
				return false;
			}
			else if(newPatID < data[index]->getPatID() && foundID == false)
			{
				foundID = true;
				placeAt = index;
			}
		}
		else if(newCatID < data[index]->getCatID() && foundID == false)
		{
			foundID = true;
			placeAt = index;
		}
	}
	if (!foundID)
	{
		data[size] = new PatientRecord(newCatID, newPatID, newName, newAddress,
								   newDOB);
	}
	else
	{
		for (int index = size; index >= placeAt; index--)
		{
			data[index + 1] = data[index]; 
		}
		data[placeAt] = new PatientRecord(newCatID, newPatID, newName, newAddress,
									   newDOB);
	}
	size++;
	return true;
}

bool RecordsManager::removeRecord(unsigned int categoryID, 
								  unsigned int patientID)
{
	if (size == (1/4)*capacity)
	{
		capacity /= 2;
		if (capacity < 128)
		{
			capacity = 128;
		}
		PatientRecord** temp = new PatientRecord*[capacity];
		for (int index = 0; index < capacity/2; index++)
		{
			temp[index] = data[index];
		}
		delete [] data;
		data = temp;
	}
	bool removed = false;
	if (size == 0)
	{
		return removed;
	}
	for (int index = 0; index < size; index++)
	{
		if (data[index]->getCatID() == categoryID)
		{
			if (data[index]->getPatID() == patientID)
			{
				delete data[index];
				removed = true;
			}
			if (data[index]->getPatID() > patientID && removed)
			{
				data[index - 1] = data[index];
			}  
			
		}
		if (data[index]->getCatID() > categoryID && removed)
		{
			data[index - 1] = data[index];
		}
	}
	if (removed)
	{
		size--;
	}
	return removed;
}


