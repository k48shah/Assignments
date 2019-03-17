//Kathan Shah 20713485
//Harim Park 20744108
//Huiseong Kim 20673270


#ifndef GRAPH_ADT_HPP
#define GRAPH_ADT_HPP
#include <iostream>
#include <string>

using namespace std;

class GraphADT
{
public:
	struct User
	{
		int index;
		string person;
		User(string newPerson, int newIndex) :
			person(newPerson), index(newIndex) {}
	};
private:
	User** list;
	int affinity[50][50];
	int* minimumDist;
	unsigned int capacity;
	unsigned int size;
	
public:
	GraphADT();
	GraphADT(int capacity);
	~GraphADT();
	int getCapacity();
	int getSize();
	int getIndex(string name);
	int getAffinity(string name1, string name2);
	bool empty();
	bool insertUser(string newUser);
	bool insertAffinity(string name1, string name2, int distance);
	int* Djikstra(string name);
	void print();
	bool manualGraph();
};


#endif
