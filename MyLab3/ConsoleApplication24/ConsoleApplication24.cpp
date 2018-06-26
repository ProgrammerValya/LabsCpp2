// 3)Реализовать виртуальный магазин ПК. Магазин должен иметь два режима работы — клиент и сотрудник (выбирается в меню). 
//Сотрудник имеет возможность управления магазином: добавление, редактирование, удаление моделей ПК.
//Предусмотреть вывод списка моделей ПК с сортировкой и/или фильтрацией по выбранному полю.
//Пользователь имеет возможность поиска ПК по заданному критерию (любое поле, для полей типа цены и объема памяти — предусмотреть ввод диапазона)
//и покупки выбранного ПК. Предусмотреть хранение истории покупок и просмотр истории сотрудником.

#include <stdio.h>
#include "stdafx.h"
#include <math.h>
#include <string.h>
#include <iostream>
#include "user.h"
#include "worker.h"
#include "client.h"
#include "InputHelp.h"
using namespace std;

void Shop()
{

	User *user;

	string name_client;

	string filename_model_PC = "files\\PC.dat";
	string filename_history_buy = "files\\buy.dat";

	while (1)
	{
		cout << " --------------------Меню---------------------  " << endl;
		cout << "1 - Зайти как клиент" << endl;
		cout << "2 - Зайти как сотрудник " << endl;
		cout << "0 - Выход" << endl;
		int changemenu = InputNumInt(0, 2, "---> ");
		switch (changemenu)
		{
		case 1:
			name_client = InputInfo("Режим клиента\n Введите имя : ");
			user = new Client(name_client, filename_model_PC, filename_history_buy);
			user->Menu();
			break;

		case 2:
			cout << "Режим сотрудника" << endl;
			user = new Worker(filename_model_PC, filename_history_buy);
			user->Menu();
			break;

		default:
			exit(1);
			break;
		}
	}
}

void main()
{
	setlocale(LC_ALL, "Russian");
	system("chcp 1251");
	Shop();
}