
#pragma once
#include <math.h>
#include <string>
#include <iostream>
#include <string>

#include "ComputerUtils.cpp"



using namespace std;

//класс пользователь. Будет родительским для worker и client
//class ComputerUtils;
class BuyingComputer;
class Computer;

class User {
protected:
	// имя файла моделей компьютера
	string filename_model_PC;
	// имя файла истории покупок
	string filename_history_buy;

	// вектор с моделями компьютеров
	ComputerUtils<Computer> vectModelComputer;

	// вектор с историеей покупок
	ComputerUtils<BuyingComputer> vectBuyingComputer;

public:

	// конструктор
	User(string filename_model_PC, string filename_history_buy);

	//вывод списка моделей ПК с фильтрацией выбранному полю
	vector<Computer> LookModelPCToCriteria();

	//  функция меню
	virtual void Menu() = 0;

	// посмотреть модели PC
	void ReadModelPC();

	// выход
	void Close();
};
