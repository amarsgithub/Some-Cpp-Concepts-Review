#include <iostream>
#include <string>
using namespace std;

class SomeClass
{
    string name;

    //here we create a pointer on the stack
    int* myArray;


public:
    SomeClass();
    SomeClass(string name, int size);
    void SetName(string name); // <- mutator
    string GetName(); // <- accessor
    


};

SomeClass::SomeClass()
{
    name = "";
    myArray = nullptr;
}

SomeClass::SomeClass(string name, int size)
{
    this->name = name;

}

void SomeClass::SetName(string name)
{
    this->name = name;
}

string SomeClass::GetName()
{
    return this->name;
}



int main(void)
{
    // Both lines below do the same exact thing - store a singleObject object on
    // the stack.
    int size = 5;

    std::cin >> size;

    SomeClass singleObject;

    //SomeClass singleObject(); // <-this line does the same thing as above, calling the default constructor


    SomeClass someObject[45]; //creates an array with a known size, no compiler error


    //By default C++ would throw a compiler error when attempting to initialize an array on the stack with a variable
    //g++, a compiler, "extends" C++, allowing this to compile
    SomeClass arrayObject[size];


    //Instead, to follow C++ protocol, you must dynamically allocate the memory yourself
    SomeClass* heapObject = new SomeClass[size]; //Creates pointer on the stack, stores objects on the heap



     //  This would cause a compiler error
     // When using the new keyword you must create a pointer on the stack
     //SomeClass heapObject = new SomeClass;

    singleObject.SetName("First object");

    cout << singleObject.GetName() << endl;

    return 0;
}
