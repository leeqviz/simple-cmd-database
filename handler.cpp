#include "handler.hpp"

int counter = 0;

void setCounter(int currentSize)
{
	counter = currentSize;
}

void insertRecords(Person* person, int currentSize)
{
	for (counter; counter < currentSize; counter++)
	{
		cout << " Çàïèñü íîìåð: " << counter + 1 << endl;
		while (1) 
		{
			fflush(stdin);
			cout << " Èìÿ (óíèêàëüíîå çíà÷åíèå): ";
			cin.getline(person[counter].name, 50);
			char buff[50];
			bool flag = false;
			for (int i = 0; i < counter; i++) 
			{
				strcpy_s(buff, person[i].name);
				if (strcmp(buff, person[counter].name) == 0) 
				{
					flag = true;
					break;
				}
			}
			if (!flag) break;			
		}
		while (1)
		{
			cout << " Ïîë (ì/æ): "; 
			char buf[128];
			fflush(stdin);
			cin.getline(buf, 10);
			if (strcmp(buf, "ì") == 0 || strcmp(buf, "æ") == 0)
			{
				strcpy_s(person[counter].sex, buf);
				break;
			}
		}
		while (1)
		{
			cout << " Âîçðàñò (öåëî÷èñëåííîå çíà÷åíèå): ";
			char buf[128];
			fflush(stdin);
			cin.getline(buf, 128);
			int age = 0;
			if ((age = atoi(buf)) != 0)
			{
				person[counter].age = age;
				break;
			}
			else
			{
				cout << " Íåîáõîäèìî ââåñòè ÷èñëî!" << endl;
			}
		}
		while (1)
		{
			cout << " Ðîñò (÷èñëî ñ ïëàâàþùåé òî÷êîé): ";
			char buf[128];
			fflush(stdin);
			cin.getline(buf, 128);
			float height = 0.0f;
			if ((height = atof(buf)) != 0.0f)
			{
				person[counter].height = height;
				break;
			}
			else
			{
				cout << " Íåîáõîäèìî ââåñòè ÷èñëî!" << endl;
			}
		}
		while (1)
		{
			cout << " Âåñ (÷èñëî ñ ïëàâàþùåé òî÷êîé): ";
			char buf[128];
			fflush(stdin);
			cin.getline(buf, 128);
			float weight = 0.0f;
			if ((weight = atof(buf)) != 0.0f)
			{
				person[counter].weight = weight;
				break;
			}
			else
			{
				cout << " Íåîáõîäèìî ââåñòè ÷èñëî!" << endl;
			}
		}
		while (1)
		{
			cout << " Ïðåäïî÷òèòåëüíûé ìàêñèìàëüíûé âîçðàñò ïàðí¸ðà: ";
			char buf[128];
			fflush(stdin);
			cin.getline(buf, 128);
			int age = 0;
			if ((age = atoi(buf)) != 0)
			{
				person[counter].requirment.maxAge = age;
				break;
			}
			else
			{
				cout << " Íåîáõîäèìî ââåñòè ÷èñëî!" << endl;
			}
		}
		while (1)
		{
			cout << " Ïðåäïî÷òèòåëüíûé ìèíèìàëüíûé âîçðàñò ïàðí¸ðà: ";
			char buf[128];
			fflush(stdin);
			cin.getline(buf, 128);
			int age = 0;
			if ((age = atoi(buf)) != 0)
			{
				person[counter].requirment.minAge = age;
				break;
			}
			else
			{
				cout << " Íåîáõîäèìî ââåñòè ÷èñëî!" << endl;
			}
		}
		while (1)
		{
			cout << " Ïðåäïî÷òèòåëüíûé ìàêñèìàëüíûé ðîñò ïàðí¸ðà: ";
			char buf[128];
			fflush(stdin);
			cin.getline(buf, 128);
			float height = 0.0f;
			if ((height = atof(buf)) != 0.0f)
			{
				person[counter].requirment.maxHeight = height;
				break;
			}
			else
			{
				cout << " Íåîáõîäèìî ââåñòè ÷èñëî!" << endl;
			}
		}
		while (1)
		{
			cout << " Ïðåäïî÷òèòåëüíûé ìèíèìàëüíûé ðîñò ïàðí¸ðà: ";
			char buf[128];
			fflush(stdin);
			cin.getline(buf, 128);
			float height = 0.0f;
			if ((height = atof(buf)) != 0.0f)
			{
				person[counter].requirment.minHeight = height;
				break;
			}
			else
			{
				cout << " Íåîáõîäèìî ââåñòè ÷èñëî!" << endl;
			}
		}
		while (1)
		{
			cout << " Ïðåäïî÷òèòåëüíûé ìàêñèìàëüíûé âåñ ïàðí¸ðà: ";
			char buf[128];
			fflush(stdin);
			cin.getline(buf, 128);
			float weight = 0.0f;
			if ((weight = atof(buf)) != 0.0f)
			{
				person[counter].requirment.maxWeight = weight;
				break;
			}
			else
			{
				cout << " Íåîáõîäèìî ââåñòè ÷èñëî!" << endl;
			}
		}
		while (1)
		{
			cout << " Ïðåäïî÷òèòåëüíûé ìèíèìàëüíûé âåñ ïàðí¸ðà: ";
			char buf[128];
			fflush(stdin);
			cin.getline(buf, 128);
			float weight = 0.0f;
			if ((weight = atof(buf)) != 0.0f)
			{
				person[counter].requirment.minWeight = weight;
				break;
			}
			else
			{
				cout << " Íåîáõîäèìî ââåñòè ÷èñëî!" << endl;
			}
		}
		cout << " ---------- " << endl;
	}
}

