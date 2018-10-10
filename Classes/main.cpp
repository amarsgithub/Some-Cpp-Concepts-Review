#include <iostream>
#include <string>
using namespace std;

class SomeClass
{
    string name;
public:
    SomeClass();
    SomeClass(string name);
    void SetName(string name); // <- mutator
    string GetName(); // <- accessor 
};

SomeClass::SomeClass()
{
    name = "";
}

SomeClass::SomeClass(string name)
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
    // Both lines below do the same exact thing - store a someObject object on
    // the stack.

    SomeClass someObject;
    // UserDefinedObject someObject(); // <-this line does the same thing as above

    someObject.SetName("First object");

    cout << someObject.GetName() << endl;

    return 0;
}
