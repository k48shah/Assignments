#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

int hours (int time_hhmmss)
{
	int time_hh = time_hhmmss / 10000;
	return time_hh;
}

int minutes(int time_hhmmss)
{
	int time_mm = (time_hhmmss / 100) % 100;
	return time_mm;
}

int seconds (int time_hhmmss)
{
	int time_ss = time_hhmmss % 100;
	return time_ss;
}

int main() {
	ifstream fin("wascally_wabbits.txt");
	if (!fin)
		return 0;
	
	double hhmmss;
	fin >> hhmmss;
	cout << hours(hhmmss) << ":" << minutes(hhmmss) << ":" << seconds(hhmmss);
	
}