void selectRecords(Person* person)
{
	for (int i = 0; i < counter; i++)
	{
		cout << " Çàïèñü íîìåð: " << i + 1 << endl
			<< " Èìÿ: " << person[i].name << endl
			<< " Ïîë: " << person[i].sex << endl
			<< " Âîçðàñò: " << person[i].age << endl
			<< " Ðîñò: " << person[i].height << endl
			<< " Âåñ: " << person[i].weight << endl

			<< " Ïðåäïî÷òèòåëüíûé ìàêñèìàëüíûé âîçðàñò ïàðí¸ðà: " << person[i].requirment.maxAge << endl
			<< " Ïðåäïî÷òèòåëüíûé ìèíèìàëüíûé âîçðàñò ïàðí¸ðà: " << person[i].requirment.minAge << endl
			<< " Ïðåäïî÷òèòåëüíûé ìàêñèìàëüíûé ðîñò ïàðí¸ðà: " << person[i].requirment.maxHeight << endl
			<< " Ïðåäïî÷òèòåëüíûé ìèíèìàëüíûé ðîñò ïàðí¸ðà: " << person[i].requirment.minHeight << endl
			<< " Ïðåäïî÷òèòåëüíûé ìàêñèìàëüíûé âåñ ïàðí¸ðà: " << person[i].requirment.maxWeight << endl
			<< " Ïðåäïî÷òèòåëüíûé ìèíèìàëüíûé âåñ ïàðí¸ðà: " << person[i].requirment.minWeight << endl
			<< " ---------- " << endl;
	}
}

void deleteRecord(Person* person, int selected)
{
	for (int i = selected; i < counter - 1; i++)
	{
		strcpy_s(person[i].name, person[i + 1].name);
		strcpy_s(person[i].sex, person[i + 1].sex);
		person[i].age = person[i + 1].age;
		person[i].height = person[i + 1].height;
		person[i].weight = person[i + 1].weight;
		
		person[i].requirment.maxAge = person[i + 1].requirment.maxAge;
		person[i].requirment.minAge = person[i + 1].requirment.minAge;
		person[i].requirment.maxHeight = person[i + 1].requirment.maxHeight;
		person[i].requirment.minHeight = person[i + 1].requirment.minHeight;
		person[i].requirment.maxWeight = person[i + 1].requirment.maxWeight;
		person[i].requirment.minWeight = person[i + 1].requirment.minWeight;
	}
	counter -= 1;
}

