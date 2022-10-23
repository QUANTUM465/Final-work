//  �������� - �������� �������� ����������� ���� �����, ������������ �� �������� �� ����� ����� �� ����������.
//  ���������� � ��� ����� ������� ���� �������� � ������ �������� ����� ��������.
//  �������� ������� ������������� ��� ������ �� �������� ������� ����������� ���� ����� :
//  ���� ������ �� ���������� �������
//		������
//�	��������� ����� ���� ����� �� �������� ������, �� ��������� � ���������
//�	���������� ���� ����� ����������� � ���������
//�	������ ���������� ��� ������� ���� ����� �� �������
//�	����� ���������� �� �������� �������(�� ����� 3 ����� ������� ������)
//�	���������� ���������� � ���� �����
//
//		��������
//�	���������� ���������� � ��� �����(��� ��������� ��������� ��������� ����� ��� ���������� �� ������ �����������)
//�	���� ������� ���������� ��� ������ ������� ���� �����
//�	��������� ��������� �������� ���� �����
//�	����� ���������� �� ��������� ���������
//�	���������� ������ ������������(��������) �������������, �� ���������� ����������

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

//��������� �������
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


//��������� �� �������
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
	cout << " \t \t \t ̲Ͳ�������� ��²�� � ����� " << endl;
	cout << " \t \t �����ϲ������� ��ֲ�������� ���Ͳ���� " << endl;
	cout << " \t \t \t �Ͳ�������� ��. �. �����" << endl;
	cout << "\n \n \n \n \n" << endl;
	cout << "\t  \t      ����������� ������ �� ����:" << endl;
	cout << "\t \t'���� ������ �� ���������� �������'" << endl;
	cout << "\n \n \n \n \n" << endl;
	cout << "\t \t \t \t \t \t \t  ϳ�������� ������� " << endl;
	cout << "\t \t \t \t \t \t \t  ����� Ѳ-12" << endl;
	cout << "\t \t \t \t \t \t \t  ������� �. �." << endl;
	cin.get();
	lst.push_back(spusok());
	pMenu();
	while (ProgEnable)
	{
		pMenu();
	}
	return 0;
}

void Writefile() // ����� ������ �� ������ ��'��� � ���� (������)
{
	string filename;
	cout << "������ ��'� ����� ���� ����� �������� "; cin >> filename; // ����� ��� ���� �����
	string path = filename + ".bin"; // ���� filename ���� dani �� ����� ����� ���� ����� ������� dani.bin
	ofstream outputfile;
	outputfile.open(path, ios::binary | ios::out);
	if (!outputfile.is_open())
	{cout << "������� ��������� �����! " << endl;}
	else
	{
		cout << "���� ��������!" << endl;
		for (int i = 0; i < lst.GetSize(); i++)
		{
			outputfile.write((char*)&lst[i], sizeof(spusok)); // ����� ������ �� ��'���� � ����
		}
		outputfile.close(); // �������� �����
	}
	system("pause");
	return;
}
void Readfile() // ���� ���� � ����� (������)
{
	string filename;
	lst.clear(); // �������� ���'��
	cout << "������ ��'� ����� ���� ����� ������� "; cin >> filename; // ����� ��� ���� �����
	string path = filename + ".bin"; // ���� filename ���� dani �� ����� ����� ���� ����� ������� dani.bin
	ifstream inputfile;
	inputfile.open(path, ios::binary); // ³������� �����
	if (!inputfile.is_open())			// �������� �� ���� �������
	{cout << "������� �������� �����! " << endl; system("pause"); return;}
	else
	{
		cout << "���� �������!" << endl;
		for (int i = 0; !inputfile.eof(); i++) // eof() ���� ����� ����� ������� ��'��� � ������� ���� ���� � ����
		{
			// ��� �� �������� ������� ����� ������ � ��������� ����� � ���� ���������� ���� � ��'���
			inputfile.read((char*)&temp, sizeof(spusok)); // ������� ������ � ����� 
			lst.push_back(temp); // ���� �� ��������� ����������� � ��'��� � ��������� � ����� ������
		}
	}
	lst.pop_back(); // ��������� ������� �������� ���������� ����� ����������� ����
	PrintData(); // ������ ������� �����
	inputfile.close(); // �������� �����
	return;
}
void AddToFile() // ������� ����������� ������ �� ����� (������)
{
	system("cls");
	for (int i = 0; i < 1; i++)
	{
		lst.push_front(spusok()); // ��������� � ������� ������ ��'���� � ������� �� ��������� � ����
		cout << "������ ��'� ��������: " << endl;
		cin >> lst[i].name;
		cout << "������ ���� �������� (�� ����/������): " << endl;
		cin >> lst[i].value;
		cout << "������ ����� �������: (³� 1 �� 5)" << endl;
		cin >> lst[i].stelag;
		cout << "������ ������ �������: (³� 1 �� 5)" << endl;
		cin >> lst[i].polycka;
		cout << "������ ���� (��): " << endl;
		cin >> lst[i].masa;
		cout << "������ ��'�� (�): (���� ������� �� ����� ���� 0)" << endl;
		cin >> lst[i].litr;
		if (lst[i].value < 0 || lst[i].stelag < 1 || lst[i].stelag > 6 || lst[i].polycka < 1 || lst[i].polycka > 6 || lst[i].masa < 0 || lst[i].litr < 0)
		{
			cout << "!!!�������!!!" << endl;
			cout << "�������� ����������� �������� ������ " << endl;
			lst.removeAt(i); // ��������� ��'���� ��������� ����������
			i--;
			// ��������� ����� �� ������� ��� � ��� ������������� �������� ������� �������� �� ����� ������ �� ��������
			system("pause");
		}
		system("cls");

	}
	Writefile(); // ������ ���곿 ��� ������ ���� � ����
	return;
}

