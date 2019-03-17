//Kathan Shah 20713485
//Harim Park 20744108
//Huiseong Kim 20673270


#include "GraphADT.hpp"

using namespace std;

GraphADT::GraphADT()
{
	capacity = 50;
	list = new User*[capacity];
	size = 0;
	for (int i = 0; i < 50; i++)
	{
		for (int j = 0; j < 50; j++)
		{
			affinity[i][j] = 10000; //Assumed the affinity will never be this high
		}
	}
}

GraphADT::GraphADT(int capacity)
{
	if (capacity > 50 || capacity < 0)
	{
		capacity = 50;
	}
	list = new User*[capacity];
	size = 0;
	for (int i = 0; i < 50; i++)
	{
		for (int j = 0; j < 50; j++)
		{
			affinity[i][j] = 10000; //Assumed the affinity will never be this high
			if (i == j)
			{
				affinity[i][j] = 0;
			}
		}
	}
}

GraphADT::~GraphADT()
{
	for (int i = 0; i < size; i++)
	{
		delete list[i];
		list[i] = NULL;
	}
	delete [] list;
}

bool GraphADT::empty()
{
	return (size == 0);
}

int GraphADT::getCapacity()
{
	return capacity;
}

int GraphADT::getSize()
{
	return size;
}

int GraphADT::getIndex(string name)
{
	if (empty())
	{
		return -1;
	}
	for (int index = 0; index < size; index++)
	{
		if (list[index]->person == name)
		{
			return index;
		}
	}
	return -1;
}

int GraphADT::getAffinity(string name1, string name2)
{
	return affinity[getIndex(name1)][getIndex(name2)];
}

bool GraphADT::insertUser(string name)
{
	if (size == capacity)
	{
		return false;
	}
	list[size] = new User(name, size + 1);
	size++;
	return true;
}

bool GraphADT::insertAffinity(string name1, string name2, int distance)
{
	if (getIndex(name1) == -1 || getIndex(name2) == -1)
	{
		return false;
	}
	affinity[getIndex(name1)][getIndex(name2)] = distance;
	affinity[getIndex(name2)][getIndex(name1)] = distance;
	return true;
}

int* GraphADT::Djikstra(string name)
{
	int* minDist = new int[size];
	for (int index = 0; index < size; index++)
	{
		minDist[index] = 1000;
	}
	int distIndex = getIndex(name);
	minDist[distIndex] = 0;
	bool* used = new bool[size];
	for (int iterate = 0; iterate < size - 1; iterate++)
	{
		int min = 10000;
		int compIndex = 0;
		for (int index = 0; index < size; index++)
		{
			if (minDist[index] < min && !used[index])
			{
				min = minDist[index];
				compIndex = index;
			}
		}
		int compDist = min;
		for (int compare = 0; compare < size; compare++)
		{
			if (!used[compare] && (affinity[compIndex][compare] + minDist[compIndex] < minDist[compare]))
			{
				minDist[compare] = affinity[compIndex][compare] + minDist[compIndex];
			}
		}
		used[compIndex] = true;
	}
	minimumDist = minDist;
	return minDist;
}

void GraphADT::print()
{
	string personName;
	for (int nameIndex = 0; nameIndex < size; nameIndex++)
	{
		if (minimumDist[nameIndex] == 0)
		{
			personName = list[nameIndex]->person;
		}
	}
	for (int i = 0; i < size; i++)
	{
		if (personName != list[i]->person && minimumDist[i] < 1000)
		{
			cout << "(" << personName << ")->(" << list[i]->person << "): " 
			 	 << minimumDist[i] << ". " << endl;
		}
	}
}

bool GraphADT::manualGraph()
{
	string addUser;
	do
	{
		cin >> addUser;
		if (addUser != "N/A")
		{
			insertUser(addUser);
		}
	} while (addUser != "N/A" && addUser != "EXAMPLE");
	if (addUser == "N/A" && getSize() > 1)
	{
		int addAffinity = 0;
		string name1, name2;
		cout << "Amount of social connections?" << endl;
		int numCon = 0;
		cin >> numCon;
		cout << "What is their social network affinity? (type name1 name2 affinity)"
			 << endl;
		for (int i = 0; i < numCon; i++)
		{
			cin >> name1 >> name2 >> addAffinity;
			if (getIndex(name1) != -1 && getIndex(name2) != -1 && addAffinity != -1)
			{
				insertAffinity(name1, name2, addAffinity);
			}
		}
		cout << "Choose someone to calculate smallest path" << endl;
		string calcUser;
		cin >> calcUser;
		Djikstra(calcUser);
		return true;
	}
	else
	{
		return false;
	}
}