void updateRecord(Person person)
{
	while (1)
	{
		fflush(stdin);
		cout << " Èìÿ (óíèêàëüíîå çíà÷åíèå): ";
		cin.getline(person.name, 50);
		break;

	}
	while (1)
	{
		cout << " Ïîë (ì/æ): ";
		char buf[128];
		fflush(stdin);
		cin.getline(buf, 10);
		if (strcmp(buf, "ì") == 0 || strcmp(buf, "æ") == 0)
		{
			strcpy_s(person.sex, buf);
			break;
		}

	}
	while (1)
	{
		cout << " Âîçðàñò (öåëî÷èñëåííîå çíà÷åíèå): ";
		char buf[128];
		fflush(stdin);
		cin.getline(buf, 128);
		int age = 0;
		if ((age = atoi(buf)) != 0)
		{
			person.age = age;
			break;
		}
		else
		{
			cout << " Íåîáõîäèìî ââåñòè ÷èñëî!" << endl;
		}
	}
	while (1)
	{
		cout << " Ðîñò (÷èñëî ñ ïëàâàþùåé òî÷êîé): ";
		char buf[128];
		fflush(stdin);
		cin.getline(buf, 128);
		float height = 0.0f;
		if ((height = atof(buf)) != 0.0f)
		{
			person.height = height;
			break;
		}
		else
		{
			cout << " Íåîáõîäèìî ââåñòè ÷èñëî!" << endl;
		}
	}
	while (1)
	{
		cout << " Âåñ (÷èñëî ñ ïëàâàþùåé òî÷êîé): ";
		char buf[128];
		fflush(stdin);
		cin.getline(buf, 128);
		float weight = 0.0f;
		if ((weight = atof(buf)) != 0.0f)
		{
			person.weight = weight;
			break;
		}
		else
		{
			cout << " Íåîáõîäèìî ââåñòè ÷èñëî!" << endl;
		}
	}
	while (1)
	{
		cout << " Ïðåäïî÷òèòåëüíûé ìàêñèìàëüíûé âîçðàñò ïàðí¸ðà: ";
		char buf[128];
		fflush(stdin);
		cin.getline(buf, 128);
		int age = 0;
		if ((age = atoi(buf)) != 0)
		{
			person.requirment.maxAge = age;
			break;
		}
		else
		{
			cout << " Íåîáõîäèìî ââåñòè ÷èñëî!" << endl;
		}
	}
	while (1)
	{
		cout << " Ïðåäïî÷òèòåëüíûé ìèíèìàëüíûé âîçðàñò ïàðí¸ðà: ";
		char buf[128];
		fflush(stdin);
		cin.getline(buf, 128);
		int age = 0;
		if ((age = atoi(buf)) != 0)
		{
			person.requirment.minAge = age;
			break;
		}
		else
		{
			cout << " Íåîáõîäèìî ââåñòè ÷èñëî!" << endl;
		}
	}
	while (1)
	{
		cout << " Ïðåäïî÷òèòåëüíûé ìàêñèìàëüíûé ðîñò ïàðí¸ðà: ";
		char buf[128];
		fflush(stdin);
		cin.getline(buf, 128);
		float height = 0.0f;
		if ((height = atof(buf)) != 0.0f)
		{
			person.requirment.maxHeight = height;
			break;
		}
		else
		{
			cout << " Íåîáõîäèìî ââåñòè ÷èñëî!" << endl;
		}
	}
	while (1)
	{
		cout << " Ïðåäïî÷òèòåëüíûé ìèíèìàëüíûé ðîñò ïàðí¸ðà: ";
		char buf[128];
		fflush(stdin);
		cin.getline(buf, 128);
		float height = 0.0f;
		if ((height = atof(buf)) != 0.0f)
		{
			person.requirment.minHeight = height;
			break;
		}
		else
		{
			cout << " Íåîáõîäèìî ââåñòè ÷èñëî!" << endl;
		}
	}
	while (1)
	{
		cout << " Ïðåäïî÷òèòåëüíûé ìàêñèìàëüíûé âåñ ïàðí¸ðà: ";
		char buf[128];
		fflush(stdin);
		cin.getline(buf, 128);
		float weight = 0.0f;
		if ((weight = atof(buf)) != 0.0f)
		{
			person.requirment.maxWeight = weight;
			break;
		}
		else
		{
			cout << " Íåîáõîäèìî ââåñòè ÷èñëî!" << endl;
		}
	}
	while (1)
	{
		cout << " Ïðåäïî÷òèòåëüíûé ìèíèìàëüíûé âåñ ïàðí¸ðà: ";
		char buf[128];
		fflush(stdin);
		cin.getline(buf, 128);
		float weight = 0.0f;
		if ((weight = atof(buf)) != 0.0f)
		{
			person.requirment.minWeight = weight;
			break;
		}
		else
		{
			cout << " Íåîáõîäèìî ââåñòè ÷èñëî!" << endl;
		}
	}
	cout << " Íàæìèòå ëþáóþ êëàâèøó äëÿ ïðîäîëæåíèÿ..." << endl;
}

