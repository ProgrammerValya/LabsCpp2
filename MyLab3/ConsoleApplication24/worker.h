#pragma once

#include <math.h>
#include <string>
#include <iostream>
#include <string>
#include<vector>
#include "user.h"


using namespace std;
// класс сотрудника

class Worker : public User
{
	
private:
	// тип ссылка на метод класса "Worker"
	//определяем имя нового типа с помощью typedef
	typedef void (Worker::*DynamicFunction)();

	// вектор ссылок на методы класса
	vector<DynamicFunction> menuFunctions;

	// вектор имен
	vector<string> menuNames;

public:

	Worker(string filename_model_PC, string filename_history_buy);

	// добавить модель PC
	void AddModelPC();

	// изменить модель PC
	void ChangeModelPC();

	// удалить модель PC
	void DeleteModelPC();

	// посмотреть историю покупок
	void ReadHistoryBuying();

	// меню
	void Menu();

};