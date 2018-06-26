// ConsoleApplication24.cpp: определяет точку входа для консольного приложения.
//

//Модель компьютера характеризуется кодом и названием марки компьютера, типом
//процессора, частотой работы процессора, объемом оперативной памяти, объемом
//жесткого диска, объемом памяти видеокарты, стоимостью компьютера и
//количеством экземпляров.Поиск по типу процессора, объему ОЗУ, памяти
//видеокарты и объему жесткого диска.
#include <stdio.h>
#include "stdafx.h"
#include <math.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include "InputHelp.h"
#include "ComputerUtils.cpp"
#include "Computer.h"
using namespace std;

int Menu()
{
	cout << " --------------------Меню---------------------  " << endl;
	cout << "1 - Добавить элемент" << endl;
	cout << "2 - Удалить элемент" << endl;
	cout << "3 - Вывод на экран" << endl;
	cout << "4 - Сохранить в файл " << endl;
	cout << "5 - Линейный поиск" << endl;
	cout << "6 - Двоичный поиск" << endl;
	cout << "7 - Вывести подможество на экран" << endl;
	cout << "8 - Сохранить подмножество в файл" << endl;
	cout << "0 - Выход" << endl;
	int n = InputNum(0, 8, "Ваш выбор: ");
	cout << "\n";
	return n;
}

void ChangeInputData()
{
	ComputerUtils<Computer> comp;
	Computer c;
	bool change = true;
	cout << " --------------------Меню---------------------  " << endl;
	cout << "1 - Заполнение контейнера с консоли" << endl;
	cout << "2 - Заполнение контейнера из файла " << endl;
	cout << "0 - Выход" << endl;
	int changemenu = InputNum(0, 2, "Ваш выбор: ");
	switch (changemenu)
	{
	case 1:
		comp.ReadFromScreen(c.InputScreenCompany);
		break;

	case 2:
		change = comp.ReadFromFile(c.ReadFromString);
		break;

	default:
		change = false;
		break;
	}
	if (change)
	{
		bool(*compare)(Computer, Computer) = NULL;
		bool(*sort)(Computer, Computer) = NULL;
	
		vector<Computer> subset;

		int numb;
		while (1)
		{
			int n = Menu();
			switch (n)
			{
			case 1:
				comp.Add(c.InputScreenCompany());
				break;
			case 2:
				comp.OutputScreen(comp.vect, c.OutputScreenComputer); 
				comp.Remove(InputNum(0, comp.size(), "Введите номер удаляемого эл-та: "));
				break;

			case 3:
				comp.OutputScreen(comp.vect, Computer::OutputScreenComputer); 
				break;

			case 4:
				comp.OutputFile(comp.vect, c.ToString);  
				break;

			case 5://///////////////////////!!!!!!
				numb = InputNum(1, 4, "Выберите тип поиска:\n 1 - по типу процессора\n 2 - по объему ОЗУ\n 3 - по памяти видеокарты\n 4 - по объему жесткого диска \nВаш выбор: ");
				c = c.InputConditionType(numb,&compare,&sort);
				subset = comp.LinearySearch(c, compare);
				if (subset.size() != 0)
					comp.OutputScreen(subset, c.OutputScreenComputer);
				else
					cout << "Элементы не найдены" << endl;
				break;

			case 6:
				numb = InputNum(1, 4, "Выберите тип поиска:\n 1 - по типу процессора\n 2 - по объему ОЗУ\n 3 - по памяти видеокарты\n 4 - по объему жесткого диска \nВаш выбор: ");
				
				c= c.InputConditionType(numb, &compare, &sort);
				subset = comp.BinarySearch(c, sort, compare);
				if (subset.size() != 0)
					comp.OutputScreen(subset, c.OutputScreenComputer);
				else
					cout << "Элементы не найдены" << endl;
				break;

			case 7:
				comp.OutputScreen(subset, c.OutputScreenComputer);
				break;

			case 8:
				comp.OutputFile(subset, c.ToString);
				break;

			default:
				cout << "Выход " << endl; exit(0);
				break;

			}
		}
	}
	else
		cout << "Выход...\n";
	system("pause");
}

void main()
{
	setlocale(LC_ALL, "Russian");
	ChangeInputData();
}

