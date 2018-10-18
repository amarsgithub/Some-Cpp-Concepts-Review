#include <iostream>
#include <string>
using namespace std;

class SomeClass
{
    string name;

    //here we create a pointer on the stack
    int* myArray;
    int capacity = 0; //to allocate max size for myArray
    int size = 0; //to keep track of actual integers stored in myArray

public:
    void insert(int value);
    void SetName(string name); // <- mutator
    string GetName(); // <- accessor

    SomeClass();
    SomeClass(string name, int size);

    ~SomeClass(); //Since we dynamically allocate memory for myArray, we must have this

    //Since we have a destructor, we must also have a copy and assignment constructor (Trilogy of 3)
    SomeClass& operator =(const SomeClass&); //assignment constructor
    SomeClass(const SomeClass&); //copy constructor, notice void return type

};

void SomeClass::insert(int value)
{
    myArray[size] = value; //gives element at size an actual value, we must delete this later in destructor
    size++;
}

SomeClass::SomeClass()
{
    //default values in default constructor
    name = "";
    myArray = nullptr;
    capacity = 0;
    size = 0;
}

SomeClass::~SomeClass() //destructor
{
    if(myArray != nullptr) //always check this before deleting to insure it hasn't already been deleted elsewhere
    {
        delete myArray;
        myArray = nullptr;
    }

}

SomeClass::SomeClass(string name, int capacity)
{
    this->name = name;
    this->capacity = capacity;

    myArray = new int[capacity]; //here we make the integer pointer point to an array of integers allocated on the heap
    //Now we must make a destructor to delete this data later
}

SomeClass& SomeClass::operator=(const SomeClass &d)
{
     //data we must copy over is name, capacity, size and integers from myArray
     //since name, capacity and size are values, we can copy directly

     this->name = d.name;
     this->capacity = d.capacity;
     this->size = d.size;

     //THIS IS BAD, since myArray is a pointer, it does not copy the data over, instead this will cause both pointers to point to the same data
     //this->myArray = d.myArray;

    if(myArray != nullptr)
    {
        delete[] myArray;
    }

    //allocates memory for data
     this->myArray = new int[capacity];
    //this will actually copy the data from myArray
     for(int i=0;i<this->size; i++) //notice that we don't go to capacity, size is the amount of data actually "filled", versus the amount allocated for (capacity)
     {
         cout << "Assigning " << d.myArray[i] << " to " << this->name << endl;
         this->myArray[i] = d.myArray[i];
     }
     return *this; //returns the object (value not reference) that we just copied data into
}

SomeClass::SomeClass(const SomeClass& d) //copy constructor is identical to assignment, except without a return type
{
    this->name = d.name;
    this->capacity = d.capacity;
    this->size = d.size;
    if(myArray != nullptr)
    {
        delete[] myArray;
    }
    this->myArray = new int[capacity];
    for(int i=0;i<this->size; i++)
    {
        this->myArray[i] = d.myArray[i];
    }

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
    SomeClass FirstObject; //default constructor
    //SomeClass FirstObject(); // <-this line does the same thing as above, calling the default constructor, parenthesis aren't required

    FirstObject.SetName("My First Object");

    cout << "FirstObject name:" << endl;
    cout << FirstObject.GetName() << endl;
    cout << endl;


    //two parameter constructor
    SomeClass SingleObject("yeet", 5); //name becomes yeet, size of myArray becomes 5

    SingleObject.insert(12); //inserts data to SingleObject's integer array
    SingleObject.insert(15);

    cout << "SingleObject name:" << endl;
    cout << SingleObject.GetName() << endl;

    SomeClass ObjectArray[45]; //creates an array with a known size (45), no compiler error

    ObjectArray[5].SetName("Ben");

    cout << "ObjectArray[5] name before assignment constructor:" << endl;
    cout << ObjectArray[5].GetName() << endl;


    //first element of ObjectArray receives values from singleObject
    ObjectArray[5] = SingleObject; //here the assignment constructor gets called, ObjectArray[0] was already previously declared
            
            
    cout << "ObjectArray[5] name after being \"assigned\"  to SingleObject:" << endl;
    cout << ObjectArray[5].GetName() << endl;
    
            
    SomeClass newObject = SingleObject; //here the copy constructor gets called since we are declaring and defining on the same line

    int size = 12;


    //By default C++ would throw a compiler error when attempting to initialize an array on the stack with a variable
    //g++, a compiler, "extends" C++, allowing this to compile
    SomeClass BadStackArray[size]; // <- only works in some IDE's (with certain compilers like g++)


    //Instead, to follow C++ protocol, you must dynamically allocate the memory yourself by using the new keyword

    // When using the new keyword you must create a pointer on the stack
    //SomeClass heapObject = new SomeClass; //<- does not work, compiler error

    //Instead this is how you dynamically allocate space
    SomeClass* GoodHeapArray = new SomeClass[size]; //Creates pointer on the stack, stores objects on the heap


    return 0;
}
