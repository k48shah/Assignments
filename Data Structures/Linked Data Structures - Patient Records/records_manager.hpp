//Kathan Shah 20713485
//Harim Park 20744108
#ifndef RECORDSMANAGER_HPP
#define RECORDSMANAGER_HPP
#include <iostream>
#include <string>
#include "patient_record.hpp"

using namespace std;

class RecordsManager
{
		int capacity;
		int size;
		PatientRecord** data = NULL;
	public:
		RecordsManager();
		RecordsManager(int nCap);
		~RecordsManager();
		int getSize();
		int getCapacity();
		void print();
		bool insertRecord(unsigned int newCatID, unsigned int newPatID, 
							 string newName, string newAddress, string newDOB);
		bool removeRecord(unsigned int newCatID, unsigned int newPatID);
		friend class RecordsManagerTest;
};

#endif
