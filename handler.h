#pragma once
#include "global.h"
#include <iostream>
#include <conio.h>

using namespace std;

void setCounter(int);

void insertRecords(Person*, int);
void selectRecords(Person*);
void deleteRecord(Person*, int);
void updateRecord(Person);

void sorting(Person*, int, int);
void search(Person*, int, int, char[128]);
void task(Person*, Pair*);