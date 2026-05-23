// C++: Type System Demo - Static Typing
#include <iostream>
#include <string>
using namespace std;

int main() {
    // Variables must be declared with a fixed type
    int x = 10;
    cout << "Value: " << x << " | Type: int" << endl;

    // x = "hello";  // THIS WOULD CAUSE A COMPILE ERROR
    // Cannot reassign a different type to the same variable

    // Each type is separate and fixed
    double y = 3.14;
    string name = "hello";
    bool flag = true;

    cout << "Double: " << y << endl;
    cout << "String: " << name << endl;
    cout << "Bool: " << flag << endl;

    // Explicit casting required to mix types
    int a = 10;
    double b = 3;
    double result = (double)a / b;
    cout << "\nExplicit cast result: " << result << endl;

    // Integer division (no cast) - truncates decimal
    int result2 = a / b;
    cout << "Integer division result: " << result2 << endl;

    // Combining int and string requires explicit conversion
    string message = "Value is: " + to_string(a);
    cout << message << endl;

    return 0;
}