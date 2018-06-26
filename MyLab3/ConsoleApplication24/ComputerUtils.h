#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

template <class Type>
class ComputerUtils {
private:

public:
	vector<Type> vect;
	ComputerUtils() {}
	~ComputerUtils() {}

	// удаление элемента
	void Remove(int numb);


	// добавление элемента
	void Add(Type &elem);


	//размер вектора
	int size();


	// проверка на пустоту
	bool Is_empty();


	// вывод в файл
	void OutputFile(void(*f)(Type, ofstream&), string newfname);
	

	// вывод на экран
	void OutputScreen(vector<Type> items, void(*f)(Type), void(*Header)());
	

	// вывод из файла
	bool ReadFromFile(Type(*f)(ifstream&), string newfname);


		// ввод с экрана
		void ReadFromScreen(Type(*f)());
	

	// линейный поиск
		vector<Type> LinearySearch(Type search_elem, bool(*Equal)(Type, Type));


	// линейный поиск возвращает номер эл-та одинакового с search_elem если одинаковый не найден возвращает -1
		int LinearySearchElem(Type search_elem);
	// бинарный поиск
	// int(*Compare)(Type, Type, int) - указатель на функцию, которая сравнивает искомый эл-т с текущим по type_search 
	// bool(*Equal)(Type, Type, int) - указатель на функцию, которая проверяет равенство искомого эл-та с текущим по type_search
		vector<Type> BinarySearch(Type find_element, bool(*Compare)(Type, Type), bool(*Equal)(Type, Type));

};





