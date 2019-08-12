#include <iostream>
#include "lbag.h"
#include <set>
using namespace std;


int main(int argc, char *argv[])
{
lbag<int> var;
var.insert(4);
var.insert(7);
var.insert(1);
cout<<var<<endl;
for(auto e:var){
  cout<<e<<endl;
}
lbag<int>::iterator i;
for(i = var.begin(); i!=var.end(); ++i){
  cout<<(*i)<<endl;
}
/*
set<string> s;
s.insert("hi");
s.insert("how");
s.insert("are");
s.insert("hi");
s.insert("you");
//Write a loop to print out everything in s.
for(auto e:s){
  cout<<e<<endl;
}
set<string>::iterator i;
for(i = s.begin(); i!=s.end(); ++i){
  cout<<(*i)<<endl;
}
*/

    return 0;
}
