#pragma once
#include "global.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void save(Person*, int);
vector<Person> load(Person*, int, bool);