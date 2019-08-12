//Carson Hom, Hw 1, CSCI60
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

void writeletter(string names[], int size, char letter, ofstream& out)
{
	for (int i = 0; i < size; i++)
	{
		if (names[i].at(1) == letter)
		{
			// out.write(names[i], sizeof(names[i]));
			
			
			out << names[i] << endl;
		}
	}
}

int main()
{ 
	string names[6];
	int nCount = 0;
    ifstream ifile ("inames.txt");
    ofstream ofile ("onames.txt");
    if (ifile.fail()) exit(1);
    if (ofile.fail()) exit(1);
    while (!ifile.eof())
    {
    	string name;
    	getline(ifile, name);
    	names[nCount] = name;
    	cout << name;
    	nCount++;
    }
    char alpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    for (int i = 0; i < 26; i++)
    {
    	writeletter(names, 6, alpha[i], ofile);
    }
    ifile.close();
    ofile.close();
    return 0; 
} 

