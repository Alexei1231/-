#pragma once//Опишу в этом классе еду
#include<string>
#include<list>
#include<iostream>
using namespace std;
class MenuFood;

class Food//в этом классе описана еда. То есть можно узнать ее состав и т д
{
	string name;//имя еды
	int price;//цена
	string composition;//состав
	int art;//артикул (или код товара)

public:

	Food(string n, int pr, string comp, int ar)// тут не нужен какой либо делегирующий конструктор или что-то в этом роде
	{
		n = name, pr = price, comp = composition, ar = art;
	}

	void FOODinfo()
	{
		cout << name << "\n";
		cout << price << "\n";
		cout << composition << endl;
		cout << art << endl;
	}

	friend class MenuFood;
};

class MenuFood     
{
	list<Food>artList;
};

