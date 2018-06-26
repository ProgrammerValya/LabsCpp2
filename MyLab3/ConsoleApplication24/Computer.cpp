#include "stdafx.h"
#include "Computer.h"
#include "InputHelp.h"
// конструктор по умолчанию
Computer::Computer()
{
	//код марки компьютера
	code = 0;
	//название марки компьютера
	name = "";
	//тип процессора, 
	CPUtype = "";
	//частота работы процессора
	frequency = 0;
	//объем оперативной памяти 
	RAM = 0;
	//объем жесткого диска 
	hardDrive = 0;
	//объем памяти видеокарты
	videoCard = 0;
	//стоимость компьютера 
	cost = 0;
	//количество экземпляров
	count = 0;
}

// свойство для кода
int Computer::get_Code()
{
	return code;
}

// свойство для кол-ва
int Computer::get_Count()
{
	return count;
}

// свойство для кол-ва
void Computer::set_Count(int value)
{
	count = value;
}


// функция ввода структуры "компьютер" с консоли
Computer Computer::InputScreenComputer()
{
	Computer c;
	c.code = InputNumInt(0, 1000000, "Введите код марки компьютера (0 - 1000000): ");
	c.name = InputInfo("Введите название марки компьютера: ");
	c.CPUtype = InputInfo("Введите тип процессора: ");
	c.frequency = InputNumInt(0, 3000, "Введите частоту работы процессора (0 - 3000): ");
	c.RAM = InputNumInt(0, 4000, "Введите объем оперативной памяти (0 - 4000): ");
	c.hardDrive = InputNumInt(0, 4000, "Введите объем жесткого диска (0 - 4000): ");
	c.videoCard = InputNumInt(0, 4000, "Введите объем памяти видеокарты (0 - 4000): ");
	c.cost = InputNumInt(0, 500000, "Введите стоимость компьютера (0 - 500000): ");
	c.count = InputNumInt(0, 100, "Введите количество экземпляров (0 - 100): ");
	return c;
}

// функция вывода структуры "компьютер" на консоль
void Computer::OutputScreenComputer(Computer c)
{
	cout << setw(9) << setiosflags(ios::left) << c.code << "|";
	cout << setw(7) << setiosflags(ios::left) << c.name << "|";
	cout << setw(15) << setiosflags(ios::left) << c.CPUtype << "|";
	cout << setw(5) << setiosflags(ios::left) << c.frequency << "|";
	cout << setw(5) << setiosflags(ios::left) << c.RAM << "|";
	cout << setw(5) << setiosflags(ios::left) << c.hardDrive << "|";
	cout << setw(5) << setiosflags(ios::left) << c.videoCard << "|";
	cout << setw(5) << setiosflags(ios::left) << c.cost << "|";
	cout << setw(3) << setiosflags(ios::left) << c.count << endl;

}

void Computer::OutputScreenHeaderComputer()
{
	//setw-ширина выходных данных для каждого элемента,   setiosflags-Вывод с выравниванием слева
	cout << setw(4) << setiosflags(ios::left) << "№" << "|";
	cout << setw(7) << setiosflags(ios::left) << "Код марки" << "|";
	cout << setw(7) << setiosflags(ios::left) << "Марка" << "|";
	cout << setw(7) << setiosflags(ios::left) << "Тип процессора " << "|";
	cout << setw(5) << setiosflags(ios::left) << "Гц" << "|";
	cout << setw(5) << setiosflags(ios::left) << "RAM" << "|";
	cout << setw(5) << setiosflags(ios::left) << "HDD" << "|";
	cout << setw(5) << setiosflags(ios::left) << "GPU" << "|";
	cout << setw(5) << setiosflags(ios::left) << "Цена" << "|";
	cout << setw(3) << setiosflags(ios::left) << "Кол-во" << endl;
	cout << "--------------------------------------------------------------------------------------------------------------" << endl;
}

