#include "file.h"

void save(Person* person, int currentSize)
{
	vector<Person> pv(currentSize);
	for (int i = 0; i < currentSize; i++)
	{
		strcpy_s(pv[i].name, person[i].name);
		strcpy_s(pv[i].sex, person[i].sex);
		pv[i].age = person[i].age;
		pv[i].height = person[i].height;
		pv[i].weight = person[i].weight;

		pv[i].requirment.maxAge = person[i].requirment.maxAge;
		pv[i].requirment.minAge = person[i].requirment.minAge;
		pv[i].requirment.maxHeight = person[i].requirment.maxHeight;
		pv[i].requirment.minHeight = person[i].requirment.minHeight;
		pv[i].requirment.maxWeight = person[i].requirment.maxWeight;
		pv[i].requirment.minWeight = person[i].requirment.minWeight;
	}

	ofstream fout("data.txt", ofstream::binary);

	for (size_t i = 0; i < pv.size(); i++)
		fout.write((char*)&pv.at(i), sizeof(Person));
	fout.close();
	cout << "Данные сохранены...";
}

vector<Person> load(Person* person, int currentSize, bool flag)
{
	vector<Person> pv(currentSize);
	if (flag) 
	{
		for (int i = 0; i < currentSize; i++) 
		{
			strcpy_s(pv[i].name, person[i].name);
			strcpy_s(pv[i].sex, person[i].sex);
			pv[i].age = person[i].age;
			pv[i].height = person[i].height;
			pv[i].weight = person[i].weight;

			pv[i].requirment.maxAge = person[i].requirment.maxAge;
			pv[i].requirment.minAge = person[i].requirment.minAge;
			pv[i].requirment.maxHeight = person[i].requirment.maxHeight;
			pv[i].requirment.minHeight = person[i].requirment.minHeight;
			pv[i].requirment.maxWeight = person[i].requirment.maxWeight;
			pv[i].requirment.minWeight = person[i].requirment.minWeight;
		}
	}
	Person p;

	ifstream fin("data.txt");
	while (!fin.eof())
	{
		if (fin.peek() == EOF) break;
		fin.read((char*)&p, sizeof(Person));
		pv.push_back(p);
	}
	fin.close();
	cout << "Данные загружены...";
	return pv;
}
