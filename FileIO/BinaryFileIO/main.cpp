#include "People.h"
#include <fstream>
#include <cstring>

void WriteToBinaryFile(People somePerson)
{
    fstream file("person.bin", ios_base::binary | ios_base::out);

    if (file.is_open())
    {
        file.write((char*)&somePerson, sizeof(People));
    }
    file.close();
}

People ReadFromFile()
{
    People anotherPerson;
    string name;
    fstream file("person.bin", ios_base::binary | ios_base::in);

    if (file.is_open())
    {
        file.read((char*)&anotherPerson, sizeof(People));
    }
    file.close();

    return anotherPerson;
}


file.read(length)
char *temp = new char[lengthOfName];
file.read(temp, lengthOfName)
tempHero.name = temp;
delete[] temp


int main(void)
{

    People Amar;
    Amar.name = "Amar";
    Amar.age = 20;
    Amar.school = "UF";

    WriteToBinaryFile(Amar);

    People person = ReadFromFile();
    cout << person.name << endl;

    return 0;
}
