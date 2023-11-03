#include "menu.h"

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
	cout << " ---------------МЕНЮ--------------" << endl 
		<< " ---------------------------------" << endl 
		<< " | 1 - Ввод массива структур     |" << endl
		<< " | 2 - Загрузить данные из файла |" << endl
		<< " | 3 - Сортировка                |" << endl
		<< " | 4 - Поиск                     |" << endl
		<< " | 5 - Изменение                 |" << endl
		<< " | 6 - Удаление                  |" << endl
		<< " | 7 - Вывод массива структур    |" << endl
		<< " | 8 - Сохранить данные в файл   |" << endl
		<< " | 9 - Индивидуальное задание    |" << endl
		<< " | x - Выход                     |" << endl 
		<< " ---------------------------------" << endl 
		<< " --------ВЫБЕРИТЕ ДЕЙСТВИЕ--------" << endl
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
		cout << " Введите количество добавляемых объектов... (x - Назад в главное меню)" << endl << endl << " ==> ";
		char buf[128];
		cin.getline(buf, 128);
		if ((items = atoi(buf)) != 0) break;
		else
		{
			if (buf[0] == 'x') return;
			cout << " Необходимо ввести число больше нуля!" << endl << " Нажмите любую клавишу для продолжения...";
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
			cout << "Возникла ошибка выделения памяти!" << endl;
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
		cout << " Введите номер поля, по которому будет осуществляться сортировка... (x - Назад в главное меню)" << endl << endl << " ==> ";
		cin.getline(buf, 128);
		if ((field = atoi(buf)) != 0)
		{
			if (field > 5)
			{
				cout << " Введенное значение больше количества полей в записи!" << endl << " Нажмите любую клавишу для продолжения...";
				(void)_getch();
				continue;
			}
			break;
		}
		else
		{
			if (buf[0] == 'x') return;
			cout << " Необходимо ввести число!" << endl << " Нажмите любую клавишу для продолжения...";
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
		cout << " Введите номер поля, по которому будет осуществляться поск... (x - Назад в главное меню)" << endl << endl << " ==> ";
		cin.getline(buf, 128);
		if ((field = atoi(buf)) != 0)
		{
			if (field > 5)
			{
				cout << " Введенное значение больше количества полей в записи!" << endl << " Нажмите любую клавишу для продолжения...";
				(void)_getch();
				continue;
			}
			memset(buf, 0, 128);
			cout << " Введите текст..." << endl << endl << " ==> ";
			cin.getline(buf, 128);
			break;
		}
		else
		{
			if (buf[0] == 'x') return;
			cout << " Необходимо ввести число!" << endl << " Нажмите любую клавишу для продолжения...";
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
		cout << " Введите номер записи... (x - Назад в главное меню)" << endl << endl << " ==> ";
		char buf[128];
		cin.getline(buf, 128);
		if ((item = atoi(buf)) != 0)
		{
			if (item > currentSize)
			{
				cout << " Введенное значение больше размера массива записей!" << endl << " Нажмите любую клавишу для продолжения...";
				(void)_getch();
				continue;
			}
			break;
		}
		else
		{
			if (buf[0] == 'x') return;
			cout << " Необходимо ввести число!" << endl << " Нажмите любую клавишу для продолжения...";
			(void)_getch();
		}
	}
	updateRecord(person[item - 1]);
	system("cls");
	cout << " Запись номер " << item << " изменена!" << endl << " Нажмите любую клавишу для продолжения...";
	(void)_getch();
}

void directionDelete(void)
{
	int item = 0;
	while (1)
	{
		system("cls");
		//cout << maxSize;
		cout << " Введите номер записи... (x - Назад в главное меню)" << endl << endl << " ==> ";
		char buf[128];
		cin.getline(buf, 128);
		if ((item = atoi(buf)) != 0)
		{
			if (item > currentSize)
			{
				cout << " Введенное значение больше размера массива записей!" << endl << " Нажмите любую клавишу для продолжения...";
				(void)_getch();
				continue;
			}
			break;
		}
		else
		{
			if (buf[0] == 'x') return;
			cout << " Необходимо ввести число!" << endl << " Нажмите любую клавишу для продолжения...";
			(void)_getch();
		}
	}
	deleteRecord(person, item - 1);
	currentSize -= 1;
	Person* p = person;
	person = (Person*)realloc(p, currentSize * sizeof(Person));
	system("cls");
	cout << " Запись номер " << item << " удалена!" << endl << " Нажмите любую клавишу для продолжения...";
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
		cout << " Вы уверены, что хотите выйти?" << endl
			<< " ------------------------------" << endl
			<< " | 1 - Назад в главное меню   |" << endl
			<< " | x - Выход                  |" << endl
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
			cout << " Выход!" << endl << " Нажмите любую клавишу для продолжения...";
			(void)_getch();
			break;
		}
		default:
		{
			//system("cls");
			cout << " Введено неверное значение!" << endl << " Нажмите любую клавишу для продолжения...";
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
				cout << "Данные уже загружены!" << endl;
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
			cout << " Введено неверное значение!" << endl << " Нажмите любую клавишу для продолжения...";
			(void)_getch();
			break;
		}
		}
	}
}