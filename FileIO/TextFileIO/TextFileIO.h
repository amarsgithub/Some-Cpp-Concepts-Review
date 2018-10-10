#pragma once
#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include "People.h"

// String import:
#include <sstream>

// File IO imports:
#include <fstream>

void GetPeopleFromFile(vector<People> &peeps);
void PutMyArrayToAFile(int *arr);
