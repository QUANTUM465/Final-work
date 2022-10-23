#pragma once
#include "Class list.h"
#include <string>
#include <iostream>
using namespace std;
class spusok
{
public:
    spusok(char name[50], float value, int stelag, int polychka, float masa, float litr);
    spusok() {};
    //private:
    char name[50]; // ��'� ��'���� 
    float value; // ֳ�� ��'���� � ��� 
    int stelag; // ����� ������� � ����� ����������� ��'��� �� 1 �� 5
    int polycka; // ������ ������� �� 1 �� 5
    float masa; // ������� ���������� ��'���� � ���
    float litr; // ������� ���������� ��'���� � ��'��
};

inline spusok::spusok(char name[50], float value = 0, int stelag = 0, int polycka = 0, float masa = 0, float litr = 0)
{ 
    this->name[50] = name[50];
    this->value = value;  
    this->stelag = stelag;
    this->polycka = polycka;
    this->masa = masa;
    this->litr = litr;
}

