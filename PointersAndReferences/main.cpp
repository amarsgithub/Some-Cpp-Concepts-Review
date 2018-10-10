#include <iostream>
using namespace std;

void passingPointer(int *passedInPtr)
{
    *passedInPtr = 10;
}

void passingReference(int &passingReference)
{
    passingReference = 15;
}

int main(void)
{
    int x = 5;

    int *ptrToX = &x; // <- assigning a pointer to a variable

    cout << "x holds the value:        " << x << endl;
    cout << "ptrToX holds the value:   " << ptrToX << endl;
    cout << "Dereferenced ptrToX is:   " << *ptrToX << endl; // <-derefencing
    cout << "The address of x is:      " << &x << endl; // <- address of x
    cout << "The address of ptrToX is: " << &ptrToX << endl;

    // Declaring a reference to x:
    int &y = x;

    cout << endl << endl << "y holds the value:   " << y << endl;
    cout << "The address of y is: " << &y << endl;
    cout << "The address of x is: " << &x << endl;


    // Passing to functions:
    cout << endl << endl << "Passing to functions" << endl;
    passingPointer(ptrToX);
    cout << "Printing x after calling passingPointer: " << x << endl;

    passingReference(y);
    cout << "Printing x after calling passingReference: " << x << endl;

    return 0;
}
