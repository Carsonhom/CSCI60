#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class Movie
{
private:
    string name;
    string rating; 
    double profit;

public:
    Movie();
    
    Movie(string name, string rating, int profit);
    

    double movieShowing (int n);
    

    void getName(); 
    

    void getRating();
    

    void getProfit();
    

    void setName(string n);
    

    void setRating(string r);
    

    void setProfit(int p);
    

    Movie mergeMovie (Movie m);
    
    
};

