#pragma once
#include <string>
#include <math.h>
#include <iostream>
#include <iomanip>
using namespace std;

//����� �����������, ������� ��� �������. �� ��� ����������� ������� �������
class BuyingComputer
{
private:
	// ��� ��������� �����
	int code;
	// ��� ����������
	string name;
	// ���� �������
	string date;

public:

	// �����������
	BuyingComputer();

	// ����� ����� ��������� "��������� ���������" � �������
	BuyingComputer(string _name, int _code);

	// ����� ������ ��������� "��������� ���������" �� �������
	static void OutputScreenBuyingComputer(BuyingComputer c);

	// ����� ���������
	static void OutputScreenHeaderBuyingComputer();

	// ������ � �������� ����
	static void WriteBuyingComputerToFile(BuyingComputer a, ofstream& os);

	// ���������� �� ��������� �����
	static BuyingComputer ReadBuyingComputerFromFile(ifstream& in);

};

