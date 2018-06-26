// ConsoleApplication24.cpp: ���������� ����� ����� ��� ����������� ����������.
//

//������ ���������� ��������������� ����� � ��������� ����� ����������, �����
//����������, �������� ������ ����������, ������� ����������� ������, �������
//�������� �����, ������� ������ ����������, ���������� ���������� �
//����������� �����������.����� �� ���� ����������, ������ ���, ������
//���������� � ������ �������� �����.
#include <stdio.h>
#include "stdafx.h"
#include <math.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include "InputHelp.h"
#include "ComputerUtils.cpp"
#include "Computer.h"
using namespace std;

int Menu()
{
	cout << " --------------------����---------------------  " << endl;
	cout << "1 - �������� �������" << endl;
	cout << "2 - ������� �������" << endl;
	cout << "3 - ����� �� �����" << endl;
	cout << "4 - ��������� � ���� " << endl;
	cout << "5 - �������� �����" << endl;
	cout << "6 - �������� �����" << endl;
	cout << "7 - ������� ����������� �� �����" << endl;
	cout << "8 - ��������� ������������ � ����" << endl;
	cout << "0 - �����" << endl;
	int n = InputNum(0, 8, "��� �����: ");
	cout << "\n";
	return n;
}

void ChangeInputData()
{
	ComputerUtils<Computer> comp;
	Computer c;
	bool change = true;
	cout << " --------------------����---------------------  " << endl;
	cout << "1 - ���������� ���������� � �������" << endl;
	cout << "2 - ���������� ���������� �� ����� " << endl;
	cout << "0 - �����" << endl;
	int changemenu = InputNum(0, 2, "��� �����: ");
	switch (changemenu)
	{
	case 1:
		comp.ReadFromScreen(c.InputScreenCompany);
		break;

	case 2:
		change = comp.ReadFromFile(c.ReadFromString);
		break;

	default:
		change = false;
		break;
	}
	if (change)
	{
		bool(*compare)(Computer, Computer) = NULL;
		bool(*sort)(Computer, Computer) = NULL;
	
		vector<Computer> subset;

		int numb;
		while (1)
		{
			int n = Menu();
			switch (n)
			{
			case 1:
				comp.Add(c.InputScreenCompany());
				break;
			case 2:
				comp.OutputScreen(comp.vect, c.OutputScreenComputer); 
				comp.Remove(InputNum(0, comp.size(), "������� ����� ���������� ��-��: "));
				break;

			case 3:
				comp.OutputScreen(comp.vect, Computer::OutputScreenComputer); 
				break;

			case 4:
				comp.OutputFile(comp.vect, c.ToString);  
				break;

			case 5://///////////////////////!!!!!!
				numb = InputNum(1, 4, "�������� ��� ������:\n 1 - �� ���� ����������\n 2 - �� ������ ���\n 3 - �� ������ ����������\n 4 - �� ������ �������� ����� \n��� �����: ");
				c = c.InputConditionType(numb,&compare,&sort);
				subset = comp.LinearySearch(c, compare);
				if (subset.size() != 0)
					comp.OutputScreen(subset, c.OutputScreenComputer);
				else
					cout << "�������� �� �������" << endl;
				break;

			case 6:
				numb = InputNum(1, 4, "�������� ��� ������:\n 1 - �� ���� ����������\n 2 - �� ������ ���\n 3 - �� ������ ����������\n 4 - �� ������ �������� ����� \n��� �����: ");
				
				c= c.InputConditionType(numb, &compare, &sort);
				subset = comp.BinarySearch(c, sort, compare);
				if (subset.size() != 0)
					comp.OutputScreen(subset, c.OutputScreenComputer);
				else
					cout << "�������� �� �������" << endl;
				break;

			case 7:
				comp.OutputScreen(subset, c.OutputScreenComputer);
				break;

			case 8:
				comp.OutputFile(subset, c.ToString);
				break;

			default:
				cout << "����� " << endl; exit(0);
				break;

			}
		}
	}
	else
		cout << "�����...\n";
	system("pause");
}

void main()
{
	setlocale(LC_ALL, "Russian");
	ChangeInputData();
}