void PrintAddData() // ���� ������ �� ����� ������ (������)
{
	cout << " �� ������ ������: " << endl;
	for (int i = 0; i < lst.GetSize(); i++)  //int i = 0; i < sizeof(spusok); i++
	{
		cout << "----------------------" << endl;
		cout << "����� ��������: " << i << endl;
		cout << "��'� ��������: " << lst[i].name << endl;
		cout << "ֳ�� (�� ����/�������): " << lst[i].value << endl;
		cout << "������: " << lst[i].stelag << endl;
		cout << "�������: " << lst[i].polycka << endl;
		cout << "����: " << lst[i].masa << endl;
		cout << "��`��: " << lst[i].litr << endl;
	}
}
void PrintData() // ������� ��������� ������ �� ������ ��'��� (������)
{
	cout << "���� �� ������ ���� ���� ������: " << endl;
	for (int i = 0; i < lst.GetSize(); i++)
	{
		cout << "----------------------" << endl;
		cout << "����� ��������: " << i << endl;
		cout << "��'� ��������: " << lst[i].name << endl;
		cout << "ֳ�� (�� ����/�������): " << lst[i].value << endl;
		cout << "������: " << lst[i].stelag << endl;
		cout << "�������: " << lst[i].polycka << endl;
		cout << "����: " << lst[i].masa << endl;
		cout << "��`��: " << lst[i].litr << endl;
	}
	system("pause");
	return;
}
void WriteData() // ����� �������� ������ � ��'��� (������)
{
	int n = 0;
	cout << "������ ������� �������� �� ����� ������: " << endl; cin >> n;
	if (n < 1)
	{
		cout << "!!!�������!!!" << endl;
		cout << "������� ���� ������� ��������" << endl;
		system("pause");
		return;
	}
	else {
		for (int i = 0; i < n; i++)
		{

			lst.push_back(spusok()); // ��������� ��'���� � ����� ������ � ���������� ���� � ����
			cout << "������ ��'� ��������: " << endl;
			cin >> lst[i].name;
			cout << "������ ���� �������� (�� ����/�������): " << endl;
			cin >> lst[i].value;
			cout << "������ ����� �������: (³� 1 �� 5)" << endl;
			cin >> lst[i].stelag;
			cout << "������ ������ �������: (³� 1 �� 5)" << endl;
			cin >> lst[i].polycka;
			cout << "������ ���� (��): " << endl;
			cin >> lst[i].masa;
			cout << "������ ��'�� (�): (���� ������� �� ����� ���� 0)" << endl;
			cin >> lst[i].litr;
			if (lst[i].value < 0 || lst[i].stelag < 1 || lst[i].stelag > 6 || lst[i].polycka < 1 || lst[i].polycka > 6 || lst[i].masa < 0 || lst[i].litr < 0)
			{
				cout << "!!!�������!!!" << endl;
				cout << "�������� ����������� �������� ������ " << endl;
				lst.removeAt(i);
				i--;
// ��������� ����� �� ������� ��� � ��� ������������� �������� ������� �������� �� ����� ������ �� ��������
				system("pause");
			}
			system("cls");
		}
	}
	return;
}
void ChangeData()
{
	int index; // ��������� �����
	PrintData(); // ������ ������� �����
	cout << "������ ������ �������� ���� ����� �������: " << endl; cin >> index;
	if (index < 0|| index> lst.GetSize())
	{
		cout << "!!!�������!!!" << endl;
		cout << "�������� �� ����� �������� �� ����" << endl;
		return;
	}
	lst.removeAt(index); // ��������� �������� �� �������� �������
	for (int i = 0; i < 1; i++)
	{
		lst.insert(spusok(),index); // ��������� �������� �� �������� ��������
// ����� ��������� ������� � �������� � ���� ������� ������� � ������ ������� �� ��� ����� �������� �������� ����� ������
		cout << "������ ��'� ��������: " << endl;
		cin >> lst[i].name;
		cout << "������ ���� �������� (�� ����/�������): " << endl;
		cin >> lst[i].value;
		cout << "������ ����� �������: (³� 1 �� 5)" << endl;
		cin >> lst[i].stelag;
		cout << "������ ������ �������: (³� 1 �� 5)" << endl;
		cin >> lst[i].polycka;
		cout << "������ ���� (��): " << endl;
		cin >> lst[i].masa;
		cout << "������ ��'�� (�): (���� ������� �� ����� ���� 0)" << endl;
		cin >> lst[i].litr;
		if (lst[i].value < 0 || lst[i].stelag < 1 || lst[i].stelag > 6 || lst[i].polycka < 1 || lst[i].polycka > 6 || lst[i].masa < 0 || lst[i].litr < 0)
		{
			cout << "!!!�������!!!" << endl;
			cout << "�������� ����������� �������� ������ " << endl;
			lst.removeAt(i);
			i--;
			// ��������� ����� �� ������� ��� � ��� ������������� �������� ������� �������� �� ����� ������ �� ��������
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
	cout << "������� ���� :" << endl;
	cout << "�������� ������� �������� : " << lst.GetSize() - 1 << endl;
	cout << "���� ��� ��������: " << summasa << endl;
	cout << "��'�� ���  ����� ��������: " << sumlitr << endl;
	system("pause");
	return;
}

void SortValue()
{
	cout << "---���� �� ����������---" << endl;
	PrintData();
	system("cls");
	// ���������� ����� ������� ������ (��� ����������, �� ��� ���� ������������ �� ���� ����, ���� �� �� ����� ������)
	for (int startIndex = 0; startIndex < lst.GetSize() - 1; ++startIndex)
	{
		// � ����� smallestIndex ���������� ������ ���������� ��������, ��� �� ������� � ������� ��������.
		// �������� � ����, �� ��������� ������� � ��� �������� - �� ������ ������� (������ 0)
		int smallestIndex = startIndex;
		// ���� ������ ������ ������� � ����� ������ ������
		for (int currentIndex = startIndex + 1; currentIndex < lst.GetSize(); ++currentIndex)
		{
			// ���� �� ������� �������, ���� ����� ������ ���������� ��������,
			if (lst[currentIndex].value < lst[smallestIndex].value)
				// �� �����'������� ����
				smallestIndex = currentIndex;
		}
		// smallestIndex ����� ��������� �������.
		// ̳����� ������ ���� ��������� �������� ����� � ���, ��� �� �������
		swap(lst[startIndex], lst[smallestIndex]);
	}
	cout << "���� ���� ����������" << endl;
	PrintData(); // ���� ������������ ������
}
void SortStelag()
{
	cout << "---���� �� ����������---" << endl;
	PrintData();
	system("cls");
	// ��� ��������� � �������� SortValue 
	for (int startIndex = 0; startIndex < lst.GetSize() - 1; ++startIndex)
	{
		int smallestIndex = startIndex;
		for (int currentIndex = startIndex + 1; currentIndex < lst.GetSize(); ++currentIndex)
		{
			// ��������� ����� ���� � if ������� ���� ����������� ����������
			if (lst[currentIndex].stelag < lst[smallestIndex].stelag)
				smallestIndex = currentIndex;
		}
		swap(lst[startIndex], lst[smallestIndex]);
	}
	cout << "���� ���� ����������" << endl;
	PrintData(); // ���� ������������ ������
}
void SortPolycka()
{
	cout << "---���� �� ����������---" << endl;
	PrintData();
	system("cls");
	// ��� ��������� � �������� SortValue 
	for (int startIndex = 0; startIndex < lst.GetSize() - 1; ++startIndex)
	{
		int smallestIndex = startIndex;
		for (int currentIndex = startIndex + 1; currentIndex < lst.GetSize(); ++currentIndex)
		{
			// ��������� ����� ���� � if ������� ���� ����������� ����������
			if (lst[currentIndex].polycka < lst[smallestIndex].polycka)
				smallestIndex = currentIndex;
		}
		swap(lst[startIndex], lst[smallestIndex]);
	}
	cout << "���� ���� ����������" << endl;
	PrintData(); // ���� ������������ ������
}
void SortMasa()
{
	cout << "---���� �� ����������---" << endl;
	PrintData();
	system("cls");
	// ��� ��������� � �������� SortValue 
	for (int startIndex = 0; startIndex < lst.GetSize() - 1; ++startIndex)
	{
		int smallestIndex = startIndex;
		for (int currentIndex = startIndex + 1; currentIndex < lst.GetSize(); ++currentIndex)
		{
			// ��������� ����� ���� � if ������� ���� ����������� ����������
			if (lst[currentIndex].masa < lst[smallestIndex].masa)
				smallestIndex = currentIndex;
		}
		swap(lst[startIndex], lst[smallestIndex]);
	}
	cout << "���� ���� ����������" << endl;
	PrintData(); // ���� ������������ ������
}
void SortLitr()
{
	cout << "---���� �� ����������---" << endl;
	PrintData();
	system("cls");
	// ��� ��������� � �������� SortValue 
	for (int startIndex = 0; startIndex < lst.GetSize() - 1; ++startIndex)
	{
		int smallestIndex = startIndex;
		for (int currentIndex = startIndex + 1; currentIndex < lst.GetSize(); ++currentIndex)
		{
			// ��������� ����� ���� � if ������� ���� ����������� ����������
			if (lst[currentIndex].litr < lst[smallestIndex].litr)
				smallestIndex = currentIndex;
		}
		swap(lst[startIndex], lst[smallestIndex]);
	}
	cout << "���� ���� ����������" << endl;
	PrintData(); // ���� ������������ ������

}

void MenuData()
{
	system("cls");
	int choseinterface;
	cout << ("1)������ ���� � ��'���;\n");
	cout << ("2)������� ���� �� ������ ���� ������ ;\n");
	cout << ("3)�������� ���� �� ����� ; \n");
	cout << ("4)������� ���� �� �������� ; \n");
	cout << ("5)������� ������� ���� ; \n");
	cout << ("6)�������� ������� ; \n");
	cout << "\n �������:";
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
	cout << ("1)�������� ����� ���� ���� ������;\n");
	cout << ("2)��������� ��� �������� ���� ���� ������;\n");
	cout << "\n �������:";
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
	cout << ("\n\t\t-----����������-----\n");
	cout << ("1) ��������� �� �����; \n");
	cout << ("2) ��������� �� ��������; \n");
	cout << ("3) ��������� �� �������; \n");
	cout << ("4) ��������� �� �����; \n");
	cout << ("5) ��������� �� ��'����; \n");
	cout << ("������� ; \n");
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
	cout << ("\n\t\t-----�����-----\n");
	cout << ("1)������ �� ����� ;\n");
	cout << ("2)������ �� �������� � ������� ;\n");
	cout << ("3)������ �� ����� ;\n");
	cout << ("4)������ �� ��'���� ;\n");
	cout << "\n �������:";
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
void menu() //������� ������� ����
{
	system("cls");
	int choseinterface;
	cout << ("\n\t\t-----����-----\n");
	cout << ("1)������ � ������ ;\n");
	cout << ("2)������ � ������� ;\n");
	cout << ("3)����� ; \n");
	cout << ("4)���������� ; \n");
	cout << ("5)�����;\n");
	cout << "\n �������:";
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

void FindPrice() // ����� �������� �� �����
{
	int price = 0, chosefind = 0;
	cout << "������ ���� ������� ��� ����� ������" << endl; cin >> price;
	cout << ("1)������ �������� ������� ������� ���� ") << endl;
	cout << ("2)������ �������� ������� ������� ���� ") << endl;
	cout << ("3)������ �������� �� �������� ����� ") << endl;
	cin >> chosefind;
	if (price < 0)
	{
		cout << "!!!�������!!!" << endl;
		cout << "ֳ�� ������� ����������� " << endl;
		system("pause");
	}
	else
	{
		switch (chosefind)
		{
		case 1:
			system("cls");
			for (int i = 0; i < lst.GetSize(); i++)
			{ // ���������� �������� ���� �� �������� ������� �� ������ ����� �� ������� � ������� ��
				if (lst[i].value > price)
				{
					cout << "----------------------" << endl;
					cout << "����� ��������: " << i << endl;
					cout << "��'� ��������: " << lst[i].name << endl;
					cout << "ֳ��: " << lst[i].value << endl;
					cout << "������: " << lst[i].stelag << endl;
					cout << "�������: " << lst[i].polycka << endl;
					cout << "����: " << lst[i].masa << endl;
					cout << "��`��: " << lst[i].litr << endl;
				}
			}
			break;
		case 2:
			system("cls");
			for (int i = 0; i < lst.GetSize(); i++)
			{// ���������� �������� ���� �� �������� ������� �� ������ ����� �� ������� � ������� ��
				if (lst[i].value < price)
				{
					cout << "----------------------" << endl;
					cout << "����� ��������: " << i << endl;
					cout << "��'� ��������: " << lst[i].name << endl;
					cout << "ֳ��: " << lst[i].value << endl;
					cout << "������: " << lst[i].stelag << endl;
					cout << "�������: " << lst[i].polycka << endl;
					cout << "����: " << lst[i].masa << endl;
					cout << "��`��: " << lst[i].litr << endl;
				}
			}
			break;
		case 3:
			system("cls");
			for (int i = 0; i < lst.GetSize(); i++)
			{// ���������� �������� ���� �� �������� ������� �� ��� ����� ����� �� � ������� � ���� ������� ��
				if (lst[i].value == price)
				{
					cout << "----------------------" << endl;
					cout << "����� ��������: " << i << endl;
					cout << "��'� ��������: " << lst[i].name << endl;
					cout << "ֳ��: " << lst[i].value << endl;
					cout << "������: " << lst[i].stelag << endl;
					cout << "�������: " << lst[i].polycka << endl;
					cout << "����: " << lst[i].masa << endl;
					cout << "��`��: " << lst[i].litr << endl;
				}
			}
			break;
		}
	}
	system("pause");
	return;
}
void FindLocation() // ����� �������� �� ������������� �� ������ � ������
{
	int stel = 0, pol = 0;
	cout << "������ ������ �� ����������� ������� (³� 1 �� 5)" << endl; cin >> stel;
	cout << "������ ������� �� ����������� ������� (³� 1 �� 5)" << endl; cin >> pol;
	if (stel < 0 || stel > 6 || pol < 0 || pol > 6)
	{
		cout << "!!!�������!!!" << endl;
		cout << "����� ������� ��� ������ ������� ����������� " << endl;
		system("pause");
	}
	else
	{
		for (int i = 0; i < lst.GetSize(); i++)
		{
			if (lst[i].stelag == stel)
			{// ���������� �������� ���� �� �������� ������� �� ��� ����� ������� ������� �� � ��������
				if (lst[i].polycka == pol)
				{// ���������� �������� ���� �� �������� ������� �� ��� ����� ������� ������� �� � ������� 
					// ���� ��������� ������
					cout << "----------------------" << endl;
					cout << "����� ��������: " << i << endl;
					cout << "��'� ��������: " << lst[i].name << endl;
					cout << "ֳ��: " << lst[i].value << endl;
					cout << "������: " << lst[i].stelag << endl;
					cout << "�������: " << lst[i].polycka << endl;
					cout << "����: " << lst[i].masa << endl;
					cout << "��`��: " << lst[i].litr << endl;
				}
			}
		}
	}
	system("pause");
	return;
}
void FindMass() // ����� �������� �� ����� 
{
	int chosefind = 0, mass = 0;
	cout << "������ ���� ������� ��� ����� ������" << endl; cin >> mass;
	cout << ("1)������ �������� ����� ������� ���� \n") << endl;
	cout << ("2)������ �������� ����� ������� ���� \n") << endl;
	cout << ("3)������ �������� �� �������� ����� \n") << endl;
	cin >> chosefind;
	if (mass < 0)
	{
		cout << "!!!�������!!!" << endl;
		cout << "���� ������� ����������� " << endl;
		system("pause");
	}
	else
	{
		switch (chosefind)
		{
		case 1:
			system("cls");
			for (int i = 0; i < lst.GetSize(); i++)
			{// ���������� �������� ���� �� �������� ������� �� ������ ����� �� ������� � ������� ��
				if (lst[i].masa > mass)
				{
					cout << "----------------------" << endl;
					cout << "����� ��������: " << i << endl;
					cout << "��'� ��������: " << lst[i].name << endl;
					cout << "ֳ��: " << lst[i].value << endl;
					cout << "������: " << lst[i].stelag << endl;
					cout << "�������: " << lst[i].polycka << endl;
					cout << "����: " << lst[i].masa << endl;
					cout << "��`��: " << lst[i].litr << endl;
				}
			}
			break;
		case 2:
			system("cls");
			for (int i = 0; i < lst.GetSize(); i++)
			{// ���������� �������� ���� �� �������� ������� �� ������ ����� �� ������� � ������� ��
				if (lst[i].masa < mass)
				{
					cout << "----------------------" << endl;
					cout << "����� ��������: " << i << endl;
					cout << "��'� ��������: " << lst[i].name << endl;
					cout << "ֳ��: " << lst[i].value << endl;
					cout << "������: " << lst[i].stelag << endl;
					cout << "�������: " << lst[i].polycka << endl;
					cout << "����: " << lst[i].masa << endl;
					cout << "��`��: " << lst[i].litr << endl;
				}
			}
			break;
		case 3:
			system("cls");
			for (int i = 0; i < lst.GetSize(); i++)
			{// ���������� �������� ���� �� �������� ������� �� ��� ����� ����� �� � ������� � ���� ������� ��
				if (lst[i].masa == mass)
				{
					cout << "----------------------" << endl;
					cout << "����� ��������: " << i << endl;
					cout << "��'� ��������: " << lst[i].name << endl;
					cout << "ֳ��: " << lst[i].value << endl;
					cout << "������: " << lst[i].stelag << endl;
					cout << "�������: " << lst[i].polycka << endl;
					cout << "����: " << lst[i].masa << endl;
					cout << "��`��: " << lst[i].litr << endl;
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
	cout << "������ ��'�� ������� ����� ����� ������: " << endl; cin >> volume;
	for (int i = 0; i < lst.GetSize(); i++)
	{
		if (lst[i].litr == volume)
		{ // ���������� �������� ���� �� �������� ������� �� ��� ���� ��'���� �� � �������� � ������� ��
			cout << "----------------------" << endl;
			cout << "����� ��������: " << i << endl;
			cout << "��'� ��������: " << lst[i].name << endl;
			cout << "ֳ��: " << lst[i].value << endl;
			cout << "������: " << lst[i].stelag << endl;
			cout << "�������: " << lst[i].polycka << endl;
			cout << "����: " << lst[i].masa << endl;
			cout << "��`��: " << lst[i].litr << endl;
		}
	}
	system("pause");
	return;
}

void DeleteElement()
{
	int index; // ��������� �����
	PrintData();
	cout << "������ ������ �������� ���� ����� ��������: " << endl; cin >> index;
	if (index < 0 || index > lst.GetSize() - 1)
	{
		cout << "�������� � ����� �������� �� ����" << endl;
		system("pause");
	}
	else
	{
		lst.removeAt(index); // ��������� �������� �� �������� �������� 
		// � ���� ���������� ��� � ��� ����� �� ����� ����
		Writefile();
		return;
	}
}