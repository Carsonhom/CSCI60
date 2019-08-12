#include "dynamicBag.h"
#include <iostream>
using namespace std;
int main(){

int x = 10;
dynamicBag b;
b.insert(5);
b.insert(70);
for(int i=0; i<5; i++)
    b.insert(i+1);
for(int i=0; i<b.size(); i++)
    cout<<b[i]<<endl;
b.erase(5);
for(int i=0; i<b.size(); i++)
    cout<<b[i]<<endl;
return 0;
}//destroy x and b - C++ will give back all memory on the stack, and will call b's destructor if we've written one.
