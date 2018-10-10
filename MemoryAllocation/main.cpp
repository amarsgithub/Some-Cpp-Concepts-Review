#include <iostream>
using namespace std;

// The below function will cause a stack overflow:
void CauseStackOverFlow()
{
    CauseStackOverFlow();
}

int main(void)
{
    int x = 5; // <- this variable is created on the stack

    int *y; // <- y is on the stack in this case.

    // y in the following code is still on the stack. It's just pointing to
    // to something on the 'heap'. In this case, just one value on the heap.
    y = new int;

    // The above code is a good example of the saying "all arrays are pointers,
    // but not all pointers are arrays". In this case, y is a pointer, but it
    // is just pointing to 4 bytes (size of an int) in memory.

    // If we wanted to make y a pointer to an array:
    delete y;

    y = new int[10];

    // y is now a pointer to an array.

    delete[] y;

    // CauseStackOverFlow();

    return 0;
}
