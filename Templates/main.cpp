#include <iostream>
#include "TemplatedClass.h"
using namespace std;

int main(void)
{
    // The following line creates a templated class object, of type 'int'.
    TemplatedClass<int> myIntObject(5);

    TemplatedClass<float> myFloatObject(10.0f);

    // Printing something from the integer object:
    myIntObject.Print();

    // Printing something from the float object:
    myFloatObject.Print();

    return 0;
}
