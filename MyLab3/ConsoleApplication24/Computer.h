#pragma once
#include <sstream>
#include <math.h>
#include <string>
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
class Computer
{
private:
	//код марки компьютера
	int code;
	//название марки компьютера
	string name;
	//тип процессора, 
	string CPUtype;
	//частота работы процессора
	int frequency;
	//объем оперативной памяти 
	int RAM;
	//объем жесткого диска 
	int hardDrive;
	//объем памяти видеокарты
	int videoCard;
	//стоимость компьютера 
	int cost;
	//количество экземпляров
	int count;

public: /// приватные поля
		// конструктор по умолчанию
	Computer();

	// свойство для кода
	int get_Code();

	// свойство для кол-ва
	int get_Count();

	// свойство для кол-ва
	void set_Count(int value);

	// функция ввода структуры "компьютер" с консоли
	static Computer InputScreenComputer();

	// функция вывода структуры "компьютер" на консоль
	static void OutputScreenComputer(Computer c);

	// вывод заголовка
	static void OutputScreenHeaderComputer();

	// ввод критерия поиска в зависимости от выбранного типа 
	static Computer InputConditionType(int ConditionType);

	// запись в бинарный файл
	static void WriteComputerToFile(Computer a, ofstream& os);

	// считывание из бинарного файла
	static Computer ReadComputerFromFile(ifstream& in);

	// изменение компьютера
	static Computer ChangeComputer(Computer &comp);

	// поиск равного элемента по выбранному критерию
	//по типу процессора
	//по коду
	static bool SearchCode(Computer n, Computer m);

	static bool SearchCPU(Computer n, Computer m);

	//по  объему ОЗУ
	static bool SearchRAM(Computer n, Computer m);

	//по объему видеокарты
	static bool SearchVideoCard(Computer n, Computer m);

	//по объему жесткого диска
	static bool SearchhardDrive(Computer n, Computer m);

	// по имени марки
	static bool SearchNameComputer(Computer n, Computer m);

	//частоте работы процессора
	static bool SearchFrequency(Computer n, Computer m);

	//стоимость компьютера 
	static bool SearchCost(Computer n, Computer m);

	//количество экземпляров
	static bool SearchCount(Computer n, Computer m);

	//-------сравнение структур
	// по имени 
	static bool SortCode(Computer n, Computer m);

	// по имени марки
	static bool SortNameComputer(Computer n, Computer m);

	// по частоте
	static bool SortFrequency(Computer n, Computer m);

	// по цене
	static bool SortCost(Computer n, Computer m);

	// по кол-ву
	static bool SortCount(Computer n, Computer m);

	//по типу процессора
	static bool SortCPU(Computer n, Computer m);

	//по  объему ОЗУ
	static bool SortRAM(Computer n, Computer m);

	//по объему видеокарты
	static bool SortVideoCard(Computer n, Computer m);

	// по объему жесткого диска
	static bool SorthardDrive(Computer n, Computer m);

	// перегруженнный оператор равенства
	friend bool operator ==(const Computer &a, const Computer &b);//перегрузка ==

};

