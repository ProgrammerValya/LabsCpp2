#pragma once

#include <math.h>
#include <string>
#include <iostream>
#include <string>
#include<vector>
#include "user.h"


using namespace std;
// ����� ����������

class Worker : public User
{
	
private:
	// ��� ������ �� ����� ������ "Worker"
	//���������� ��� ������ ���� � ������� typedef
	typedef void (Worker::*DynamicFunction)();

	// ������ ������ �� ������ ������
	vector<DynamicFunction> menuFunctions;

	// ������ ����
	vector<string> menuNames;

public:

	Worker(string filename_model_PC, string filename_history_buy);

	// �������� ������ PC
	void AddModelPC();

	// �������� ������ PC
	void ChangeModelPC();

	// ������� ������ PC
	void DeleteModelPC();

	// ���������� ������� �������
	void ReadHistoryBuying();

	// ����
	void Menu();

};