// C++: Static Typing Error Demo
// This program deliberately causes a compile error
// to demonstrate C++ static type enforcement
#include <iostream>
#include <string>
using namespace std;

int main() {
    int x = 10;
    x = "hello";   // ERROR: cannot assign string to int
    cout << x << endl;
    return 0;
}