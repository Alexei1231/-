#pragma once//����� � ���� ������ ���
#include<string>
#include<list>
#include<iostream>
using namespace std;
class MenuFood;

class Food//� ���� ������ ������� ���. �� ���� ����� ������ �� ������ � � �
{
	string name;//��� ���
	int price;//����
	string composition;//������
	int art;//������� (��� ��� ������)

public:

	Food(string n, int pr, string comp, int ar)// ��� �� ����� ����� ���� ������������ ����������� ��� ���-�� � ���� ����
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

