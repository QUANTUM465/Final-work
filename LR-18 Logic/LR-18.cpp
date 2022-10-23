//  Завдання - створити програму опрацювання бази даних, застосувавши її розбиття на окремі модулі та підпрограми.
//  Інформація у базі даних повинна бути записана у вигляді бінарного файлу структур.
//  Програма повинна забезпечувати такі основні та додаткові функції опрацювання бази даних :
//  Облік товарів на промисловій гуртовні
//		Основні
//•	Створення файла бази даних із довільним іменем, що вводиться з клавіатури
//•	Наповнення бази даних інформацією з клавіатури
//•	Видрук інформації про елемент бази даних на дисплей
//•	Пошук інформації за вказаним критерієм(не менше 3 різних критеріїв пошуку)
//•	Доповнення інформації у базу даних
//
//		Додаткові
//•	Сортування інформації у базі даних(або створення відповідних індексних файлів для сортування за різними показниками)
//•	Зміна існуючої інформації про певний елемент бази даних
//•	Видалення вибраного елемента бази даних
//•	Пошук інформації за складними критеріями
//•	Обчислення певних узагальнених(сумарних) характеристик, що потребують розрахунку

#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include "Class element.h"
#include "Class list.h"

using namespace std;
bool ProgEnable = true;
List <spusok> lst;
spusok temp;

//Прототипи функцій
void menu();
void MenuSortData();
void MenuFindData();
void MenuFile();
void MenuData();

void Writefile();
void Readfile();

void PrintData();
void PrintAddData();
void WriteData();
void AddToFile();
void ChangeData();
void Sum();

void SortValue();
void SortStelag();
void SortPolycka();
void SortMasa();
void SortLitr();

void DeleteElement();

void FindVolume();
void FindMass();
void FindPrice();
void FindLocation();


//Вказівники на функції
void (*pMenu)() = menu;
void (*pMSData)() = MenuSortData;
void (*pMFData)() = MenuFindData;
void (*pMFile)() = MenuFile;
void (*pMData)() = MenuData;

void (*pwfile)() = Writefile;
void (*prfile)() = Readfile;

void (*pPData)() = PrintData;
void (*pwData)() = WriteData;
void (*pTFile)() = AddToFile;
void (*pPAData)() = PrintAddData;
void (*pCData)() = ChangeData;
void (*pSum)() = Sum;

void (*pFPrice)() = FindPrice;
void (*pFLocation)() = FindLocation;
void (*pFMass)() = FindMass;
void (*pFVolume)() = FindVolume;

void (*pSValue)() = SortValue;
void (*pSStelag)() = SortStelag;
void (*pSPolycka)() = SortPolycka;
void (*pSMasa)() = SortMasa;
void (*pSLitr)() = SortLitr;

void (*pDElement)() = DeleteElement;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	system("cls");
	cout << " \t \t \t МІНІСТЕРСТВО ОСВІТИ І НАУКИ " << endl;
	cout << " \t \t ТЕРНОПІЛЬСЬКИЙ НАЦІОНАЛЬНИЙ ТЕХНІЧНИЙ " << endl;
	cout << " \t \t \t УНІВЕРСИТЕТ ІМ. І. ПУЛЮЯ" << endl;
	cout << "\n \n \n \n \n" << endl;
	cout << "\t  \t      Лабораторна робота на тему:" << endl;
	cout << "\t \t'Облік товарів на промисловій гуртовні'" << endl;
	cout << "\n \n \n \n \n" << endl;
	cout << "\t \t \t \t \t \t \t  Підготував студент " << endl;
	cout << "\t \t \t \t \t \t \t  групи СІ-12" << endl;
	cout << "\t \t \t \t \t \t \t  Курцеба Т. В." << endl;
	cin.get();
	lst.push_back(spusok());
	pMenu();
	while (ProgEnable)
	{
		pMenu();
	}
	return 0;
}

