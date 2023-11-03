#include "menu.hpp"

Requirement* requirment = nullptr;
Person* person = nullptr;
Pair* pairs = nullptr;
int currentSize = 0;

bool memoryIsAllocated = false;

char inputCheck(char begin, char end)
{
	char choice;
	while (1)
	{
		cout << " ==> ";
		choice = _getch();
		if (choice > begin || choice < end || choice == 'x') break;
	}
	return choice;
}

char menuDisplay(void) 
{
	system("cls");
	cout << " ---------------ÌÅÍÞ--------------" << endl 
		<< " ---------------------------------" << endl 
		<< " | 1 - Ââîä ìàññèâà ñòðóêòóð     |" << endl
		<< " | 2 - Çàãðóçèòü äàííûå èç ôàéëà |" << endl
		<< " | 3 - Ñîðòèðîâêà                |" << endl
		<< " | 4 - Ïîèñê                     |" << endl
		<< " | 5 - Èçìåíåíèå                 |" << endl
		<< " | 6 - Óäàëåíèå                  |" << endl
		<< " | 7 - Âûâîä ìàññèâà ñòðóêòóð    |" << endl
		<< " | 8 - Ñîõðàíèòü äàííûå â ôàéë   |" << endl
		<< " | 9 - Èíäèâèäóàëüíîå çàäàíèå    |" << endl
		<< " | x - Âûõîä                     |" << endl 
		<< " ---------------------------------" << endl 
		<< " --------ÂÛÁÅÐÈÒÅ ÄÅÉÑÒÂÈÅ--------" << endl
		<< endl;
	return inputCheck('1', '9');
}

void directionInsert(void)
{
	int items = 0;
	while (1)
	{
		system("cls");
		//cout << maxSize;
		cout << " Ââåäèòå êîëè÷åñòâî äîáàâëÿåìûõ îáúåêòîâ... (x - Íàçàä â ãëàâíîå ìåíþ)" << endl << endl << " ==> ";
		char buf[128];
		cin.getline(buf, 128);
		if ((items = atoi(buf)) != 0) break;
		else
		{
			if (buf[0] == 'x') return;
			cout << " Íåîáõîäèìî ââåñòè ÷èñëî áîëüøå íóëÿ!" << endl << " Íàæìèòå ëþáóþ êëàâèøó äëÿ ïðîäîëæåíèÿ...";
			(void)_getch();
		}
	}
	if (!memoryIsAllocated) {
		currentSize = items;
		person = (Person*)malloc(currentSize * sizeof(Person));
		memoryIsAllocated = true;
	}
	else
	{
		currentSize += items;
		Person* p = person;
		person = (Person*)realloc(p, currentSize * sizeof(Person));
	}
	system("cls");
	insertRecords(person, currentSize);
	(void)_getch();
}

bool directionLoad(bool flag)
{
	system("cls");
	vector<Person> pv = load(person, currentSize, memoryIsAllocated);
	if (pv.size() != 0)
	{
		currentSize = pv.size();
		setCounter(currentSize);
		if (person = (Person*)malloc(currentSize * sizeof(Person)))
		{
			for (int i = 0; i < currentSize; i++)
			{
				strcpy_s(person[i].name, pv[i].name);
				strcpy_s(person[i].sex, pv[i].sex);
				person[i].age = pv[i].age;
				person[i].height = pv[i].height;
				person[i].weight = pv[i].weight;

				person[i].requirment.maxAge = pv[i].requirment.maxAge;
				person[i].requirment.minAge = pv[i].requirment.minAge;
				person[i].requirment.maxHeight = pv[i].requirment.maxHeight;
				person[i].requirment.minHeight = pv[i].requirment.minHeight;
				person[i].requirment.maxWeight = pv[i].requirment.maxWeight;
				person[i].requirment.minWeight = pv[i].requirment.minWeight;
			}
			if (!memoryIsAllocated) memoryIsAllocated = true;
		}
		else
		{
			cout << "Âîçíèêëà îøèáêà âûäåëåíèÿ ïàìÿòè!" << endl;
			flag = true;
		}
	}
	(void)_getch();
	return flag;
}

