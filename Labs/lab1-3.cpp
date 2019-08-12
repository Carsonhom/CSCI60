#include<iostream>
#include<fstream>
#include<string>
using namespace std;

struct Time{//military time, no am/pm
int hour;
int minute;
};

Time earlier(Time t1, Time t2){
    Time ret;
    if(t1.hour == t2.hour){
        if(t1.minute<t2.minute)
            ret = t1;
        else
            ret = t2;
    }
    else if(t1.hour<t2.hour){
        ret = t1;
    }
    else{
        ret = t2;
    }
    return ret;
}

class Carpool{
public:
    string names[5];
    int numofpeople;
    Time time;
    Carpool combineCarpool(Carpool car2){
    if (numofpeople + car2.numofpeople <= 5) {
        Carpool car3;
        for (int i = 0; i < numofpeople; i++) {
            car3.names[i] = names[i];
        }
        int k = 0;
        for (int j = numofpeople; j <= numofpeople + car2.numofpeople; j++) {
            
            car3.names[j] = car2.names[k];
            k++;
        }
        car3.numofpeople = numofpeople + car2.numofpeople;
        car3.time = earlier(time, car2.time);
        return car3;
    }
    else {
        Carpool car3;
        car3.numofpeople = 0;
        return car3;
    }
    }
    void print(){
        for (int i = 0; i < numofpeople; i++) {
            cout << names[i] << endl;
        }
        cout << numofpeople << endl;
        cout << time.hour << ", ";
        cout << time.minute << endl;
    }


};



int main()
{ 
    Carpool car1;
    cout << "How many people in the carpool?" << endl;
    cin >> car1.numofpeople;
    cout << "What are the names of the people" << endl;
    for (int i = 0; i < car1.numofpeople; i++) {
        cin >> car1.names[i];
    }
    car1.time.hour = 1;
    car1.time.minute = 0;
    Carpool car2;
    cout << "How many people in the carpool?" << endl;
    cin >> car2.numofpeople;
    cout << "What are the names of the people" << endl;
    for (int i = 0; i < car2.numofpeople; i++) {
        cin>>car2.names[i];
    }
    car2.time.hour = 3;
    car2.time.minute = 0;

    Carpool car3 = car1.combineCarpool(car2);
    // for (int i = 0; i < car3.numofpeople; i++) {
    //     cout << car3.names[i];
    // }
    // cout << '\n';
    car3.print();
    return 0; 
} 