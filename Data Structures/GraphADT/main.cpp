//Kathan Shah 20713485
//Harim Park 20744108
//Huiseong Kim 20673270


#include <iostream>
#include <string>

#include "GraphADT.hpp"
#include "GraphADT.cpp"

using namespace std;

int main()
{
	GraphADT socialNetwork;
	cout << "Which users would you like to add? (type N/A to stop adding names or EXAMPLE to go to the example"
		 << endl;
	if (!socialNetwork.manualGraph())
	{
		//Insert People into the network
		socialNetwork.insertUser("Darryl");
		socialNetwork.insertUser("Andy");
		socialNetwork.insertUser("Maria");
		socialNetwork.insertUser("Kelsey");
		socialNetwork.insertUser("Brooks");
		socialNetwork.insertUser("Nathan");
		socialNetwork.insertUser("Jess");
		socialNetwork.insertUser("Olive");
		socialNetwork.insertUser("Greg");
		socialNetwork.insertUser("Shelley");
		//Insert Affinities into the network
		socialNetwork.insertAffinity("Darryl", "Andy", 9);
		socialNetwork.insertAffinity("Darryl", "Maria", 2);
		socialNetwork.insertAffinity("Andy", "Brooks", 3);
		socialNetwork.insertAffinity("Andy", "Kelsey", 1);
		socialNetwork.insertAffinity("Maria", "Kelsey", 2);
		socialNetwork.insertAffinity("Maria", "Brooks", 6);
		socialNetwork.insertAffinity("Kelsey", "Nathan", 7);
		socialNetwork.insertAffinity("Brooks", "Nathan", 8);
		socialNetwork.insertAffinity("Brooks", "Jess", 5);
		socialNetwork.insertAffinity("Nathan", "Jess", 1);
		socialNetwork.insertAffinity("Nathan", "Olive", 6);
		socialNetwork.insertAffinity("Jess", "Olive", 7);
		socialNetwork.insertAffinity("Jess", "Shelley", 6);
		socialNetwork.insertAffinity("Olive", "Greg", 10);
		socialNetwork.insertAffinity("Olive", "Shelley", 4);
		socialNetwork.insertAffinity("Greg", "Shelley", 2);
		
		//Djikstra calculation
		socialNetwork.Djikstra("Andy");
	}
	socialNetwork.print();
}

/*
Output(Example):
Which users would you like to add? (type N/A to stop adding names or EXAMPLE to go to the example
EXAMPLE
(Andy)->(Darryl): 5.
(Andy)->(Maria): 3.
(Andy)->(Kelsey): 1.
(Andy)->(Brooks): 3.
(Andy)->(Nathan): 8.
(Andy)->(Jess): 8.
(Andy)->(Olive): 14.
(Andy)->(Greg): 16.
(Andy)->(Shelley): 14.

--------------------------------
Process exited after 4.275 seconds with return value 0
Press any key to continue . . .

Output(Manual):
Using attached graph image
Which users would you like to add? (type N/A to stop adding names or EXAMPLE to go to the example
a
b
c
d
e
f
N/A
Amount of social connections?
9
What is their social network affinity? (type name1 name2 affinity)
a f 14
a c 9
a b 7
b c 10
b d 15
c f 2
c d 11
d e 6
e f 9
Choose someone to calculate smallest path
a
(a)->(b): 7.
(a)->(c): 9.
(a)->(d): 20.
(a)->(e): 20.
(a)->(f): 11.

--------------------------------
Process exited after 116.3 seconds with return value 0
Press any key to continue . . .
*/
