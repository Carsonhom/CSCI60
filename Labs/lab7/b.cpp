#include <iostream>
#include <string>
#include <set>
#include <map>
#include <fstream>
using namespace std;

int main()
{
	map<string, int> served;
	ifstream ifile;
	ofstream ofile;
	ifile.open("input.txt");
	ofile.open("output.txt");
	if(ifile.fail())
	{
		exit(1);
	}
	if(ofile.fail())
	{
		exit(1);
	}

	string name;
	while(!ifile.eof())
	{
		getline(ifile, name);
		served[name]++;
	}
	

	double total = 0;
	for(auto e:served)
	{
		ofile << e.first << ", " << e.second << endl;
		total += e.second;
	}

	cout << "The average number of times an individual recieved service is: " << (total / served.size()) << endl;
	return 0;
}