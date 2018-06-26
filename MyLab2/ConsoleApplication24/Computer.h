#pragma once
#include <stdio.h>
#include <sstream>
#include <math.h>
#include <string>
#include <iostream>
//
#include <string>


using namespace std;
class Computer
{  //!!
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
	
	// перегруженный оператор равенства для структуры "компьютер"
	Computer& operator = (Computer c);
	
// функция ввода структуры "компьютер" с консоли
	static Computer InputScreenCompany();

// функция вывода структуры "компьютер" на консоль
	static void OutputScreenComputer(Computer c);

//перевод структуры "компьютер" в строку
	static string ToString(Computer c, int /**/i);

static string ReadString(ifstream input, string wrd, Computer c);

//считывание структуры "компьютер" из строки
static Computer ReadFromString(ifstream& input);

// ввод критерия поиска в зависимости от выбранного типа 
//1 - по типу процессора
//2 - по  объему ОЗУ
//3 - по объему видеокарты
//4 - по объему жесткого диска
static Computer InputConditionType(int ConditionType, bool(**compare)(Computer, Computer), bool(**sort)(Computer, Computer));

// поиск равного элемента по выбранному критерию
//по типу процессора
static bool SearchCPU(Computer n, Computer m);

//по  объему ОЗУ
static bool SearchRAM(Computer n, Computer m);

//по объему видеокарты
static bool SearchVideoCard(Computer n, Computer m);

//по объему жесткого диска
static bool SearchhardDrive(Computer n, Computer m);

// сравнения структур в зависимости от выбранного поля для сортировки
//по типу процессора
static bool SortCPU(Computer n, Computer m);

//по  объему ОЗУ
static bool SortRAM(Computer n, Computer m);

//по объему видеокарты
static bool SortVideoCard(Computer n, Computer m);

// по объему жесткого диска
static bool SorthardDrive(Computer n, Computer m);

};

