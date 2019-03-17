#include "drones_manager.hpp"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

DronesManager::DronesManager() {
	size = 0;
	first = NULL;
	last = NULL;
}

DronesManager::~DronesManager() {
	while(first) {
		DroneRecord* temp = first->next;
		delete first;
		first = temp;
	}
}

unsigned int DronesManager::get_size() const {
	return size;
}

bool DronesManager::empty() const {
	return (size == 0);
}

DronesManager::DroneRecord DronesManager::select(unsigned int index) const {
	DroneRecord* temp = first;
	for (int s = 0; s < index; s++)
	{
		if (temp->next != NULL)
		{
			temp = temp->next;
		}
		else
		{
			return *last;
		}
	}
	return *temp;
}

unsigned int DronesManager::search(DroneRecord value) const {
	DroneRecord* temp = first;
	int index = 0;
	while (value.droneID != temp->droneID && temp != NULL)
	{
		temp = temp->next;
		index++;
	}
	return index;
}

void DronesManager::print() const {
	DroneRecord* temp = first;
	while (temp != last)
	{
		cout << temp->droneID << setw(10) << temp->range << setw(6)
			 << temp->range << setw(6) << temp->yearBought << setw(8)
			 << temp->droneType << setw(15) << temp->manufacturer << setw(15)
			 << temp->description << setw(20) << temp->batteryType << setw(15);
		temp = temp->next;
	}
}

