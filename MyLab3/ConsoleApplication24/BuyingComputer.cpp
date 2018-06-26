#include "stdafx.h"

#include "BuyingComputer.h"
#include "MyDate.h"
#include "InputHelp.h"
#include "User.h"


// конструктор
BuyingComputer::BuyingComputer()
{
	code = 0;
	name = "";
	date = "";
}

// функция ввода структуры "купленный компьютер" с консоли. На вход сразу поступают имя и код товара. 
BuyingComputer::BuyingComputer(string _name, int _code)
{
	//BuyingComputer c;
	MyDate mydate;
	code = _code;
	name = _name;
	mydate.InputDate();
	date = mydate.ToString();
	//return c;
}

// функция вывода структуры "купленный компьютер" на консоль
void BuyingComputer::OutputScreenBuyingComputer(BuyingComputer c)
{
	cout << setw(10) << setiosflags(ios::left) << c.code << "|";																	
	cout << setw(15) << setiosflags(ios::left) << c.name << "|";
		cout << setw(15) << setiosflags(ios::left) << c.date << "|" << endl;;
}

// вывод заголовка
void BuyingComputer::OutputScreenHeaderBuyingComputer()
{
	cout << setw(4) << setiosflags(ios::left) << "№" << "|";
	cout << setw(10) << setiosflags(ios::left) << "Код марки" << "|";
	cout << setw(15) << setiosflags(ios::left) << "Покупатель" << "|";
	cout << setw(15) << setiosflags(ios::left) << "Дата" << "|" << endl;
	cout << "------------------------------------------------------------" << endl;
}

// запись в бинарный файл
void BuyingComputer::WriteBuyingComputerToFile(BuyingComputer a, ofstream& os)
{
	//(char*)&i-делаем стркоу байтов, чтобы отдать, открытому потоку в бинарном режиме
	//sizeof(int)-ограничиваем число уходящих в поток байтов 
	os.write((char*)&a.code, sizeof(int));  //записываем код компьютера
	StringInBinFile(os, a.name);  //записываем марку
	StringInBinFile(os, a.date);  //записываем дату
	
}

// считывание из бинарного файла
BuyingComputer BuyingComputer::ReadBuyingComputerFromFile(ifstream& in)
{
	BuyingComputer a;

	in.read((char*)&a.code, sizeof(int)); //считываем код
	a.name = StringFromBinFile(in);  //считываем марку
	a.date = StringFromBinFile(in);  //считываем дату

	return a;
}







