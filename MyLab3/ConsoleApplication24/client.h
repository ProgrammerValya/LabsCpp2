#pragma once
#include <math.h>
#include <string>
#include <iostream>
#include<vector>
#include "User.h"
using namespace std;

// ����� �������
class Client : public User
{
private:
	// ��� ������ �� ����� 
	//���������� ��� ������ ���� � ������� typedef
	typedef void (Client::*DynamicFunction)();

	// ������ ������ �� ������ ������
	vector<DynamicFunction> menuFunctions;

	// ������ ����
	vector<string> menuNames;

protected:
	string name_client;
public:

	// �����������
	Client(string _name_client, string _filename_model_PC, string _filename_history_buy);


	// ����� � ��������
	void BuyingModelPC();

	// ����
	void Menu();

};














