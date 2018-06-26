// ConsoleApplication24.cpp: определяет точку входа для консольного приложения.
/*Варианты контейнера :
C) список(std::list)
Вариант преобразования :
9. Умножить каждое четное число на первое отрицательное число.*/


#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <list>  
#include <iterator>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <numeric>
#include <cstring>
#include <clocale> 
#include <string.h>
#include <stdio.h> 
#include <string>

using namespace std;

//Вспомогательная функция для заполнения текстового файла N целыми случайными числами в цикле.
int Random(int M)
{
	return rand() % (2 * M + 1) - M;
}

// Функция заполнения текстового файла N целыми случайными числами в диапазоне от - M до M, в цикле.
ofstream FillFileRandom(string FileName,int N, int M)  
{
	ofstream input(FileName);
	list<int> l1;
	srand(time(0)); 
	for (int i = 0; i < N; i++)
		l1.push_back(Random(M));
	copy(l1.begin(), l1.end(), ostream_iterator<int>(input, " "));  //Вывод в файл
	input.close();
	return input;
}

class RandomRange
{
private:
	int M;  //диапазон
public:
	RandomRange(const int& x) : M(x)
	{}
	int operator ( ) () const  
	{
		return rand() % (2 * M + 1) - M;
	}
};

// Функция заполнения текстового файла N целыми случайными числами в диапазоне от - M до M, с использованием generate.
ofstream FillFileGenerate(string FileName, int N, int M)  
{
	ofstream input(FileName);
	list<int> l1(N);
	srand(time(0));  
	generate(l1.begin(), l1.end(), RandomRange(M));   
	copy(l1.begin(), l1.end(), ostream_iterator<int>(input, " "));  //Вывод в файл
	input.close();
	return input;
}

//Функция, получающая файл на вход, и возвращающую последовательный контейнер, заполненный числами из файла.
list<int> LoadFromFile(string FileName)//должна ли функция получать на фход имя файла!!!??
{
	
	ifstream  input(FileName);
	list<int> OutputList;
	int buff; // буфер промежуточного хранения считываемого из файла текста
	input.seekg(0);
	while (!input.eof())	//заполняем контейнер числами из файла
	{
		input >> buff;
		OutputList.push_back(buff); 		
	}
	input.close();
	return OutputList;
}

//Функция, вычисляющая сумму, содержащихся в контейнере.
int Sum(list<int> l1)
{
	return accumulate(l1.begin(), l1.end(), 0); //по умолчанию accumulate суммирует элементы, 0-точка старта. 
}

//Функция, вычисляющая среднее арифметическое чисел, содержащихся в контейнере.
double SrArifm(list<int> l1)
{
	if (l1.empty())
	{
		throw "Список пуст!";
	}
	

	return (Sum(l1) / l1.size()); //вывод
}

// поиск первого отрицательного числа
int SearchFirstNeg(list<int>::iterator begin, list<int>::iterator end)
{
	int FirstNeg = *begin;
	bool find = false;
	std::list<int>::iterator it = begin;
	
		while ((it != end) && !find)
		{
			if ((*it) < 0)
			{
				find = true;
				FirstNeg = *it;
			}
			it++;
	
		if (find) return FirstNeg;
		else throw "Нет отрицательных чисел";
	}
	
}

//Перегруженная функция modify, принимающая на вход итераторы начала и конца обрабатываемой части контейнера.
list<int> modify(list<int>::iterator begin, list<int>::iterator end)
{
	list<int> OutputList;
	int FirstNeg = SearchFirstNeg(begin, end);  
	for (auto it = begin; it != end; it++)
	{
		if ((*it) % 2 == 0)
		{
			(*it) = (*it)*FirstNeg;
		}
		OutputList.push_back(*it);
	}
	return OutputList;
}

// Перегруженнуя функция modify, выполняющая преобразование полученного контейнера.
list<int> modify(list<int> l1)
{
	return modify(l1.begin(), l1.end());
}

class xform		
{
private:
	int n;  //число, на которое нужно умножить элемент т.е. первое отрицательное число
public:
	xform(const int& x) : n(x) 
	{
	}

	int operator ( ) (int& elem) const  //оператор умножает элемент на n т.е. на поступающее в конструктор число
	{
		if (elem % 2==0)
			elem = n*elem;
		return elem;
	}
};

//Функция, реализующуя требуемое преобразование с использованием алгоритма std::transform вместо функции modify.
list<int> ModifyTransform(list<int> l1)
{
	int FirstNeg = SearchFirstNeg(l1.begin(), l1.end());
	std::transform(l1.begin(), l1.end(),l1.begin(),xform(FirstNeg));
	return l1;
}

//Функция, реализующуя требуемое преобразование с использованием алгоритма std::for_each вместо функции modify.
list<int> ModifyForEach(list<int> l1)
{
	int FirstNeg;
	SearchFirstNeg(l1.begin(), l1.end());
	for_each(l1.begin(), l1.end(), xform(FirstNeg));
	return l1;
}