// запись в бинарный файл
void Computer::WriteComputerToFile(Computer a, ofstream& os)
{
	os.write((char*)&a.code, sizeof(int));
	StringInBinFile(os, a.name);
	StringInBinFile(os, a.CPUtype);
	os.write((char*)&a.frequency, sizeof(int));
	os.write((char*)&a.RAM, sizeof(int));
	os.write((char*)&a.hardDrive, sizeof(int));
	os.write((char*)&a.videoCard, sizeof(int));
	os.write((char*)&a.cost, sizeof(int));
	os.write((char*)&a.count, sizeof(int));

}

// считывание из бинарного файла
Computer Computer::ReadComputerFromFile(ifstream& in)
{
	Computer a;

	in.read((char*)&a.code, sizeof(int));
	a.name = StringFromBinFile(in);
	a.CPUtype = StringFromBinFile(in);
	in.read((char*)&a.frequency, sizeof(int));
	in.read((char*)&a.RAM, sizeof(int));
	in.read((char*)&a.hardDrive, sizeof(int));
	in.read((char*)&a.videoCard, sizeof(int));
	in.read((char*)&a.cost, sizeof(int));
	in.read((char*)&a.count, sizeof(int));

	return a;
}

// изменение компьютера
Computer Computer::ChangeComputer(Computer &comp)
{
	if (InputNumInt(0, 1, "Вы хотите изменить код марки компьютера  " + to_string(comp.code) + " (0 - нет, 1 - да)\n-->: ") == 1)
		comp.code = InputNumInt(0, 10000, "Введите новый код марки: ");
	if (InputNumInt(0, 1, "Вы хотите изменить название марки компьютера " + comp.name + " (0 - нет, 1 - да)\nВыш выбор: ") == 1)
		comp.name = InputInfo("Введите новое название марки компьютера: ");
	if (InputNumInt(0, 1, "Вы хотите изменить тип процессора " + comp.CPUtype + " (0 - нет, 1 - да)\nВыш выбор: ") == 1)
		comp.CPUtype = InputInfo("Введите новый тип процессора: ");
	if (InputNumInt(0, 1, "Вы хотите изменить частоту работы процесcора " + to_string(comp.frequency) + " (0-нет, 1 - да)\nВыш выбор: ") == 1)
		comp.frequency = InputNumInt(0.0, 1000.0, "Введите новую частоту работы процесcора (0 - 1000000): ");
	if (InputNumInt(0, 1, "Вы хотите изменить объем оперативной памяти  " + to_string(comp.RAM) + " (0-нет, 1 - да)\nВыш выбор: ") == 1)
		comp.RAM = InputNumInt(0, 1000, "Введите новый объем оперативной памяти (0 - 1000): ");
	if (InputNumInt(0, 1, "Вы хотите изменить объем жесткого диска  " + to_string(comp.hardDrive) + " (0-нет, 1 - да)\nВыш выбор: ") == 1)
		comp.hardDrive = InputNumInt(0, 1000, "Введите новый объем жесткого диска  (0 - 1000): ");
	if (InputNumInt(0, 1, "Вы хотите изменить объем памяти видеокарты " + to_string(comp.videoCard) + " (0-нет, 1 - да)\nВыш выбор: ") == 1)
		comp.videoCard = InputNumInt(0, 1000, "Введите новый объем памяти видеокарты (0 - 1000): ");
	if (InputNumInt(0, 1, "Вы хотите изменить стоимость компьютера  " + to_string(comp.cost) + " (0-нет, 1 - да)\nВыш выбор: ") == 1)
		comp.frequency = InputNumInt(0.0, 1000000.0, "Введите новую стоимость компьютера (0 - 1000000): ");
	if (InputNumInt(0, 1, "Вы хотите изменить количество экземпляров  " + to_string(comp.count) + " (0-нет, 1 - да)\nВыш выбор: ") == 1)
		comp.frequency = InputNumInt(0, 4000, "Введите новое количество экземпляров (0 - 4000): ");

	return comp;
}



