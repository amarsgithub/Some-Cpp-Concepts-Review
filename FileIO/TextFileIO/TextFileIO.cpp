#include "TextFileIO.h"

void GetPeopleFromFile(vector<People> &peeps)
{
    ifstream file("myTextFile.txt");
    string line;
    People person;

    if (file.is_open())
    {
        // Read line by line:
        while (getline(file, line))
        {
            // cout << "The line is: " << endl << line << endl;

            // String tokenizer:
            // Take the value from str and put it into temp
            istringstream str(line);
            string temp;

            // Put in the name
            getline(str, temp, ' ');
            person.name = temp;

            // Put in the age
            getline(str, temp, ' ');
                person.age = stoi(temp);

            if (getline(str, temp, ' '))
                person.school = temp;

            peeps.push_back(person);
        }
        file.close();
    }

}

void PutMyArrayToAFile(int *arr)
{
    ofstream file("myOutputFile.txt");

    if (file.is_open())
    {
        for (int i = 0; i < 5; i++)
            file << arr[i] << endl;
    }
    file.close();
}