void Writefile() // Запис данних які містить об'єкт у файл (Працює)
{
	string filename;
	cout << "Введіть ім'я файлу який треба створити "; cin >> filename; // Змінна для імені файлу
	string path = filename + ".bin"; // Якщо filename буде dani то назва файлу який треба відкрити dani.bin
	ofstream outputfile;
	outputfile.open(path, ios::binary | ios::out);
	if (!outputfile.is_open())
	{cout << "Помилка створення файла! " << endl;}
	else
	{
		cout << "Файл створено!" << endl;
		for (int i = 0; i < lst.GetSize(); i++)
		{
			outputfile.write((char*)&lst[i], sizeof(spusok)); // Запис данних із об'єкта у файл
		}
		outputfile.close(); // Закриття файлу
	}
	system("pause");
	return;
}
void Readfile() // Читає данні з файлу (Працює)
{
	string filename;
	lst.clear(); // Очищення пам'яті
	cout << "Введіть ім'я файлу який треба відкрити "; cin >> filename; // Змінна для імені файлу
	string path = filename + ".bin"; // Якщо filename буде dani то назва файлу який треба відкрити dani.bin
	ifstream inputfile;
	inputfile.open(path, ios::binary); // Відкриття файлу
	if (!inputfile.is_open())			// Перевірка чи файл відкрито
	{cout << "Помилка відкриття файла! " << endl; system("pause"); return;}
	else
	{
		cout << "Файл відкрито!" << endl;
		for (int i = 0; !inputfile.eof(); i++) // eof() додає лишній циклиі створює об'єкт з данними яких немає у файлі
		{
			// Щоб не виникала помилка треба читати в тимчасову змінну а потім записувати данні в об'єкт
			inputfile.read((char*)&temp, sizeof(spusok)); // Читання данних з файлу 
			lst.push_back(temp); // Данні які читаються записуються в об'єкт і додаються в кінець списку
		}
	}
	lst.pop_back(); // Видалення зайвого елемента створеного через надлишковий цикл
	PrintData(); // Виклик функції друку
	inputfile.close(); // Закриття файлу
	return;
}
void AddToFile() // Функція дописування данних до файлу (Працює)
{
	system("cls");
	for (int i = 0; i < 1; i++)
	{
		lst.push_front(spusok()); // Додавання в початок списку об'єкта з данними які вводяться в циклі
		cout << "Введіть ім'я елемента: " << endl;
		cin >> lst[i].name;
		cout << "Введіть ціну елемента (за метр/одницю): " << endl;
		cin >> lst[i].value;
		cout << "Введіть номер стелажу: (Від 1 до 5)" << endl;
		cin >> lst[i].stelag;
		cout << "Введіть полицю стелажа: (Від 1 до 5)" << endl;
		cin >> lst[i].polycka;
		cout << "Введіть масу (кг): " << endl;
		cin >> lst[i].masa;
		cout << "Введіть об'єм (л): (Якщо елемент не рідина буде 0)" << endl;
		cin >> lst[i].litr;
		if (lst[i].value < 0 || lst[i].stelag < 1 || lst[i].stelag > 6 || lst[i].polycka < 1 || lst[i].polycka > 6 || lst[i].masa < 0 || lst[i].litr < 0)
		{
			cout << "!!!Помилка!!!" << endl;
			cout << "Перевірте правильність введених данних " << endl;
			lst.removeAt(i); // Видалення об'єкта введеного непраильно
			i--;
			// Зменшення циклу на одиницю щоб у разі неправильного введення кількість елементів які треба добати не змінилась
			system("pause");
		}
		system("cls");

	}
	Writefile(); // Виклик функії яка записує данні у файл
	return;
}

