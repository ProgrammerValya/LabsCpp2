#pragma once
#include <string>
#include <math.h>
#include <iostream>
#include <iomanip>
using namespace std;

//класс компьютеров, которые уже купиили. Из них формируется история покупок
class BuyingComputer
{
private:
	// код купленной марки
	int code;
	// имя покупателя
	string name;
	// дата покупки
	string date;

public:

	// конструктор
	BuyingComputer();

	// метод ввода структуры "купленный компьютер" с консоли
	BuyingComputer(string _name, int _code);

	// метод вывода структуры "купленный компьютер" на консоль
	static void OutputScreenBuyingComputer(BuyingComputer c);

	// метод заголовка
	static void OutputScreenHeaderBuyingComputer();

	// запись в бинарный файл
	static void WriteBuyingComputerToFile(BuyingComputer a, ofstream& os);

	// считывание из бинарного файла
	static BuyingComputer ReadBuyingComputerFromFile(ifstream& in);

};

