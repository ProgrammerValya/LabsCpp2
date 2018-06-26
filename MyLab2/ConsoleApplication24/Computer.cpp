#include "stdafx.h"
#include "Computer.h"
#include "InputHelp.h"


Computer::Computer()
{
	//код марки компьютера
	code = 0;
	//название марки компьютера
	string name = "";
	//тип процессора, 
	string CPUtype = "";
	//частота работы процессора
	int frequency = 0;
	//объем оперативной памяти 
	int RAM = 0;
	//объем жесткого диска 
	int hardDrive = 0;
	//объем памяти видеокарты
	int videoCard = 0;
	//стоимость компьютера 
	int cost = 0;
	//количество экземпляров
	int count = 0;
}

Computer & Computer::operator=(Computer c)
{
	//код марки компьютера
	code = c.code;
	//название марки компьютера
	name = c.name;
	//тип процессора, 
	CPUtype = c.CPUtype;
	//частота работы процессора
	frequency = c.frequency;
	//объем оперативной памяти 
	RAM = c.RAM;
	//объем жесткого диска 
	hardDrive = c.hardDrive;
	//объем памяти видеокарты
	videoCard = c.videoCard;
	//стоимость компьютера 
	cost = c.cost;
	//количество экземпляров
	count = c.count;

	return (*this);
}

Computer Computer::InputScreenCompany()
{
	Computer c;
	c.code = InputNum(0, 1000000, "Введите код марки компьютера: ");
	c.name = InputInfo("Введите название марки компьютера: ");
	c.CPUtype = InputInfo("Введите тип процессора: ");
	c.frequency = InputNum(0, 3000, "Введите частоту работы процессора: ");
	c.RAM = InputNum(0, 4000, "Введите объем оперативной памяти : ");
	c.hardDrive = InputNum(0, 4000, "Введите объем жесткого диска : ");
	c.videoCard = InputNum(0, 4000, "Введите объем памяти видеокарты: ");
	c.cost = InputNum(0, 200000, "Введите стоимость компьютера : ");
	c.count = InputNum(0, 100, "Введите количество экземпляров: ");
	return c;
}

void Computer::OutputScreenComputer(Computer c)
{

	cout << "Код марки компьютера: " << c.code << endl;
	cout << "Название марки компьютера: " << c.name << endl;
	cout << "Тип процессора: " << c.CPUtype << endl;
	cout << "Частота работы процессора: " << c.frequency << endl;
	cout << "Объем оперативной памяти : " << c.RAM << endl;
	cout << "Объем жесткого диска : " << c.hardDrive << endl;
	cout << "Объем памяти видеокарты: " << c.videoCard << endl;
	cout << "Стоимость компьютера : " << c.cost << endl;
	cout << "Количество экземпляров: " << c.count << endl;

}

string Computer::ToString(Computer c, int i)
{
	string result = "Запись № " + to_string(i) + "\n" + "Код марки компьютера: " + to_string(c.code) + "\n" + "Название марки компьютера: " + c.name
		+ "\n" + "Тип процессора: " + c.CPUtype + "\n" + "Частота работы процессора: " + to_string(c.frequency) + "\n" + "Объем оперативной памяти : " +
		to_string(c.RAM) + "\n" + "Объем жесткого диска : " + to_string(c.hardDrive) + "\n" + "Объем памяти видеокарты: " + to_string(c.videoCard)
		+ "\n" + "Стоимость компьютера : " + to_string(c.cost) + "\n" + "Количество экземпляров: " + to_string(c.count) + "\n";
	return result;
}

string Computer::ReadString(ifstream input, string wrd, Computer c)
{
	string s;
	if (!input.eof())
	{///////////////////
		getline(input, s, '\n');
		
	}
	return(s.substr(wrd.length(), s.length()).c_str());

}

Computer Computer::ReadFromString(ifstream &input)  //??
{
	Computer c;
	string s;
	try
	{
		getline(input, s, '\n');
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "Код марки компьютера: ";
			c.code = atoi(s.substr(wrd.length(), s.length()).c_str());
		}

		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "Название марки компьютера: ";
			c.name = s.substr(wrd.length(), s.length());
		}
	
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "Тип процессора: ";
			c.CPUtype = s.substr(wrd.length(), s.length());
		}

		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "Частота работы процессора: ";
			c.frequency = atoi(s.substr(wrd.length(), s.length()).c_str());
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "Объем оперативной памяти: ";
			c.RAM = atoi(s.substr(wrd.length(), s.length()).c_str());
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "Объем жесткого диска:  ";
			c.hardDrive = atoi(s.substr(wrd.length(), s.length()).c_str());
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "Объем памяти видеокарты: ";
			c.videoCard = atoi(s.substr(wrd.length(), s.length()).c_str());
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "Стоимость компьютера:  ";
			c.cost = atoi(s.substr(wrd.length(), s.length()).c_str());
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "Количество экземпляров: ";
			c.count = atoi(s.substr(wrd.length(), s.length()).c_str());
		}
	}
	catch (...)
	{
		cout << "Ошибка чтения из файла!" << endl;
	}
	return c;
}

Computer Computer::InputConditionType(int ConditionType, bool(**compare)(Computer, Computer), bool(**sort)(Computer, Computer))  //??
{
	Computer result;
	switch (ConditionType)
	{
	case 1:
		result.CPUtype = InputInfo("Введите искомый тип процессора: ");
		*compare = SearchCPU;
		*sort = SortCPU;
		return result;
	case 2:
		result.RAM = InputNum(0, 4000, "Введите искомый объем ОЗУ: ");
		*compare = SearchRAM;
		*sort = SortRAM;
		return result;
	case 3:
		result.videoCard = InputNum(0, 4000, "Введите искомый объем видеокарты: ");
		*compare = SearchVideoCard;
		*sort = SortVideoCard;
		return result;
	case 4:
		result.hardDrive = InputNum(0, 4000, "Введите новый искомый жесткого диска: ");
		*compare = SearchhardDrive;
		*sort = SorthardDrive;
		return result;
	default:
		return result;
	}
}

bool Computer::SearchCPU(Computer n, Computer m)
{
	return n.CPUtype == m.CPUtype;
}

bool Computer::SearchRAM(Computer n, Computer m)
{
	return n.RAM == m.RAM;
}

bool Computer::SearchVideoCard(Computer n, Computer m)
{
	return n.videoCard == m.videoCard;
}

bool Computer::SearchhardDrive(Computer n, Computer m)
{
	return n.hardDrive == m.hardDrive;
}

bool Computer::SortCPU(Computer n, Computer m)
{
	return n.CPUtype > m.CPUtype;
}

bool Computer::SortRAM(Computer n, Computer m)
{
	return n.RAM > m.RAM;
}

bool Computer::SortVideoCard(Computer n, Computer m)
{
	return n.videoCard > m.videoCard;
}

bool Computer::SorthardDrive(Computer n, Computer m)
{
	return n.hardDrive > m.hardDrive;
}