void PrintAddData() // Друк данних які треба додати (Працює)
{
	cout << " Ви хочете додати: " << endl;
	for (int i = 0; i < lst.GetSize(); i++)  //int i = 0; i < sizeof(spusok); i++
	{
		cout << "----------------------" << endl;
		cout << "Номер елемента: " << i << endl;
		cout << "Ім'я елемента: " << lst[i].name << endl;
		cout << "Ціна (за метр/одиницю): " << lst[i].value << endl;
		cout << "Стелаж: " << lst[i].stelag << endl;
		cout << "Поличка: " << lst[i].polycka << endl;
		cout << "Маса: " << lst[i].masa << endl;
		cout << "Об`єм: " << lst[i].litr << endl;
	}
}
void PrintData() // Функція виведення данних які містить об'єкт (Працює)
{
	cout << "Данні які містить файл бази данних: " << endl;
	for (int i = 0; i < lst.GetSize(); i++)
	{
		cout << "----------------------" << endl;
		cout << "Номер елемента: " << i << endl;
		cout << "Ім'я елемента: " << lst[i].name << endl;
		cout << "Ціна (за метр/одиницю): " << lst[i].value << endl;
		cout << "Стелаж: " << lst[i].stelag << endl;
		cout << "Поличка: " << lst[i].polycka << endl;
		cout << "Маса: " << lst[i].masa << endl;
		cout << "Об`єм: " << lst[i].litr << endl;
	}
	system("pause");
	return;
}
void WriteData() // Функія введення данних у об'єкт (Працює)
{
	int n = 0;
	cout << "Введіть кількість елементів які треба ввести: " << endl; cin >> n;
	if (n < 1)
	{
		cout << "!!!Помилка!!!" << endl;
		cout << "Занадто мала кількість елементів" << endl;
		system("pause");
		return;
	}
	else {
		for (int i = 0; i < n; i++)
		{

			lst.push_back(spusok()); // Додавання об'єкту в кінець списку і наповнення його у циклі
			cout << "Введіть ім'я елемента: " << endl;
			cin >> lst[i].name;
			cout << "Введіть ціну елемента (за метр/одиницю): " << endl;
			cin >> lst[i].value;
			cout << "Введіть номер стелажу: (Від 1 до 5)" << endl;
			cin >> lst[i].stelag;
			cout << "Введіть полицю стелажа: (Від 1 до 5)" << endl;
			cin >> lst[i].polycka;
			cout << "Введіть масу (кг): " << endl;
			cin >> lst[i].masa;
			cout << "Введіть об'єм (л): (Якщо елемент не рідина буде 0)" << endl;
			cin >> lst[i].litr;
			if (lst[i].value < 0 || lst[i].stelag < 1 || lst[i].stelag > 6 || lst[i].polycka < 1 || lst[i].polycka > 6 || lst[i].masa < 0 || lst[i].litr < 0)
			{
				cout << "!!!Помилка!!!" << endl;
				cout << "Перевірте правильність введених данних " << endl;
				lst.removeAt(i);
				i--;
// Зменшення циклу на одиницю щоб у разі неправильного введення кількість елементів які треба добати не змінилась
				system("pause");
			}
			system("cls");
		}
	}
	return;
}
void ChangeData()
{
	int index; // Тимчасова змінна
	PrintData(); // Виклик функції друку
	cout << "Введіть індекс елемента який треба замінити: " << endl; cin >> index;
	if (index < 0|| index> lst.GetSize())
	{
		cout << "!!!Помилка!!!" << endl;
		cout << "Елемента під таким індексом не існує" << endl;
		return;
	}
	lst.removeAt(index); // Видалення елемента за вказаним індеком
	for (int i = 0; i < 1; i++)
	{
		lst.insert(spusok(),index); // Додавання елемента за вказаним індексом
// Тобто видаливши елемент з індексом а потім додавши елемент з новими данними під тим самим індексом отримаємо заміну данних
		cout << "Введіть ім'я елемента: " << endl;
		cin >> lst[i].name;
		cout << "Введіть ціну елемента (за метр/одиницю): " << endl;
		cin >> lst[i].value;
		cout << "Введіть номер стелажу: (Від 1 до 5)" << endl;
		cin >> lst[i].stelag;
		cout << "Введіть полицю стелажа: (Від 1 до 5)" << endl;
		cin >> lst[i].polycka;
		cout << "Введіть масу (кг): " << endl;
		cin >> lst[i].masa;
		cout << "Введіть об'єм (л): (Якщо елемент не рідина буде 0)" << endl;
		cin >> lst[i].litr;
		if (lst[i].value < 0 || lst[i].stelag < 1 || lst[i].stelag > 6 || lst[i].polycka < 1 || lst[i].polycka > 6 || lst[i].masa < 0 || lst[i].litr < 0)
		{
			cout << "!!!Помилка!!!" << endl;
			cout << "Перевірте правильність введених данних " << endl;
			lst.removeAt(i);
			i--;
			// Зменшення циклу на одиницю щоб у разі неправильного введення кількість елементів які треба добати не змінилась
			system("pause");
		}
		system("cls");
	}
	Writefile();
	return;
}
void Sum()
{
	float summasa = 0, sumlitr = 0;
	for (int i = 0; i < lst.GetSize(); i++)
	{
		summasa += lst[i].masa;
	}
	for (int i = 0; i < lst.GetSize(); i++)
	{
		sumlitr += lst[i].litr;
	}
	cout << "Загальні данні :" << endl;
	cout << "Загальна кількість елементів : " << lst.GetSize() - 1 << endl;
	cout << "Маса усіх елементів: " << summasa << endl;
	cout << "Об'єм усіх  рідких елементів: " << sumlitr << endl;
	system("pause");
	return;
}