// проверка корректности символа в имени файла 
bool CorrectSb(char c)
{
	switch (c)
	{
	case '*':
	case '?':
	case '<':
	case '>':
	case ':':
	case '|':
		return false;
	default:
		return true;
	}
}

// проверка проверка корректности имени	
bool CorrectName(string name)
{
	int i = 1;
	bool OkName = true;
	for (i=1;((i<name.length()) && OkName);i++)
		OkName = CorrectSb(name[i]);
	return OkName;
}

//ввод имени файла	
string InputFileName()
{
	char* FileName;
	FileName = new char[45];
	 while (true)
	 {
		 cout << "Введите имя файла:  ";
		 cin >> FileName;
		 if (CorrectName(FileName))
		 {
			 strcat(FileName, ".txt");  	 
			 break;
		 }
		 else
			 cout << "В имени файла ошибки\n";
	 }
	return FileName;
}

// печать списка на экран
void Print(list<int> l1)
{
	copy(l1.begin(), l1.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	
}

// печать списка в файл
void PrintToFile(string FileName,list<int> &InputList)
{
	ofstream File;
	File.open(FileName, ios::out);
	if (File)
	{
		list<int>::const_iterator it;
		copy(InputList.begin(), InputList.end(), ostream_iterator<int>(File, " "));
		cout << endl << "Файл выведен!" << endl;
		File.close();
	}
	else
	{
		cout << "Ошибка открытия файла!" << endl;
	}
}

//для меню
int InputNumber(int min, int max)
{
	int n=-1;
	while ((n < min) || (n > max))
	{
		cout << "Введите число: ";
		while ((!(cin >> n)) || cin.get() != '\n')
		{
			cout << "Некорректное число\n";
			cin.clear();
			cin.sync();
			cout << "Введите число: ";
		}
	};
	return n;
}

//для ввода N и M
int InputData(const string text)
{
	int n = -1;
	cout<<text;
	cin >> n;
	while (n < 0)
	{
		cout << "Некорректное число\n";
		cout << "Введите число: ";
		cin >> n;
	};	
	return n;
} 

int Menu()
{
	cout << " --------------------Меню---------------------  " << endl;
	cout << "1 - Посчитать сумму" << endl;
	cout << "2 - Посчитать среднее арифметическое" << endl;
	cout << "3 - Modify(преобразование списка )" << endl;
	cout << "4 - Modify(преобразование списка - перегруженный вариант) " << endl;
	cout << "5 - Преобразование с помощью transform" << endl;
	cout << "6 - Преобразование с помощью for_each" << endl;
	cout << "7 - Вывод на экран " << endl;
	cout << "8 - Вывод в файл" << endl;
	cout << "0 - Выход " << endl;
	int n = InputNumber(0, 8);
	cout << "\n";
	return n;
}


int main()
{	
	setlocale(LC_ALL, "Russian");
	int item; 
	bool enterfile = true;
	ofstream OutputFile;
	string FileName="";
	int N = 5;//кол-во чисел в очереди
	int M; //диапазон
	list<int> MyList;	
	cout << "1 - Заполнение файла через generate" << endl;
	cout << "2 - Заполнение файла через цикл" << endl;
	cout << "0 - Выход" << endl;
	item = InputNumber(0, 2);
	switch (item)
	{
	case 1:
	{
		FileName = InputFileName();
		N = InputData("Введите N,количество эл-тов: ");
		M = InputData("Введите M, диапазон значений: ");
		OutputFile = FillFileGenerate(FileName, N, M);
		break;		
	}
	case 2:
	{
		FileName = InputFileName();
		N = InputData("Введите N,количество эл-тов: ");
		M = InputData("Введите M, диапазон значений: ");
		OutputFile = FillFileRandom(FileName, N, M);
		break;	
	}
	default:
		enterfile = false;
		exit(0);
		break;
	}

	if (enterfile)
	{		
		MyList = LoadFromFile(FileName);
		for (;;)
		{
			int n = Menu();
			switch (n)
			{
			case 1:
				cout << "Сумма: " << Sum(MyList) << endl;
				break;
			case 2:
				cout << "Среднее арифметическое: " << SrArifm(MyList) << endl;
				break;
			case 3:
				try
				{
					MyList = modify(MyList);
				}
				catch (const string text)
				{
					cout << text << endl;
				}
				break;				
			case 4:
				try
				{
					MyList = modify(MyList.begin(), MyList.end());
				}
				catch (const string text)
				{
					cout << text << endl;
				}
				break;
			case 5:
				try
				{
					MyList = ModifyTransform(MyList);
				}
				catch (const string text)
				{
					cout << text << endl;
				}
				break;
			case 6:
				try
				{
					MyList = ModifyForEach(MyList);
				}
				catch (const string text)
				{
					cout << text << endl;
				}
				break;
			case 7:
				cout << "Список: " << endl;
				Print(MyList);
				break;
			case 8:
				PrintToFile(FileName,MyList);
				break;
			default:
				cout << "Выход " << endl; exit(0);
				break;
			}
		}
	}
	else
		cout << "Выход\n";
	system("pause");

}

