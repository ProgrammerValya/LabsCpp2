#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "stdafx.h"
#include <math.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <class Type>
class ComputerUtils {
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
	void OutputFile(vector<Type> items, string(*f)(Type, int));
	// ����� �� �����
	void OutputScreen(vector<Type> items, void(*f) (Type));
	// ����� �� �����
	bool ReadFromFile(Type(*f)(ifstream&));
	// ���� � ������
	void ReadFromScreen(Type(*f)());

	// �������� �����
	vector<Type> LinearySearch(Type search_elem, bool(*Equal)(Type, Type));

	// �������� �����
	// int(*Compare)(Type, Type, int) - ��������� �� �������, ������� ���������� ������� ��-� � ������� �� type_search 
	// bool(*Equal)(Type, Type, int) - ��������� �� �������, ������� ��������� ��������� �������� ��-�� � ������� �� type_search
	vector<Type> BinarySearch(Type find_element, bool(*Compare)(Type, Type), bool(*Equal)(Type, Type));
};



