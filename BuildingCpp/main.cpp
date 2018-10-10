#include <iostream> // <- this guy is a preprocessor directive 
using namespace std;

// This right here is the function prototype/declaration:
void PrintPassedIn(int);

int main(void)
{
    PrintPassedIn(5);

    // This right here is the demo of the scope resolution operator:
    std::cout << "Using scope resolution operators for prints" << std::endl;
    // 'std' is the namespace that we're referring to over here.

    return 0;
}

void PrintPassedIn(int x)
{
    cout << x << endl;
}