void SortValue()
{
	cout << "---Данні до сортування---" << endl;
	PrintData();
	system("cls");
	// Перебираємо кожен елемент масиву (крім останнього, він вже буде відсортований до того часу, коли ми до нього дійдемо)
	for (int startIndex = 0; startIndex < lst.GetSize() - 1; ++startIndex)
	{
		// У змінній smallestIndex зберігається індекс найменшого значення, яке ми знайшли в поточній ітерації.
		// Починаємо з того, що найменший елемент в цій ітерації - це перший елемент (індекс 0)
		int smallestIndex = startIndex;
		// Потім шукаємо менший елемент в іншій частині масиву
		for (int currentIndex = startIndex + 1; currentIndex < lst.GetSize(); ++currentIndex)
		{
			// Якщо ми знайшли елемент, який менше нашого найменшого елементу,
			if (lst[currentIndex].value < lst[smallestIndex].value)
				// то запам'ятовуємо його
				smallestIndex = currentIndex;
		}
		// smallestIndex тепер найменший елемент.
		// Міняємо місцями наше початкове найменше число з тим, яке ми виявили
		swap(lst[startIndex], lst[smallestIndex]);
	}
	cout << "Данні після сортування" << endl;
	PrintData(); // Друк відсортованих данних
}
void SortStelag()
{
	cout << "---Данні до сортування---" << endl;
	PrintData();
	system("cls");
	// Тут аналогічно з функцією SortValue 
	for (int startIndex = 0; startIndex < lst.GetSize() - 1; ++startIndex)
	{
		int smallestIndex = startIndex;
		for (int currentIndex = startIndex + 1; currentIndex < lst.GetSize(); ++currentIndex)
		{
			// Змінюється тільки поля в if відносно яких проводиться сортування
			if (lst[currentIndex].stelag < lst[smallestIndex].stelag)
				smallestIndex = currentIndex;
		}
		swap(lst[startIndex], lst[smallestIndex]);
	}
	cout << "Данні після сортування" << endl;
	PrintData(); // Друк відсортованих данних
}
void SortPolycka()
{
	cout << "---Данні до сортування---" << endl;
	PrintData();
	system("cls");
	// Тут аналогічно з функцією SortValue 
	for (int startIndex = 0; startIndex < lst.GetSize() - 1; ++startIndex)
	{
		int smallestIndex = startIndex;
		for (int currentIndex = startIndex + 1; currentIndex < lst.GetSize(); ++currentIndex)
		{
			// Змінюється тільки поля в if відносно яких проводиться сортування
			if (lst[currentIndex].polycka < lst[smallestIndex].polycka)
				smallestIndex = currentIndex;
		}
		swap(lst[startIndex], lst[smallestIndex]);
	}
	cout << "Данні після сортування" << endl;
	PrintData(); // Друк відсортованих данних
}
void SortMasa()
{
	cout << "---Данні до сортування---" << endl;
	PrintData();
	system("cls");
	// Тут аналогічно з функцією SortValue 
	for (int startIndex = 0; startIndex < lst.GetSize() - 1; ++startIndex)
	{
		int smallestIndex = startIndex;
		for (int currentIndex = startIndex + 1; currentIndex < lst.GetSize(); ++currentIndex)
		{
			// Змінюється тільки поля в if відносно яких проводиться сортування
			if (lst[currentIndex].masa < lst[smallestIndex].masa)
				smallestIndex = currentIndex;
		}
		swap(lst[startIndex], lst[smallestIndex]);
	}
	cout << "Данні після сортування" << endl;
	PrintData(); // Друк відсортованих данних
}
void SortLitr()
{
	cout << "---Данні до сортування---" << endl;
	PrintData();
	system("cls");
	// Тут аналогічно з функцією SortValue 
	for (int startIndex = 0; startIndex < lst.GetSize() - 1; ++startIndex)
	{
		int smallestIndex = startIndex;
		for (int currentIndex = startIndex + 1; currentIndex < lst.GetSize(); ++currentIndex)
		{
			// Змінюється тільки поля в if відносно яких проводиться сортування
			if (lst[currentIndex].litr < lst[smallestIndex].litr)
				smallestIndex = currentIndex;
		}
		swap(lst[startIndex], lst[smallestIndex]);
	}
	cout << "Данні після сортування" << endl;
	PrintData(); // Друк відсортованих данних

}

