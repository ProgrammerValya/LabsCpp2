#include "stdafx.h"
#include "InputHelp.h"

string InputInfo(string info)
{
	string a;
	cout << info;
	cin >> a;
	return a;
}

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

bool CorrectName(string name)
{
	int i = 0;
	bool goodsm = true;
	for (int i = 0; (i < name.length() && goodsm); i++)
		goodsm = CorrectSymbol(name[i]);
	return goodsm;
}

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

string StringFromBinFile(ifstream & in)
{
	string result;
	__int64 len_name; ww
	in.read((char*)&len_name, sizeof(len_name)); // чтение длины записанной строки
	char * buf = new char[len_name];         // Выделение буфера для чтения
	in.read(buf, len_name);// Чтение (с нулевым байтом)
	result = buf;                       // Присвоение считанной строки 
	delete[]buf;               // Освобождение памяти

	return result;
}

void StringInBinFile(ofstream & os, string str)
{

	__int64 len_name = str.length() + 1;  // длина с нулевым байтом
	os.write((char*)&len_name, sizeof(__int64)); // запись длины
	os.write(str.c_str(), len_name);  // запись информации
}

int InputNumInt(int min, int max, string message)
{
	int n;
	bool flag = true;
	do
	{
		if (!flag)
			cout << "Число вне диапозона!!\n";
		else
			flag = !flag;
		cout << message;
		while ((!(cin >> n)) || cin.get() != '\n')
		{
			cout << "Неправильный ввод !!  Повторите ввод!\n";
			cin.clear();  // восстанавливает поток если он в ошибочном сосотянии
			cin.sync();   // очищает поток от имеющихся символов
			cout << message;
			getchar();
			getchar();
		}
		/*cout << "Неправильный ввод !!  Повторите ввод!\n";*/
	} while ((n < min) || (n > max));
	return n;
}