bool operator==(const DronesManager::DroneRecord& lhs, const DronesManager::DroneRecord& rhs) {
	return lhs.droneID == rhs.droneID;
	if (lhs.droneID == rhs.droneID && lhs.range == rhs.range &&
		lhs.yearBought == rhs.yearBought && lhs.droneType == rhs.droneType &&
		lhs.manufacturer == rhs.manufacturer && lhs.description == rhs.description &&
		lhs.batteryType == rhs.batteryType)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool DronesManager::insert(DroneRecord value, unsigned int index) {
	DroneRecord* temp = first;
	if (empty())
	{
		first = new DroneRecord(value);
		last = first;
		size++;
		return true;
	}
	else if (!empty())
	{
		while (temp != NULL)
		{
			if (value.droneID == temp->droneID)
			{
				return false;
			}
			temp = temp->next;
		}
		temp = first;
		if (index > size)
		{
			return false;
		}
		if (index == size)
		{
			last->next = new DroneRecord(value);
			value.prev = last;
			last = &value;
			size++;
			return true;
		}
		if (index == 0)
		{
			first->prev = new DroneRecord(value);
			value.next = first;
			first = &value;
			size++;
			return true;
		}
		else
		{
			for (int moveIndex = 0; moveIndex < index; moveIndex++)
			{
				temp = temp->next;
			}
			value.next = temp;
			value.prev = temp->prev;
			temp->prev->next = &value;
			temp->prev = &value;
			size++;
			return true;
		}
	}
}

bool DronesManager::insert_front(DroneRecord value) {
	if (empty())
	{
		first = new DroneRecord(value);
		last = first;
		size++;
		return true;
	}
	else
	{
		DroneRecord* temp = first;

		while (temp != NULL)
		{
			if (value.droneID == temp->droneID)
			{
				return false;
			}
			temp = temp->next;
		}

		first->prev = new DroneRecord(value);
		first->prev->next = first;
		first = first->prev;
		size++;
		return true;
	}
	
}

bool DronesManager::insert_back(DroneRecord value) {
	if (empty())
	{
		first = new DroneRecord(value);
		last = first;
		size++;
		return true;
	}
	else
	{
		DroneRecord* temp = first;
		while (temp != NULL)
		{
			if (value.droneID == temp->droneID)
			{
				return false;
			}
			temp = temp->next;
		}
		
	}
	last->next = new DroneRecord(value);
	last->next->prev = last;
	last = last->next;
	size++;
	return true;
}

bool DronesManager::remove(unsigned int index) {
	DroneRecord* temp = first;
	if (empty())
	{	
		return false;
	}
	if (index == 0)
	{
		remove_front();
		size--;
		return true;
	}
	else if (index == size - 1)
	{
		remove_back();
		size--;
		return true;
	}
	else
	{
		for (int moveIndex = 0; moveIndex < index; moveIndex++)
		{
			temp = temp->next;
		}
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		delete temp;
		size--;
		return true;
	}
}

bool DronesManager::remove_front() {
	if (empty())
	{
		return false;
	}
	if (size == 1)
	{
		delete first;
		first = NULL;
		last = first;
	}
	else
	{
		first = first->next;
		delete first->prev;
		first->prev = NULL;
	}
	size--;
	return true;
}

bool DronesManager::remove_back() {
	if (empty())
	{
		return false;
	}
	last = last->prev;
	if (size != 1)
	{
		delete first->prev;
		last->next = NULL;
	}
	size--;
	return true;
}

bool DronesManager::replace(unsigned int index, DroneRecord value) {
	if (index >= size || empty())
	{
		return false;
	}
	DroneRecord* temp = first;
	for (int rep = 0; rep < index; rep++)
	{
		temp = temp->next;
	}
	temp->next->prev = &value;
	temp->prev->next = &value;
	value.next = temp->next;
	value.prev = temp->prev;
	return true;
}

bool DronesManager::reverse_list() {
	if (!empty())
	{
		DroneRecord* temp;
		DroneRecord* temp2;
		temp = last;
		last = first;
		first = temp;
		for (int index = 0; index < size - 1; index++)
		{
			temp2 = temp->prev;
			temp->prev = temp->next;
			temp->next = temp2;
			temp = temp->prev;
		}
	}

	return false;
}

bool DronesManagerSorted::is_sorted_asc() const {
	DroneRecord* temp = first;
	for (int index = 0; index < size; index++)
	{
		if (temp->droneID > temp->next->droneID && temp->next != NULL)
		{
			return false;
		}
		else if (temp->next == NULL)
		{
			return true;
		}
	}
}

bool DronesManagerSorted::is_sorted_desc() const {
	DroneRecord* temp = first;
	for (int index = 0; index < size; index++)
	{
		if (temp->droneID < temp->next->droneID && temp->next != NULL)
		{
			return false;
		}
		else if (temp->next == NULL)
		{
			return true;
		}
	}
}

bool DronesManagerSorted::insert_sorted_asc(DroneRecord val) {
	if (!is_sorted_asc())
	{
		return false;
	}
	DroneRecord* temp = first;
	int index = 0;
	while (val.droneID > temp->droneID)
	{
		temp = temp->next;
		index++;
	}
	if (empty())
	{
		first = &val;
		last = &val;
		size++;
		return true;
	}
	while (temp != NULL)
	{
		if (val.droneID == temp->droneID)
		{
			return false;
		}
		temp = temp->next;
	}
	temp = first;
	if (index == size)
	{
		last->next = &val;
		val.prev = last;
		last = &val;
		size++;
		return true;
	}
	if (index == 0)
	{
		first->prev = &val;
		val.next = first;
		first = &val;
		size++;
		return true;
	}
	else
	{
		for (int moveIndex = 0; moveIndex < index; moveIndex++)
		{
			temp = temp->next;
		}
		val.next = temp;
		val.prev = temp->prev;
		temp->prev->next = &val;
		temp->prev = &val;
		size++;
		return true;
	}
	return false;
}

bool DronesManagerSorted::insert_sorted_desc(DroneRecord val) {
	if (!is_sorted_desc())
	{
		return false;
	}
	DroneRecord* temp = first;
	int index = 0;
	while (val.droneID < temp->droneID)
	{
		temp = temp->next;
		index++;
	}if (empty())
	{
		first = &val;
		last = &val;
		size++;
		return true;
	}
	while (temp != NULL)
	{
		if (val.droneID == temp->droneID)
		{
			return false;
		}
		temp = temp->next;
	}
	temp = first;
	if (index == size)
	{
		last->next = &val;
		val.prev = last;
		last = &val;
		size++;
		return true;
	}
	if (index == 0)
	{
		first->prev = &val;
		val.next = first;
		first = &val;
		size++;
		return true;
	}
	else
	{
		for (int moveIndex = 0; moveIndex < index; moveIndex++)
		{
			temp = temp->next;
		}
		val.next = temp;
		val.prev = temp->prev;
		temp->prev->next = &val;
		temp->prev = &val;
		size++;
		return true;
	}
	return false;
}

void DronesManagerSorted::sort_asc() {
	/*for (int i = 0; i < size; ++i) {
	DroneRecord* temp = first;
	for (int j = 0; j < (size-1); ++j) {
		if (temp->droneID > temp->next->droneID) 
		{
			temp->next->prev = temp->prev;
			temp->prev = temp->next;
			
		}
		temp = temp->next;
	}*/
}

void DronesManagerSorted::sort_desc() {
}
