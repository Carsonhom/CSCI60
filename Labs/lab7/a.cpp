#include <iostream>
#include <string>
#include <set>
#include <fstream>
using namespace std;

int main()
{
	set<string> served;
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
		served.insert(name);
	}
	
	//B b.
	cout << served.size() << endl;

	for(auto e:served)
	{
		ofile << e << endl;
	}

	
	return 0;
}