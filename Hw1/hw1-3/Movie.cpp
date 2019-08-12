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
    Movie()
    {        
        name = "";
        rating = "G";
        profit = 0;       
    }

    Movie(string name, string rating, int profit)
    {
        name = name;
        rating = rating;
        profit = profit;   
    }

    double movieShowing (int n)
    {
        return profit += (((double)n) * 12.00);
    }

    void getName() 
    {
        cout << name;
    }

    void getRating()
    {
        cout << rating;
    }

    void getProfit()
    {
        cout << profit;
    }

    void setName(string n)
    {
        name = n;
    }

    void setRating(string r)
    {
        rating = r;
    }

    void setProfit(int p)
    {
        profit = p;
    }

    Movie mergeMovie (Movie m)
    {
        if (name == m.name)
        {
            int r;
            int p;
            if (rating == "G")
            {
                if (m.rating == "PG")
                {
                    rating = "PG";
                }
                else if (m.rating == "PG-13")
                {
                    rating = "PG-13";
                }
                else if (m.rating == "R")
                {
                    rating = "R";
                }
            }
            else if (rating == "PG")
            {
                if (m.rating == "PG-13")
                {
                    rating = "PG-13"; 
                }
                else if (m.rating == "R")
                {
                    rating = "R";
                }
            }
            else if (rating == "PG-13")
            {
                if (m.rating == "R") 
                {
                    rating = "R";
                }
            }
            



            p = profit + m.profit;
            return Movie(name, rating, p);
        }
        else 
            return Movie("Could not combine", "", 0);
        
    }
};

