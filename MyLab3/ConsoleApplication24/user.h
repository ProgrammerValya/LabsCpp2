
#pragma once
#include <math.h>
#include <string>
#include <iostream>
#include <string>

#include "ComputerUtils.cpp"



using namespace std;

//����� ������������. ����� ������������ ��� worker � client
//class ComputerUtils;
class BuyingComputer;
class Computer;

class User {
protected:
	// ��� ����� ������� ����������
	string filename_model_PC;
	// ��� ����� ������� �������
	string filename_history_buy;

	// ������ � �������� �����������
	ComputerUtils<Computer> vectModelComputer;

	// ������ � ��������� �������
	ComputerUtils<BuyingComputer> vectBuyingComputer;

public:

	// �����������
	User(string filename_model_PC, string filename_history_buy);

	//����� ������ ������� �� � ����������� ���������� ����
	vector<Computer> LookModelPCToCriteria();

	//  ������� ����
	virtual void Menu() = 0;

	// ���������� ������ PC
	void ReadModelPC();

	// �����
	void Close();
};
