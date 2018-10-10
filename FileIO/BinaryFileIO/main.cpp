#include "People.h"
#include <fstream>
#include <cstring>

void WriteToBinaryFile(People somePerson)
{
    fstream file("person.bin", ios_base::binary | ios_base::out);

    if (file.is_open())
    {
        file.write((char*)&somePerson.name, sizeof(People));

    }

    file.close();
}

void ReadFromFile()
{
    People anotherPerson;
    fstream file("person.bin", ios_base::binary | ios_base::in);

    if (file.is_open())
    {
        file.read((char*)&anotherPerson, sizeof(People));
    }
    file.close();
}


int main(void)
{

    People Amar;
    Amar.name = "Amar";
    Amar.age = 20;
    Amar.school = "UF";

    WriteToBinaryFile(Amar);

    ReadFromFile();

    return 0;
}
