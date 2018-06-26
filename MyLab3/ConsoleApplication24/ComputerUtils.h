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

	// �������� ��������
	void Remove(int numb);


	// ���������� ��������
	void Add(Type &elem);


	//������ �������
	int size();


	// �������� �� �������
	bool Is_empty();


	// ����� � ����
	void OutputFile(void(*f)(Type, ofstream&), string newfname);
	

	// ����� �� �����
	void OutputScreen(vector<Type> items, void(*f)(Type), void(*Header)());
	

	// ����� �� �����
	bool ReadFromFile(Type(*f)(ifstream&), string newfname);


		// ���� � ������
		void ReadFromScreen(Type(*f)());
	

	// �������� �����
		vector<Type> LinearySearch(Type search_elem, bool(*Equal)(Type, Type));


	// �������� ����� ���������� ����� ��-�� ����������� � search_elem ���� ���������� �� ������ ���������� -1
		int LinearySearchElem(Type search_elem);
	// �������� �����
	// int(*Compare)(Type, Type, int) - ��������� �� �������, ������� ���������� ������� ��-� � ������� �� type_search 
	// bool(*Equal)(Type, Type, int) - ��������� �� �������, ������� ��������� ��������� �������� ��-�� � ������� �� type_search
		vector<Type> BinarySearch(Type find_element, bool(*Compare)(Type, Type), bool(*Equal)(Type, Type));

};





