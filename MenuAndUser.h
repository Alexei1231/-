#pragma once
#include <stdio.h>
#include <Windows.h>
#include<iostream>
#include<string>
//#include"Menu.h"
#include"WhatToEat.h"
#include<fstream>
using namespace std;

//class infofile
//{
//
//};

class anyUser
{
protected:
	string realName;
	string all_userInfo;
	bool ban = 0;//забанен или нет
	int poryadok;//порядковый номер


public:
	bool logIn(ifstream& infout)
	{
		string log;
		cout << "Enter the login - while you entering it, screen gonna be black" << endl;
		system("color 00");
		cin >> log;
		system("cls");
		system("color 0F");
		for (int i = 0; i < 50; i++) // шифр цезаря
		{

			if (log[i] == 'A') log[i] = 'Z';
			else log[i]--;

		}
		string pass;
		cout << "Enter the pass - while you entering it, screen gonna be black" << endl;
		cout << "Enter the pass" << endl;
		system("color 00");
		cin >> pass;
		system("cls");
		system("color 0F");
		for (int i = 0; i < 50; i++) // шифр цезаря
		{

			if (pass[i] == 'A') pass[i] = 'Z';
			else pass[i]--;

		}
		int por_number_a, por_number_b;
		char symbol;
		string allfile;
		getline(infout, allfile);
		bool wr_log, wr_pass;
		string real_log, real_pass;
		int g = 0;
		while (wr_log == 0)
		{
			allfile[g] = symbol;
			if (symbol == '$')
			{
				por_number_a++;
				por_number_a++;
			}
			if (por_number_a == poryadok and symbol != '$' and symbol != '@')
			{
				real_log = symbol;
			}


		}
		g = 0;
		while (wr_pass == 0)
		{
			allfile[g] = symbol;
			if (symbol == '@')
			{
				por_number_a++;
			}
			if (por_number_a == poryadok and symbol != '$' and symbol != '@')
			{
				real_pass = symbol;
			}
		}
		
		if (real_log == log and real_pass == pass)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
};

class Manager : public anyUser
{
	string place_work;//адрес подразделения сети быстрого питания

};




class Director :public anyUser  //director
{

public:
	friend ofstream& AddNew(ofstream& infout);
	friend class Manager;
	



};



ofstream& AddNew(ofstream& infout)
{


	cout << "Ник должен быть написан латиницей и не быть больше 49 символов во избежание сбоев! Символы $, @ - не использовать" << endl;
	string uname;
	cin >> uname;
	for (int i = 0; i < 50; i++) // шифр цезаря
	{

		if (uname[i] == 'Z') uname[i] = 'A';
		else uname[i]++;

	}
	infout << "$" << uname << "@";
	uname = '0';
	cout << "Пароль должен быть написан латиницей и не быть больше 49 символов во избежание сбоев! Символы $, @ - не использовать" << endl;
	string upass;
	cin >> upass;
	for (int i = 0; i < 50; i++) // шифр цезаря
	{

		if (upass[i] == 'Z') upass[i] = 'A';
		else upass[i]++;

	}
	infout << "@" << upass;
	upass = '0';
	return infout;



}//функция для директора



class MenuDir
{
	int manage;
public:

	MenuDir(Director& dir)
	{
		cout << "Hello, user! Press any key to continue" << endl;
		cin >> manage;
		if (manage)
		{
			StockScreen(dir);
		}
	}
	void Menustart(Director& dir)
	{
		cout << "Hello, user! Press any key to continue" << endl;
		cin >> manage;
		if (manage)
		{
			StockScreen(dir);
		}
	}

	void StockScreen(Director& dir)
	{
		cin >> manage;
		cout << "Choose what you want to do\n 1.Add user\n 2.Ban user \n 3. Info from managers\n 4. Exit" << endl;
		if (manage == 1)
		{
			ofstream& AddNew(ofstream & infout);
		}
		else if (manage == 2)
		{
			//ban
		}
		else if (manage == 3)
		{
			//info
		}
		else if (manage == 4)
		{
			Menustart(dir);
		}
	}



	friend class  Director;
};

class MenuManag
{
private:
	int manage;


public:
	void Menustart(Manager& man)
	{
		cout << "Hello, user! Press any key to continue" << endl;
		cin >> manage;
		if (manage)
		{
			StockScreen(man);
		}

	}
	void StockScreen(Manager& man)
	{
		cin >> manage;
		cout << "Choose what you want to do\n 1.Add\n 2.Ban user \n 3. Info from managers\n 4. Exit" << endl;
		if (manage == 1)
		{
			ofstream& AddNew(ofstream & infout);
		}
		else if (manage == 2)
		{
			//ban
		}
		else if (manage == 3)
		{
			//info
		}
		else if (manage == 4)
		{
			Menustart(man);
		}
	}

	class MenuAll
	{
		int ch;
	public:
		MenuAll()
		{

		}
	};

};