// ввод критерия поиска в зависимости от выбранного типа 
//1 - по типу процессора
//2 - по  объему ОЗУ
//3 - по объему видеокарты
//4 - по объему жесткого диска
Computer Computer::InputConditionType(int ConditionType)
{
	Computer result;
	switch (ConditionType)
	{
	case 1:
		result.code = InputNumInt(0, 10000, "Введите искомый код марки компьютера: ");
		return result;
	case 2:
		result.name = InputInfo("Введите искомое название марки: ");
		return result;
	case 3:
		result.CPUtype = InputInfo("Введите искомый тип процессора: ");
		return result;
	case 4:
		result.frequency = InputNumInt(0.0, 10000, "Введите искомую частоту: ");
		return result;
	case 5:
		result.RAM = InputNumInt(1, 1000, "Введите искомый объем ОЗУ: ");
		return result;
	case 6:
		result.hardDrive = InputNumInt(1, 1000, "Введите искомый объем жесткого диска: ");
		return result;
	case 7:
		result.videoCard = InputNumInt(0, 1000, "Введите искомый объем памяти видеокарты: ");
		return result;
	case 8:
		result.cost = InputNumInt(0, 500000, "Введите искомую цену: ");
		return result;
	case 9:
		result.count = InputNumInt(0, 4000, "Введите искомое кол-во: ");
		return result;
	default:
		return result;
	}
}

// поиск равного элемента по выбранному критерию
//по типу процессора
bool Computer::SearchCPU(Computer n, Computer m)
{
	return n.CPUtype == m.CPUtype;
}
//по  объему ОЗУ
bool Computer::SearchRAM(Computer n, Computer m)
{
	return n.RAM == m.RAM;
}
//по объему видеокарты
bool Computer::SearchVideoCard(Computer n, Computer m)
{
	return n.videoCard == m.videoCard;
}
//по объему жесткого диска
bool Computer::SearchhardDrive(Computer n, Computer m)
{
	return n.hardDrive == m.hardDrive;
}

// по коду марки
bool Computer::SearchCode(Computer n, Computer m)
{
	return n.code == m.code;
}

// по названию марки
bool Computer::SearchNameComputer(Computer n, Computer m)
{
	return n.name == m.name;
}

bool Computer::SearchFrequency(Computer n, Computer m)
{

	return n.frequency == m.frequency;
}

//стоимость компьютера 
bool Computer::SearchCost(Computer n, Computer m)
{

	return n.cost == m.cost;
}

//количество экземпляров
bool Computer::SearchCount(Computer n, Computer m)
{
	return n.count == m.count;
}

// сравнения структур в зависимости от выбранного поля для сортировки
//по типу процессора
bool Computer::SortCPU(Computer n, Computer m)
{
	return n.CPUtype > m.CPUtype;
}
//по  объему ОЗУ
bool Computer::SortRAM(Computer n, Computer m)
{
	return n.RAM > m.RAM;
}
//по объему видеокарты
bool Computer::SortVideoCard(Computer n, Computer m)
{
	return n.videoCard > m.videoCard;
}
// по объему жесткого диска
bool Computer::SorthardDrive(Computer n, Computer m)
{
	return n.hardDrive > m.hardDrive;
}

bool Computer::SortCode(Computer n, Computer m)
{
	return n.code > m.code;
}

// по имени марки
bool Computer::SortNameComputer(Computer n, Computer m)
{
	return n.name > m.name;
}

// по частоте !!
bool Computer::SortFrequency(Computer n, Computer m)
{
	return (n.frequency  > m.frequency);
}

// по цене !!
bool Computer::SortCost(Computer n, Computer m)
{
	return n.cost > m.cost;
}

// по кол-ву 
bool Computer::SortCount(Computer n, Computer m)
{

	return n.count > m.count;
}


// перегруженнный оператор равенства
bool operator ==(const Computer &a, const Computer &b)//перегрузка ==
{
	
	//return ((a.code == b.code) && (a.name == b.name) && (a.CPUtype == b.CPUtype) && (abs(a.cost - b.cost) < e) && (a.count == b.count) && (abs(a.frequency - b.frequency) < e) && (a.hardDrive == b.hardDrive) && (a.RAM == b.RAM) && (a.videoCard == b.videoCard));
	return ((a.code == b.code) && (a.name == b.name) && (a.CPUtype == b.CPUtype) && (a.cost == b.cost) && (a.count == b.count) && (a.frequency == b.frequency) && (a.hardDrive == b.hardDrive) && (a.RAM == b.RAM) && (a.videoCard == b.videoCard));
}

