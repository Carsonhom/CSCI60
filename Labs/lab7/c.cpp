#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <fstream>
using namespace std;

int main()
{
	vector<string> served;
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
		served.push_back(name);
	}
	
	//B a.
	cout << "The total number of people served is: " << served.size() << endl;

	for(auto e:served)
	{
		ofile << e << endl;
	}
	return 0;
}