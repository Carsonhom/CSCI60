#include <iostream>

using namespace std;

int main(int argc, char *argv[])//doesn't allow 14 or 15
{
    int a(5);
    const int *const pa(&a);

    cout << a << endl;
    cout << *pa << endl;

    int b(6);
    *pa = 7;//  const int * pa(&a); doesn't allow
    pa = &b;//  int *const pa(&a); doesn't allow

    cout << a << endl;
    cout << *pa << endl;

    return 0;

}