void swap(Person* pLeft, Person* pRight)
{
	char buff[128];
	
	strcpy_s(buff, pLeft->name);
	strcpy_s(pLeft->name, pRight->name);
	strcpy_s(pRight->name, buff);

	strcpy_s(buff, pLeft->sex);
	strcpy_s(pLeft->sex, pRight->sex);
	strcpy_s(pRight->sex, buff);

	int age = 0;

	age = pLeft->age;
	pLeft->age = pRight->age;
	pRight->age = age;

	float height = 0.0f, weight = 0.0f;

	height = pLeft->height;
	pLeft->height = pRight->height;
	pRight->height = height;

	weight = pLeft->weight;
	pLeft->weight = pRight->weight;
	pRight->weight = weight;

	////////////////////
	age = pLeft->requirment.maxAge;
	pLeft->requirment.maxAge = pRight->requirment.maxAge;
	pRight->requirment.maxAge = age;

	age = pLeft->requirment.minAge;
	pLeft->requirment.minAge = pRight->requirment.minAge;
	pRight->requirment.minAge = age;

	height = pLeft->requirment.maxHeight;
	pLeft->requirment.maxHeight = pRight->requirment.maxHeight;
	pRight->requirment.maxHeight = height;

	height = pLeft->requirment.minHeight;
	pLeft->requirment.minHeight = pRight->requirment.minHeight;
	pRight->requirment.minHeight = height;

	weight = pLeft->requirment.maxWeight;
	pLeft->requirment.maxWeight = pRight->requirment.maxWeight;
	pRight->requirment.maxWeight = weight;

	weight = pLeft->requirment.minWeight;
	pLeft->requirment.minWeight = pRight->requirment.minWeight;
	pRight->requirment.minWeight = weight;
}

void sorting(Person* person, int currentSize, int field)
{
	char bLeft[128] = { 0 }, bRight[128] = { 0 };
	for (int i = 0; i < currentSize - 1; i++)
	{
		if (field == 1) strcpy_s(bLeft, person[i].name);
		else if (field == 2) strcpy_s(bLeft, person[i].sex);
		else if (field == 3) sprintf_s(bLeft, "%d", person[i].age);
		else if (field == 4) sprintf_s(bLeft, "%f", person[i].height);
		else if (field == 5) sprintf_s(bLeft, "%f", person[i].weight);

		for (int j = i + 1; j < currentSize; j++)
		{
			if (field == 1) strcpy_s(bRight, person[j].name);
			else if (field == 2) strcpy_s(bRight, person[j].sex);
			else if (field == 3) sprintf_s(bRight, "%d", person[j].age);
			else if (field == 4) sprintf_s(bRight, "%f", person[j].height);
			else if (field == 5) sprintf_s(bRight, "%f", person[j].weight);

			if (strcmp(bLeft, bRight) > 0) swap(person[i], person[j]);
		}
	}
	cout << "Îòñîðòèðîâàíî..." << endl;
}

