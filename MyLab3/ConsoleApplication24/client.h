#pragma once
#include <math.h>
#include <string>
#include <iostream>
#include<vector>
#include "User.h"
using namespace std;

// класс клиента
class Client : public User
{
private:
	// тип ссылка на метод 
	//определяем имя нового типа с помощью typedef
	typedef void (Client::*DynamicFunction)();

	// вектор ссылок на методы класса
	vector<DynamicFunction> menuFunctions;

	// вектор имен
	vector<string> menuNames;

protected:
	string name_client;
public:

	// конструктор
	Client(string _name_client, string _filename_model_PC, string _filename_history_buy);


	// поиск с покупкой
	void BuyingModelPC();

	// меню
	void Menu();

};














