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
    char name[50]; // Ім'я об'єкта 
    float value; // Ціна об'єкта в базі 
    int stelag; // Номер стелажу в якому знаходиться об'єкт від 1 до 5
    int polycka; // Полиця стелажа від 1 до 5
    float masa; // Одиниця вимірювання об'єкту в масі
    float litr; // Одиниця вимірювання об'єкту в об'ємі
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

