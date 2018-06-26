#include "stdafx.h"
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <fstream>
#include <istream>
#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include "InputHelp.h"
using namespace std;

int InputNum(int min, int max, string info)
{
	int n;
	do
	{
		cout << info;
		while ((!(cin >> n)) || cin.get() != '\n')
		{
			cout << "Неправильный ввод !!  Повторите ввод!\n";
			cin.clear();
			cin.sync();
			cout << info;
			getchar();
			getchar();
		}
	} while ((n < min) || (n > max));
	return n;
}

// ввод информации
string InputInfo(string info)
{
	string a;
	cout << info;
	cin >> a;
	return a;
}

// проверка символа на корректность в имени файла
bool CorrectSymbol(char c)
{
	switch (c)
	{

	case '*':
	case '?':
	case '<':
	case '>':
	case ':':
	case '|':
	case '/':
		return false;
	default:
		return true;
	}
}


// проверка имени файла на коректность
bool CorrectName(string name)
{
	size_t i;
	bool goodsm = true;
	for (i = 0; (i < name.length() && goodsm); i++)
		goodsm = CorrectSymbol(name[i]);
	return goodsm;
}

// ввод имени файла
string InputFileName()
{

	string filename;
	do
	{
		cout << "Введите имя файла:  ";
		cin >> filename;

		if (CorrectName(filename))
		{

			break;
		}
		else
			cout << "Неверное имя файла\n";
	} while (true);

	return filename;
}










