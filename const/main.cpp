#include <iostream>
using namespace std;

// The below code represents content with variables, with classes, it's kind of
// different. Here's how it goes with functions in classes or other functions:

// In the following line of code, the const keyword is making the class
// members read-only. You will not be able to modify any class variables in this
// case.
// void Print() const;

// 'const' in the following code is going to be used to return a const variable,
// const int GetAge();
// If you wanted to return a non-const version of the age variable, then you
// could just do this:
// int GetAge();

// If you have a const inside the parenthesis, it means that the function will
// not modify the object passed in. For example, in our copy constructors:
// Showroom(const Showroom &rhs);
// In this case, the const keyword is protecting the rhs object. It prevents
// the object passed in from being modified.

// You could mix all three of the ones we talked about above, check out this guy!
// const int ReturnSomething(const Vehicle &rhs) const;
// this is returning a constant integer, prevents it from modifying the class
// object, and also passes in a const Vehicle to the function. 

int main(void)
{
    int x = 5;
    int y = 10;

    int *ptrToX = &x;

    ptrToX = &y; // <- this line totally works. No constants!

// =============================================================================
//                                 const variable
// =============================================================================
    // If we wanted to restrict access, there are a couple of ways we can do it

    const int constVariable = 5; // say we have an example const variable
    const int *const constVariablePointer = &constVariable; // pointers to it

    // the following line doesn't work. The const pointer prevents this from
    // happening.

    // *constVariablePointer = 10; // <- this doesn't work. The const pointer
                                   // prevents this from happening

// =============================================================================
//                                  const pointer
// =============================================================================


    int runningOutOfNames = 15;
    int * const runningOutOfNamesPointer = &runningOutOfNames;

    x = 20; // this is totally legal.
    // runningOutOfNamesPointer = &x; // this is not legal.

    // The above doesn't work because the pointer is staring right at the var
    // and doesn't let you modify it, but other things could totally modify it.

    return 0;
}
