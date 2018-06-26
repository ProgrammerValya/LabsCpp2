// 3)����������� ����������� ������� ��. ������� ������ ����� ��� ������ ������ � ������ � ��������� (���������� � ����). 
//��������� ����� ����������� ���������� ���������: ����������, ��������������, �������� ������� ��.
//������������� ����� ������ ������� �� � ����������� �/��� ����������� �� ���������� ����.
//������������ ����� ����������� ������ �� �� ��������� �������� (����� ����, ��� ����� ���� ���� � ������ ������ � ������������� ���� ���������)
//� ������� ���������� ��. ������������� �������� ������� ������� � �������� ������� �����������.

#include <stdio.h>
#include "stdafx.h"
#include <math.h>
#include <string.h>
#include <iostream>
#include "user.h"
#include "worker.h"
#include "client.h"
#include "InputHelp.h"
using namespace std;

void Shop()
{

	User *user;

	string name_client;

	string filename_model_PC = "files\\PC.dat";
	string filename_history_buy = "files\\buy.dat";

	while (1)
	{
		cout << " --------------------����---------------------  " << endl;
		cout << "1 - ����� ��� ������" << endl;
		cout << "2 - ����� ��� ��������� " << endl;
		cout << "0 - �����" << endl;
		int changemenu = InputNumInt(0, 2, "---> ");
		switch (changemenu)
		{
		case 1:
			name_client = InputInfo("����� �������\n ������� ��� : ");
			user = new Client(name_client, filename_model_PC, filename_history_buy);
			user->Menu();
			break;

		case 2:
			cout << "����� ����������" << endl;
			user = new Worker(filename_model_PC, filename_history_buy);
			user->Menu();
			break;

		default:
			exit(1);
			break;
		}
	}
}

void main()
{
	setlocale(LC_ALL, "Russian");
	system("chcp 1251");
	Shop();
}