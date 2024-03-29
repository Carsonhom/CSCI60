//Carson Hom, Hw 1, CSCI60
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

struct Animal 
{
    string name;
    string gender;
    int age;
    int price;
    string species;
};

Animal cheapest(string type, Animal a[], int size)
{
    int cheapest = -1;
    int index;
    for (int i = 0; i < size; i++)
    {
        if (a[i].species == type && cheapest == -1)
        {
            index = i;
        }
        else if (a[i].species == type && a[i].price < cheapest)
        {
            index = i;
        }
    }
    return a[index];
}

bool livetogether (Animal a, Animal b)
{
    if (a.species == b.species)
    {
        return true;
    }
    else return false;
}

int main()
{ 
    Animal shelter[20];
    Animal inexpensive = cheapest("Dog", shelter, 20);

    return 0; 
} 

