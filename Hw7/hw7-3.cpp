#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
using namespace std;

int main()
{
	map<int, pair<int, vector<string>>> scores;
	ifstream ifile;
	ofstream ofile;
	ifile.open("input3.txt");
	ofile.open("output3.txt");
	if(ifile.fail())
	{
		exit(1);
	}
	if(ofile.fail())
	{
		exit(1);
	}
	
	int score;
	string name;
	while(!ifile.eof())
	{
		// getline(ifile, score, ' ');
		ifile >> score;
		getline(ifile, name);
		scores[score].first++;
		scores[score].second.push_back(name);
		// scores.insert(score, {++, push_back(name)});
		// scores[score], {++, push_back(name)};
	} 

	int possiblescores[11] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int pos = 0;

	for(int i = 0; i < 11; i++)
	{
		cout << possiblescores[i];
		for(int j = 0; j < scores[i].first; j++)
		{
			cout << 'x';
		}
		cout << endl;
	}

	int input;
	cout << "What score would you like to check?: ";
	cin >> input;
	for(auto e:scores[input].second)
	{
		cout << e << ", ";
	}
	cout << endl;

	// for(auto e:scores)
	// {
	// 	ofile << possiblescores[pos];
	// 	pos++;
	// }

	return 0;
}