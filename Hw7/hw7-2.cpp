//Problem 2
#include <iostream>
#include <string>
#include <set>
#include <fstream>
using namespace std;

int main()
{
	set<string> words;
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

	string word;
	while(!ifile.eof())
	{
		ifile >> word;
		words.insert(word);
	}
	
	for(auto e:words)
	{
		ofile << e << endl;
	}

	
	return 0;
}

//Warm up Problem 3
//I prefer using a vector because it has all the same functionality as a set
//and can do more such as counting the number of times a word appears in a 
//novel