void directionSorting(void)
{
	int field = 0;
	char buf[128];
	while (1)
	{
		system("cls");
		//cout << maxSize;
		cout << " Ââåäèòå íîìåð ïîëÿ, ïî êîòîðîìó áóäåò îñóùåñòâëÿòüñÿ ñîðòèðîâêà... (x - Íàçàä â ãëàâíîå ìåíþ)" << endl << endl << " ==> ";
		cin.getline(buf, 128);
		if ((field = atoi(buf)) != 0)
		{
			if (field > 5)
			{
				cout << " Ââåäåííîå çíà÷åíèå áîëüøå êîëè÷åñòâà ïîëåé â çàïèñè!" << endl << " Íàæìèòå ëþáóþ êëàâèøó äëÿ ïðîäîëæåíèÿ...";
				(void)_getch();
				continue;
			}
			break;
		}
		else
		{
			if (buf[0] == 'x') return;
			cout << " Íåîáõîäèìî ââåñòè ÷èñëî!" << endl << " Íàæìèòå ëþáóþ êëàâèøó äëÿ ïðîäîëæåíèÿ...";
			(void)_getch();
		}
	}
	system("cls");
	sorting(person, currentSize, field);
	(void)_getch();
}

void directionSearch(void)
{
	int field = 0;
	char buf[128];
	while (1)
	{
		system("cls");
		//cout << maxSize;
		cout << " Ââåäèòå íîìåð ïîëÿ, ïî êîòîðîìó áóäåò îñóùåñòâëÿòüñÿ ïîñê... (x - Íàçàä â ãëàâíîå ìåíþ)" << endl << endl << " ==> ";
		cin.getline(buf, 128);
		if ((field = atoi(buf)) != 0)
		{
			if (field > 5)
			{
				cout << " Ââåäåííîå çíà÷åíèå áîëüøå êîëè÷åñòâà ïîëåé â çàïèñè!" << endl << " Íàæìèòå ëþáóþ êëàâèøó äëÿ ïðîäîëæåíèÿ...";
				(void)_getch();
				continue;
			}
			memset(buf, 0, 128);
			cout << " Ââåäèòå òåêñò..." << endl << endl << " ==> ";
			cin.getline(buf, 128);
			break;
		}
		else
		{
			if (buf[0] == 'x') return;
			cout << " Íåîáõîäèìî ââåñòè ÷èñëî!" << endl << " Íàæìèòå ëþáóþ êëàâèøó äëÿ ïðîäîëæåíèÿ...";
			(void)_getch();
		}
	}
	system("cls");
	search(person, currentSize, field, buf);
	(void)_getch();
}

void directionUpdate(void)
{
	int item = 0;
	while (1)
	{
		system("cls");
		//cout << maxSize;
		cout << " Ââåäèòå íîìåð çàïèñè... (x - Íàçàä â ãëàâíîå ìåíþ)" << endl << endl << " ==> ";
		char buf[128];
		cin.getline(buf, 128);
		if ((item = atoi(buf)) != 0)
		{
			if (item > currentSize)
			{
				cout << " Ââåäåííîå çíà÷åíèå áîëüøå ðàçìåðà ìàññèâà çàïèñåé!" << endl << " Íàæìèòå ëþáóþ êëàâèøó äëÿ ïðîäîëæåíèÿ...";
				(void)_getch();
				continue;
			}
			break;
		}
		else
		{
			if (buf[0] == 'x') return;
			cout << " Íåîáõîäèìî ââåñòè ÷èñëî!" << endl << " Íàæìèòå ëþáóþ êëàâèøó äëÿ ïðîäîëæåíèÿ...";
			(void)_getch();
		}
	}
	updateRecord(person[item - 1]);
	system("cls");
	cout << " Çàïèñü íîìåð " << item << " èçìåíåíà!" << endl << " Íàæìèòå ëþáóþ êëàâèøó äëÿ ïðîäîëæåíèÿ...";
	(void)_getch();
}