void MenuData()
{
	system("cls");
	int choseinterface;
	cout << ("1)Ввести данні в об'єкт;\n");
	cout << ("2)Вивести данні які містить база данних ;\n");
	cout << ("3)Дописати данні до файлу ; \n");
	cout << ("4)Замінити данні за індексом ; \n");
	cout << ("5)Вивести загальні данні ; \n");
	cout << ("6)Видалити елемент ; \n");
	cout << "\n Вибрано:";
	cin >> choseinterface;
	switch (choseinterface)
	{
	case 1:
		system("cls");
		pwData();
		break;
	case 2:
		system("cls");
		pPData();
		break;

	case 3:
		system("cls");
		pTFile();
		break;
	case 4:
		system("cls");
		pCData();
		break;
	case 5:
		system("cls");
		pSum();
		break;
	case 6:
		system("cls");
		pDElement();
		break;
	}
}
void MenuFile()
{
	system("cls");
	int choseinterface;
	cout << ("1)Створити новий файл бази данних;\n");
	cout << ("2)Прочитати вже існуючий файл бази данних;\n");
	cout << "\n Вибрано:";
	cin >> choseinterface;
	switch (choseinterface)
	{
	case 1:
		system("cls");
		pwfile();
		break;
	case 2:
		system("cls");
		prfile();
		break;
	}
}
void MenuSortData()
{
	system("cls");
	int chosesort;
	cout << ("\n\t\t-----Сортування-----\n");
	cout << ("1) Сортувати за ціною; \n");
	cout << ("2) Сортувати за стелажем; \n");
	cout << ("3) Сортувати за полицею; \n");
	cout << ("4) Сортувати за масою; \n");
	cout << ("5) Сортувати за об'ємом; \n");
	cout << ("Вибрано ; \n");
	cin >> chosesort;

	switch (chosesort)
	{
	case 1:
		system("cls");
		pSValue();
		break;
	case 2:
		system("cls");
		pSStelag();
		break;
	case 3:
		system("cls");
		pSPolycka();
		break;
	case 4:
		system("cls");
		pSMasa();
		break;
	case 5:
		system("cls");
		pSLitr();
		break;
	}
	return;
}
void MenuFindData()
{
	system("cls");
	int choseway;
	cout << ("\n\t\t-----Пошук-----\n");
	cout << ("1)Шукати за ціною ;\n");
	cout << ("2)Шукати за стелажем і полицею ;\n");
	cout << ("3)Шукати за масою ;\n");
	cout << ("4)Шукати за об'ємом ;\n");
	cout << "\n Вибрано:";
	cin >> choseway;
	switch (choseway)
	{
	case 1:
		system("cls");
		pFPrice();
		break;

	case 2:
		system("cls");
		pFLocation();
		break;

	case 3:
		system("cls");
		pFMass();
		break;

	case 4:
		system("cls");
		pFVolume();
		break;
	}
	return;
}
void menu() //Функція виклику меню
{
	system("cls");
	int choseinterface;
	cout << ("\n\t\t-----Меню-----\n");
	cout << ("1)Робота з файлом ;\n");
	cout << ("2)Робота з данними ;\n");
	cout << ("3)Пошук ; \n");
	cout << ("4)Сортування ; \n");
	cout << ("5)Вихід;\n");
	cout << "\n Вибрано:";
	cin >> choseinterface;
	switch (choseinterface)
	{
	case 1:
		system("cls");
		pMFile();
		break;
	case 2:
		system("cls");
		pMData();
		break;
	case 3:
		system("cls");
		pMFData();
		break;
	case 4:
		system("cls");
		pMSData();
		break;
	case 5:
		system("cls");
		lst.clear();
		ProgEnable = false;
		break;

	}
}

