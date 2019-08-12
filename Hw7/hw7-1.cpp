//Problem 1
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

int main()
{
	vector<string> words;
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
		words.push_back(word);
	}
	
	sort(words.begin(), words.end());

	int copies = 0;
	string str = words[0];
	for(auto e:words)
	{
		if(e == str)
		{
			++copies;
		}
		else
		{
			ofile << str << "  appears " << copies << " times" << endl;
			str = e;
			copies = 1;
		}
	}

	unique(words.begin(), words.end());

	return 0;
}