void directionDelete(void)
{
	int item = 0;
	while (1)
	{
		system("cls");
		//cout << maxSize;
		cout << " Ââåäèòå íîìåð çàïèñè... (x - Íàçàä â ãëàâíîå ìåíþ)" << endl << endl << " ==> ";
		char buf[128];
		cin.getline(buf, 128);
		if ((item = atoi(buf)) != 0)
		{
			if (item > currentSize)
			{
				cout << " Ââåäåííîå çíà÷åíèå áîëüøå ðàçìåðà ìàññèâà çàïèñåé!" << endl << " Íàæìèòå ëþáóþ êëàâèøó äëÿ ïðîäîëæåíèÿ...";
				(void)_getch();
				continue;
			}
			break;
		}
		else
		{
			if (buf[0] == 'x') return;
			cout << " Íåîáõîäèìî ââåñòè ÷èñëî!" << endl << " Íàæìèòå ëþáóþ êëàâèøó äëÿ ïðîäîëæåíèÿ...";
			(void)_getch();
		}
	}
	deleteRecord(person, item - 1);
	currentSize -= 1;
	Person* p = person;
	person = (Person*)realloc(p, currentSize * sizeof(Person));
	system("cls");
	cout << " Çàïèñü íîìåð " << item << " óäàëåíà!" << endl << " Íàæìèòå ëþáóþ êëàâèøó äëÿ ïðîäîëæåíèÿ...";
	(void)_getch();
}

void directionSelect(void)
{
	system("cls");
	selectRecords(person);
	(void)_getch();
}

void directionSave(void)
{
	system("cls");
	save(person, currentSize);
	(void)_getch();
}

void directionTask(void)
{
	system("cls");
	task(person, pairs);
	(void)_getch();
}

bool directionExit(bool flag)
{
	system("cls");
	bool exit = false;
	while (!exit)
	{
		system("cls");
		char choice;
		cout << " Âû óâåðåíû, ÷òî õîòèòå âûéòè?" << endl
			<< " ------------------------------" << endl
			<< " | 1 - Íàçàä â ãëàâíîå ìåíþ   |" << endl
			<< " | x - Âûõîä                  |" << endl
			<< " ------------------------------" << endl
			<< endl << " ==> ";
		choice = _getch();
		switch (choice)
		{
		case '1':
		{
			exit = true;
			break;
		}
		case 'x':
		{
			//system("cls");
			if (memoryIsAllocated) free(person);
			flag = true;
			exit = true;
			cout << " Âûõîä!" << endl << " Íàæìèòå ëþáóþ êëàâèøó äëÿ ïðîäîëæåíèÿ...";
			(void)_getch();
			break;
		}
		default:
		{
			//system("cls");
			cout << " Ââåäåíî íåâåðíîå çíà÷åíèå!" << endl << " Íàæìèòå ëþáóþ êëàâèøó äëÿ ïðîäîëæåíèÿ...";
			(void)_getch();
			break;
		}
		}
	}
	return flag;
}

void menu(void) 
{
	bool exit = false, isLoaded = false;
	while (!exit)
	{
		switch (menuDisplay())
		{
		case '1': 
		{
			directionInsert();
			break;
		}
		case '2': 
		{
			if (!isLoaded)
			{
				exit = directionLoad(exit);
				isLoaded = true;
			}
			else 
			{
				system("cls");
				cout << "Äàííûå óæå çàãðóæåíû!" << endl;
				(void)_getch();
			}
			break;
		}
		case '3': 
		{
			directionSorting();
			break;
		}
		case '4': 
		{
			directionSearch();
			break;
		}
		case '5': 
		{
			directionUpdate();
			break;
		}
		case '6': 
		{
			directionDelete();
			break;
		}
		case '7': 
		{
			directionSelect();
			break;
		}
		case '8': 
		{
			directionSave();
			break;
		}
		case '9': 
		{
			directionTask();
			break;
		}
		case 'x': 
		{
			exit = directionExit(exit);
			break;
		}
		default: 
		{
			//system("cls");
			cout << " Ââåäåíî íåâåðíîå çíà÷åíèå!" << endl << " Íàæìèòå ëþáóþ êëàâèøó äëÿ ïðîäîëæåíèÿ...";
			(void)_getch();
			break;
		}
		}
	}
}
