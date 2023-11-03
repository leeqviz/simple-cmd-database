#pragma once
#include <cstdlib>

struct Requirement
{
	int minAge, maxAge;
	float minHeight, maxHeight, minWeight, maxWeight;
};
extern Requirement* requirment;

struct Person
{
	char sex[10];
	char name[50];
	int age;
	float height, weight;
	Requirement requirment;
};
extern Person* person;

struct Pair
{
	Person husband;
	Person wife;
};
extern Pair* pairs;

extern int currentSize;
