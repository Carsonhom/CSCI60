#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class ModInt{
private:
    int mod;
    int value;
public:
    ModInt();

    ModInt(int m, int v);

    int getMod();

    int getValue();

    void operator+=(ModInt rhs);
};

ModInt::ModInt() {
    mod = 1;
    value = 0;
}

ModInt::ModInt(int m, int v) {
    mod = m;
    value = v;
}

int ModInt::getMod() {
    return mod;
}

int ModInt::getValue() {
    return value;
}

bool operator==(ModInt lhs, ModInt rhs) {
    if(lhs.getValue() == rhs.getValue() && lhs.getMod() == rhs.getMod()) return true;
    else return false;
}

void ModInt::operator+=(ModInt rhs) {
    if(mod == rhs.mod) {
        value += rhs.value;
        value = value % mod;
    }
    else {
        value = -1;
        mod = -1;
    }
}

ModInt operator+(ModInt lhs, ModInt rhs) {
    int m;
    int v;
    if(rhs.getMod() == lhs.getMod()) {
        v = rhs.getValue() + lhs.getValue();
        m = rhs.getMod();
        v = v % m;
        ModInt a (m, v);
        return a;
    }
    else {
        ModInt a (-1, -1);
        return a;
    }    
}

ModInt operator*(ModInt lhs, ModInt rhs) {
    int m;
    int v;
    if(rhs.getMod() == lhs.getMod()) {
        v = rhs.getValue() * lhs.getValue();
        m = rhs.getMod();
        v = v % m;
        ModInt a (m, v);
        return a;
    }
    else {
        ModInt a (-1, -1);
        return a;
    }    
}

ostream& operator<<(ostream& out, ModInt a) {
    string s = "The value is " + to_string(a.getValue()) + " and the mod is " + to_string(a.getMod());

    out << s;
    return out;
}


int main() {
    ModInt a (0, 100);
    cout << a.getMod() << endl;
    cout << a.getValue() << endl;

    ModInt b (2000, 1998);
    cout << b.getMod() << endl;
    cout << b.getValue() << endl;

    ModInt c (2000, 5);

    if(a == b) cout << "True" << endl;
    else cout << "False" << endl;

    if(b == c) cout << "True" << endl;
    else cout << "False" << endl;

    b += c;
    cout << b.getMod() << endl;
    cout << b.getValue() << endl;

    ModInt d = b * c;
    cout << d.getMod() << endl;
    cout << d.getValue() << endl;

    cout << d << endl;
    return 0;
}