void search(Person* person, int currentSize, int field, char text[128])
{
	char buff[128] = { 0 };
	int c = 0, left = 0, right = currentSize - 1;
	bool yes = false;

	while ((left <= right) && (yes != true)) {
		c = (left + right) / 2;

		if (field == 1) strcpy_s(buff, person[c].name);
		else if (field == 2) strcpy_s(buff, person[c].sex);
		else if (field == 3) sprintf_s(buff, "%d", person[c].age);
		else if (field == 4) sprintf_s(buff, "%f", person[c].height);
		else if (field == 5) sprintf_s(buff, "%f", person[c].weight);

		if (strcmp(buff, text) == 0 || strstr(buff, text) != 0) yes = true;

		if (strcmp(buff, text) == 1) right = c - 1;
		else left = c + 1;

		if (yes) {
			cout << " Çàïèñü ïîä íîìåðîì " << c + 1 << " íàéäåíà!" << endl
				<< " ______________________________" << endl
				<< " Èìÿ: " << person[c].name << endl
				<< " Ïîë: " << person[c].sex << endl
				<< " Âîçðàñò: " << person[c].age << endl
				<< " Ðîñò: " << person[c].height << endl
				<< " Âåñ: " << person[c].weight << endl
				<< " ______________________________" << endl;
		}
		else cout << " Çàïèñü íå íàéäåíà!" << endl;
	}
}

void task(Person* person, Pair* pairs)
{
	int count = 0;
	pairs = (Pair*)malloc(count * sizeof(Pair));

	for (int i = 0; i < counter; i++)
	{
		for (int j = 0; j < counter; j++)
		{
			if ((person[j].age >= person[i].requirment.minAge && person[j].age <= person[i].requirment.maxAge)
				&& (person[j].height >= person[i].requirment.minHeight && person[j].height <= person[i].requirment.maxHeight)
				&& (person[j].weight >= person[i].requirment.minWeight && person[j].weight <= person[i].requirment.maxWeight))
			{
				if ((strcmp(person[j].sex, "ì") == 0 && strcmp(person[i].sex, "æ") == 0)
					|| (strcmp(person[j].sex, "æ") == 0 && strcmp(person[i].sex, "ì") == 0))
				{
					bool flag = false;
					for (int c = 0; c < count; c++) {
						if ((strcmp(pairs[c].husband.name, person[j].name) == 0 || strcmp(pairs[c].wife.name, person[j].name) == 0)
							|| (strcmp(pairs[c].husband.name, person[i].name) == 0 || strcmp(pairs[c].wife.name, person[i].name) == 0))
						{
							flag = true;
							break;
						}
					}
					if (flag)
					{
						continue;
					}
					else
					{
						count++;
						Pair* t = pairs;
						if (pairs = (Pair*)realloc(pairs, count * sizeof(Pair)))
						{
							pairs[count - 1].husband = strcmp(person[j].sex, "ì") == 0 ? person[j] : person[i];
							pairs[count - 1].wife = strcmp(person[j].sex, "æ") == 0 ? person[j] : person[i];
						}
						else
						{
							cout << "Âîçíèêëà îøèáêà âûäåëåíèÿ ïàìÿòè!" << endl;
							return;
						}
						break;
					}
				}
			}
		}
	}
	cout << "Ïàðû:" << endl;
	for (int k = 0; k < count; k++) 
	{
		cout << "----------" << endl
			<< pairs[k].husband.name << " <-> " << pairs[k].wife.name << endl;
	}
	free(pairs);
}