void FindPrice() // Пошук елементів за ціною
{
	int price = 0, chosefind = 0;
	cout << "Введіть ціну відносно якої треба шукати" << endl; cin >> price;
	cout << ("1)Шукати елементи дорожчі вказаної ціни ") << endl;
	cout << ("2)Шукати елементи дешевші вказаної ціни ") << endl;
	cout << ("3)Шукати елементи за вказаною ціною ") << endl;
	cin >> chosefind;
	if (price < 0)
	{
		cout << "!!!Помилка!!!" << endl;
		cout << "Ціна введена неправильно " << endl;
		system("pause");
	}
	else
	{
		switch (chosefind)
		{
		case 1:
			system("cls");
			for (int i = 0; i < lst.GetSize(); i++)
			{ // Перебираємо елементи поки не знайдемо елемент із більшою ціною ніж вказана і друкуємо їх
				if (lst[i].value > price)
				{
					cout << "----------------------" << endl;
					cout << "Номер елемента: " << i << endl;
					cout << "Ім'я елемента: " << lst[i].name << endl;
					cout << "Ціна: " << lst[i].value << endl;
					cout << "Стелаж: " << lst[i].stelag << endl;
					cout << "Поличка: " << lst[i].polycka << endl;
					cout << "Маса: " << lst[i].masa << endl;
					cout << "Об`єм: " << lst[i].litr << endl;
				}
			}
			break;
		case 2:
			system("cls");
			for (int i = 0; i < lst.GetSize(); i++)
			{// Перебираємо елементи поки не знайдемо елемент із меншою ціною ніж вказана і друкуємо їх
				if (lst[i].value < price)
				{
					cout << "----------------------" << endl;
					cout << "Номер елемента: " << i << endl;
					cout << "Ім'я елемента: " << lst[i].name << endl;
					cout << "Ціна: " << lst[i].value << endl;
					cout << "Стелаж: " << lst[i].stelag << endl;
					cout << "Поличка: " << lst[i].polycka << endl;
					cout << "Маса: " << lst[i].masa << endl;
					cout << "Об`єм: " << lst[i].litr << endl;
				}
			}
			break;
		case 3:
			system("cls");
			for (int i = 0; i < lst.GetSize(); i++)
			{// Перебираємо елементи поки не знайдемо елемент із тою самою ціною що і вказана а потім друкуємо їх
				if (lst[i].value == price)
				{
					cout << "----------------------" << endl;
					cout << "Номер елемента: " << i << endl;
					cout << "Ім'я елемента: " << lst[i].name << endl;
					cout << "Ціна: " << lst[i].value << endl;
					cout << "Стелаж: " << lst[i].stelag << endl;
					cout << "Поличка: " << lst[i].polycka << endl;
					cout << "Маса: " << lst[i].masa << endl;
					cout << "Об`єм: " << lst[i].litr << endl;
				}
			}
			break;
		}
	}
	system("pause");
	return;
}
void FindLocation() // Пошук елементів за розташуванням на стелажі і полиці
{
	int stel = 0, pol = 0;
	cout << "Введіть стелаж де знаходиться елемент (Від 1 до 5)" << endl; cin >> stel;
	cout << "Введіть поличку де знаходиться елемент (Від 1 до 5)" << endl; cin >> pol;
	if (stel < 0 || stel > 6 || pol < 0 || pol > 6)
	{
		cout << "!!!Помилка!!!" << endl;
		cout << "Номер стелажа або полиці введено неправильно " << endl;
		system("pause");
	}
	else
	{
		for (int i = 0; i < lst.GetSize(); i++)
		{
			if (lst[i].stelag == stel)
			{// Перебираємо елементи поки не знайдемо елемент із тим самим номером стелажа як і вказаний
				if (lst[i].polycka == pol)
				{// Перебираємо елементи поки не знайдемо елемент із тим самим номером ролички як і вказана 
					// Друк знайдених данних
					cout << "----------------------" << endl;
					cout << "Номер елемента: " << i << endl;
					cout << "Ім'я елемента: " << lst[i].name << endl;
					cout << "Ціна: " << lst[i].value << endl;
					cout << "Стелаж: " << lst[i].stelag << endl;
					cout << "Поличка: " << lst[i].polycka << endl;
					cout << "Маса: " << lst[i].masa << endl;
					cout << "Об`єм: " << lst[i].litr << endl;
				}
			}
		}
	}
	system("pause");
	return;
}
void FindMass() // Пошук елемента за масою 
{
	int chosefind = 0, mass = 0;
	cout << "Введіть масу відносно якої треба шукати" << endl; cin >> mass;
	cout << ("1)Шукати елементи важчі вказаної маси \n") << endl;
	cout << ("2)Шукати елементи легші вказаної маси \n") << endl;
	cout << ("3)Шукати елементи за вказаною масою \n") << endl;
	cin >> chosefind;
	if (mass < 0)
	{
		cout << "!!!Помилка!!!" << endl;
		cout << "Маса введена неправильно " << endl;
		system("pause");
	}
	else
	{
		switch (chosefind)
		{
		case 1:
			system("cls");
			for (int i = 0; i < lst.GetSize(); i++)
			{// Перебираємо елементи поки не знайдемо елемент із більшою масою ніж вказана і друкуємо їх
				if (lst[i].masa > mass)
				{
					cout << "----------------------" << endl;
					cout << "Номер елемента: " << i << endl;
					cout << "Ім'я елемента: " << lst[i].name << endl;
					cout << "Ціна: " << lst[i].value << endl;
					cout << "Стелаж: " << lst[i].stelag << endl;
					cout << "Поличка: " << lst[i].polycka << endl;
					cout << "Маса: " << lst[i].masa << endl;
					cout << "Об`єм: " << lst[i].litr << endl;
				}
			}
			break;
		case 2:
			system("cls");
			for (int i = 0; i < lst.GetSize(); i++)
			{// Перебираємо елементи поки не знайдемо елемент із меншою масою ніж вказана і друкуємо їх
				if (lst[i].masa < mass)
				{
					cout << "----------------------" << endl;
					cout << "Номер елемента: " << i << endl;
					cout << "Ім'я елемента: " << lst[i].name << endl;
					cout << "Ціна: " << lst[i].value << endl;
					cout << "Стелаж: " << lst[i].stelag << endl;
					cout << "Поличка: " << lst[i].polycka << endl;
					cout << "Маса: " << lst[i].masa << endl;
					cout << "Об`єм: " << lst[i].litr << endl;
				}
			}
			break;
		case 3:
			system("cls");
			for (int i = 0; i < lst.GetSize(); i++)
			{// Перебираємо елементи поки не знайдемо елемент із тою самою масою що і вказана а потім друкуємо їх
				if (lst[i].masa == mass)
				{
					cout << "----------------------" << endl;
					cout << "Номер елемента: " << i << endl;
					cout << "Ім'я елемента: " << lst[i].name << endl;
					cout << "Ціна: " << lst[i].value << endl;
					cout << "Стелаж: " << lst[i].stelag << endl;
					cout << "Поличка: " << lst[i].polycka << endl;
					cout << "Маса: " << lst[i].masa << endl;
					cout << "Об`єм: " << lst[i].litr << endl;
				}
			}
			break;
		}
	}
	system("pause");
	return;
}
void FindVolume()
{
	int volume = 0;
	cout << "Введіть об'єм відносно якого треба шукати: " << endl; cin >> volume;
	for (int i = 0; i < lst.GetSize(); i++)
	{
		if (lst[i].litr == volume)
		{ // Перебираємо елементи поки не знайдемо елемент із тим сами об'ємом що і вказаний і друкуємо їх
			cout << "----------------------" << endl;
			cout << "Номер елемента: " << i << endl;
			cout << "Ім'я елемента: " << lst[i].name << endl;
			cout << "Ціна: " << lst[i].value << endl;
			cout << "Стелаж: " << lst[i].stelag << endl;
			cout << "Поличка: " << lst[i].polycka << endl;
			cout << "Маса: " << lst[i].masa << endl;
			cout << "Об`єм: " << lst[i].litr << endl;
		}
	}
	system("pause");
	return;
}

void DeleteElement()
{
	int index; // Тимчасова змінна
	PrintData();
	cout << "Введіть індекс елемента який треба видалити: " << endl; cin >> index;
	if (index < 0 || index > lst.GetSize() - 1)
	{
		cout << "Елемента з таким індексом не існує" << endl;
		system("pause");
	}
	else
	{
		lst.removeAt(index); // Видалення елемента за вказаним індексом 
		// А потім збереження змін у той самий чи інший файл
		Writefile();
		return;
	}
}